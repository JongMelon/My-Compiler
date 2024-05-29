#include "Trans.h"

SymbolTable::SymbolTable(SymbolTable::Scope scope, string local_label) {
    this->scope = scope;
    if (scope == SymbolTable::Scope::LOCAL)
        this->local_label = local_label;

    table.push_back(unordered_map<string, shared_ptr<SymbolType>>());
    level = 0;

    func_ret_label = new_label();
}

shared_ptr<SymbolType> SymbolTable::lookup(string name) {
    for (int i = level; i >= 0; i--) {
        if (table[i].find(name) != table[i].end())
            return table[i][name];
    }
        return nullptr;
}

void SymbolTable::insert(string name, shared_ptr<SymbolType> symbol) {
    table[level][name] = symbol;
}

void SymbolTable::enter_scope() {
    table.push_back(unordered_map<string, shared_ptr<SymbolType>>());
    level++;
}

void SymbolTable::exit_scope() {
    table.pop_back();
    level--;
}

int SymbolTable::new_label() {
    return label++;
}

void SymbolTable::push_loop_labels(int start, int end) {
    curr_loop_start.push(start);
    curr_loop_end.push(end);
}

void SymbolTable::pop_loop_labels() {
    if (!curr_loop_start.empty())
        curr_loop_start.pop();
    if (!curr_loop_end.empty())
        curr_loop_end.pop();
}

int SymbolTable::get_loop_start() {
    if (!curr_loop_start.empty())
        return curr_loop_start.top();
    return -1;
}

int SymbolTable::get_loop_end() {
    if (!curr_loop_end.empty())
        return curr_loop_end.top();
    return -1;
}

int SymbolTable::get_func_ret_label() {
    return func_ret_label;
}

inline void SymbolTable::new_regs(int id) {
    if (id < 0 || id > 5) {
        fprintf(stderr, "Invalid register id!\n");
        exit(1);
    }
    if (regs_used[id] > 0) {
        assembly_code.push_back("\tpush  " + param_regs[id]);
        push_cnt++;
    }
    regs_used[id]++;
}

inline void SymbolTable::free_regs(int id) {
    if (id < 0 || id > 5) {
        fprintf(stderr, "Invalid register id!\n");
        exit(1);
    }
    regs_used[id]--;
    if (regs_used[id] > 0) {
        assembly_code.push_back("\tpop  " + param_regs[id]);
        push_cnt--; 
    }
}

CodeGenerator::CodeGenerator() {
    global_table = make_shared<SymbolTable>(SymbolTable::Scope::GLOBAL, "");

    shared_ptr<FuncSymbol> symbol = make_shared<FuncSymbol>(SymbolType::FuncKind::INT, 0, "printf");
    lib_funcs["printf"] = symbol;
    global_table->insert("printf", symbol);

    symbol = make_shared<FuncSymbol>(SymbolType::FuncKind::INT, 0, "scanf");
    lib_funcs["scanf"] = symbol;
    global_table->insert("scanf", symbol);
}

bool CodeGenerator::check_is_lib(string name) {
    return (lib_funcs.find(name) != lib_funcs.end());
}

string CodeGenerator::judge_const(pair<bool, int>& res, bool is_rax) {
    if (is_rax)
        return res.first ? to_string(res.second) : "rax";
    else
        return res.first ? to_string(res.second) : "eax";
}

void CodeGenerator::fill_zero(shared_ptr<SymbolTable> table, int array_base, int offset, int fill_size) {
    if (fill_size < 2) {
        table->assembly_code.push_back("\tmov  dword ptr [rbp" + to_string(array_base + offset * 4) + "], 0");
        return;
    }

    table->new_regs(3);

    table->assembly_code.push_back("\tlea  rdi, [rbp" + to_string(array_base + offset * 4) + "]");
    table->assembly_code.push_back("\tmov  rcx, " + to_string(fill_size / 2));
    table->assembly_code.push_back("\tmov  rax, 0");
    table->assembly_code.push_back("\trep stosq");

    if (fill_size % 2)
        table->assembly_code.push_back("\tmov  dword ptr [rdi], eax");

    table->free_regs(3);

    return;
}

void CodeGenerator::dump(shared_ptr<CompUnit> comp_unit, string filename) {
    traverse(global_table, comp_unit);

    // output assembly code to file

    ofstream out_file;
    out_file.open(filename);

    std::cerr << global_table->assembly_code.size() << endl;

    out_file << ".intel_syntax noprefix" << endl;

    out_file << endl;

    out_file << ".section .rodata" << endl;
    for (auto code : rdata)
        out_file << code << endl;
    
    out_file << endl;

    out_file << ".section .data" << endl;
    for (auto code : global_data)
        out_file << code << endl;

    out_file << endl;

    out_file << ".section .text" << endl;
    for (auto name : text)
        out_file << ".globl  " << name << endl;

    out_file << endl;

    for (auto code : global_table->assembly_code)
        out_file << code << endl;

    for (auto table : tables) {
        // align the stack pointer to 16 bytes
        int stack_ptr = table->stack_ptr; // < 0
        stack_ptr *= -1;
        stack_ptr = (stack_ptr + 15) / 16 * 16;
        table->header_code.push_back("\tsub  rsp, " + to_string(stack_ptr));
        for (auto head : table->header_code)
            out_file << head << endl;
        for (auto code : table->assembly_code) {
            out_file << code << endl;
        }
        for (auto foot : table->footer_code)
            out_file << foot << endl;
    }

    out_file.close();
}

shared_ptr<SymbolType> CodeGenerator::lookup(shared_ptr<SymbolTable> curr_table, string name) {
    shared_ptr<SymbolType> symbol = curr_table->lookup(name);
    if (symbol == nullptr)
        symbol = global_table->lookup(name);
    return symbol;
}

inline int CodeGenerator::search_const_str(string str) {
    if (const_str.find(str) != const_str.end())
        return const_str[str];
    const_str[str] = str_num;
    rdata.push_back(".LC" + to_string(str_num) + ":");
    rdata.push_back("\t.string  \"" + str + "\"");
    return str_num++;
}

pair<bool, int> CodeGenerator::handle_exp(shared_ptr<SymbolTable> table, shared_ptr<Tree> node) {
    if (typeid(*node) == typeid(Exp))
        return handle_exp(table, dynamic_pointer_cast<Exp>(node)->add_exp);
    
    else if (typeid(*node) == typeid(ConstExp)) {
        shared_ptr<ConstExp> const_exp = dynamic_pointer_cast<ConstExp>(node);
        pair<bool, int> res = handle_exp(table, const_exp->exp);
        if (res.first)
            return res;
        else {
            fprintf(stderr, "Error: %s\n", "Const exp should be a const");
            exit(1);
        }
    }

    else if (typeid(*node) == typeid(AddExp)) {
        shared_ptr<AddExp> add_exp = dynamic_pointer_cast<AddExp>(node);
        if (add_exp->addExpType == AddExpType::MulExp)
            return handle_exp(table, add_exp->mul_exp);
        else if (add_exp->addExpType == AddExpType::AddMulExp) {
            pair<bool, int> res2 = handle_exp(table, add_exp->mul_exp);
            if (!res2.first) {
                table->new_regs(3);
                table->assembly_code.push_back("\tpush  rax");
                table->push_cnt++;
            }
            pair<bool, int> res1 = handle_exp(table, add_exp->add_exp);
            if (!res2.first) {
                table->assembly_code.push_back("\tpop  rcx");
                table->push_cnt--;
            }

            if (add_exp->op == "+") {
                if ((!res1.first) && (!res2.first)) {
                    table->assembly_code.push_back("\tadd  eax, ecx");
                    table->free_regs(3);
                }
                else if ((!res1.first) && res2.first)
                    table->assembly_code.push_back("\tadd  eax, " + to_string(res2.second));
                else if (res1.first && (!res2.first)) {
                    table->assembly_code.push_back("\tadd  ecx, " + to_string(res1.second));
                    table->assembly_code.push_back("\tmov  ecx, eax");
                    table->free_regs(3);
                }
                else
                    return make_pair(true, res1.second + res2.second);
                return make_pair(false, 1);
            }
            else if (add_exp->op == "-") {
                if ((!res1.first) && (!res2.first)) {
                    table->assembly_code.push_back("\tsub  eax, ecx");
                    table->free_regs(3);
                }
                else if ((!res1.first) && res2.first)
                    table->assembly_code.push_back("\tsub  eax, " + to_string(res2.second));
                else if (res1.first && (!res2.first)) {
                    table->assembly_code.push_back("\tsub  ecx, " + to_string(res1.second));
                    table->assembly_code.push_back("\tmov  eax, ecx");
                    table->free_regs(3);
                }  
                else
                    return make_pair(true, res1.second - res2.second);
                return make_pair(false, 1);
            }
        }
    }

    else if (typeid(*node) == typeid(MulExp)) {
        shared_ptr<MulExp> mul_exp = dynamic_pointer_cast<MulExp>(node);
        if (mul_exp->mulExpType == MulExpType::UnaryExp)
            return handle_exp(table, mul_exp->unary_exp);
        else if (mul_exp->mulExpType == MulExpType::MulUnaryExp) {
            pair<bool, int> res2 = handle_exp(table, mul_exp->unary_exp);
            if (!res2.first) {
                table->new_regs(3);
                table->assembly_code.push_back("\tpush  rax");
                table->push_cnt++;
            }
            pair<bool, int> res1 = handle_exp(table, mul_exp->mul_exp);
            if (!res2.first) {
                table->assembly_code.push_back("\tpop  rcx"); // now rax = exp2, rcx = exp1
                table->push_cnt--;
            }

            if (mul_exp->op == "*") {
                if ((!res1.first) && (!res2.first)) {
                    table->assembly_code.push_back("\timul eax, ecx");
                    table->free_regs(3);
                }
                else if ((!res1.first) && res2.first) {
                    //table->assembly_code.push_back("\tmov  eax, ecx");
                    table->assembly_code.push_back("\timul eax, " + to_string(res2.second));
                }
                else if (res1.first && (!res2.first)) {
                    table->assembly_code.push_back("\timul ecx, " + to_string(res1.second));
                    table->assembly_code.push_back("\tmov  eax, ecx");
                    table->free_regs(3);
                }
                else
                    return make_pair(true, res1.second * res2.second);
                return make_pair(false, 1);
            }
            else if (mul_exp->op == "/") {
                if ((!res1.first) && (!res2.first)) {
                    table->new_regs(2);
                    //table->new_regs(3);
                    table->assembly_code.push_back("\tcdq");
                    table->assembly_code.push_back("\tidiv ecx");
                }
                else if ((!res1.first) && res2.first) {
                    table->new_regs(2);
                    table->new_regs(3);
                    table->assembly_code.push_back("\tcdq");
                    table->assembly_code.push_back("\tmov  ecx, " + to_string(res2.second));
                    table->assembly_code.push_back("\tidiv ecx");
                }
                else if (res1.first && (!res2.first)) {
                    table->new_regs(2);
                    //table->new_regs(3);
                    table->assembly_code.push_back("\tmov  eax, " + to_string(res1.second));
                    table->assembly_code.push_back("\tcdq");
                    table->assembly_code.push_back("\tidiv ecx");
                }
                else
                    return make_pair(true, res1.second / res2.second);
                table->free_regs(2);
                table->free_regs(3);
                return make_pair(false, 1);
            }
            else if (mul_exp->op == "%") {
                if ((!res1.first) && (!res2.first)) {
                    table->new_regs(2);
                    //table->new_regs(3);
                    table->assembly_code.push_back("\tcdq");
                    table->assembly_code.push_back("\tidiv ecx");
                }
                else if ((!res1.first) && res2.first) {
                    table->new_regs(2);
                    table->new_regs(3);
                    table->assembly_code.push_back("\tcdq");
                    table->assembly_code.push_back("\tmov  ecx, " + to_string(res2.second));
                    table->assembly_code.push_back("\tidiv ecx");

                }
                else if (res1.first && (!res2.first)) {
                    table->new_regs(2);
                    //table->new_regs(3);
                    table->assembly_code.push_back("\tmov  eax, " + to_string(res1.second));
                    table->assembly_code.push_back("\tcdq");
                    table->assembly_code.push_back("\tidiv ecx");
                }
                else
                    return make_pair(true, res1.second % res2.second);
                table->assembly_code.push_back("\tmov  eax, edx");
                table->free_regs(2);
                table->free_regs(3);
                return make_pair(false, 1);
            }
        }
    }

    else if (typeid(*node) == typeid(UnaryExp)) {
        shared_ptr<UnaryExp> unary_exp = dynamic_pointer_cast<UnaryExp>(node);
        if (unary_exp->unaryExpType == UnaryExpType::PrimaryExp)
            return handle_exp(table, unary_exp->primary_exp);
        else if (unary_exp->unaryExpType == UnaryExpType::FuncCall) {
            shared_ptr<FuncSymbol> symbol = dynamic_pointer_cast<FuncSymbol>(global_table->lookup(unary_exp->func_ident));
            if (symbol == nullptr) {
                fprintf(stderr, "Error: %s\n", "Function not declared");
                std::cerr << "function name: " << unary_exp->func_ident << std::endl;
                exit(1);
            }
            int param_num = unary_exp->funcRParamList ? unary_exp->funcRParamList->exps.size() : 0;
            if (!check_is_lib(symbol->name)) {
                if (param_num != symbol.get()->param_num) {
                    fprintf(stderr, "Error: %s\n", "Number of parameters does not match");
                    exit(1);
                }
            }
            //table->store_regs();

            for (int i = 0; i < param_num; i++) {
                if (i >= param_reg_num)
                    break;
                table->new_regs(i);
            }

            if (param_num > param_reg_num) {
                if ((param_num - param_reg_num + table->push_cnt) & 1)
                    table->assembly_code.push_back("\tsub  rsp, 8");
            }

            for (int i = param_num - 1; i >= 0; i--) {
                pair<bool, int> res = handle_exp(table, unary_exp->funcRParamList->exps[i]);
                if (i < param_reg_num) {
                    table->assembly_code.push_back("\tmov  " + param_regs[i] + ", " + judge_const(res));
                }
                else
                    table->assembly_code.push_back("\tpush  " + judge_const(res));
            }
            table->assembly_code.push_back("\txor  eax, eax");
            table->assembly_code.push_back("\tcall  " + symbol.get()->name);
            if (param_num > param_reg_num) {
                int align_size = ((param_num - param_reg_num + table->push_cnt) & 1);
                table->assembly_code.push_back("\tadd  rsp, " + to_string((param_num - param_reg_num + align_size) * 8));
            }
            
            for (int i = param_num - 1; i >= 0; i--) {
                if (i >= param_reg_num)
                    continue;
                table->free_regs(i);
            }

            return make_pair(false, 1);
        }
        else if (unary_exp->unaryExpType == UnaryExpType::OP_Exp) {
            pair<bool, int> res = handle_exp(table, unary_exp->unary_exp);
            if (unary_exp->op == "-") {
                if (res.first)
                    return make_pair(true, -res.second);
                else {
                    table->assembly_code.push_back("\tneg  eax");
                    return make_pair(false, 1);
                }
            }
            else if (unary_exp->op == "&") {
                shared_ptr<VarSymbol> symbol = dynamic_pointer_cast<VarSymbol>(lookup(table, unary_exp->ident));
                if (symbol == nullptr) {
                    fprintf(stderr, "Error: %s\n", "Variable not declared");
                    fprintf(stderr, "Variable name: %s\n", unary_exp->ident.c_str());
                    fprintf(stderr, "Table name: %s\n", table->local_label.c_str());
                    fprintf(stderr, "Table scope: %d\n", table->level);
                    exit(1);
                }
                if (symbol->kind == VarSymbol::VarKind::INT)
                    table->assembly_code.push_back("\tlea  rax, [rbp" + to_string(symbol->offset) + "]");
                else if (symbol->kind == VarSymbol::VarKind::GLOBAL_INT)
                    table->assembly_code.push_back("\tlea  rax, " + symbol->name + "[rip]"); // TODO: check this
                return make_pair(false, 1);
            }
        }
    }

    else if (typeid(*node) == typeid(PrimaryExp)) {
        shared_ptr<PrimaryExp> primary_exp = dynamic_pointer_cast<PrimaryExp>(node);
        if (primary_exp->primaryExpType == PrimaryExpType::Exp)
            return handle_exp(table, primary_exp->exp);
        else if (primary_exp->primaryExpType == PrimaryExpType::LVal) {
            shared_ptr<SymbolType> symbol = lookup(table, primary_exp->lVal->ident);
            if (symbol == nullptr) {
                fprintf(stderr, "Error: %s\n", "Variable not declared in exp");
                fprintf(stderr, "Variable name: %s\n", primary_exp->lVal->ident.c_str());
                fprintf(stderr, "Table name: %s\n", table->local_label.c_str());
                fprintf(stderr, "Table scope: %d\n", table->level);
                exit(1);
            }
            if /*(primary_exp->lVal->varKind == VarKind::Var)*/ (typeid(*symbol) == typeid(VarSymbol)) {
                shared_ptr<VarSymbol> var_symbol = dynamic_pointer_cast<VarSymbol>(symbol);
                if (var_symbol->kind == VarSymbol::VarKind::INT) {
                    table->assembly_code.push_back("\tmov  eax, dword ptr [rbp" + to_string(var_symbol->offset) + "]");
                    return make_pair(false, 1);
                }
                else if (var_symbol->kind == VarSymbol::VarKind::GLOBAL_INT) {
                    table->assembly_code.push_back("\tmov  rax,  qword ptr " + var_symbol->name + "@GOTPCREL[rip]");
                    table->assembly_code.push_back("\tmov  eax, dword ptr [rax]");
                    return make_pair(false, 1);
                }
                else if (var_symbol->kind == VarSymbol::VarKind::CONST_INT) {
                    //table->assembly_code.push_back("\tmov  eax, " + to_string(symbol->value));
                    std::cerr << "const int: " << var_symbol->value << endl;
                    return make_pair(true, var_symbol->value);
                }
                else if (var_symbol->kind == VarSymbol::VarKind::GLOBAL_CONST) {
                    //table->assembly_code.push_back("\tmov  eax, " + symbol->name + "[rip]");
                    return make_pair(true, var_symbol->value);
                }
            }
            else if /*(primary_exp->lVal->varKind == VarKind::Array)*/ (typeid(*symbol) == typeid(ArraySymbol)) {
                if (primary_exp->lVal->varKind == VarKind::Array) {
                    shared_ptr<ArraySymbol> arr_symbol = dynamic_pointer_cast<ArraySymbol>(symbol);
                    int exp_num = primary_exp->lVal->arrayIndex->exps.size();
                    if (exp_num != arr_symbol->dim) {
                        fprintf(stderr, "Error: %s\n", "Number of dimensions does not match");
                        exit(1);
                    }

                    if (arr_symbol->kind == ArraySymbol::ArrayKind::CONST_INT || arr_symbol->kind == ArraySymbol::ArrayKind::GLOBAL_CONST) {
                        bool is_const = true;
                        int addr = 0;
                        for (int i = 0; i < exp_num - 1; i++) {
                            pair<bool, int> res = handle_exp(table, primary_exp->lVal->arrayIndex->exps[i]);
                            is_const = is_const && res.first;
                            addr += res.second;
                            addr *= arr_symbol->dim_size[i + 1];
                        }
                        pair<bool, int> res = handle_exp(table, primary_exp->lVal->arrayIndex->exps[exp_num - 1]);
                        is_const = is_const && res.first;
                        addr += res.second;

                        if (!is_const) {
                            fprintf(stderr, "Error: can not get a const value from const array!\n");
                            exit(1);
                        }

                        return make_pair(true, arr_symbol->const_val[addr]);
                    }

                    // using register r8 to store the address of the array
                    table->new_regs(4);
                    table->assembly_code.push_back("\txor  r8, r8");

                    for (int i = 0; i < exp_num - 1; i++) {
                        pair<bool, int> res = handle_exp(table, primary_exp->lVal->arrayIndex->exps[i]);
                        table->assembly_code.push_back("\tadd  r8,  " + judge_const(res));
                        table->assembly_code.push_back("\timul r8, " + to_string(arr_symbol->dim_size[i + 1]));
                    }
                    pair<bool, int> res = handle_exp(table, primary_exp->lVal->arrayIndex->exps[exp_num - 1]);
                    table->assembly_code.push_back("\tadd  r8, " + judge_const(res));

                    if (arr_symbol->kind == ArraySymbol::ArrayKind::INT) {
                        table->assembly_code.push_back("\tmov  eax, dword ptr [rbp" + to_string(arr_symbol->offset) + " + r8 * 4]");
                        table->free_regs(4);
                        return make_pair(false, 1);
                    }
                    else if (arr_symbol->kind == ArraySymbol::ArrayKind::GLOBAL_INT) {
                        table->assembly_code.push_back("\tmov  rax,  qword ptr " + arr_symbol->name + "@GOTPCREL[rip]");
                        table->assembly_code.push_back("\tmov  eax, dword ptr [rax + r8 * 4]");
                        table->free_regs(4);
                        return make_pair(false, 1);
                    }
                    else if (arr_symbol->kind == ArraySymbol::ArrayKind::PARAM_PTR) {
                        table->new_regs(5);
                        table->assembly_code.push_back("\tmov  r9, qword ptr [rbp" + to_string(arr_symbol->offset) + "]");
                        table->assembly_code.push_back("\tmov  eax, dword ptr [r9 + r8 * 4]");
                        table->free_regs(5);
                        table->free_regs(4);
                        return make_pair(false, 1);
                    }
                }
                else if (primary_exp->lVal->varKind == VarKind::Var) {
                    // convert array to pointer
                    shared_ptr<ArraySymbol> ptr_symbol = dynamic_pointer_cast<ArraySymbol>(symbol);
                    if (ptr_symbol->kind == ArraySymbol::ArrayKind::INT || ptr_symbol->kind == ArraySymbol::ArrayKind::CONST_INT) {
                        table->assembly_code.push_back("\tlea  rax, [rbp" + to_string(ptr_symbol->offset) + "]");
                        return make_pair(false, 1);
                    }
                    else if (ptr_symbol->kind == ArraySymbol::ArrayKind::GLOBAL_INT) {
                        table->assembly_code.push_back("\tmov  rax, qword ptr " + ptr_symbol->name + "@GOTPCREL[rip]");
                        return make_pair(false, 1);
                    }
                    else if (ptr_symbol->kind == ArraySymbol::ArrayKind::PARAM_PTR) {
                        table->assembly_code.push_back("\tmov  rax, qword ptr [rbp" + to_string(ptr_symbol->offset) + "]");
                        return make_pair(false, 1);
                    }
                    else if (ptr_symbol->kind == ArraySymbol::ArrayKind::GLOBAL_CONST) {
                        table->assembly_code.push_back("\tlea  rax, " + ptr_symbol->name + "[rip]");
                        return make_pair(false, 1);
                    }
                }
            }
        }
        else if (primary_exp->primaryExpType == PrimaryExpType::Number) {
            return make_pair(true, primary_exp->number);
        }
        else if (primary_exp->primaryExpType == PrimaryExpType::String) {
            int str_num = search_const_str(primary_exp->str);
            table->assembly_code.push_back("\tlea  rax, .LC" + to_string(str_num) + "[rip]");
            return make_pair(false, 1);
        }
    }

    return make_pair(false, 1); // should not enter here
}

pair<bool, int> CodeGenerator::handle_initval(shared_ptr<SymbolTable> table, shared_ptr<Tree> node) {
    if (typeid(*node) == typeid(ConstInitVal)) {
        shared_ptr<ConstInitVal> const_init_val = dynamic_pointer_cast<ConstInitVal>(node);
        if (const_init_val->constExp == nullptr) {
            fprintf(stderr, "Error: %s\n", "Const variable should be initialized");
            exit(1);
        }
        return handle_exp(table, const_init_val->constExp);
    }
    else if (typeid(*node) == typeid(InitVal)) {
        shared_ptr<InitVal> init_val = dynamic_pointer_cast<InitVal>(node);
        if (init_val->varKind == VarKind::Var)
            return handle_exp(table, init_val->exp);
        else if (init_val->varKind == VarKind::Array) {
            fprintf(stderr, "Error: %s\n", "Should not enter here");
            exit(1);
        }
    }
    fprintf(stderr, "Error: %s\n", "Should not enter here");
    return make_pair(false, 1);
}

// handle initialization of array like this : int arr[3][2][2] = {1,2,3,4,{ {{},{6}} ,-1,-2 },{9,10}}
int CodeGenerator::handle_arr_initval(shared_ptr<SymbolTable> table, shared_ptr<ArraySymbol> array, shared_ptr<InitVal> init_val, int dim, int offset) {
    int max_size = 1;

    std::cerr << "array: " << array->name << endl;
    std::cerr << "dim: " << dim << endl;
    std::cerr << "offset: " << offset << endl;

    for (int i = dim; i < array->dim_size.size(); i++)
        max_size *= array->dim_size[i];

    std::cerr << "max_size: " << max_size << endl;
    
    int next_align_size = dim < array->dim_size.size() ? max_size / array->dim_size[dim] : 1;

    std::cerr << "next_align_size: " << next_align_size << endl;

    if (init_val->varKind == VarKind::Var) {
        // fill the array with exp value
        pair<bool, int> res = handle_exp(table, init_val->exp);
        /*if (!res.first) {
            fprintf(stderr, "Error: Initialize array with non-const exp\n");
            exit(1);
        }*/
        
        if (array->kind == ArraySymbol::ArrayKind::GLOBAL_INT) {
            if (res.first)
                global_data.push_back("\t.long  " + to_string(res.second));
            else {
                fprintf(stderr, "Error: %s\n", "Initialize global array with non-const exp");
                exit(1);
            }
        }
        else if (array->kind == ArraySymbol::ArrayKind::PARAM_PTR) {
            fprintf(stderr, "Error: %s\n", "Should not initialize a parameter array");
            exit(1);
        }
        else if (array->kind == ArraySymbol::ArrayKind::GLOBAL_CONST) {
            if (res.first)
                rdata.push_back("\t.long  " + to_string(res.second));
            else {
                fprintf(stderr, "Error: %s\n", "Initialize global const array with non-const exp");
                exit(1);
            }
        }
        else {
            if (res.first) {
                table->assembly_code.push_back("\tmov  dword ptr [rbp" + to_string(array->offset + offset * 4) + "], " + to_string(res.second));
                if (array->kind == ArraySymbol::ArrayKind::CONST_INT)
                    array->const_val.push_back(res.second); 
            }
            else {
                table->assembly_code.push_back("\tmov  dword ptr [rbp" + to_string(array->offset + offset * 4) + "], eax");
                if (array->kind == ArraySymbol::ArrayKind::CONST_INT) {
                    fprintf(stderr, "Error: %s\n", "Initialize const array with non-const exp");
                    exit(1);
                }
            }
        }
        return 1;
    }

    else {
        if (init_val->initValList == nullptr) {
            // fill this dimension with 0, using rep stosq
            if (array->kind == ArraySymbol::ArrayKind::GLOBAL_INT || array->kind == ArraySymbol::ArrayKind::GLOBAL_CONST)
                global_data.push_back("\t.zero  " + to_string(max_size * 4));
            else {
                fill_zero(table, array->offset, offset, max_size);
                if (array->kind == ArraySymbol::ArrayKind::CONST_INT) {
                    for (int i = 0; i < max_size; i++)
                        array->const_val.push_back(0);
                }
            }
            return max_size;
        }
        else {
            if (dim >= array->dim_size.size() && init_val->initValList->initVals.size() > 1) {
                fprintf(stderr, "Error: %s\n", "Initialization of array with too many dimensions");
                exit(1);
            }
            int filled_size = 0;
            for (auto init_val_it : init_val->initValList->initVals) {
                if (filled_size >= max_size) {
                    fprintf(stderr, "Error: %s\n", "Initialization of array with too many arguments");
                    exit(1);
                }
                if (init_val_it->varKind == VarKind::Var) {
                    // still in the same dimension!
                    filled_size += handle_arr_initval(table, array, init_val_it, dim, offset + filled_size);
                }
                else {
                    /*if (max_size % filled_size) {
                        fprintf(stderr, "Error: %s\n", "Initialization of array with too few arguments");
                        exit(1);
                    }*/

                    int next_depth = array->dim_size.size() - 1;
                    int temp_filled = filled_size;
                    while (next_depth > dim) {
                        if (temp_filled % array->dim_size[next_depth])
                            break;
                        else {
                            temp_filled /= array->dim_size[next_depth];
                            next_depth--;
                        }
                    }

                    if (next_depth == array->dim_size.size() - 1) {
                        fprintf(stderr, "Error: %s\n", "Initialization of array not aligned");
                        exit(1);
                    }

                    int next_filled = handle_arr_initval(table, array, init_val_it, next_depth + 1, offset + filled_size);
                    if (next_filled > next_align_size) {
                        fprintf(stderr, "Error: %s\n", "Initialization of array with too many arguments");
                        exit(1);
                    }
                    // align
                    if (next_filled < next_align_size) {
                        // fill with 0
                        if (array->kind == ArraySymbol::ArrayKind::GLOBAL_INT)
                            global_data.push_back("\t.zero  " + to_string((next_align_size - next_filled) * 4));
                        else {
                            fill_zero(table, array->offset, offset + filled_size + next_filled, next_align_size - next_filled);
                            if (array->kind == ArraySymbol::ArrayKind::CONST_INT) {
                                for (int i = 0; i < next_align_size - next_filled; i++)
                                    array->const_val.push_back(0);
                            }
                        }
                    }
                    filled_size += next_align_size;
                }
            }
            if (filled_size < max_size) {
                if (array->kind == ArraySymbol::ArrayKind::GLOBAL_INT)
                    global_data.push_back("\t.zero  " + to_string((max_size - filled_size) * 4));
                    //global_decl.push_back("\t.zero  " + to_string((max_size - filled_size) * 4));
                else {
                    fill_zero(table, array->offset, offset + filled_size, max_size - filled_size);
                    //table->assembly_code.push_back("// dim: " + to_string(dim) + " offset: " + to_string(offset) + " filled_size: " + to_string(filled_size) + " max_size: " + to_string(max_size));
                } 
            }
            return max_size;
        }
    }
}

void CodeGenerator::handle_constdef(shared_ptr<SymbolTable> table, shared_ptr<ConstDef> node) {
    if (node->varKind == VarKind::Var) {
        if (node->constInitVal == nullptr) {
            fprintf(stderr, "Error: %s\n", "Const variable should be initialized");
            exit(1);
        }
        if (node->constInitVal->varKind == VarKind::Array) {
            fprintf(stderr, "Error: %s\n", "Initialization of const variable with array initializer");
            exit(1);
        }

        shared_ptr<VarSymbol> symbol = make_shared<VarSymbol>(SymbolType::VarKind::CONST_INT, 0, 0, node->ident);

        if (table->scope == SymbolTable::Scope::GLOBAL) {
            symbol->kind = VarSymbol::VarKind::GLOBAL_CONST;
            table->insert(node->ident, symbol);
            rdata.push_back(node->ident + ":");
            
            pair<bool, int> res = handle_initval(table, node->constInitVal);

            table->assembly_code.push_back("\tlong  " + to_string(res.second));

            symbol->value = res.second;
        }
        else {
            table->insert(node->ident, symbol);
            table->stack_ptr -= 4;
            symbol->offset = table->stack_ptr;
            pair<bool, int> res = handle_initval(table, node->constInitVal);

            if (res.first) {
                table->assembly_code.push_back("\tmov  dword ptr [rbp" + to_string(symbol->offset) + "], " + to_string(res.second));
                symbol->value = res.second;
            }
            else
                table->assembly_code.push_back("\tmov  dword ptr [rbp" + to_string(symbol->offset) + "], eax");
        }   
    }
    else if (node->varKind == VarKind::Array) {
        shared_ptr<ArraySymbol> symbol = make_shared<ArraySymbol>(SymbolType::ArrayKind::CONST_INT, 0, node->ident);

        std::cerr << "const array: " << node->ident << endl;
        if (table->scope == SymbolTable::Scope::GLOBAL) {
            global_table->insert(node->ident, symbol);
            symbol->kind = ArraySymbol::ArrayKind::GLOBAL_CONST;
            rdata.push_back(node->ident + ":");
        }
        else
            table->insert(node->ident, symbol);

        symbol->total_size = 1;
        symbol->dim = node->constArrayIndex->const_exps.size();
        for (int i = 0; i < symbol->dim; i++) {
            pair<bool, int> res = handle_exp(table, node->constArrayIndex->const_exps[i]);
            if (!res.first) {
                fprintf(stderr, "Error: Initialize array dim size with non-const exp\n");
                exit(1);
            }
            std::cerr << "dim size: " << res.second << endl;
            symbol->dim_size.push_back(res.second);
            symbol->total_size *= res.second;
        }

        table->stack_ptr -= symbol->total_size * 4;
        symbol->offset = table->stack_ptr;

        if (node->array_initval) {
            std::cerr << "handle the array initval..." << std::endl;
            std::cerr << table->stack_ptr << std::endl;
            std::cerr << symbol->offset << std::endl;
            handle_arr_initval(table, symbol, node->array_initval, 0, 0);
        }
        else {
            fprintf(stderr, "Error: %s\n", "Initialization of const array without initializer");
            exit(1);
        }
    }
}

void CodeGenerator::handle_vardef(shared_ptr<SymbolTable> table, shared_ptr<VarDef> node) {
    if (node->varKind == VarKind::Var) {

        if (node->initVal) {
            if (node->initVal->varKind == VarKind::Array) {
                fprintf(stderr, "Error: %s\n", "Initialization of variable with array initializer");
                exit(1);
            }
        }

        shared_ptr<VarSymbol> symbol = make_shared<VarSymbol>(SymbolType::VarKind::INT, 0, 0, node->ident);

        if (table->scope == SymbolTable::Scope::GLOBAL) {
            // global variable
            symbol->kind = VarSymbol::VarKind::GLOBAL_INT;
            table->insert(node->ident, symbol);
            global_data.push_back(node->ident + ":");
            //global_decl.push_back(node->ident + ":");
        }
        else {
            table->insert(node->ident, symbol);
            std::cerr << "def var: " << node->ident << endl;
            std::cerr << "table name: " << table->local_label << endl;
            std::cerr << "table scope: " << table->level << endl;
        }

        if (symbol->kind != VarSymbol::VarKind::GLOBAL_INT) {
            table->stack_ptr -= 4;
            symbol->offset = table->stack_ptr;
            if (symbol->kind == VarSymbol::VarKind::INT) {
                if (node->initVal) {
                    pair<bool, int> res = handle_initval(table, node->initVal);
                    table->assembly_code.push_back("\tmov  dword ptr [rbp" + to_string(symbol->offset) + "], " + judge_const(res, false));
                }
            }
            else if (symbol->kind == VarSymbol::VarKind::CONST_INT) {
                if (node->initVal) {
                    if (node->initVal->exp) {
                        pair<bool, int> res = handle_exp(table, node->initVal->exp);
                        if (res.first) {
                            table->assembly_code.push_back("\tmov  dword ptr [rbp" + to_string(symbol->offset) + "], " + to_string(res.second));
                            symbol->value = res.second;
                        }
                        else {
                            fprintf(stderr, "Error: %s\n", "Initialization of const variable with non-const exp");
                            exit(1);
                        }
                    }
                    else {
                        fprintf(stderr, "Error: %s\n", "Initialization of const variable with array initializer");
                        exit(1);
                    }
                }
            }
        }
        else {
            if (node->initVal) {
                if (node->initVal->exp) {
                    pair<bool, int> res = handle_exp(table, node->initVal->exp);
                    if (res.first)
                        global_data.push_back("\t.long  " + to_string(res.second));
                        //global_decl.push_back("\t.long  " + to_string(res.second));
                    else {
                        fprintf(stderr, "Error: %s\n", "Initialization of global variable with non-const exp");
                        exit(1);
                    }
                }
            }
            else
                global_data.push_back("\t.zero  4");
        }
    }

    else if (node->varKind == VarKind::Array) {
        shared_ptr<ArraySymbol> symbol = make_shared<ArraySymbol>(SymbolType::ArrayKind::INT, 0, node->ident);

        if (table->scope == SymbolTable::Scope::GLOBAL) {
            symbol->kind = ArraySymbol::ArrayKind::GLOBAL_INT;
            global_table->insert(node->ident, symbol);
            global_data.push_back(node->ident + ":");
            //global_decl.push_back(node->ident + ":");
        }
        else {
            table->insert(node->ident, symbol);
            std::cerr << "def array: " << node->ident << endl;
            std::cerr << "table name: " << table->local_label << endl;
            std::cerr << "table scope: " << table->level << endl;
        }

        symbol->total_size = 1;
        symbol->dim = node->constArrayIndex->const_exps.size();
        std::cerr << "array: " << node->ident << endl;
        for (int i = 0; i < symbol->dim; i++) {
            pair<bool, int> res = handle_exp(table, node->constArrayIndex->const_exps[i]);
            if (!res.first) {
                fprintf(stderr, "Error: Initialize array dim size with non-const exp\n");
                exit(1);
            }
            std::cerr << "dim size: " << res.second << endl;
            symbol->dim_size.push_back(res.second);
            symbol->total_size *= res.second;
        }

        table->stack_ptr -= symbol->total_size * 4;

        symbol->offset = table->stack_ptr;

        if (node->initVal) {
            //handle_initval(table, node->initVal);
            if (node->initVal->varKind == VarKind::Var) {
                fprintf(stderr, "Error: %s\n", "Initialization of array with variable initializer");
                exit(1);
            }
            handle_arr_initval(table, symbol, node->initVal, 0, 0);
        }
        else if (symbol->kind == ArraySymbol::ArrayKind::GLOBAL_INT)
            global_data.push_back("\t.zero  " + to_string(symbol->total_size * 4));
    }
}

shared_ptr<SymbolTable> CodeGenerator::handle_funcDef(shared_ptr<SymbolTable> table, shared_ptr<FuncDef> node) {
    shared_ptr<FuncSymbol> symbol = make_shared<FuncSymbol>(SymbolType::FuncKind::INT, 0, node->ident);

    // table should be a new table
    table = make_shared<SymbolTable>(SymbolTable::Scope::LOCAL, node->ident);

    if (node->funcType->type == "void")
        symbol->kind = FuncSymbol::FuncKind::VOID;
    else
        symbol->kind = FuncSymbol::FuncKind::INT;
    
    table->insert(node->ident, symbol);
    table->curr_func_kind = symbol->kind;

    table->local_label = node->ident;

    text.push_back(node->ident);

    table->footer_code.push_back(".L" + to_string(table->get_func_ret_label()) + ":");
    table->footer_code.push_back("\tleave");
    table->footer_code.push_back("\tret");

    global_table->insert(node->ident, symbol);

    if (node->funcFParamList) {
        symbol->param_num = node->funcFParamList->funcFParams.size();
        for (int i = 0; i < symbol->param_num; i++) {
            if (node->funcFParamList->funcFParams[i]->varKind == VarKind::Var) {
                shared_ptr<VarSymbol> param_symbol = make_shared<VarSymbol>(SymbolType::VarKind::INT, 0, 0, node->funcFParamList->funcFParams[i]->ident);
                table->insert(node->funcFParamList->funcFParams[i]->ident, param_symbol);

                std::cerr << "param: " << node->funcFParamList->funcFParams[i]->ident << endl;
                std::cerr << "table name and scope: " << table->local_label << " " << table->level << endl;

                symbol->params.push_back(param_symbol);
                if (i < param_reg_num) {
                    table->stack_ptr -= 4;
                    param_symbol->offset = table->stack_ptr;
                    table->assembly_code.push_back("\tmov  dword ptr [rbp" + to_string(param_symbol->offset) + "], " + param_regs_32[i]);
                }
                else
                    param_symbol->offset = 16 + (i - param_reg_num) * 8;
            }
            else if (node->funcFParamList->funcFParams[i]->varKind == VarKind::Array) {
                shared_ptr<ArraySymbol> param_symbol = make_shared<ArraySymbol>(SymbolType::ArrayKind::PARAM_PTR, 0, node->funcFParamList->funcFParams[i]->ident);
                param_symbol->dim = 1;
                param_symbol->dim_size.push_back(-1); // the first dim is []
                if (node->funcFParamList->funcFParams[i]->arrayIndex) {
                    for (auto exp : node->funcFParamList->funcFParams[i]->arrayIndex->exps) {
                        pair<bool, int> res = handle_exp(table, exp);
                        if (!res.first) {
                            fprintf(stderr, "Error: Initialize array dim size with non-const exp\n");
                            exit(1);
                        }
                        param_symbol->dim_size.push_back(res.second);
                        param_symbol->dim++;
                    }
                }
                table->insert(node->funcFParamList->funcFParams[i]->ident, param_symbol);
                symbol->params.push_back(param_symbol);

                fprintf(stderr, "param: %s\n", node->funcFParamList->funcFParams[i]->ident.c_str());
                fprintf(stderr, "table name and scope: %s %d\n", table->local_label.c_str(), table->level);

                if (i < param_reg_num) {
                    table->stack_ptr -= 8; // a pointer to the array, 8 bytes
                    param_symbol->offset = table->stack_ptr;
                    table->assembly_code.push_back("\tmov  qword ptr [rbp" + to_string(param_symbol->offset) + "], " + param_regs[i]);
                }
                else
                    param_symbol->offset = 16 + (i - param_reg_num) * 8;
            }
        }
    }

    table->header_code.push_back(node->ident + ":");
    table->header_code.push_back("\tpush  rbp");
    table->header_code.push_back("\tmov  rbp, rsp");

    tables.push_back(table);

    return table;
}

void CodeGenerator::handle_cond(shared_ptr<SymbolTable> table, shared_ptr<Tree> node, int true_label, int false_label) {
    // if the label == -1, then it means the control flow can move to the next statement directly
    if (typeid(*node) == typeid(Exp)) {
        pair<bool, int> res = handle_exp(table, dynamic_pointer_cast<Exp>(node));
        if (res.first) {
            table->assembly_code.push_back("\tmov  eax, " + to_string(res.second)); // Can be optimized
            if (res.second) {
                if (true_label > 0)
                    table->assembly_code.push_back("\tjmp  .L" + to_string(true_label));
            }
            else {
                if (false_label > 0)
                    table->assembly_code.push_back("\tjmp  .L" + to_string(false_label));
            }
        }
        else {
            table->assembly_code.push_back("\ttest  eax, eax");
            if (true_label > 0)
                table->assembly_code.push_back("\tjnz  .L" + to_string(true_label));
            if (false_label > 0)
                table->assembly_code.push_back("\tjmp  .L" + to_string(false_label));
        }
    }
    else if (typeid(*node) == typeid(Cond)) {
        shared_ptr<Cond> cond = dynamic_pointer_cast<Cond>(node);
        handle_cond(table, cond->lOrExp, true_label, false_label);
    }
    else if (typeid(*node) == typeid(LOrExp)) {
        shared_ptr<LOrExp> lOrExp = dynamic_pointer_cast<LOrExp>(node);
        if (lOrExp->lOrExpType == LOrExpType::LAndExp)
            handle_cond(table, lOrExp->lAndExp, true_label, false_label);
        else if (lOrExp->lOrExpType == LOrExpType::LOrLAndExp) {
            int new_false_label = table->new_label();
            handle_cond(table, lOrExp->lOrExp, true_label, new_false_label);
            table->assembly_code.push_back(".L" + to_string(new_false_label) + ":");
            handle_cond(table, lOrExp->lAndExp, true_label, false_label);
        }
    }
    else if (typeid(*node) == typeid(LAndExp)) {
        shared_ptr<LAndExp> lAndExp = dynamic_pointer_cast<LAndExp>(node);
        if (lAndExp->lAndExpType == LAndExpType::EqExp)
            handle_cond(table, lAndExp->eqExp, true_label, false_label);
        else if (lAndExp->lAndExpType == LAndExpType::LAndEqExp) {
            int new_true_label = table->new_label();
            handle_cond(table, lAndExp->lAndExp, new_true_label, false_label);
            table->assembly_code.push_back(".L" + to_string(new_true_label) + ":");
            handle_cond(table, lAndExp->eqExp, true_label, false_label);
        }
    }
    else if (typeid(*node) == typeid(EqExp)) {
        shared_ptr<EqExp> eqExp = dynamic_pointer_cast<EqExp>(node);
        if (eqExp->eqExpType == EqExpType::RelExp)
            handle_cond(table, eqExp->relExp, true_label, false_label);
        else if (eqExp->eqExpType == EqExpType::EqRelExp) {
            if (eqExp->is_rel_exp && eqExp->eqExp->is_rel_exp) {
                pair<bool, int> res2 = handle_exp(table, eqExp->relExp->exp);
                if (!res2.first) {
                    table->new_regs(3);
                    table->assembly_code.push_back("\tpush  rax");
                    table->push_cnt++;
                }
                pair<bool, int> res1 = handle_exp(table, eqExp->eqExp->relExp->exp);
                if (!res2.first) {
                    table->assembly_code.push_back("\tpop  rcx");
                    table->push_cnt--;
                }
                if (eqExp->op == "==") {
                    if (res1.first && res2.first) {
                        if (res1.second == res2.second) {
                            if (true_label > 0)
                                table->assembly_code.push_back("\tjmp  .L" + to_string(true_label));
                        }
                        else {
                            if (false_label > 0)
                                table->assembly_code.push_back("\tjmp  .L" + to_string(false_label));
                        }
                        return;
                    }
                    else if (res1.first && (!res2.first)) {
                        table->assembly_code.push_back("\tcmp  " + to_string(res1.second) + ", rcx");
                        table->free_regs(3);
                    }
                    else if ((!res1.first) && res2.first)
                        table->assembly_code.push_back("\tcmp  rax, " + to_string(res2.second));
                    else {
                        table->assembly_code.push_back("\tcmp  rax, rcx");
                        table->free_regs(3);
                    }
                    if (true_label > 0)
                        table->assembly_code.push_back("\tje  .L" + to_string(true_label));
                    if (false_label > 0)
                        table->assembly_code.push_back("\tjne  .L" + to_string(false_label));
                }
                else if (eqExp->op == "!=") {
                    if (res1.first && res2.first) {
                        if (res1.second != res2.second) {
                            if (true_label > 0)
                                table->assembly_code.push_back("\tjmp  .L" + to_string(true_label));
                        }
                        else {
                            if (false_label > 0)
                                table->assembly_code.push_back("\tjmp  .L" + to_string(false_label));
                        }
                        return;
                    }
                    else if (res1.first && (!res2.first)) {
                        table->assembly_code.push_back("\tcmp  " + to_string(res1.second) + ", rcx");
                        table->free_regs(3);
                    }
                    else if ((!res1.first) && res2.first)
                        table->assembly_code.push_back("\tcmp  rax, " + to_string(res2.second));
                    else {
                        table->assembly_code.push_back("\tcmp  rax, rcx");
                        table->free_regs(3);
                    }
                    if (true_label > 0)
                        table->assembly_code.push_back("\tjne  .L" + to_string(true_label));
                    if (false_label > 0)
                        table->assembly_code.push_back("\tje  .L" + to_string(false_label));
                }
            }
            else {
                fprintf(stderr, "Error: %s\n", "Can not convert bool to int");
                exit(1);
            }
        }
    }
    else if (typeid(*node) == typeid(RelExp)) {
        shared_ptr<RelExp> relExp = dynamic_pointer_cast<RelExp>(node);
        if (relExp->relExpType == RelExpType::Exp)
            handle_exp(table, relExp->exp);
        else if (relExp->relExpType == RelExpType::RelExp) {
            if (relExp->relExp->is_exp) {
                pair<bool, int> res2 = handle_exp(table, relExp->exp);
                if (!res2.first) {
                    table->new_regs(3);
                    table->assembly_code.push_back("\tpush  rax");
                    table->push_cnt++;
                }
                pair<bool, int> res1 = handle_exp(table, relExp->relExp->exp);
                if (!res2.first) {
                    table->assembly_code.push_back("\tpop  rcx");
                    table->push_cnt--;
                }
                if (relExp->op == "\\<") {
                    if (res1.first && res2.first) {
                        if (res1.second < res2.second) {
                            if (true_label > 0)
                                table->assembly_code.push_back("\tjmp  .L" + to_string(true_label));
                        }
                        else {
                            if (false_label > 0)
                                table->assembly_code.push_back("\tjmp  .L" + to_string(false_label));
                        }
                        return;
                    }
                    else if (res1.first && (!res2.first)) {
                        table->assembly_code.push_back("\tcmp  " + to_string(res1.second) + ", rcx");
                        table->free_regs(3);
                    }
                    else if ((!res1.first) && res2.first)
                        table->assembly_code.push_back("\tcmp  rax, " + to_string(res2.second));
                    else {
                        table->assembly_code.push_back("\tcmp  rax, rcx");
                        table->free_regs(3);
                    }
                    if (true_label > 0)
                        table->assembly_code.push_back("\tjl  .L" + to_string(true_label));
                    if (false_label > 0)
                        table->assembly_code.push_back("\tjge  .L" + to_string(false_label));
                }
                else if (relExp->op == "\\<=") {
                    if (res1.first && res2.first) {
                        if (res1.second <= res2.second) {
                            if (true_label > 0)
                                table->assembly_code.push_back("\tjmp  .L" + to_string(true_label));
                        }
                        else {
                            if (false_label > 0)
                                table->assembly_code.push_back("\tjmp  .L" + to_string(false_label));
                        }
                        return;
                    }
                    else if (res1.first && (!res2.first)) {
                        table->assembly_code.push_back("\tcmp  " + to_string(res1.second) + ", rcx");
                        table->free_regs(3);
                    }
                    else if ((!res1.first) && res2.first)
                        table->assembly_code.push_back("\tcmp  rax, " + to_string(res2.second));
                    else {
                        table->assembly_code.push_back("\tcmp  rax, rcx");
                        table->free_regs(3);
                    }
                    if (true_label > 0)
                        table->assembly_code.push_back("\tjle  .L" + to_string(true_label));
                    if (false_label > 0)
                        table->assembly_code.push_back("\tjg  .L" + to_string(false_label));
                }
                else if (relExp->op == "\\>") {
                    if (res1.first && res2.first) {
                        if (res1.second > res2.second) {
                            if (true_label > 0)
                                table->assembly_code.push_back("\tjmp  .L" + to_string(true_label));
                        }
                        else {
                            if (false_label > 0)
                                table->assembly_code.push_back("\tjmp  .L" + to_string(false_label));
                        }
                        return;
                    }
                    else if (res1.first && (!res2.first)) {
                        table->assembly_code.push_back("\tcmp  " + to_string(res1.second) + ", rcx");
                        table->free_regs(3);
                    }
                    else if ((!res1.first) && res2.first)
                        table->assembly_code.push_back("\tcmp  rax, " + to_string(res2.second));
                    else {
                        table->assembly_code.push_back("\tcmp  rax, rcx");
                        table->free_regs(3);
                    }
                    if (true_label > 0)
                        table->assembly_code.push_back("\tjg  .L" + to_string(true_label));
                    if (false_label > 0)
                        table->assembly_code.push_back("\tjle  .L" + to_string(false_label));
                }
                else if (relExp->op == "\\>=") {
                    if (res1.first && res2.first) {
                        if (res1.second >= res2.second) {
                            if (true_label > 0)
                                table->assembly_code.push_back("\tjmp  .L" + to_string(true_label));
                        }
                        else {
                            if (false_label > 0)
                                table->assembly_code.push_back("\tjmp  .L" + to_string(false_label));
                        }
                        return;
                    }
                    else if (res1.first && (!res2.first)) {
                        table->assembly_code.push_back("\tcmp  " + to_string(res1.second) + ", rcx");
                        table->free_regs(3);
                    }
                    else if ((!res1.first) && res2.first)
                        table->assembly_code.push_back("\tcmp  rax, " + to_string(res2.second));
                    else {
                        table->assembly_code.push_back("\tcmp  rax, rcx");
                        table->free_regs(3);
                    }  
                    if (true_label > 0)
                        table->assembly_code.push_back("\tjge  .L" + to_string(true_label));
                    if (false_label > 0)
                        table->assembly_code.push_back("\tjl  .L" + to_string(false_label));
                }
            }
            else {
                fprintf(stderr, "Error: %s\n", "Can not convert bool to int");
                exit(1);
            }
        }
    }
}

void CodeGenerator::handle_assign(shared_ptr<SymbolTable> table, shared_ptr<Stmt> node) {
    if (node->lVal->varKind == VarKind::Var) {
        shared_ptr<VarSymbol> symbol = dynamic_pointer_cast<VarSymbol>(table->lookup(node->lVal->ident));
        if (symbol == nullptr) {
            fprintf(stderr, "Error: %s\n", "Variable not declared when assigning");
            fprintf(stderr, "Variable name: %s\n", node->lVal->ident.c_str());
            fprintf(stderr, "Table name: %s\n", table->local_label.c_str());
            fprintf(stderr, "Table scope: %d\n", table->level);
            
            exit(1);
        }
        if (symbol->kind == VarSymbol::VarKind::INT) {
            pair<bool, int> res = handle_exp(table, node->exp);
            table->assembly_code.push_back("\tmov  dword ptr [rbp" + to_string(symbol->offset) + "], " + judge_const(res, false));
        }
        else if (symbol->kind == VarSymbol::VarKind::GLOBAL_INT) {
            pair<bool, int> res = handle_exp(table, node->exp);
            table->assembly_code.push_back("\tmov  rax,  qword ptr " + symbol->name + "@GOTPCREL[rip]");
            table->assembly_code.push_back("\tmov  dword ptr [rax], " + judge_const(res, false));
        }
        else if (symbol->kind == VarSymbol::VarKind::CONST_INT) {
            fprintf(stderr, "Error: %s\n", "Assign to const variable");
            exit(1);
        }
        else {
            fprintf(stderr, "Error: %s\n", "Assign to array");
            exit(1);
        }
    }
    else {
        shared_ptr<ArraySymbol> symbol = dynamic_pointer_cast<ArraySymbol>(table->lookup(node->lVal->ident));
        if (symbol == nullptr) {
            fprintf(stderr, "Error: %s\n", "Array not declared");
            exit(1);
        }

        int exp_num = node->lVal->arrayIndex->exps.size();
        if (exp_num != symbol->dim) {
            fprintf(stderr, "Error: %s\n", "Number of dimensions does not match");
            exit(1);
        }
        // using register r8 to store the address of the array
        table->new_regs(4);
        table->assembly_code.push_back("\txor  r8, r8");
        for (int i = 0; i < exp_num - 1; i++) {
            pair<bool, int> res = handle_exp(table, node->lVal->arrayIndex->exps[i]);
            table->assembly_code.push_back("\tadd  r8,  " + judge_const(res));
            table->assembly_code.push_back("\timul r8, " + to_string(symbol->dim_size[i + 1]));
        }
        pair<bool, int> res = handle_exp(table, node->lVal->arrayIndex->exps[exp_num - 1]);
        table->assembly_code.push_back("\tadd  r8,  " + judge_const(res));

        if (symbol->kind == ArraySymbol::ArrayKind::INT) {
            pair<bool, int> res = handle_exp(table, node->exp);
            table->assembly_code.push_back("\tmov  dword ptr [rbp" + to_string(symbol->offset) + " + r8 * 4], " + judge_const(res, false));
        }
        else if (symbol->kind == ArraySymbol::ArrayKind::GLOBAL_INT) {
            pair<bool, int> res = handle_exp(table, node->exp);
            table->assembly_code.push_back("\tmov  rax,  qword ptr " + symbol->name + "@GOTPCREL[rip]");
            table->assembly_code.push_back("\tmov  dword ptr [rax + r8 * 4], " + judge_const(res, false));
        }
        else if (symbol->kind == ArraySymbol::ArrayKind::PARAM_PTR) {
            pair<bool, int> res = handle_exp(table, node->exp);
            table->new_regs(5);
            table->assembly_code.push_back("\tmov  r9, qword ptr [rbp" + to_string(symbol->offset) + "]");
            table->assembly_code.push_back("\tmov  dword ptr [r9 + r8 * 4], " + judge_const(res, false));
            table->free_regs(5);
        }
        else if (symbol->kind == ArraySymbol::ArrayKind::CONST_INT) {
            table->free_regs(4);
            fprintf(stderr, "Error: %s\n", "Assign to const array");
            exit(1);
        }
        else {
            table->free_regs(4);
            fprintf(stderr, "Error: %s\n", "Assign to variable");
            exit(1);
        }
        table->free_regs(4);
    }
}

void CodeGenerator::traverse(shared_ptr<SymbolTable> table, shared_ptr<Tree> node) {
    if (node == nullptr)
        return;
    std::cerr << "enter traverse\n";

    std::cerr << typeid(*node).name() << std::endl;

    if (typeid(*node) == typeid(CompUnit)) {
        std::cerr << "enter CompUnit\n";
        traverse(table, dynamic_pointer_cast<CompUnit>(node)->compList);
    }
    else if (typeid(*node) == typeid(CompList)) {
        shared_ptr<CompList> compList = dynamic_pointer_cast<CompList>(node);
        for (auto declOrDef : compList->declOrDefs)
            traverse(table, declOrDef);
        //traverse(table, compList->declOrDef);
        //if (compList->if_more_CompList)
            //traverse(table, compList->compList);
    }
    else if (typeid(*node) == typeid(DeclOrDef)) {
        shared_ptr<DeclOrDef> declOrDef = dynamic_pointer_cast<DeclOrDef>(node);
        if (declOrDef->if_decl && declOrDef->decl != nullptr) {
            traverse(table, declOrDef->decl);
        }
        else if (!declOrDef->if_decl && declOrDef->funcDef != nullptr) {
            traverse(table, declOrDef->funcDef);
        }
    }
    else if (typeid(*node) == typeid(Decl)) {
        shared_ptr<Decl> decl = dynamic_pointer_cast<Decl>(node);
        if (decl->decType == DecType::VarDecl) {
            shared_ptr<VarDecl> varDecl = dynamic_pointer_cast<VarDecl>(decl->varDecl);
            traverse(table, varDecl->varDefList);
        }
        else if (decl->decType == DecType::ConstDecl) {
            shared_ptr<ConstDecl> constDecl = dynamic_pointer_cast<ConstDecl>(decl->constDecl);
            traverse(table, constDecl->constDefList);
        }
    }
    /*else if (typeid(*node) == typeid(VarDecl)) {
        
    }*/
    else if (typeid(*node) == typeid(VarDefList)) {
        shared_ptr<VarDefList> varDefList = dynamic_pointer_cast<VarDefList>(node);
        for (auto varDef : varDefList->vardefs)
            handle_vardef(table, varDef);
    }
    else if (typeid(*node) == typeid(ConstDefList)) {
        shared_ptr<ConstDefList> constDefList = dynamic_pointer_cast<ConstDefList>(node);
        for (auto constDef : constDefList->constdefs)
            handle_constdef(table, constDef);
    }

    else if (typeid(*node) == typeid(FuncDef)) {
        shared_ptr<FuncDef> funcDef = dynamic_pointer_cast<FuncDef>(node);
        shared_ptr<SymbolTable> func_table = handle_funcDef(table, funcDef);
        //handle_block(func_table, funcDef->block);
        traverse(func_table, funcDef->block);
    }

    else if (typeid(*node) == typeid(Block)) {
        shared_ptr<Block> block = dynamic_pointer_cast<Block>(node);
        if (block->blockItemList) {
            for (auto blockItem : block->blockItemList->blockItems) {
                if (blockItem->blockItemType == BlockItemType::Decl)
                    traverse(table, blockItem->decl);
                else if (blockItem->blockItemType == BlockItemType::Stmt)
                    traverse(table, blockItem->stmt);
            }
        
        }
    }
    else if (typeid(*node) == typeid(Stmt)) {
        shared_ptr<Stmt> stmt = dynamic_pointer_cast<Stmt>(node);
        if (stmt->stmtType == StmtType::Assign)
            handle_assign(table, stmt);
        else if (stmt->stmtType == StmtType::Exp)
            handle_exp(table, stmt->exp);
        else if (stmt->stmtType == StmtType::Block) {
            table->enter_scope();
            traverse(table, stmt->block);
            table->exit_scope();
        }
        else if (stmt->stmtType == StmtType::If) {
            int end_label = table->new_label();

            handle_cond(table, stmt->cond, -1, end_label);

            traverse(table, stmt->block);
            table->assembly_code.push_back(".L" + to_string(end_label) + ":");
            // handle condition
        }
        else if (stmt->stmtType == StmtType::IfElse) {
            int else_label = table->new_label();
            int end_label = table->new_label();

            handle_cond(table, stmt->cond, -1, else_label);

            traverse(table, stmt->stmt_if);
            table->assembly_code.push_back("\tjmp  .L" + to_string(end_label));

            table->assembly_code.push_back(".L" + to_string(else_label) + ":");
            traverse(table, stmt->stmt_if_else);

            table->assembly_code.push_back(".L" + to_string(end_label) + ":");
        }
        else if (stmt->stmtType == StmtType::While) {
            //handle_return(func_table, stmt);
            int start_label = table->new_label();
            int end_label = table->new_label();

            table->push_loop_labels(start_label, end_label);

            table->assembly_code.push_back(".L" + to_string(start_label) + ":");

            handle_cond(table, stmt->cond, -1, end_label);

            traverse(table, stmt->stmt_while);

            table->assembly_code.push_back("\tjmp  .L" + to_string(start_label));

            table->assembly_code.push_back(".L" + to_string(end_label) + ":");

            table->pop_loop_labels();
        }
        else if (stmt->stmtType == StmtType::Break) {
            int loop_end = table->get_loop_end();
            if (loop_end == -1) {
                fprintf(stderr, "Error: %s\n", "Break statement not in loop");
                exit(1);
            }
            table->assembly_code.push_back("\tjmp  .L" + to_string(loop_end));
        }
        else if (stmt->stmtType == StmtType::Continue) {
            int loop_start = table->get_loop_start();
            if (loop_start == -1) {
                fprintf(stderr, "Error: %s\n", "Continue statement not in loop");
                exit(1);
            }
            table->assembly_code.push_back("\tjmp  .L" + to_string(loop_start));
        }
        else if (stmt->stmtType == StmtType::Return) {
            if (table->curr_func_kind == SymbolType::FuncKind::INT) {
                fprintf(stderr, "Error: %s\n", "Return nothing in int function");
                exit(1);
            }
            if (stmt->exp) {
                fprintf(stderr, "Error: %s\n", "Return value in void function");
                exit(1);
            }
            table->assembly_code.push_back("\tjmp  .L" + to_string(table->get_func_ret_label()));
        }
        else if (stmt->stmtType == StmtType::ReturnExp) {
            if (table->curr_func_kind == SymbolType::FuncKind::VOID) {
                fprintf(stderr, "Error: %s\n", "Return value in void function");
                exit(1);
            }
            if (!stmt->exp) {
                fprintf(stderr, "Error: %s\n", "Return nothing in int function");
                exit(1);
            }
            pair<bool, int> res = handle_exp(table, stmt->exp);
            if (res.first)
                table->assembly_code.push_back("\tmov  eax, " + to_string(res.second));
            table->assembly_code.push_back("\tjmp  .L" + to_string(table->get_func_ret_label()));
        }
    }
}
