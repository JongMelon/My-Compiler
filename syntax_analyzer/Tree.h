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
    Empty,
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

class Tree;

class CompUnit;
class CompList;

class DeclOrDef;
class Decl;
class VarDecl;
class ConstDecl;

class VarDefList;
class ConstDefList;

class ConstDef;
class VarDef;
class InitVal;
class ConstInitVal;

class InitValList;
class ConstInitValList;

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
class FuncFParamList;

class Exp;
class ConstExp;
class Cond;
class LVal;
class PrimaryExp;
class UnaryExp;
class FuncRParamList;
class MulExp;
class AddExp;
class RelExp;
class EqExp;
class LAndExp;
class LOrExp;

class Tree {
    public:
        ~Tree() = default;
        virtual void print(int parent, string part) = 0;
};

class CompUnit : public Tree {
    public:
        shared_ptr<CompList> compList;
        void print(int parent, string part);
};

class CompList : public Tree {
    public:
        bool if_more_CompList = false;
        shared_ptr<CompList> compList;
        shared_ptr<DeclOrDef> declOrDef;
        void print(int parent, string part);
};

class DeclOrDef : public Tree {
    public:
        bool if_decl = false;
        shared_ptr<Decl> decl;
        shared_ptr<FuncDef> funcDef;
        void print(int parent, string part);
};

class Decl : public Tree {
    public:
        DecType decType;
        shared_ptr<VarDecl> varDecl;
        shared_ptr<ConstDecl> constDecl;
        void print(int parent, string part);
};

class VarDecl : public Tree {
    public:
        DecType decType = DecType::VarDecl;
        shared_ptr<VarDefList> varDefList;
        shared_ptr<VarType> varType;
        void print(int parent, string part) override;
};

class VarDefList : public Tree {
    public:
        shared_ptr<VarDef> varDef;
        shared_ptr<VarDefList> varDefList;
        void print(int parent, string part);
};

class ConstDecl : public Tree {
    public:
        DecType decType = DecType::ConstDecl;
        shared_ptr<ConstDefList> constDefList;
        shared_ptr<VarType> varType;
        void print(int parent, string part) override;
};

class ConstDefList : public Tree {
    public:
        shared_ptr<ConstDef> constDef;
        shared_ptr<ConstDefList> constDefList;
        void print(int parent, string part);
};

class ConstDef : public Tree {
    public:
        string ident;
        VarKind varKind;
        shared_ptr<ConstInitVal> constInitVal;
        shared_ptr<ConstArrayIndex> constArrayIndex;
        void print(int parent, string part);
};

class VarDef : public Tree {
    public:
        string ident;
        VarKind varKind;
        shared_ptr<InitVal> initVal;
        shared_ptr<ConstArrayIndex> constArrayIndex;
        void print(int parent, string part);
};

class InitVal : public Tree {
    public:
        VarKind varKind;
        shared_ptr<Exp> exp;
        shared_ptr<InitValList> initValList;
        void print(int parent, string part);
};

class InitValList : public Tree {
    public:
        shared_ptr<InitVal> initVal;
        shared_ptr<InitValList> initValList;
        void print(int parent, string part);
};

class ConstInitVal : public Tree {
    public:
        VarKind varKind;
        shared_ptr<ConstExp> constExp;
        shared_ptr<ConstInitValList> constInitValList;
        void print(int parent, string part);
};

class ConstInitValList : public Tree {
    public:
        shared_ptr<ConstInitVal> constInitVal;
        shared_ptr<ConstInitValList> constInitValList;
        void print(int parent, string part);
};

class LVal : public Tree {
    public:
        VarKind varKind;
        string ident;
        shared_ptr<ArrayIndex> arrayIndex;
        void print(int parent, string part);
};

class ArrayIndex : public Tree {
    public:
        shared_ptr<ArrayIndex> arrayIndex;
        shared_ptr<Exp> exp;
        void print(int parent, string part);
};

class ConstArrayIndex : public Tree {
    public:
        shared_ptr<ConstArrayIndex> constArrayIndex;
        shared_ptr<ConstExp> const_exp;
        void print(int parent, string part);
};

class ConstExp : public Tree {
    public:
        bool is_in_array = false;
        shared_ptr<Exp> exp;
        void print(int parent, string part);
};

class Block : public Tree {
    public:
        shared_ptr<BlockItemList> blockItemList;
        void print(int parent, string part);
};

class BlockItemList : public Tree {
    public:
        shared_ptr<BlockItem> blockItem;
        shared_ptr<BlockItemList> blockItemList;
        void print(int parent, string part);
};

class BlockItem : public Tree {
    public:
        BlockItemType blockItemType;
        shared_ptr<Decl> decl;
        shared_ptr<Stmt> stmt;
        void print(int parent, string part);
};

class Stmt : public Tree {
    public:
        StmtType stmtType;
        shared_ptr<LVal> lVal;
        shared_ptr<Exp> exp;
        shared_ptr<Cond> cond;
        shared_ptr<Block> block;
        shared_ptr<Stmt> stmt_if;
        shared_ptr<Stmt> stmt_if_else;
        shared_ptr<Stmt> stmt_while;
        void print(int parent, string part);
};

class FuncType : public Tree {
    public:
        string type;
        void print(int parent, string part);
};

class VarType : public Tree {
    public:
        string type;
        void print(int parent, string part) {};
};

class FuncDef : public Tree {
    public:
        shared_ptr<FuncType> funcType;
        string ident;
        shared_ptr<FuncFParamList> funcFParamList;
        shared_ptr<Block> block;
        void print(int parent, string part);
};

class FuncFParamList : public Tree {
    public:
        shared_ptr<FuncFParam> funcFParam;
        shared_ptr<FuncFParamList> funcFParamList;
        void print(int parent, string part);
};

class FuncFParam : public Tree {
    public:
        VarKind varKind;
        string ident;
        shared_ptr<VarType> varType;
        shared_ptr<ArrayIndex> arrayIndex;
        void print(int parent, string part);
};

class Exp : public Tree {
    public:
        bool is_in_array = false;
        shared_ptr<AddExp> add_exp;
        void print(int parent, string part);
};

class AddExp : public Tree {
    public:
        AddExpType addExpType;
        shared_ptr<MulExp> mul_exp;
        shared_ptr<AddExp> add_exp;
        string op;
        void print(int parent, string part);
};

class MulExp : public Tree {
    public:
        MulExpType mulExpType;
        shared_ptr<UnaryExp> unary_exp;
        shared_ptr<MulExp> mul_exp;
        string op;
        void print(int parent, string part);
};

class UnaryExp : public Tree {
    public:
        UnaryExpType unaryExpType;
        shared_ptr<PrimaryExp> primary_exp;
        string func_ident;
        shared_ptr<FuncRParamList> funcRParamList;
        string op;
        shared_ptr<UnaryExp> unary_exp;
        void print(int parent, string part);
};

class PrimaryExp : public Tree {
    public:
        PrimaryExpType primaryExpType;
        shared_ptr<Exp> exp;
        shared_ptr<LVal> lVal;
        int number;
        void print(int parent, string part);
};

class FuncRParamList : public Tree {
    public:
        shared_ptr<Exp> exp;
        shared_ptr<FuncRParamList> funcRParamList;
        void print(int parent, string part);
};

class Cond : public Tree {
    public:
        shared_ptr<LOrExp> lOrExp;
        void print(int parent, string part);
};

class LOrExp : public Tree {
    public:
        LOrExpType lOrExpType;
        shared_ptr<LAndExp> lAndExp;
        shared_ptr<LOrExp> lOrExp;
        void print(int parent, string part);
};

class LAndExp : public Tree {
    public:
        LAndExpType lAndExpType;
        shared_ptr<EqExp> eqExp;
        shared_ptr<LAndExp> lAndExp;
        void print(int parent, string part);
};

class EqExp : public Tree {
    public:
        EqExpType eqExpType;
        shared_ptr<RelExp> relExp;
        shared_ptr<EqExp> eqExp;
        string op;
        void print(int parent, string part);
};

class RelExp : public Tree {
    public:
        RelExpType relExpType;
        shared_ptr<AddExp> add_exp;
        shared_ptr<RelExp> relExp;
        string op;
        void print(int parent, string part);
};

#endif // TREE_H