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
    Block,
    If,
    IfElse,
    While,
    Break,
    Continue,
    Return
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

class Base;

class CompUnit;

class Decl;
class VarDecl;
class ConstDecl;

class ConstDef;
class VarDef;
class InitVal;
class ConstInitVal;
class ConstExp;
class ExpSQBList;
class ConstExpSQBList;

class Block;
class BlockItem;
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

class Base {
    public:
        virtual void print(int depth) = 0;
        virtual ~Base() = default;
};

class CompUnit : public Base {
    public:
        vector<shared_ptr<Decl>> decls;
        vector<shared_ptr<FuncDef>> funcDefs;
        CompUnit() = default;
        void print(int depth) override;
};

class Decl : public Base {
    public:
        DecType decType;
        vector<shared_ptr<VarDecl>> varDecls;
        vector<shared_ptr<ConstDecl>> constDecls;
        virtual void print(int depth) = 0;
        virtual ~Decl() = default;
};

class VarDecl : public Decl {
    public:
        VarDecl() {
            decType = DecType::VarDecl;
        }
        vector<shared_ptr<VarDef>> varDefs;
        shared_ptr<VarType> varType;
        void print(int depth) override;
};

class ConstDecl : public Decl {
    public:
        ConstDecl() {
            decType = DecType::ConstDecl;
        }
        vector<shared_ptr<ConstDef>> constDefs;
        shared_ptr<VarType> varType;
        void print(int depth) override;
};

class ConstDef : public Base {
    public:
        string ident;
        VarKind varKind;
        shared_ptr<ConstInitVal> constInitVal;
        vector<shared_ptr<ConstExp>> const_exp;
        void print(int depth) override;
};

class VarDef : public Base {
    public:
        string ident;
        VarKind varKind;
        shared_ptr<InitVal> initVal;
        vector<shared_ptr<ConstExp>> const_exps;
        void print(int depth) override;
};

class InitVal : public Base {
    public:
        VarKind varKind;
        shared_ptr<Exp> exp;
        shared_ptr<InitVal> init_vals;
        void print(int depth) override;
};

class ConstInitVal : public Base {
    public:
        VarKind varKind;
        shared_ptr<ConstExp> constExp;
        vector<shared_ptr<ConstInitVal>> const_initvals;
        void print(int depth) override;
};

class LVal : public Base {
    public:
        VarKind varKind;
        string ident;
        shared_ptr<Exp> exp;
        vector<shared_ptr<Exp>> exps;
        void print(int depth) override;
};

class ExpSQBList : public Base {
    public:
        vector<shared_ptr<Exp>> exps;
        void print(int depth) override;
};

class ConstExpSQBList : public Base {
    public:
        vector<shared_ptr<ConstExp>> const_exps;
        void print(int depth) override;
};

class ConstExp : public Base {
    public:
        shared_ptr<Exp> exp;
        void print(int depth) override;
};

class Block : public Base {
    public:
        vector<shared_ptr<BlockItem>> blockItems;
        void print(int depth) override;
};

class BlockItem : public Base {
    public:
        BlockItemType blockItemType;
        shared_ptr<Decl> decl;
        shared_ptr<Stmt> stmt;
        void print(int depth) override;
};

class Stmt : public Base {
    public:
        StmtType stmtType;
        shared_ptr<LVal> lVal;
        shared_ptr<Exp> exp;
        shared_ptr<Cond> cond;
        shared_ptr<Block> block;
        shared_ptr<Stmt> stmt_if;
        shared_ptr<Stmt> stmt_if_else;
        void print(int depth) override;
};

class FuncType : public Base {
    public:
        string type;
        void print(int depth) override;
};

class VarType : public Base {
    public:
        string type;
        void print(int depth) override;
};

class FuncDef : public Base {
    public:
        shared_ptr<FuncType> funcType;
        string ident;
        shared_ptr<FuncFParams> funcFParams;
        shared_ptr<Block> block;
        void print(int depth) override;
};

class FuncFParams : public Base {
    public:
        vector<shared_ptr<FuncFParam>> funcFParams;
        void print(int depth) override;
};

class FuncFParam : public Base {
    public:
        VarKind varKind;
        string ident;
        shared_ptr<VarType> varType;
        vector<shared_ptr<ConstExp>> const_exps;
        void print(int depth) override;
};

class Exp : public Base {
    public:
        shared_ptr<AddExp> add_exp;
        void print(int depth) override;
};

class AddExp : public Base {
    public:
        AddExpType addExpType;
        shared_ptr<MulExp> mul_exp;
        shared_ptr<AddExp> add_exp;
        string op;
        void print(int depth) override;
};

class MulExp : public Base {
    public:
        MulExpType mulExpType;
        shared_ptr<UnaryExp> unary_exp;
        shared_ptr<MulExp> mul_exp;
        string op;
        void print(int depth) override;
};

class UnaryExp : public Base {
    public:
        UnaryExpType unaryExpType;
        shared_ptr<PrimaryExp> primary_exp;
        string func_ident;
        shared_ptr<FuncRParams> func_rparams;
        char op;
        shared_ptr<UnaryExp> unary_exp;
        void print(int depth) override;
};

class PrimaryExp : public Base {
    public:
        PrimaryExpType primaryExpType;
        shared_ptr<Exp> exp;
        shared_ptr<LVal> lVal;
        int number;
        void print(int depth) override;
};

class FuncRParams : public Base {
    public:
        vector<shared_ptr<Exp>> exps;
        void print(int depth) override;
};

class Cond : public Base {
    public:
        shared_ptr<LOrExp> lOrExp;
        void print(int depth) override;
};

class LOrExp : public Base {
    public:
        LOrExpType lOrExpType;
        shared_ptr<LAndExp> lAndExp;
        shared_ptr<LOrExp> lOrExp;
        void print(int depth) override;
};

class LAndExp : public Base {
    public:
        LAndExpType lAndExpType;
        shared_ptr<EqExp> eqExp;
        shared_ptr<LAndExp> lAndExp;
        void print(int depth) override;
};

class EqExp : public Base {
    public:
        EqExpType eqExpType;
        shared_ptr<RelExp> relExp;
        shared_ptr<EqExp> eqExp;
        string op;
        void print(int depth) override;
};

class RelExp : public Base {
    public:
        RelExpType relExpType;
        shared_ptr<AddExp> addExp;
        shared_ptr<RelExp> relExp;
        string op;
        void print(int depth) override;
};

#endif // TREE_H