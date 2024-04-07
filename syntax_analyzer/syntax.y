%code requires {
    #include "Tree.h"
}


%{

#include <stdio.h>
#include <string>
#include "Tree.h"

int yylex(void);
void yyerror(const char *s);

%}

%union {
    int ival;
    char chval;
    std::string* sval;
    Tree* tree;
}

%start CompUnit

%token <sval>CONST INT IF ELSE WHILE BREAK CONTINUE RETURN IDENT VOID
%token <ival>INTCONST
%token <chval>LEFTSQB RIGHTSQB LPAREN RPAREN LEFTBRACE RIGHTBRACE
%token <chval>'+' '-' '*' '/' '%' '<' '>' '!' ',' ';' '='
%token <sval>LE GE EQ NE LOR LAND

%type <tree> CompUnit
%type <tree>Decl ConstDecl VarDecl ConstDef ConstDefList VarDef VarDefList ConstInitVal InitVal ConstInitValList InitValList
%type <tree>Exp ArrayIndex ConstExp ConstArrayIndex AddExp LOrExp PrimaryExp UnaryExp MulExp RelExp EqExp LAndExp
%type <tree>FuncDef FuncType FuncFParam FuncFParamList FuncRParamList
%type <tree>Block BlockItem BlockItemList Stmt LVal Cond

%type <tree>CompList DecOrDef VarType

%type <chval>UnaryOp

%left LOR
%left LAND
%left EQ NE
%left '<' '>' LE GE
%left '+' '-'
%left '*' '/' '%'
%right '!'

%%

CompUnit
: CompList {
    shared_ptr<CompUnit> compUnit = make_shared<CompUnit>();
    compUnit->compList = shared_ptr<CompList>((CompList* )$1);
    $$ = compUnit.get();
    compUnit->print(0, "");
}

CompList
: DecOrDef {
    shared_ptr<CompList> compList = make_shared<CompList>();
    compList->declOrDef = shared_ptr<DeclOrDef>((DeclOrDef* )$1);
    $$ = compList.get();
}
| CompList DecOrDef {
    shared_ptr<CompList> compList = make_shared<CompList>();
    compList->if_more_CompList = true;
    compList->compList = shared_ptr<CompList>((CompList* )$1);
    compList->declOrDef = shared_ptr<DeclOrDef>((DeclOrDef* )$2);
    $$ = compList.get();
}

DecOrDef
: Decl {
    shared_ptr<DeclOrDef> decOrDef = make_shared<DeclOrDef>();
    decOrDef->if_decl = true;
    decOrDef->decl = shared_ptr<Decl>((Decl* )$1);
    $$ = decOrDef.get();
}
| FuncDef {
    shared_ptr<DeclOrDef> decOrDef = make_shared<DeclOrDef>();
    decOrDef->funcDef = shared_ptr<FuncDef>((FuncDef* )$1);
    $$ = decOrDef.get();
}

Decl
: ConstDecl {
    shared_ptr<Decl> decl = make_shared<Decl>();
    decl->decType = DecType::ConstDecl;
    decl->constDecl = shared_ptr<ConstDecl>((ConstDecl* )$1);
    $$ = decl.get();
}
| VarDecl {
    shared_ptr<Decl> decl = make_shared<Decl>();
    decl->decType = DecType::VarDecl;
    decl->varDecl = shared_ptr<VarDecl>((VarDecl* )$1);
    $$ = decl.get();
}

ConstDecl
: CONST VarType ConstDefList ';' {
    shared_ptr<ConstDecl> constDecl = make_shared<ConstDecl>();
    constDecl->varType = shared_ptr<VarType>((VarType* )$2);
    constDecl->constDefList = shared_ptr<ConstDefList>((ConstDefList* )$3);
    $$ = constDecl.get();
}

ConstDefList
: ConstDef {
    shared_ptr<ConstDefList> constDefList = make_shared<ConstDefList>();
    constDefList->constDef = shared_ptr<ConstDef>((ConstDef* )$1);
    $$ = constDefList.get();
}
| ConstDef ',' ConstDefList {
    shared_ptr<ConstDefList> constDefList = make_shared<ConstDefList>();
    constDefList->constDef = shared_ptr<ConstDef>((ConstDef* )$1);
    constDefList->constDefList = shared_ptr<ConstDefList>((ConstDefList* )$3);
    $$ = constDefList.get();
}

ConstDef
: IDENT '=' ConstInitVal {
    shared_ptr<ConstDef> constDef = make_shared<ConstDef>();
    constDef->varKind = VarKind::Var;
    constDef->ident = *($1);
    constDef->constInitVal = shared_ptr<ConstInitVal>((ConstInitVal* )$3);
    $$ = constDef.get();
}
| IDENT ConstArrayIndex '=' ConstInitVal {
    shared_ptr<ConstDef> constDef = make_shared<ConstDef>();
    constDef->varKind = VarKind::Array;
    constDef->ident = *($1);
    constDef->constArrayIndex = shared_ptr<ConstArrayIndex>((ConstArrayIndex* )$2);
    constDef->constInitVal = shared_ptr<ConstInitVal>((ConstInitVal* )$4);
    $$ = constDef.get();
}

ConstInitVal
: ConstExp {
    shared_ptr<ConstInitVal> constInitVal = make_shared<ConstInitVal>();
    constInitVal->constExp = shared_ptr<ConstExp>((ConstExp* )$1);
    $$ = constInitVal.get();
}
| LEFTBRACE RIGHTBRACE {
    shared_ptr<ConstInitVal> constInitVal = make_shared<ConstInitVal>();
    constInitVal->varKind = VarKind::Array;
    $$ = constInitVal.get();
}
| LEFTBRACE ConstInitValList RIGHTBRACE {
    shared_ptr<ConstInitVal> constInitVal = make_shared<ConstInitVal>();
    constInitVal->varKind = VarKind::Array;
    constInitVal->constInitValList = shared_ptr<ConstInitValList>((ConstInitValList* )$2);
    $$ = constInitVal.get();
}

ConstInitValList
: ConstInitVal {
    shared_ptr<ConstInitValList> constInitValList = make_shared<ConstInitValList>();
    constInitValList->constInitVal = shared_ptr<ConstInitVal>((ConstInitVal* )$1);
    $$ = constInitValList.get();
}
| ConstInitVal ',' ConstInitValList {
    shared_ptr<ConstInitValList> constInitValList = make_shared<ConstInitValList>();
    constInitValList->constInitVal = shared_ptr<ConstInitVal>((ConstInitVal* )$1);
    constInitValList->constInitValList = shared_ptr<ConstInitValList>((ConstInitValList* )$3);
    $$ = constInitValList.get();
}

VarDecl
: FuncType VarDefList ';' {
    shared_ptr<VarDecl> varDecl = make_shared<VarDecl>();
    varDecl->varDefList = shared_ptr<VarDefList>((VarDefList* )$2);
    $$ = varDecl.get();
}

VarDefList
: VarDef {
    shared_ptr<VarDefList> varDefList = make_shared<VarDefList>();
    varDefList->varDef = shared_ptr<VarDef>((VarDef* )$1);
    $$ = varDefList.get();
}
| VarDef ',' VarDefList {
    shared_ptr<VarDefList> varDefList = make_shared<VarDefList>();
    varDefList->varDef = shared_ptr<VarDef>((VarDef* )$1);
    varDefList->varDefList = shared_ptr<VarDefList>((VarDefList* )$3);
    $$ = varDefList.get();
}

VarDef
: IDENT {
    shared_ptr<VarDef> varDef = make_shared<VarDef>();
    varDef->varKind = VarKind::Var;
    varDef->ident = *($1);
    $$ = varDef.get();
}
| IDENT '=' InitVal {
    shared_ptr<VarDef> varDef = make_shared<VarDef>();
    varDef->varKind = VarKind::Var;
    varDef->ident = *($1);
    varDef->initVal = shared_ptr<InitVal>((InitVal* )$3);
    $$ = varDef.get();
}
| IDENT ConstArrayIndex {
    shared_ptr<VarDef> varDef = make_shared<VarDef>();
    varDef->varKind = VarKind::Array;
    varDef->ident = *($1);
    varDef->constArrayIndex = shared_ptr<ConstArrayIndex>((ConstArrayIndex* )$2);
    $$ = varDef.get();
}
| IDENT ConstArrayIndex '=' InitVal {
    shared_ptr<VarDef> varDef = make_shared<VarDef>();
    varDef->varKind = VarKind::Array;
    varDef->ident = *($1);
    varDef->constArrayIndex = shared_ptr<ConstArrayIndex>((ConstArrayIndex* )$2);
    varDef->initVal = shared_ptr<InitVal>((InitVal* )$4);
    $$ = varDef.get();
}

ConstArrayIndex
: LEFTSQB ConstExp RIGHTSQB {
    shared_ptr<ConstArrayIndex> constArrayIndex = make_shared<ConstArrayIndex>();
    constArrayIndex->const_exp = shared_ptr<ConstExp>((ConstExp* )$2);
    $$ = constArrayIndex.get();
}
| ConstArrayIndex LEFTSQB ConstExp RIGHTSQB {
    shared_ptr<ConstArrayIndex> constArrayIndex = make_shared<ConstArrayIndex>();
    constArrayIndex->constArrayIndex = shared_ptr<ConstArrayIndex>((ConstArrayIndex* )$1);
    constArrayIndex->const_exp = shared_ptr<ConstExp>((ConstExp* )$3);
    $$ = constArrayIndex.get();
}

InitVal
: Exp {
    shared_ptr<InitVal> initVal = make_shared<InitVal>();
    initVal->varKind = VarKind::Var;
    initVal->exp = shared_ptr<Exp>((Exp* )$1);
    $$ = initVal.get();
}
| LEFTBRACE RIGHTBRACE {
    shared_ptr<InitVal> initVal = make_shared<InitVal>();
    initVal->varKind = VarKind::Array;
    $$ = initVal.get();
}
| LEFTBRACE InitValList RIGHTBRACE {
    shared_ptr<InitVal> initVal = make_shared<InitVal>();
    initVal->varKind = VarKind::Array;
    initVal->initValList = shared_ptr<InitValList>((InitValList* )$2);
    $$ = initVal.get();
}

InitValList
: InitVal {
    shared_ptr<InitValList> initValList = make_shared<InitValList>();
    initValList->initVal = shared_ptr<InitVal>((InitVal* )$1);
    $$ = initValList.get();
}
| InitVal ',' InitValList {
    shared_ptr<InitValList> initValList = make_shared<InitValList>();
    initValList->initVal = shared_ptr<InitVal>((InitVal* )$1);
    initValList->initValList = shared_ptr<InitValList>((InitValList* )$3);
    $$ = initValList.get();
}

FuncDef
: FuncType IDENT LPAREN RPAREN Block {
    shared_ptr<FuncDef> funcDef = make_shared<FuncDef>();
    funcDef->funcType = shared_ptr<FuncType>((FuncType* )$1);
    funcDef->ident = *($2);
    funcDef->block = shared_ptr<Block>((Block* )$5);
    $$ = funcDef.get();
}
| FuncType IDENT LPAREN FuncFParamList RPAREN Block {
    shared_ptr<FuncDef> funcDef = make_shared<FuncDef>();
    funcDef->funcType = shared_ptr<FuncType>((FuncType* )$1);
    funcDef->ident = *($2);
    funcDef->funcFParamList = shared_ptr<FuncFParamList>((FuncFParamList* )$4);
    funcDef->block = shared_ptr<Block>((Block* )$6);
    $$ = funcDef.get();
}

VarType
: INT {
    shared_ptr<VarType> varType = make_shared<VarType>();
    varType->type = "int";
    $$ = varType.get();
}

FuncType
: VOID {
    shared_ptr<FuncType> funcType = make_shared<FuncType>();
    funcType->type = "void";
    $$ = funcType.get();
}
| INT {
    shared_ptr<FuncType> funcType = make_shared<FuncType>();
    funcType->type = "int";
    $$ = funcType.get();
}

FuncFParamList
: FuncFParam {
    shared_ptr<FuncFParamList> funcFParamList = make_shared<FuncFParamList>();
    funcFParamList->funcFParam = shared_ptr<FuncFParam>((FuncFParam* )$1);
    $$ = funcFParamList.get();
}
| FuncFParam ',' FuncFParamList {
    shared_ptr<FuncFParamList> funcFParamList = make_shared<FuncFParamList>();
    funcFParamList->funcFParam = shared_ptr<FuncFParam>((FuncFParam* )$1);
    funcFParamList->funcFParamList = shared_ptr<FuncFParamList>((FuncFParamList* )$3);
    $$ = funcFParamList.get();
}

FuncFParam
: VarType IDENT {
    shared_ptr<FuncFParam> funcFParam = make_shared<FuncFParam>();
    funcFParam->varKind = VarKind::Var;
    funcFParam->varType = shared_ptr<VarType>((VarType* )$1);
    funcFParam->ident = *($2);
    $$ = funcFParam.get();
}
| VarType IDENT LEFTSQB RIGHTSQB {
    shared_ptr<FuncFParam> funcFParam = make_shared<FuncFParam>();
    funcFParam->varKind = VarKind::Array;
    funcFParam->varType = shared_ptr<VarType>((VarType* )$1);
    funcFParam->ident = *($2);
    $$ = funcFParam.get();
}
| VarType IDENT LEFTSQB RIGHTSQB ArrayIndex {
    shared_ptr<FuncFParam> funcFParam = make_shared<FuncFParam>();
    funcFParam->varKind = VarKind::Array;
    funcFParam->varType = shared_ptr<VarType>((VarType* )$1);
    funcFParam->ident = *($2);
    funcFParam->arrayIndex = shared_ptr<ArrayIndex>((ArrayIndex* )$5);
    $$ = funcFParam.get();
}

ArrayIndex
: LEFTSQB Exp RIGHTSQB {
    shared_ptr<ArrayIndex> arrayIndex = make_shared<ArrayIndex>();
    arrayIndex->exp = shared_ptr<Exp>((Exp* )$2);
    $$ = arrayIndex.get();
}
| ArrayIndex LEFTSQB Exp RIGHTSQB {
    shared_ptr<ArrayIndex> arrayIndex = make_shared<ArrayIndex>();
    arrayIndex->arrayIndex = shared_ptr<ArrayIndex>((ArrayIndex* )$1);
    arrayIndex->exp = shared_ptr<Exp>((Exp* )$3);
    $$ = arrayIndex.get();
}

Block
: LEFTBRACE RIGHTBRACE {
    shared_ptr<Block> block = make_shared<Block>();
    $$ = block.get();
}
| LEFTBRACE BlockItemList RIGHTBRACE {
    shared_ptr<Block> block = make_shared<Block>();
    block->blockItemList = shared_ptr<BlockItemList>((BlockItemList* )$2);
    $$ = block.get();
}

BlockItemList
: BlockItem {
    shared_ptr<BlockItemList> blockItemList = make_shared<BlockItemList>();
    blockItemList->blockItem = shared_ptr<BlockItem>((BlockItem* )$1);
    $$ = blockItemList.get();
}
| BlockItem BlockItemList {
    shared_ptr<BlockItemList> blockItemList = make_shared<BlockItemList>();
    blockItemList->blockItem = shared_ptr<BlockItem>((BlockItem* )$1);
    blockItemList->blockItemList = shared_ptr<BlockItemList>((BlockItemList* )$2);
    $$ = blockItemList.get();
}

BlockItem
: Decl {
    shared_ptr<BlockItem> blockItem = make_shared<BlockItem>();
    blockItem->blockItemType = BlockItemType::Decl;
    blockItem->decl = shared_ptr<Decl>((Decl* )$1);
    $$ = blockItem.get();
}
| Stmt {
    shared_ptr<BlockItem> blockItem = make_shared<BlockItem>();
    blockItem->blockItemType = BlockItemType::Stmt;
    blockItem->stmt = shared_ptr<Stmt>((Stmt* )$1);
    $$ = blockItem.get();
}

Stmt
: LVal '=' Exp ';' {
    shared_ptr<Stmt> stmt = make_shared<Stmt>();
    stmt->stmtType = StmtType::Assign;
    stmt->lVal = shared_ptr<LVal>((LVal* )$1);
    stmt->exp = shared_ptr<Exp>((Exp* )$3);
    $$ = stmt.get();
}
| ';' {
    shared_ptr<Stmt> stmt = make_shared<Stmt>();
    stmt->stmtType = StmtType::Empty;
    $$ = stmt.get();
}
| Exp ';' {
    shared_ptr<Stmt> stmt = make_shared<Stmt>();
    stmt->stmtType = StmtType::Exp;
    stmt->exp = shared_ptr<Exp>((Exp* )$1);
    $$ = stmt.get();
}
| Block {
    shared_ptr<Stmt> stmt = make_shared<Stmt>();
    stmt->stmtType = StmtType::Block;
    stmt->block = shared_ptr<Block>((Block* )$1);
    $$ = stmt.get();
}
| IF LPAREN Cond RPAREN Stmt {
    shared_ptr<Stmt> stmt = make_shared<Stmt>();
    stmt->stmtType = StmtType::If;
    stmt->cond = shared_ptr<Cond>((Cond* )$3);
    stmt->stmt_if = shared_ptr<Stmt>((Stmt* )$5);
    $$ = stmt.get();
}
| IF LPAREN Cond RPAREN Stmt ELSE Stmt {
    shared_ptr<Stmt> stmt = make_shared<Stmt>();
    stmt->stmtType = StmtType::IfElse;
    stmt->cond = shared_ptr<Cond>((Cond* )$3);
    stmt->stmt_if = shared_ptr<Stmt>((Stmt* )$5);
    stmt->stmt_if_else = shared_ptr<Stmt>((Stmt* )$7);
    $$ = stmt.get();
}
| WHILE LPAREN Cond RPAREN Stmt {
    shared_ptr<Stmt> stmt = make_shared<Stmt>();
    stmt->stmtType = StmtType::While;
    stmt->cond = shared_ptr<Cond>((Cond* )$3);
    stmt->stmt_while = shared_ptr<Stmt>((Stmt* )$5);
    $$ = stmt.get();
}
| BREAK ';' {
    shared_ptr<Stmt> stmt = make_shared<Stmt>();
    stmt->stmtType = StmtType::Break;
    $$ = stmt.get();
}
| CONTINUE ';' {
    shared_ptr<Stmt> stmt = make_shared<Stmt>();
    stmt->stmtType = StmtType::Continue;
    $$ = stmt.get();
}
| RETURN ';' {
    shared_ptr<Stmt> stmt = make_shared<Stmt>();
    stmt->stmtType = StmtType::Return;
    $$ = stmt.get();
}
| RETURN Exp ';' {
    shared_ptr<Stmt> stmt = make_shared<Stmt>();
    stmt->stmtType = StmtType::Return;
    stmt->exp = shared_ptr<Exp>((Exp* )$2);
    $$ = stmt.get();
}

ConstExp
: Exp {
    shared_ptr<ConstExp> constExp = make_shared<ConstExp>();
    constExp->exp = shared_ptr<Exp>((Exp* )$1);
    $$ = constExp.get();
}

Exp
: AddExp {
    shared_ptr<Exp> exp = make_shared<Exp>();
    exp->add_exp = shared_ptr<AddExp>((AddExp* )$1);
    $$ = exp.get();
}

Cond
: LOrExp {
    shared_ptr<Cond> cond = make_shared<Cond>();
    cond->lOrExp = shared_ptr<LOrExp>((LOrExp* )$1);
    $$ = cond.get();
}

LVal
: IDENT {
    shared_ptr<LVal> lVal = make_shared<LVal>();
    lVal->varKind = VarKind::Var;
    lVal->ident = *($1);
    $$ = lVal.get();
}
| IDENT ArrayIndex {
    shared_ptr<LVal> lVal = make_shared<LVal>();
    lVal->varKind = VarKind::Array;
    lVal->ident = *($1);
    lVal->arrayIndex = shared_ptr<ArrayIndex>((ArrayIndex* )$2);
    $$ = lVal.get();
}

PrimaryExp
: LPAREN Exp RPAREN {
    shared_ptr<PrimaryExp> primaryExp = make_shared<PrimaryExp>();
    primaryExp->primaryExpType = PrimaryExpType::Exp;
    primaryExp->exp = shared_ptr<Exp>((Exp* )$2);
    $$ = primaryExp.get();
}
| LVal {
    shared_ptr<PrimaryExp> primaryExp = make_shared<PrimaryExp>();
    primaryExp->primaryExpType = PrimaryExpType::LVal;
    primaryExp->lVal = shared_ptr<LVal>((LVal* )$1);
    $$ = primaryExp.get();
}
| INTCONST {
    shared_ptr<PrimaryExp> primaryExp = make_shared<PrimaryExp>();
    primaryExp->primaryExpType = PrimaryExpType::Number;
    primaryExp->number = $1;
    $$ = primaryExp.get();
}

UnaryExp
: PrimaryExp {
    shared_ptr<UnaryExp> unaryExp = make_shared<UnaryExp>();
    unaryExp->unaryExpType = UnaryExpType::PrimaryExp;
    unaryExp->primary_exp = shared_ptr<PrimaryExp>((PrimaryExp* )$1);
    $$ = unaryExp.get();
}
| IDENT LPAREN RPAREN {
    shared_ptr<UnaryExp> unaryExp = make_shared<UnaryExp>();
    unaryExp->unaryExpType = UnaryExpType::FuncCall;
    unaryExp->func_ident = *($1);
    $$ = unaryExp.get();
}
| IDENT LPAREN FuncRParamList RPAREN {
    shared_ptr<UnaryExp> unaryExp = make_shared<UnaryExp>();
    unaryExp->unaryExpType = UnaryExpType::FuncCall;
    unaryExp->func_ident = *($1);
    unaryExp->funcRParamList = shared_ptr<FuncRParamList>((FuncRParamList* )$3);
    $$ = unaryExp.get();
} // function call
| UnaryOp UnaryExp {
    shared_ptr<UnaryExp> unaryExp = make_shared<UnaryExp>();
    unaryExp->unaryExpType = UnaryExpType::OP_Exp;
    unaryExp->op = $1;
    unaryExp->unary_exp = shared_ptr<UnaryExp>((UnaryExp* )$2);
    $$ = unaryExp.get();
}

UnaryOp
: '+' {
    $$ = '+';
}
| '-' {
    $$ = '-';
}
| '!' {
    $$ = '!';
}

FuncRParamList
: Exp {
    shared_ptr<FuncRParamList> funcRParamList = make_shared<FuncRParamList>();
    funcRParamList->exp = shared_ptr<Exp>((Exp* )$1);
    $$ = funcRParamList.get();
}
| Exp ',' FuncRParamList {
    shared_ptr<FuncRParamList> funcRParamList = make_shared<FuncRParamList>();
    funcRParamList->exp = shared_ptr<Exp>((Exp* )$1);
    funcRParamList->funcRParamList = shared_ptr<FuncRParamList>((FuncRParamList* )$3);
    $$ = funcRParamList.get();
}

MulExp
: UnaryExp {
    shared_ptr<MulExp> mulExp = make_shared<MulExp>();
    mulExp->mulExpType = MulExpType::UnaryExp;
    mulExp->unary_exp = shared_ptr<UnaryExp>((UnaryExp* )$1);
    $$ = mulExp.get();
}
| MulExp '*' UnaryExp {
    shared_ptr<MulExp> mulExp = make_shared<MulExp>();
    mulExp->mulExpType = MulExpType::MulUnaryExp;
    mulExp->mul_exp = shared_ptr<MulExp>((MulExp* )$1);
    mulExp->op = $2;
    mulExp->unary_exp = shared_ptr<UnaryExp>((UnaryExp* )$3);
    $$ = mulExp.get();
}
| MulExp '/' UnaryExp {
    shared_ptr<MulExp> mulExp = make_shared<MulExp>();
    mulExp->mulExpType = MulExpType::MulUnaryExp;
    mulExp->mul_exp = shared_ptr<MulExp>((MulExp* )$1);
    mulExp->op = $2;
    mulExp->unary_exp = shared_ptr<UnaryExp>((UnaryExp* )$3);
    $$ = mulExp.get();
}
| MulExp '%' UnaryExp {
    shared_ptr<MulExp> mulExp = make_shared<MulExp>();
    mulExp->mulExpType = MulExpType::MulUnaryExp;
    mulExp->mul_exp = shared_ptr<MulExp>((MulExp* )$1);
    mulExp->op = $2;
    mulExp->unary_exp = shared_ptr<UnaryExp>((UnaryExp* )$3);
    $$ = mulExp.get();
}

AddExp
: MulExp {
    shared_ptr<AddExp> addExp = make_shared<AddExp>();
    addExp->addExpType = AddExpType::MulExp;
    addExp->mul_exp = shared_ptr<MulExp>((MulExp* )$1);
    $$ = addExp.get();
}
| AddExp '+' MulExp {
    shared_ptr<AddExp> addExp = make_shared<AddExp>();
    addExp->addExpType = AddExpType::AddMulExp;
    addExp->add_exp = shared_ptr<AddExp>((AddExp* )$1);
    addExp->op = $2;
    addExp->mul_exp = shared_ptr<MulExp>((MulExp* )$3);
    $$ = addExp.get();
}
| AddExp '-' MulExp {
    shared_ptr<AddExp> addExp = make_shared<AddExp>();
    addExp->addExpType = AddExpType::AddMulExp;
    addExp->add_exp = shared_ptr<AddExp>((AddExp* )$1);
    addExp->op = $2;
    addExp->mul_exp = shared_ptr<MulExp>((MulExp* )$3);
    $$ = addExp.get();
}

RelExp
: AddExp {
    shared_ptr<RelExp> relExp = make_shared<RelExp>();
    relExp->relExpType = RelExpType::AddExp;
    relExp->add_exp = shared_ptr<AddExp>((AddExp* )$1);
    $$ = relExp.get();
}
| RelExp '<' AddExp {
    shared_ptr<RelExp> relExp = make_shared<RelExp>();
    relExp->relExpType = RelExpType::RelAddExp;
    relExp->relExp = shared_ptr<RelExp>((RelExp* )$1);
    relExp->op = $2;
    relExp->add_exp = shared_ptr<AddExp>((AddExp* )$3);
    $$ = relExp.get();
}
| RelExp '>' AddExp {
    shared_ptr<RelExp> relExp = make_shared<RelExp>();
    relExp->relExpType = RelExpType::RelAddExp;
    relExp->relExp = shared_ptr<RelExp>((RelExp* )$1);
    relExp->op = $2;
    relExp->add_exp = shared_ptr<AddExp>((AddExp* )$3);
    $$ = relExp.get();
}
| RelExp LE AddExp {
    shared_ptr<RelExp> relExp = make_shared<RelExp>();
    relExp->relExpType = RelExpType::RelAddExp;
    relExp->relExp = shared_ptr<RelExp>((RelExp* )$1);
    relExp->op = "<=";
    relExp->add_exp = shared_ptr<AddExp>((AddExp* )$3);
    $$ = relExp.get();
}
| RelExp GE AddExp {
    shared_ptr<RelExp> relExp = make_shared<RelExp>();
    relExp->relExpType = RelExpType::RelAddExp;
    relExp->relExp = shared_ptr<RelExp>((RelExp* )$1);
    relExp->op = ">=";
    relExp->add_exp = shared_ptr<AddExp>((AddExp* )$3);
    $$ = relExp.get();
}

EqExp
: RelExp {
    shared_ptr<EqExp> eqExp = make_shared<EqExp>();
    eqExp->eqExpType = EqExpType::RelExp;
    eqExp->relExp = shared_ptr<RelExp>((RelExp* )$1);
    $$ = eqExp.get();
}
| EqExp EQ RelExp {
    shared_ptr<EqExp> eqExp = make_shared<EqExp>();
    eqExp->eqExpType = EqExpType::EqRelExp;
    eqExp->eqExp = shared_ptr<EqExp>((EqExp* )$1);
    eqExp->op = "==";
    eqExp->relExp = shared_ptr<RelExp>((RelExp* )$3);
    $$ = eqExp.get();
}
| EqExp NE RelExp {
    shared_ptr<EqExp> eqExp = make_shared<EqExp>();
    eqExp->eqExpType = EqExpType::EqRelExp;
    eqExp->eqExp = shared_ptr<EqExp>((EqExp* )$1);
    eqExp->op = "!=";
    eqExp->relExp = shared_ptr<RelExp>((RelExp* )$3);
    $$ = eqExp.get();
}

LAndExp
: EqExp {
    shared_ptr<LAndExp> lAndExp = make_shared<LAndExp>();
    lAndExp->lAndExpType = LAndExpType::EqExp;
    lAndExp->eqExp = shared_ptr<EqExp>((EqExp* )$1);
    $$ = lAndExp.get();
}
| LAndExp LAND EqExp {
    shared_ptr<LAndExp> lAndExp = make_shared<LAndExp>();
    lAndExp->lAndExpType = LAndExpType::LAndEqExp;
    lAndExp->lAndExp = shared_ptr<LAndExp>((LAndExp* )$1);
    lAndExp->eqExp = shared_ptr<EqExp>((EqExp* )$3);
    $$ = lAndExp.get();
}

LOrExp
: LAndExp {
    shared_ptr<LOrExp> lOrExp = make_shared<LOrExp>();
    lOrExp->lOrExpType = LOrExpType::LAndExp;
    lOrExp->lAndExp = shared_ptr<LAndExp>((LAndExp* )$1);
    $$ = lOrExp.get();
}
| LOrExp LOR LAndExp {
    shared_ptr<LOrExp> lOrExp = make_shared<LOrExp>();
    lOrExp->lOrExpType = LOrExpType::LOrLAndExp;
    lOrExp->lOrExp = shared_ptr<LOrExp>((LOrExp* )$1);
    lOrExp->lAndExp = shared_ptr<LAndExp>((LAndExp* )$3);
    $$ = lOrExp.get();
}


%%

void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
}

int main()
{
    freopen("input.sy", "r", stdin);
    freopen("output.txt", "w", stdout);
    yyparse();
    fclose(stdin);
    fclose(stdout);
    return 0;
}

