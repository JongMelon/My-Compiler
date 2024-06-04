#ifndef TRANS
#define TRANS

#include <vector>
#include <string>
#include <stack>
#include <iostream>
#include <unordered_map>
#include <fstream>
#include "AST.h"

using std::vector;
using std::string;
using std::stack;
using std::to_string;
using std::unordered_map;
using std::dynamic_pointer_cast;
using std::pair;
using std::make_pair;

using std::ofstream;

using std::cout;
using std::endl;

/*
    Generating the x86-64 assembly code directly from the syntax tree.
*/

class SymbolType {
    public:
        enum class VarKind {
            INT,
            CONST_INT,
            GLOBAL_INT,
            GLOBAL_CONST
        };

        enum class ArrayKind {
            INT,
            CONST_INT,
            GLOBAL_INT,
            PARAM_PTR,
            GLOBAL_CONST
        };

        enum class FuncKind {
            INT,
            VOID
        };

        

        virtual ~SymbolType() = default;
};

class VarSymbol : public SymbolType {
    public:
        VarKind kind;
        int offset;
        int value;
        string name;

        VarSymbol(VarKind kind, int offset, int value, string name) : kind(kind), offset(offset), value(value), name(name) {}
};

class ArraySymbol : public SymbolType {
    public:
        ArrayKind kind;
        int offset;

        int dim;
        int total_size;
        vector<int> dim_size;
        vector<int> dim_offset;

        vector<int> const_val; // only for const array

        string name;

        ArraySymbol(ArrayKind kind, int dim, string name) : kind(kind), dim(dim), name(name) {}
};

class FuncSymbol : public SymbolType {
    public:
        FuncKind kind;
        int offset;
        int param_num;
        int mem_size;

        vector<shared_ptr<SymbolType>> params;

        string name;

        FuncSymbol(FuncKind kind, int offset, string name) : kind(kind), offset(offset), name(name) {}
};

// Symbol table

static const int param_reg_num = 6;

static const vector<string> param_regs = {"rdi", "rsi", "rdx", "rcx", "r8", "r9"};
static const vector<string> param_regs_32 = {"edi", "esi", "edx", "ecx", "r8d", "r9d"};

class SymbolTable {
    public:
        enum class Scope {
            GLOBAL,
            LOCAL
        };

        Scope scope;

        int level = 0;

        int stack_ptr = 0;

        int push_cnt = 0;

        vector<int> regs_used = vector<int>(param_reg_num, 0);

        vector<unordered_map<string, shared_ptr<SymbolType>>> map_table;

        vector<string> header_code;
        vector<string> assembly_code;
        vector<string> footer_code;

        stack<int> curr_loop_start;
        stack<int> curr_loop_end;

        int func_ret_label;

        SymbolType::FuncKind curr_func_kind;

        string local_label;

        SymbolTable(SymbolTable::Scope scope, string local_label);
        shared_ptr<SymbolType> lookup(string name);
        void insert(string name, shared_ptr<SymbolType> symbol);

        void enter_scope();
        void exit_scope();

        void new_regs(int id);
        void free_regs(int id);

        void save_regs();
        void restore_regs();

        void push_loop_labels(int start, int end);
        void pop_loop_labels();

        int get_loop_start();
        int get_loop_end();
        int get_func_ret_label();

        int new_label();

        ~SymbolTable() = default;
};

class CodeGenerator {
    public:

        CodeGenerator();

        int str_num = 0;
        int label = 1;

        shared_ptr<SymbolTable> global_table;

        inline int search_const_str(string str);

        pair<bool, int> handle_exp(shared_ptr<SymbolTable> table, shared_ptr<Tree> node);

        pair<bool, int> handle_initval(shared_ptr<SymbolTable> table, shared_ptr<Tree> node);
        int handle_arr_initval(shared_ptr<SymbolTable> table, shared_ptr<ArraySymbol> array, shared_ptr<InitVal> init_val, int dim, int offset);
        void handle_constdef(shared_ptr<SymbolTable> table, shared_ptr<ConstDef> node);
        void handle_vardef(shared_ptr<SymbolTable> table, shared_ptr<VarDef> node);
        shared_ptr<SymbolTable> handle_funcDef(shared_ptr<SymbolTable> table, shared_ptr<FuncDef> node);
        void handle_cond(shared_ptr<SymbolTable> table, shared_ptr<Tree> node, int true_label, int false_label);
        void handle_assign(shared_ptr<SymbolTable> table, shared_ptr<Stmt> node);
        void traverse(shared_ptr<SymbolTable> table, shared_ptr<Tree> node);

        shared_ptr<SymbolType> lookup(shared_ptr<SymbolTable>curr_table, string name);

        void dump(shared_ptr<CompUnit> comp_unit, string filename);

        void fill_zero(shared_ptr<SymbolTable> table, int array_base, int offset, int fill_size);

        unordered_map<string, int> const_str;
        vector<shared_ptr<SymbolTable>> tables;
        vector<string> rdata;
        vector<string> global_data;
        vector<string> text;

        unordered_map<string, shared_ptr<FuncSymbol>> lib_funcs;
        bool check_is_lib(string name);

        string judge_const(pair<bool, int>& res, bool is_rax = true);

        ~CodeGenerator() = default;
};

inline string my_to_string(int val);

#endif