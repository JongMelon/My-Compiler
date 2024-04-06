#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>
#include <string>
#include <memory>

using std::vector;
using std::string;
using std::shared_ptr;
using std::make_shared;

enum class DecType {
    VarDecl,
    ConstDecl
};

enum class VarKind {
    Var,
    Array
};

enum class BlockItemType {
    Decl,
    Stmt
};

enum class StmtType {
    Assign,
    Exp,
    Char,
    Block,
    If,
    IfElse,
    While,
    Break,
    Continue,
    Return,
    ReturnExp
};

enum class UnaryExpType {
    PrimaryExp,
    FuncCall,
    OP_Exp
};

enum class PrimaryExpType {
    Exp,
    LVal,
    Number
};

enum class AddExpType {
    MulExp,
    AddMulExp
};

enum class MulExpType {
    UnaryExp,
    MulUnaryExp
};

enum class LOrExpType {
    LAndExp,
    LOrLAndExp
};

enum class LAndExpType {
    EqExp,
    LAndEqExp
};

enum class EqExpType {
    RelExp,
    EqRelExp
};

enum class RelExpType {
    AddExp,
    RelAddExp
};

class CompUnit;
class CompList;

class DeclOrDef;
class Decl;
class VarDecl;
class ConstDecl;

class ConstDef;
class VarDef;
class InitVal;
class ConstInitVal;
class ConstExp;
class ArrayIndex;
class ConstArrayIndex;

class Block;
class BlockItem;
class BlockItemList;
class Stmt;

class FuncType;
class VarType;

class FuncDef;
class FuncFParam;
class FuncFParams;

class Exp;
class ConstExp;
class Cond;
class LVal;
class PrimaryExp;
class UnaryExp;
class FuncRParams;
class MulExp;
class AddExp;
class RelExp;
class EqExp;
class LAndExp;
class LOrExp;

class CompUnit {
    public:
        shared_ptr<CompList> compList;
        void print(int parent, string part);
};

class CompList {
    public:
        bool if_more_CompList = false;
        shared_ptr<CompList> compList;
        shared_ptr<DeclOrDef> declOrDefs;
        void print(int parent, string part);
};

class DeclOrDef {
    public:
        bool if_decl = false;
        shared_ptr<Decl> decl;
        shared_ptr<FuncDef> funcDef;
        void print(int parent, string part);
};

class Decl {
    public:
        DecType decType;
        shared_ptr<VarDecl> varDecl;
        shared_ptr<ConstDecl> constDecl;
        virtual void print(int parent, string part) = 0;
        virtual ~Decl() = default;
};

class VarDecl : public Decl {
    public:
        VarDecl() {
            decType = DecType::VarDecl;
        }
        vector<shared_ptr<VarDef>> varDefs;
        shared_ptr<VarType> varType;
        void print(int parent, string part) override;
};

class ConstDecl : public Decl {
    public:
        ConstDecl() {
            decType = DecType::ConstDecl;
        }
        vector<shared_ptr<ConstDef>> constDefs;
        shared_ptr<VarType> varType;
        void print(int parent, string part) override;
};

class ConstDef {
    public:
        string ident;
        VarKind varKind;
        shared_ptr<ConstInitVal> constInitVal;
        shared_ptr<ConstArrayIndex> constArrayIndex;
        void print(int parent, string part);
};

class VarDef {
    public:
        string ident;
        VarKind varKind;
        shared_ptr<InitVal> initVal;
        shared_ptr<ConstArrayIndex> constArrayIndex;
        void print(int parent, string part);
};

class InitVal {
    public:
        VarKind varKind;
        shared_ptr<Exp> exp;
        vector<shared_ptr<InitVal>> init_vals;
        void print(int parent, string part);
};

class ConstInitVal {
    public:
        VarKind varKind;
        shared_ptr<ConstExp> constExp;
        vector<shared_ptr<ConstInitVal>> const_initvals;
        void print(int parent, string part);
};

class LVal {
    public:
        VarKind varKind;
        string ident;
        shared_ptr<ArrayIndex> arrayIndex;
        void print(int parent, string part);
};

class ArrayIndex {
    public:
        shared_ptr<ArrayIndex> arrayIndex;
        shared_ptr<Exp> exp;
        void print(int parent, string part);
};

class ConstArrayIndex {
    public:
        shared_ptr<ConstArrayIndex> constArrayIndex;
        shared_ptr<ConstExp> const_exp;
        void print(int parent, string part);
};

class ConstExp {
    public:
        bool is_in_array = false;
        shared_ptr<Exp> exp;
        void print(int parent, string part);
};

class Block {
    public:
        shared_ptr<BlockItemList> blockItemList;
        void print(int parent, string part);
};

class BlockItemList {
    public:
        shared_ptr<BlockItem> blockItem;
        shared_ptr<BlockItemList> blockItemList;
        void print(int parent, string part);
};

class BlockItem {
    public:
        BlockItemType blockItemType;
        shared_ptr<Decl> decl;
        shared_ptr<Stmt> stmt;
        void print(int parent, string part);
};

class Stmt {
    public:
        StmtType stmtType;
        shared_ptr<LVal> lVal;
        shared_ptr<Exp> exp;
        shared_ptr<Cond> cond;
        shared_ptr<Block> block;
        shared_ptr<Stmt> stmt_if;
        shared_ptr<Stmt> stmt_if_else;
        shared_ptr<Stmt> stmt_while;
        shared_ptr<Exp> exp_return;
        void print(int parent, string part);
};

class FuncType {
    public:
        string type;
        void print(int parent, string part);
};

class VarType {
    public:
        string type;
        void print(int parent, string part) {};
};

class FuncDef {
    public:
        shared_ptr<FuncType> funcType;
        string ident;
        shared_ptr<FuncFParams> funcFParams;
        shared_ptr<Block> block;
        void print(int parent, string part);
};

class FuncFParams {
    public:
        vector<shared_ptr<FuncFParam>> funcFParams;
        void print(int parent, string part);
};

class FuncFParam {
    public:
        VarKind varKind;
        string ident;
        shared_ptr<VarType> varType;
        shared_ptr<ArrayIndex> ArrayIndex;
        void print(int parent, string part);
};

class Exp {
    public:
        bool is_in_array = false;
        shared_ptr<AddExp> add_exp;
        void print(int parent, string part);
};

class AddExp {
    public:
        AddExpType addExpType;
        shared_ptr<MulExp> mul_exp;
        shared_ptr<AddExp> add_exp;
        string op;
        void print(int parent, string part);
};

class MulExp {
    public:
        MulExpType mulExpType;
        shared_ptr<UnaryExp> unary_exp;
        shared_ptr<MulExp> mul_exp;
        string op;
        void print(int parent, string part);
};

class UnaryExp {
    public:
        UnaryExpType unaryExpType;
        shared_ptr<PrimaryExp> primary_exp;
        string func_ident;
        shared_ptr<FuncRParams> func_rparams;
        char op;
        shared_ptr<UnaryExp> unary_exp;
        void print(int parent, string part);
};

class PrimaryExp {
    public:
        PrimaryExpType primaryExpType;
        shared_ptr<Exp> exp;
        shared_ptr<LVal> lVal;
        int number;
        void print(int parent, string part);
};

class FuncRParams {
    public:
        vector<shared_ptr<Exp>> exps;
        void print(int parent, string part);
};

class Cond {
    public:
        shared_ptr<LOrExp> lOrExp;
        void print(int parent, string part);
};

class LOrExp {
    public:
        LOrExpType lOrExpType;
        shared_ptr<LAndExp> lAndExp;
        shared_ptr<LOrExp> lOrExp;
        void print(int parent, string part);
};

class LAndExp {
    public:
        LAndExpType lAndExpType;
        shared_ptr<EqExp> eqExp;
        shared_ptr<LAndExp> lAndExp;
        void print(int parent, string part);
};

class EqExp {
    public:
        EqExpType eqExpType;
        shared_ptr<RelExp> relExp;
        shared_ptr<EqExp> eqExp;
        string op;
        void print(int parent, string part);
};

class RelExp {
    public:
        RelExpType relExpType;
        shared_ptr<AddExp> add_exp;
        shared_ptr<RelExp> relExp;
        string op;
        void print(int parent, string part);
};

#endif // TREE_H