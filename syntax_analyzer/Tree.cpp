#include "Tree.h"

using std::cout;
using std::endl;

int node_id = 0;

void CompUnit::print(int parent, string part) {
    cout << "node" << node_id << "[label = \"<f0> CompUnit\"];" << endl;
    this->compList->print(node_id++, "f0");
}

void CompList::print(int parent, string part) {
    if (if_more_CompList) {
        cout << "node" << node_id << "[label = \"<f0> CompList|<f1> DecOrDef\"];" << endl;
        cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
        int parent_id = node_id;
        node_id++;
        this->compList->print(parent_id, "f0");
        node_id++;
        this->declOrDefs->print(parent_id, "f1");
    }
    else {
        cout << "node" << node_id << "[label = \"<f0> DecOrDef\"];" << endl;
        cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
        this->declOrDefs->print(node_id++, "f0");
    }
}

void DeclOrDef::print(int parent, string part) {
    if (if_decl)
        this->decl->print(parent, part);
    else
        this->funcDef->print(parent, part);
}

void Decl::print(int parent, string part) {
    cout << "node" << node_id << "[label = \"<f0> Decl\"];" << endl;
    cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
    if (decType == DecType::VarDecl)
        this->varDecl->print(node_id++, "f0");
    else
        this->constDecl->print(node_id++, "f0");
}

void VarDecl::print(int parent, string part) {
    cout << "node" << node_id << "[label = \"<f0> VarDecl\"];" << endl;
    cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
    int parent_id = node_id;
    for (auto varDef : this->varDefs) {
        node_id++;
        varDef->print(parent_id, "f0");
    }
}

void ConstDecl::print(int parent, string part) {
    cout << "node" << node_id << "[label = \"<f0> ConstDecl\"];" << endl;
    cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
    int parent_id = node_id;
    for (auto constDef : this->constDefs) {
        node_id++;
        constDef->print(parent_id, "f0");
    }
}

void ConstDef::print(int parent, string part) {
    if (varKind == VarKind::Var) {
        cout << "node" << node_id << "[label = \"<f0> const |<f1> int|<f2> ConstDef|<f3> ;\"];" << endl;
        cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
        cout << "node" << node_id + 1 << "[label = \"<f0> " << ident << "|<f1> =|<f2> [ConstInitVal]\"];" << endl;
        cout << "\"node" << node_id << "\":" << "f2" << "->\"node" << node_id + 1 << "\";" << endl;
        node_id++;
        this->constInitVal->print(node_id++, "f2");
    }
    else {
        cout << "node" << node_id << "[label = \"<f0> const |<f1> int|<f2> ConstDef|<f3> ;\"];" << endl;
        cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
        cout << "node" << node_id + 1 << "[label = \"<f0> " << ident << "|<f1> ConstArrayIndex|<f2> =|<f3> [ConstInitVal]\"];" << endl;
        cout << "\"node" << node_id << "\":" << "f2" << "->\"node" << node_id + 1 << "\";" << endl;
        node_id++;
        int parent_id = node_id;
        node_id++;
        this->constArrayIndex->print(parent_id, "f1");
        this->constInitVal->print(parent_id, "f3");
    }
}

void VarDef::print(int parent, string part) {
    bool if_initVal = this->initVal != nullptr;
    if (if_initVal) {
        if (varKind == VarKind::Var) {
            cout << "node" << node_id << "[label = \"<f0> int|<f1> VarDef\"];" << endl;
            cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
            cout << "node" << node_id + 1 << "[label = \"<f0> " << ident << "|<f1> =|<f2> [InitVal]\"];" << endl;
            cout << "\"node" << node_id << "\":" << "f1" << "->\"node" << node_id + 1 << "\";" << endl;
            node_id++;
            this->initVal->print(node_id++, "f2");
        }
        else {
            cout << "node" << node_id << "[label = \"<f0> int|<f1> VarDef\"];" << endl;
            cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
            cout << "node" << node_id + 1 << "[label = \"<f0> " << ident << "|<f1> ConstArrayIndex|<f2> InitVal\"];" << endl;
            cout << "\"node" << node_id << "\":" << "f1" << "->\"node" << node_id + 1 << "\";" << endl;
            node_id++;
            int parent_id = node_id;
            node_id++;
            this->constArrayIndex->print(parent_id, "f1");
            this->initVal->print(parent_id, "f2");
        }
    }
    else {
        if (varKind == VarKind::Var) {
            cout << "node" << node_id << "[label = \"<f0> int|<f1> VarDef|<f2> ;\"];" << endl;
            cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
            cout << "node" << node_id + 1 << "[label = \"<f0> " << ident << "|<f1> ;\"];" << endl;
            cout << "\"node" << node_id << "\":" << "f1" << "->\"node" << node_id + 1 << "\";" << endl;
            node_id += 2;
        }
        else {
            cout << "node" << node_id << "[label = \"<f0> int|<f1> VarDef|<f2> ;\"];" << endl;
            cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
            cout << "node" << node_id + 1 << "[label = \"<f0> " << ident << "|<f1> ConstArrayIndex|<f2> ;\"];" << endl;
            cout << "\"node" << node_id << "\":" << "f1" << "->\"node" << node_id + 1<< "\";" << endl;
            node_id++;
            this->constArrayIndex->print(node_id++, "f1");
        }
    }
}

void InitVal::print(int parent, string part) {
    if (varKind == VarKind::Var) {
        this->exp->print(parent, part);
    }
    else {
        cout << "node" << node_id << "[label = \"<f0> {|<f1> InitalVals|<f2> }\"];" << endl;
        cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
        int parent_id = node_id;
        node_id++;
        for (auto init_val : this->init_vals) {
            init_val->print(parent_id, "f1");
        }
    }
}

void ConstInitVal::print(int parent, string part) {
    if (varKind == VarKind::Var) {
        this->constExp->print(parent, part);
    }
    else {
        cout << "node" << node_id << "[label = \"<f0> {|<f1> ConstInitalVals|<f2> }\"];" << endl;
        cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
        int parent_id = node_id;
        node_id++;
        for (auto const_init_val : this->const_initvals) {
            const_init_val->print(parent_id, "f1");
        }
    }
}

void LVal::print(int parent, string part) {
    if (varKind == VarKind::Var) {
        cout << "node" << node_id << "[label = \"<f0> LVal\"];" << endl;
        cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
        cout << "node" << node_id + 1 << "[label = \"<f0> " << ident << "\"];" << endl;
        cout << "\"node" << node_id << "\":" << "f0" << "->\"node" << node_id + 1 << "\";" << endl;
        node_id += 2;
    }
    else {
        cout << "node" << node_id << "[label = \"<f0> LVal\"];" << endl;
        cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
        this->arrayIndex->print(node_id++, "f1");
    }
}

void ArrayIndex::print(int parent, string part) {
    if (arrayIndex == nullptr) {
        cout << "node" << node_id << "[label = \"<f0> [|<f1> Exp|<f2> ]\"];" << endl;
        cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
        this->exp->print(node_id++, "f1");
    }
    else {
        cout << "node" << node_id << "[label = \"<f0> ArrayIndex|<f1> [|<f2> Exp|<f3> ]\"];" << endl;
        cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
        int parent_id = node_id++;
        this->arrayIndex->print(parent_id, "f0");
        this->exp->print(parent_id, "f2");
    }
}

void ConstArrayIndex::print(int parent, string part) {
    if (constArrayIndex == nullptr) {
        cout << "node" << node_id << "[label = \"<f0> [|<f1> ConstExp|<f2> ]\"];" << endl;
        cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
        this->const_exp->print(node_id++, "f1");
    }
    else {
        cout << "node" << node_id << "[label = \"<f0> ConstArrayIndex|<f1> [|<f2> ConstExp|<f3> ]\"];" << endl;
        cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
        int parent_id = node_id++;
        this->constArrayIndex->print(parent_id, "f0");
        this->const_exp->print(parent_id, "f2");
    }
}

void ConstExp::print(int parent, string part) {
    if (is_in_array) {
        cout << "node" << node_id << "[label = \"<f0> [|<f1> ConstExp|<f2> ]\"];" << endl;
        cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
        this->exp->print(node_id++, "f1");
    }
    else {
        cout << "node" << node_id << "[label = \"<f0> ConstExp\"];" << endl;
        cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
        this->exp->print(node_id++, "f0");
    }
}

void Exp::print(int parent, string part) {
    if (is_in_array) {
        cout << "node" << node_id << "[label = \"<f0> [|<f1> Exp|<f2> ]\"];" << endl;
        cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
        this->add_exp->print(node_id++, "f1");
    }
    else {
        cout << "node" << node_id << "[label = \"<f0> Exp\"];" << endl;
        cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
        this->add_exp->print(node_id++, "f0");
    }
}

void AddExp::print(int parent, string part) {
    if (addExpType == AddExpType::AddMulExp) {
        cout << "node" << node_id << "[label = \"<f0> AddExp|<f1> " << op << "|<f2> MulExp\"];" << endl;
        cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
        int parent_id = node_id;
        node_id++;
        this->add_exp->print(parent_id, "f0");
        this->mul_exp->print(parent_id, "f2");
    }
    else {
        cout << "node" << node_id << "[label = \"<f0> MulExp\"];" << endl;
        cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
        this->mul_exp->print(node_id++, "f0");
    }
}

void MulExp::print(int parent, string part) {
    if (mulExpType == MulExpType::MulUnaryExp) {
        cout << "node" << node_id << "[label = \"<f0> MulExp|<f1> " << op << "|<f2> UnaryExp\"];" << endl;
        cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
        int parent_id = node_id;
        node_id++;
        this->mul_exp->print(parent_id, "f0");
        this->unary_exp->print(parent_id, "f2");
    }
    else {
        cout << "node" << node_id << "[label = \"<f0> UnaryExp\"];" << endl;
        cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
        this->unary_exp->print(node_id++, "f0");
    }
}

void UnaryExp::print(int parent, string part) {
    if (unaryExpType == UnaryExpType::PrimaryExp) {
        cout << "node" << node_id << "[label = \"<f0> PrimaryExp\"];" << endl;
        cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
        this->primary_exp->print(node_id++, "f0");
    }
    else if (unaryExpType == UnaryExpType::FuncCall) {
        if (func_rparams == nullptr) {
            cout << "node" << node_id << "[label = \"<f0> " << func_ident << "|<f1> ()\"];" << endl;
            cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
            node_id++;
        }
        else {
            cout << "node" << node_id << "[label = \"<f0> " << func_ident << "|<f1> FuncRParams\"];" << endl;
            cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
            this->func_rparams->print(node_id++, "f1");
        }
    }
    else {
        cout << "node" << node_id << "[label = \"<f0> UnaryExp|<f1> " << op << "|<f2> UnaryExp\"];" << endl;
        cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
        int parent_id = node_id++;
        this->unary_exp->print(parent_id, "f0");
        this->unary_exp->print(parent_id, "f2");
    }
}

void PrimaryExp::print(int parent, string part) {
    if (primaryExpType == PrimaryExpType::LVal) {
        cout << "node" << node_id << "[label = \"<f0> LVal\"];" << endl;
        cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
        this->lVal->print(node_id++, "f0");
    }
    else if (primaryExpType == PrimaryExpType::Number) {
        cout << "node" << node_id << "[label = \"<f0> " << number << "\"];" << endl;
        cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
        node_id++;
    }
    else {
        cout << "node" << node_id << "[label = \"<f0> (|<f1> Exp|<f2> )\"];" << endl;
        cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
        this->exp->print(node_id++, "f1");
    }
}

void FuncRParams::print(int parent, string part) {
    cout << "node" << node_id << "[label = \"<f0> FuncRParams\"];" << endl;
    cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
    int parent_id = node_id;
    node_id++;
    for (auto exp : this->exps) {
        exp->print(parent_id, "f1");
    }
}

void Cond::print(int parent, string part) {
    cout << "node" << node_id << "[label = \"<f0> Cond\"];" << endl;
    cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
    this->lOrExp->print(node_id++, "f0");
}

void LOrExp::print(int parent, string part) {
    if (lOrExpType == LOrExpType::LOrLAndExp) {
        cout << "node" << node_id << "[label = \"<f0> LOrExp|<f1> |||<f2> LAndExp\"];" << endl;
        cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
        int parent_id = node_id;
        node_id++;
        this->lOrExp->print(parent_id, "f0");
        this->lAndExp->print(parent_id, "f2");
    }
    else {
        cout << "node" << node_id << "[label = \"<f0> LAndExp\"];" << endl;
        cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
        this->lAndExp->print(node_id++, "f0");
    }
}

void LAndExp::print(int parent, string part) {
    if (lAndExpType == LAndExpType::LAndEqExp) {
        cout << "node" << node_id << "[label = \"<f0> LAndExp|<f1> &&|<f2> EqExp\"];" << endl;
        cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
        int parent_id = node_id++;
        this->lAndExp->print(parent_id, "f0");
        this->eqExp->print(parent_id, "f2");
    }
    else {
        cout << "node" << node_id << "[label = \"<f0> EqExp\"];" << endl;
        cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
        this->eqExp->print(node_id++, "f0");
    }
}

void EqExp::print(int parent, string part) {
    if (eqExpType == EqExpType::EqRelExp) {
        cout << "node" << node_id << "[label = \"<f0> EqExp|<f1> " << op << "|<f2> RelExp\"];" << endl;
        cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
        int parent_id = node_id++;
        this->eqExp->print(parent_id, "f0");
        this->relExp->print(parent_id, "f2");
    }
    else {
        cout << "node" << node_id << "[label = \"<f0> RelExp\"];" << endl;
        cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
        this->relExp->print(node_id++, "f0");
    }
}

void RelExp::print(int parent, string part) {
    if (relExpType == RelExpType::RelAddExp) {
        cout << "node" << node_id << "[label = \"<f0> RelExp|<f1> " << op << "|<f2> AddExp\"];" << endl;
        cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
        int parent_id = node_id++;
        this->relExp->print(parent_id, "f0");
        this->add_exp->print(parent_id, "f2");
    }
    else {
        cout << "node" << node_id << "[label = \"<f0> AddExp\"];" << endl;
        cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
        this->add_exp->print(node_id++, "f0");
    }
}

void FuncDef::print(int parent, string part) {
    cout << "node" << node_id << "[label = \"<f0> FuncDef\"];" << endl;
    cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
    int parent_id = node_id++;
    this->funcType->print(parent_id, "f0");
    if (this->funcFParams != nullptr)
        this->funcFParams->print(parent_id, "f0");
    else {
        cout << "node" << node_id++ << "[label = \"<f0> ()\"];" << endl;
        cout << "\"node" << parent_id << "\":" << "f0" << "->\"node" << node_id - 1 << "\";" << endl;
    }
    this->block->print(parent_id, "f0");
}

void FuncType::print(int parent, string part) {
    cout << "node" << node_id << "[label = \"<f0> " << type << "\"];" << endl;
    cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
    node_id++;
}

void FuncFParams::print(int parent, string part) {
    cout << "node" << node_id << "[label = \"<f0> (|<f1> FuncFParams|<f2> )\"];" << endl;
    cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
    int parent_id = node_id;
    node_id++;
    for (auto func_fparam : this->funcFParams) {
        func_fparam->print(parent_id, "f1");
    }
}

void FuncFParam::print(int parent, string part) {
    cout << "node" << node_id << "[label = \"<f0> FuncFParam\"];" << endl;
    cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
    if (varKind == VarKind::Var) {
        cout << "node" << node_id + 1 << "[label = \"<f0> int|<f1> " << ident << "\"];" << endl;
        cout << "\"node" << node_id << "\":" << "f0" << "->\"node" << node_id + 1 << "\";" << endl;
        node_id += 2;
    }
    else {
        if (ArrayIndex != nullptr) {
            cout << "node" << node_id + 1 << "[label = \"<f0> int|<f1> " << ident << "|<f2> [|<f3> ]|<f4> ArrayIndex\"];" << endl;
            cout << "\"node" << node_id << "\":" << "f0" << "->\"node" << node_id + 1 << "\";" << endl;
            node_id++;
            this->ArrayIndex->print(node_id++, "f4");
        }
        else {
            cout << "node" << node_id + 1 << "[label = \"<f0> int|<f1> " << ident << "|<f2> [|<f3> ]\"];" << endl;
            cout << "\"node" << node_id << "\":" << "f0" << "->\"node" << node_id + 1 << "\";" << endl;
            node_id += 2;
        }
    }
}

void Block::print(int parent, string part) {
    cout << "node" << node_id << "[label = \"<f0> Block\"];" << endl;
    cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
    if (blockItemList != nullptr) {
        cout << "node" << node_id + 1 << "[label = \"<f0> {|<f1> BlockItemList|<f2> }\"];" << endl;
        cout << "\"node" << node_id << "\":" << "f0" << "->\"node" << node_id + 1 << "\";" << endl;
        node_id++;
        this->blockItemList->print(node_id++, "f1");
    }
    else {
        cout << "node" << node_id + 1 << "[label = \"<f0> {}\"];" << endl;
        cout << "\"node" << node_id << "\":" << "f0" << "->\"node" << node_id + 1 << "\";" << endl;
        node_id += 2;
    }
}

void BlockItemList::print(int parent, string part) {
    if (blockItemList == nullptr) {
        cout << "node" << node_id << "[label = \"<f0> BlockItem\"];" << endl;
        cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;;
        this->blockItem->print(node_id++, "f0");
    }
    else {
        cout << "node" << node_id << "[label = \"<f0> BlockItem|<f1> BlockItemList\"];" << endl;
        cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
        int parent_id = node_id++;
        this->blockItem->print(parent_id, "f0");
        this->blockItemList->print(parent_id, "f1");
    }
}

void BlockItem::print(int parent, string part) {
    if (blockItemType == BlockItemType::Decl) {
        this->decl->print(parent, part);
    }
    else {
        this->stmt->print(parent, part);
    }
}

void Stmt::print(int parent, string part) {
    cout << "node" << node_id << "[label = \"<f0> Stmt\"];" << endl;
    cout << "\"node" << parent << "\":" << part << "->\"node" << node_id << "\";" << endl;
    if (stmtType == StmtType::Assign) {
        cout << "node" << node_id + 1 << "[label = \"<f0> LVal|<f1> =|<f2> Exp|<f3> ;\"];" << endl;
        cout << "\"node" << node_id << "\":" << "f0" << "->\"node" << node_id + 1 << "\";" << endl;
        node_id++;
        int parent_id = node_id++;
        this->lVal->print(parent_id, "f0");
        this->exp->print(parent_id, "f2");
    }
    else if (stmtType == StmtType::Block) {
        this->block->print(node_id++, "f0");
    }
    else if (stmtType == StmtType::If) {
        if (stmt_if_else == nullptr) {
            cout << "node" << node_id + 1 << "[label = \"<f0> if|<f1> (|<f2> Cond|<f3> )|<f4> Stmt\"];" << endl;
            cout << "\"node" << node_id << "\":" << part << "->\"node" << node_id + 1 << "\";" << endl;
            node_id++;
            int parent_id = node_id++;
            this->cond->print(parent_id, "f2");
            this->stmt_if->print(parent_id, "f4");
        }
        else {
            cout << "node" << node_id + 1 << "[label = \"<f0> if|<f1> (|<f2> Cond|<f3> )|<f4> Stmt|<f5> else|<f6> Stmt\"];" << endl;
            cout << "\"node" << node_id << "\":" << part << "->\"node" << node_id + 1 << "\";" << endl;
            node_id++;
            int parent_id = node_id++;
            this->cond->print(parent_id, "f2");
            this->stmt_if->print(parent_id, "f4");
            this->stmt_if_else->print(parent_id, "f6");
        }
    }
    else if (stmtType == StmtType::While) {
        cout << "node" << node_id + 1 << "[label = \"<f0> while|<f1> (|<f2> Cond|<f3> )|<f4> Stmt\"];" << endl;
        cout << "\"node" << node_id << "\":" << part << "->\"node" << node_id + 1 << "\";" << endl;
        node_id++;
        int parent_id = node_id++;
        this->cond->print(parent_id, "f2");
        this->stmt_while->print(parent_id, "f4");
    }
    else if (stmtType == StmtType::Exp) {
        cout << "node" << node_id + 1 << "[label = \"<f0> Exp|<f1> ;\"];" << endl;
        cout << "\"node" << node_id << "\":" << part << "->\"node" << node_id + 1 << "\";" << endl;
        node_id++;
        this->exp->print(node_id++, "f0");
    }
    else if (stmtType == StmtType::ReturnExp) {
        cout << "node" << node_id + 1 << "[label = \"<f0> return|<f1> Exp|<f2> ;\"];" << endl;
        cout << "\"node" << node_id << "\":" << part << "->\"node" << node_id + 1 << "\";" << endl;
        node_id++;
        this->exp_return->print(node_id++, "f1");
    }
    else if (stmtType == StmtType::Return) {
        cout << "node" << node_id + 1 << "[label = \"<f0> return|<f1> ;\"];" << endl;
        cout << "\"node" << node_id << "\":" << part << "->\"node" << node_id + 1 << "\";" << endl;
        node_id += 2;
    }
    else if (stmtType == StmtType::Continue) {
        cout << "node" << node_id + 1 << "[label = \"<f0> continue|<f1> ;\"];" << endl;
        cout << "\"node" << node_id << "\":" << part << "->\"node" << node_id + 1 << "\";" << endl;
        node_id += 2;
    }
    else if (stmtType == StmtType::Break) {
        cout << "node" << node_id + 1 << "[label = \"<f0> break|<f1> ;\"];" << endl;
        cout << "\"node" << node_id << "\":" << part << "->\"node" << node_id + 1 << "\";" << endl;
        node_id += 2;
    }
    else {
        cout << "node" << node_id + 1 << "[label = \"<f0> ;\"];" << endl;
        cout << "\"node" << node_id << "\":" << part << "->\"node" << node_id + 1 << "\";" << endl;
        node_id += 2;
    }
}
