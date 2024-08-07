%code requires {
    #include "ASM.h"
}

%{

#include <stdio.h>
#include <string>
//#include "Tree.h"
#include "ASM.h"

int yylex(void);
void yyerror(const char *s);

// default file name
string file_name = "assembly.s";

%}

%union {
    int ival;
    char chval;
    std::string* sval;
    Tree* tree;
}

%start CompUnit

%token <sval>CONST INT IF ELSE WHILE BREAK CONTINUE RETURN IDENT VOID STRING INCLUDE FILE_NAME
%token <ival>INTCONST
%token <chval>LEFTSQB RIGHTSQB LPAREN RPAREN LEFTBRACE RIGHTBRACE
%token <chval>'+' '*' '/' '%' '<' '>' '!' ',' ';' '='
%token <chval>MINUS
%token <sval>LE GE EQ NE LOR LAND

%type <tree> CompUnit
%type <tree>Decl ConstDecl VarDecl ConstDef ConstDefList VarDef VarDefList ConstInitVal InitVal ConstInitValList InitValList
%type <tree>Exp ArrayIndex ConstExp ConstArrayIndex AddExp LOrExp PrimaryExp UnaryExp MulExp RelExp EqExp LAndExp
%type <tree>FuncDef FuncType FuncFParam FuncFParamList FuncRParamList
%type <tree>Block BlockItem BlockItemList Stmt LVal Cond

%type <tree>CompList DecOrDef VarType

%type <sval>INCLUDE_STMT

%type <chval>UnaryOp

%left LOR
%left LAND
%left EQ NE
%left '<' '>' LE GE
%left '+' MINUS
%left '*' '/' '%'
%right '!'

%%

CompUnit
: INCLUDE_STMT CompList {
    auto compUnit = new CompUnit();
    compUnit->compList = shared_ptr<CompList>((CompList* )$2);
    $$ = compUnit;
    std::cout << "digraph \" \"{" << std::endl;
    std::cout << "node [shape = record,height=.1]" << std::endl;
    compUnit->print(0, "");
    std::cout << "}" << std::endl;

    auto Code_Generator = new CodeGenerator();
    Code_Generator->dump(shared_ptr<CompUnit>(compUnit), file_name);
}

CompList
: DecOrDef {
    auto compList = new CompList();
    compList->declOrDef = shared_ptr<DeclOrDef>((DeclOrDef* )$1);
    compList->declOrDefs.push_back(compList->declOrDef);
    $$ = compList;
}
| CompList DecOrDef {
    auto compList = new CompList();
    compList->if_more_CompList = true;
    compList->compList = shared_ptr<CompList>((CompList* )$1);
    compList->declOrDef = shared_ptr<DeclOrDef>((DeclOrDef* )$2);

    compList->declOrDefs = compList->compList->declOrDefs;
    compList->declOrDefs.push_back(compList->declOrDef);

    $$ = compList;
}

DecOrDef
: Decl {
    auto decOrDef = new DeclOrDef();
    decOrDef->if_decl = true;
    decOrDef->decl = shared_ptr<Decl>((Decl* )$1);
    $$ = decOrDef;
}
| FuncDef {
    auto decOrDef = new DeclOrDef();
    decOrDef->funcDef = shared_ptr<FuncDef>((FuncDef* )$1);
    $$ = decOrDef;
}

Decl
: ConstDecl {
    auto decl = new Decl();
    decl->decType = DecType::ConstDecl;
    decl->constDecl = shared_ptr<ConstDecl>((ConstDecl* )$1);
    $$ = decl;
}
| VarDecl {
    auto decl = new Decl();
    decl->decType = DecType::VarDecl;
    decl->varDecl = shared_ptr<VarDecl>((VarDecl* )$1);
    $$ = decl;
}

ConstDecl
: CONST VarType ConstDefList ';' {
    auto constDecl = new ConstDecl();
    constDecl->varType = shared_ptr<VarType>((VarType* )$2);
    constDecl->constDefList = shared_ptr<ConstDefList>((ConstDefList* )$3);
    $$ = constDecl;
}
| CONST VarType IDENT ';' {
    fprintf(stderr, "Error: Unknown constdeflist\n");
    auto constDecl = new ConstDecl();
    constDecl->err_empty = true;
    $$ = constDecl;
}

ConstDefList
: ConstDef {
    auto constDefList = new ConstDefList();
    constDefList->constDef = shared_ptr<ConstDef>((ConstDef* )$1);
    constDefList->constdefs.push_back(constDefList->constDef);
    $$ = constDefList;
}
| ConstDefList ',' ConstDef {
    auto constDefList = new ConstDefList();
    constDefList->constDef = shared_ptr<ConstDef>((ConstDef* )$3);
    constDefList->constDefList = shared_ptr<ConstDefList>((ConstDefList* )$1);

    constDefList->constdefs = constDefList->constDefList->constdefs;
    constDefList->constdefs.push_back(constDefList->constDef);

    $$ = constDefList;
}

ConstDef
: IDENT '=' ConstInitVal {
    auto constDef = new ConstDef();
    constDef->varKind = VarKind::Var;
    constDef->ident = *($1);
    constDef->constInitVal = shared_ptr<ConstInitVal>((ConstInitVal* )$3);
    $$ = constDef;
}
| IDENT ConstArrayIndex '=' InitVal {
    auto constDef = new ConstDef();
    constDef->varKind = VarKind::Array;
    constDef->ident = *($1);
    constDef->constArrayIndex = shared_ptr<ConstArrayIndex>((ConstArrayIndex* )$2);
    constDef->array_initval = shared_ptr<InitVal>((InitVal* )$4);
    $$ = constDef;
}
/*| IDENT ConstArrayIndex '=' ConstInitVal {
    auto constDef = new ConstDef();
    constDef->varKind = VarKind::Array;
    constDef->ident = *($1);
    constDef->constArrayIndex = shared_ptr<ConstArrayIndex>((ConstArrayIndex* )$2);
    constDef->constInitVal = shared_ptr<ConstInitVal>((ConstInitVal* )$4);
    $$ = constDef;
}*/

ConstInitVal
: ConstExp {
    auto constInitVal = new ConstInitVal();
    constInitVal->constExp = shared_ptr<ConstExp>((ConstExp* )$1);
    $$ = constInitVal;
}
| LEFTBRACE RIGHTBRACE {
    auto constInitVal = new ConstInitVal();
    constInitVal->varKind = VarKind::Array;
    $$ = constInitVal;
}
| LEFTBRACE ConstInitValList RIGHTBRACE {
    auto constInitVal = new ConstInitVal();
    constInitVal->varKind = VarKind::Array;
    constInitVal->constInitValList = shared_ptr<ConstInitValList>((ConstInitValList* )$2);
    $$ = constInitVal;
}

ConstInitValList
: ConstInitVal {
    auto constInitValList = new ConstInitValList();
    constInitValList->constInitVal = shared_ptr<ConstInitVal>((ConstInitVal* )$1);
    $$ = constInitValList;
}
| ConstInitVal ',' ConstInitValList {
    auto constInitValList = new ConstInitValList();
    constInitValList->constInitVal = shared_ptr<ConstInitVal>((ConstInitVal* )$1);
    constInitValList->constInitValList = shared_ptr<ConstInitValList>((ConstInitValList* )$3);
    $$ = constInitValList;
}

VarDecl
: FuncType VarDefList ';' {
    auto varDecl = new VarDecl();
    varDecl->varDefList = shared_ptr<VarDefList>((VarDefList* )$2);
    varDecl->vardefs = varDecl->varDefList->vardefs;
    $$ = varDecl;
}
| error VarDefList ';' {
    fprintf(stderr, "Error: Unknown VarType\n");
    auto varDecl = new VarDecl();
    varDecl->varDefList = shared_ptr<VarDefList>((VarDefList* )$2);
    varDecl->unknownType = true;
    $$ = varDecl;
}

VarDefList
: VarDef {
    auto varDefList = new VarDefList();
    varDefList->varDef = shared_ptr<VarDef>((VarDef* )$1);
    varDefList->vardefs.push_back(varDefList->varDef);
    $$ = varDefList;
}
| VarDefList ',' VarDef {
    auto varDefList = new VarDefList();
    varDefList->varDef = shared_ptr<VarDef>((VarDef* )$3);
    varDefList->varDefList = shared_ptr<VarDefList>((VarDefList* )$1);

    varDefList->vardefs = varDefList->varDefList->vardefs;
    varDefList->vardefs.push_back(varDefList->varDef);
    $$ = varDefList;
}

VarDef
: IDENT {
    auto varDef = new VarDef();
    varDef->varKind = VarKind::Var;
    varDef->ident = *($1);
    $$ = varDef;
}
| IDENT '=' InitVal {
    auto varDef = new VarDef();
    varDef->varKind = VarKind::Var;
    varDef->ident = *($1);
    varDef->initVal = shared_ptr<InitVal>((InitVal* )$3);
    $$ = varDef;
}
| IDENT ConstArrayIndex {
    auto varDef = new VarDef();
    varDef->varKind = VarKind::Array;
    varDef->ident = *($1);
    varDef->constArrayIndex = shared_ptr<ConstArrayIndex>((ConstArrayIndex* )$2);
    $$ = varDef;
}
| IDENT ConstArrayIndex '=' InitVal {
    auto varDef = new VarDef();
    varDef->varKind = VarKind::Array;
    varDef->ident = *($1);
    varDef->constArrayIndex = shared_ptr<ConstArrayIndex>((ConstArrayIndex* )$2);
    varDef->initVal = shared_ptr<InitVal>((InitVal* )$4);
    $$ = varDef;
}
| INTCONST IDENT {
    fprintf(stderr, "Error: Invaild ident name\n");
    auto varDef = new VarDef();
    varDef->varKind = VarKind::Var;
    varDef->ident = *($2);
    $$ = varDef;
}
| INTCONST IDENT '=' InitVal {
    fprintf(stderr, "Error: Invaild ident name\n");
    auto varDef = new VarDef();
    varDef->varKind = VarKind::Var;
    varDef->ident = *($2);
    varDef->initVal = shared_ptr<InitVal>((InitVal* )$4);
    $$ = varDef;
}
| INTCONST IDENT ConstArrayIndex {
    fprintf(stderr, "Error: Invaild ident name\n");
    auto varDef = new VarDef();
    varDef->varKind = VarKind::Array;
    varDef->ident = *($2);
    varDef->constArrayIndex = shared_ptr<ConstArrayIndex>((ConstArrayIndex* )$3);
    $$ = varDef;
}
| INTCONST IDENT ConstArrayIndex '=' InitVal {
    fprintf(stderr, "Error: Invaild ident name\n");
    auto varDef = new VarDef();
    varDef->varKind = VarKind::Array;
    varDef->ident = *($2);
    varDef->constArrayIndex = shared_ptr<ConstArrayIndex>((ConstArrayIndex* )$3);
    varDef->initVal = shared_ptr<InitVal>((InitVal* )$5);
    $$ = varDef;
}

ConstArrayIndex
: LEFTSQB ConstExp RIGHTSQB {
    auto constArrayIndex = new ConstArrayIndex();
    constArrayIndex->const_exp = shared_ptr<ConstExp>((ConstExp* )$2);
    constArrayIndex->const_exps.push_back(constArrayIndex->const_exp);
    $$ = constArrayIndex;
}
| ConstArrayIndex LEFTSQB ConstExp RIGHTSQB {
    auto constArrayIndex = new ConstArrayIndex();
    constArrayIndex->constArrayIndex = shared_ptr<ConstArrayIndex>((ConstArrayIndex* )$1);
    constArrayIndex->const_exp = shared_ptr<ConstExp>((ConstExp* )$3);
    constArrayIndex->const_exps = constArrayIndex->constArrayIndex->const_exps;
    constArrayIndex->const_exps.push_back(constArrayIndex->const_exp);
    $$ = constArrayIndex;
}

InitVal
: Exp {
    auto initVal = new InitVal();
    initVal->varKind = VarKind::Var;
    initVal->exp = shared_ptr<Exp>((Exp* )$1);
    $$ = initVal;
}
| LEFTBRACE RIGHTBRACE {
    auto initVal = new InitVal();
    initVal->varKind = VarKind::Array;
    $$ = initVal;
}
| LEFTBRACE InitValList RIGHTBRACE {
    auto initVal = new InitVal();
    initVal->varKind = VarKind::Array;
    initVal->initValList = shared_ptr<InitValList>((InitValList* )$2);
    $$ = initVal;
}

InitValList
: InitVal {
    auto initValList = new InitValList();
    initValList->initVal = shared_ptr<InitVal>((InitVal* )$1);

    initValList->initVals.push_back(initValList->initVal);

    $$ = initValList;
}
| InitValList ',' InitVal {
    auto initValList = new InitValList();
    initValList->initVal = shared_ptr<InitVal>((InitVal* )$3);
    initValList->initValList = shared_ptr<InitValList>((InitValList* )$1);

    initValList->initVals = initValList->initValList->initVals;
    initValList->initVals.push_back(initValList->initVal);

    $$ = initValList;
}

FuncDef
: FuncType IDENT LPAREN RPAREN Block {
    auto funcDef = new FuncDef();
    funcDef->funcType = shared_ptr<FuncType>((FuncType* )$1);
    funcDef->ident = *($2);
    funcDef->block = shared_ptr<Block>((Block* )$5);
    $$ = funcDef;
}
| FuncType IDENT LPAREN FuncFParamList RPAREN Block {
    auto funcDef = new FuncDef();
    funcDef->funcType = shared_ptr<FuncType>((FuncType* )$1);
    funcDef->ident = *($2);
    funcDef->funcFParamList = shared_ptr<FuncFParamList>((FuncFParamList* )$4);
    funcDef->block = shared_ptr<Block>((Block* )$6);
    $$ = funcDef;
}
| FuncType IDENT LPAREN error RPAREN Block {
    fprintf(stderr, "Error: Unknown funcfparamlist\n");
    auto funcDef = new FuncDef();
    funcDef->funcType = shared_ptr<FuncType>((FuncType* )$1);
    funcDef->ident = *($2);
    funcDef->block = shared_ptr<Block>((Block* )$6);
    funcDef->err_empty = true;
    $$ = funcDef;
}

VarType
: INT {
    auto varType = new VarType();
    varType->type = "int";
    $$ = varType;
}

FuncType
: VOID {
    auto funcType = new FuncType();
    funcType->type = "void";
    $$ = funcType;
}
| INT {
    auto funcType = new FuncType();
    funcType->type = "int";
    $$ = funcType;
}

FuncFParamList
: FuncFParam {
    auto funcFParamList = new FuncFParamList();
    funcFParamList->funcFParam = shared_ptr<FuncFParam>((FuncFParam* )$1);

    funcFParamList->funcFParams.push_back(funcFParamList->funcFParam);

    $$ = funcFParamList;
}
| FuncFParamList ',' FuncFParam {
    auto funcFParamList = new FuncFParamList();
    funcFParamList->funcFParam = shared_ptr<FuncFParam>((FuncFParam* )$3);
    funcFParamList->funcFParamList = shared_ptr<FuncFParamList>((FuncFParamList* )$1);

    funcFParamList->funcFParams = funcFParamList->funcFParamList->funcFParams;
    funcFParamList->funcFParams.push_back(funcFParamList->funcFParam);

    $$ = funcFParamList;
}

FuncFParam
: VarType IDENT {
    auto funcFParam = new FuncFParam();
    funcFParam->varKind = VarKind::Var;
    funcFParam->varType = shared_ptr<VarType>((VarType* )$1);
    funcFParam->ident = *($2);
    $$ = funcFParam;
}
| VarType IDENT LEFTSQB RIGHTSQB {
    auto funcFParam = new FuncFParam();
    funcFParam->varKind = VarKind::Array;
    funcFParam->varType = shared_ptr<VarType>((VarType* )$1);
    funcFParam->ident = *($2);
    $$ = funcFParam;
}
| VarType IDENT LEFTSQB RIGHTSQB ArrayIndex {
    auto funcFParam = new FuncFParam();
    funcFParam->varKind = VarKind::Array;
    funcFParam->varType = shared_ptr<VarType>((VarType* )$1);
    funcFParam->ident = *($2);
    funcFParam->arrayIndex = shared_ptr<ArrayIndex>((ArrayIndex* )$5);
    $$ = funcFParam;
}
| VarType IDENT LEFTSQB error RIGHTSQB {
    fprintf(stderr, "Error: Unknown function param\n");
    auto funcFParam = new FuncFParam();
    funcFParam->varKind = VarKind::Var;
    funcFParam->varType = shared_ptr<VarType>((VarType* )$1);
    funcFParam->ident = *($2);
    funcFParam->err_empty = true;
    $$ = funcFParam;
}

ArrayIndex
: LEFTSQB Exp RIGHTSQB {
    auto arrayIndex = new ArrayIndex();
    arrayIndex->exp = shared_ptr<Exp>((Exp* )$2);
    arrayIndex->exps.push_back(arrayIndex->exp);
    $$ = arrayIndex;
}
| ArrayIndex LEFTSQB Exp RIGHTSQB {
    auto arrayIndex = new ArrayIndex();
    arrayIndex->arrayIndex = shared_ptr<ArrayIndex>((ArrayIndex* )$1);
    arrayIndex->exp = shared_ptr<Exp>((Exp* )$3);
    arrayIndex->exps = arrayIndex->arrayIndex->exps;
    arrayIndex->exps.push_back(arrayIndex->exp);
    $$ = arrayIndex;
}

Block
: LEFTBRACE RIGHTBRACE {
    auto block = new Block();
    $$ = block;
}
| LEFTBRACE BlockItemList RIGHTBRACE {
    auto block = new Block();
    block->blockItemList = shared_ptr<BlockItemList>((BlockItemList* )$2);
    $$ = block;
}

BlockItemList
: BlockItem {
    auto blockItemList = new BlockItemList();
    blockItemList->blockItem = shared_ptr<BlockItem>((BlockItem* )$1);

    blockItemList->blockItems.push_back(blockItemList->blockItem);

    $$ = blockItemList;
}
| BlockItemList BlockItem {
    auto blockItemList = new BlockItemList();
    blockItemList->blockItem = shared_ptr<BlockItem>((BlockItem* )$2);
    blockItemList->blockItemList = shared_ptr<BlockItemList>((BlockItemList* )$1);

    blockItemList->blockItems = blockItemList->blockItemList->blockItems;
    blockItemList->blockItems.push_back(blockItemList->blockItem);

    $$ = blockItemList;
}

BlockItem
: Decl {
    auto blockItem = new BlockItem();
    blockItem->blockItemType = BlockItemType::Decl;
    blockItem->decl = shared_ptr<Decl>((Decl* )$1);
    $$ = blockItem;
}
| Stmt {
    auto blockItem = new BlockItem();
    blockItem->blockItemType = BlockItemType::Stmt;
    blockItem->stmt = shared_ptr<Stmt>((Stmt* )$1);
    $$ = blockItem;
}

Stmt
: LVal '=' Exp ';' {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::Assign;
    stmt->lVal = shared_ptr<LVal>((LVal* )$1);
    stmt->exp = shared_ptr<Exp>((Exp* )$3);
    $$ = stmt;
}
| ';' {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::Empty;
    $$ = stmt;
}
| Exp ';' {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::Exp;
    stmt->exp = shared_ptr<Exp>((Exp* )$1);
    $$ = stmt;
}
| Block {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::Block;
    stmt->block = shared_ptr<Block>((Block* )$1);
    $$ = stmt;
}
| IF LPAREN Cond RPAREN Stmt {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::If;
    stmt->cond = shared_ptr<Cond>((Cond* )$3);
    stmt->stmt_if = shared_ptr<Stmt>((Stmt* )$5);
    $$ = stmt;
}
| IF LPAREN Cond RPAREN Stmt ELSE Stmt {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::IfElse;
    stmt->cond = shared_ptr<Cond>((Cond* )$3);
    stmt->stmt_if = shared_ptr<Stmt>((Stmt* )$5);
    stmt->stmt_if_else = shared_ptr<Stmt>((Stmt* )$7);
    $$ = stmt;
}
| WHILE LPAREN Cond RPAREN Stmt {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::While;
    stmt->cond = shared_ptr<Cond>((Cond* )$3);
    stmt->stmt_while = shared_ptr<Stmt>((Stmt* )$5);
    $$ = stmt;
}
| BREAK ';' {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::Break;
    $$ = stmt;
}
| CONTINUE ';' {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::Continue;
    $$ = stmt;
}
| RETURN ';' {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::Return;
    $$ = stmt;
}
| RETURN Exp ';' {
    auto stmt = new Stmt();
    stmt->stmtType = StmtType::ReturnExp;
    stmt->exp = shared_ptr<Exp>((Exp* )$2);
    $$ = stmt;
}

ConstExp
: Exp {
    auto constExp = new ConstExp();
    constExp->exp = shared_ptr<Exp>((Exp* )$1);
    $$ = constExp;
}

Exp
: AddExp {
    auto exp = new Exp();
    exp->add_exp = shared_ptr<AddExp>((AddExp* )$1);
    exp->is_const = exp->add_exp->is_const;
    $$ = exp;
}

Cond
: LOrExp {
    auto cond = new Cond();
    cond->lOrExp = shared_ptr<LOrExp>((LOrExp* )$1);
    $$ = cond;
}

LVal
: IDENT {
    auto lVal = new LVal();
    lVal->varKind = VarKind::Var;
    lVal->ident = *($1);
    $$ = lVal;
}
| IDENT ArrayIndex {
    auto lVal = new LVal();
    lVal->varKind = VarKind::Array;
    lVal->ident = *($1);
    lVal->arrayIndex = shared_ptr<ArrayIndex>((ArrayIndex* )$2);
    $$ = lVal;
}

PrimaryExp
: LPAREN Exp RPAREN {
    auto primaryExp = new PrimaryExp();
    primaryExp->primaryExpType = PrimaryExpType::Exp;
    primaryExp->exp = shared_ptr<Exp>((Exp* )$2);
    $$ = primaryExp;
}
| LVal {
    auto primaryExp = new PrimaryExp();
    primaryExp->primaryExpType = PrimaryExpType::LVal;
    primaryExp->lVal = shared_ptr<LVal>((LVal* )$1);
    $$ = primaryExp;
}
| INTCONST {
    auto primaryExp = new PrimaryExp();
    primaryExp->primaryExpType = PrimaryExpType::Number;
    primaryExp->number = $1;
    $$ = primaryExp;
}
| STRING {
    auto primaryExp = new PrimaryExp();
    primaryExp->primaryExpType = PrimaryExpType::String;
    primaryExp->str = *($1);
    $$ = primaryExp;
}

UnaryExp
: PrimaryExp {
    auto unaryExp = new UnaryExp();
    unaryExp->unaryExpType = UnaryExpType::PrimaryExp;
    unaryExp->primary_exp = shared_ptr<PrimaryExp>((PrimaryExp* )$1);
    $$ = unaryExp;
}
| IDENT LPAREN RPAREN {
    auto unaryExp = new UnaryExp();
    unaryExp->unaryExpType = UnaryExpType::FuncCall;
    unaryExp->func_ident = *($1);
    $$ = unaryExp;
}
| IDENT LPAREN FuncRParamList RPAREN {
    auto unaryExp = new UnaryExp();
    unaryExp->unaryExpType = UnaryExpType::FuncCall;
    unaryExp->func_ident = *($1);
    unaryExp->funcRParamList = shared_ptr<FuncRParamList>((FuncRParamList* )$3);
    $$ = unaryExp;
} // function call
| UnaryOp UnaryExp {
    auto unaryExp = new UnaryExp();
    unaryExp->unaryExpType = UnaryExpType::OP_Exp;
    unaryExp->op = $1;
    unaryExp->unary_exp = shared_ptr<UnaryExp>((UnaryExp* )$2);
    $$ = unaryExp;
}
| '&' IDENT {
    auto unaryExp = new UnaryExp();
    unaryExp->unaryExpType = UnaryExpType::OP_Exp;
    unaryExp->op = "&";
    unaryExp->ident = *($2);
    $$ = unaryExp;
}
| '&' IDENT ArrayIndex {
    auto unaryExp = new UnaryExp();
    unaryExp->unaryExpType = UnaryExpType::OP_Exp;
    unaryExp->op = "&";
    unaryExp->ident = *($2);
    unaryExp->ptr_to_array = true;
    unaryExp->arrayIndex = shared_ptr<ArrayIndex>((ArrayIndex* )$3);
    $$ = unaryExp;
}

UnaryOp
: '+' {
    $$ = '+';
}
| MINUS {
    $$ = '-';
}
| '!' {
    $$ = '!';
}

FuncRParamList
: Exp {
    auto funcRParamList = new FuncRParamList();
    funcRParamList->exp = shared_ptr<Exp>((Exp* )$1);
    funcRParamList->exps.push_back(funcRParamList->exp);
    $$ = funcRParamList;
}
| FuncRParamList ',' Exp {
    auto funcRParamList = new FuncRParamList();
    funcRParamList->exp = shared_ptr<Exp>((Exp* )$3);
    funcRParamList->funcRParamList = shared_ptr<FuncRParamList>((FuncRParamList* )$1);
    funcRParamList->exps = funcRParamList->funcRParamList->exps;
    funcRParamList->exps.push_back(funcRParamList->exp);
    $$ = funcRParamList;
}

MulExp
: UnaryExp {
    auto mulExp = new MulExp();
    mulExp->mulExpType = MulExpType::UnaryExp;
    mulExp->unary_exp = shared_ptr<UnaryExp>((UnaryExp* )$1);
    $$ = mulExp;
}
| MulExp '*' UnaryExp {
    auto mulExp = new MulExp();
    mulExp->mulExpType = MulExpType::MulUnaryExp;
    mulExp->mul_exp = shared_ptr<MulExp>((MulExp* )$1);
    mulExp->op = "*";
    mulExp->unary_exp = shared_ptr<UnaryExp>((UnaryExp* )$3);
    $$ = mulExp;
}
| MulExp '/' UnaryExp {
    auto mulExp = new MulExp();
    mulExp->mulExpType = MulExpType::MulUnaryExp;
    mulExp->mul_exp = shared_ptr<MulExp>((MulExp* )$1);
    mulExp->op = "/";
    mulExp->unary_exp = shared_ptr<UnaryExp>((UnaryExp* )$3);
    $$ = mulExp;
}
| MulExp '%' UnaryExp {
    auto mulExp = new MulExp();
    mulExp->mulExpType = MulExpType::MulUnaryExp;
    mulExp->mul_exp = shared_ptr<MulExp>((MulExp* )$1);
    mulExp->op = "%";
    mulExp->unary_exp = shared_ptr<UnaryExp>((UnaryExp* )$3);
    $$ = mulExp;
}

AddExp
: MulExp {
    auto addExp = new AddExp();
    addExp->addExpType = AddExpType::MulExp;
    addExp->mul_exp = shared_ptr<MulExp>((MulExp* )$1);
    $$ = addExp;
}
| AddExp '+' MulExp {
    auto addExp = new AddExp();
    addExp->addExpType = AddExpType::AddMulExp;
    addExp->add_exp = shared_ptr<AddExp>((AddExp* )$1);
    addExp->op = "+";
    addExp->mul_exp = shared_ptr<MulExp>((MulExp* )$3);
    $$ = addExp;
}
| AddExp MINUS MulExp {
    auto addExp = new AddExp();
    addExp->addExpType = AddExpType::AddMulExp;
    addExp->add_exp = shared_ptr<AddExp>((AddExp* )$1);
    addExp->op = "-";
    addExp->mul_exp = shared_ptr<MulExp>((MulExp* )$3);
    $$ = addExp;
}

RelExp
: Exp {
    auto relExp = new RelExp();
    relExp->relExpType = RelExpType::Exp;
    relExp->exp = shared_ptr<Exp>((Exp* )$1);

    relExp->is_exp = true;

    $$ = relExp;
}
| RelExp '<' Exp {
    auto relExp = new RelExp();
    relExp->relExpType = RelExpType::RelExp;
    relExp->relExp = shared_ptr<RelExp>((RelExp* )$1);
    relExp->op = "\\<";
    relExp->exp = shared_ptr<Exp>((Exp* )$3);
    $$ = relExp;
}
| RelExp '<' error {
    fprintf(stderr, "Error: Unknown operator\n");
    auto relExp = new RelExp();
    relExp->relExpType = RelExpType::RelExp;
    relExp->relExp = shared_ptr<RelExp>((RelExp* )$1);
    relExp->op = "\\<";
    relExp->err_empty = true;
    $$ = relExp;

}
| RelExp '>' Exp {
    auto relExp = new RelExp();
    relExp->relExpType = RelExpType::RelExp;
    relExp->relExp = shared_ptr<RelExp>((RelExp* )$1);
    relExp->op = "\\>";
    relExp->exp = shared_ptr<Exp>((Exp* )$3);
    $$ = relExp;
}
| RelExp LE Exp {
    auto relExp = new RelExp();
    relExp->relExpType = RelExpType::RelExp;
    relExp->relExp = shared_ptr<RelExp>((RelExp* )$1);
    relExp->op = "\\<=";
    relExp->exp = shared_ptr<Exp>((Exp* )$3);
    $$ = relExp;
}
| RelExp GE Exp {
    auto relExp = new RelExp();
    relExp->relExpType = RelExpType::RelExp;
    relExp->relExp = shared_ptr<RelExp>((RelExp* )$1);
    relExp->op = "\\>=";
    relExp->exp = shared_ptr<Exp>((Exp* )$3);
    $$ = relExp;
}

EqExp
: RelExp {
    auto eqExp = new EqExp();
    eqExp->eqExpType = EqExpType::RelExp;
    eqExp->relExp = shared_ptr<RelExp>((RelExp* )$1);

    eqExp->is_rel_exp = eqExp->relExp->is_exp;

    $$ = eqExp;
}
| EqExp EQ RelExp {
    auto eqExp = new EqExp();
    eqExp->eqExpType = EqExpType::EqRelExp;
    eqExp->eqExp = shared_ptr<EqExp>((EqExp* )$1);
    eqExp->op = "==";
    eqExp->relExp = shared_ptr<RelExp>((RelExp* )$3);

    eqExp->is_rel_exp = eqExp->relExp->is_exp;

    $$ = eqExp;
}
| EqExp NE RelExp {
    auto eqExp = new EqExp();
    eqExp->eqExpType = EqExpType::EqRelExp;
    eqExp->eqExp = shared_ptr<EqExp>((EqExp* )$1);
    eqExp->op = "!=";

    eqExp->relExp = shared_ptr<RelExp>((RelExp* )$3);
    eqExp->is_rel_exp = eqExp->relExp->is_exp;
    $$ = eqExp;
}

LAndExp
: EqExp {
    auto lAndExp = new LAndExp();
    lAndExp->lAndExpType = LAndExpType::EqExp;
    lAndExp->eqExp = shared_ptr<EqExp>((EqExp* )$1);
    $$ = lAndExp;
}
| LAndExp LAND EqExp {
    auto lAndExp = new LAndExp();
    lAndExp->lAndExpType = LAndExpType::LAndEqExp;
    lAndExp->lAndExp = shared_ptr<LAndExp>((LAndExp* )$1);
    lAndExp->eqExp = shared_ptr<EqExp>((EqExp* )$3);
    $$ = lAndExp;
}

LOrExp
: LAndExp {
    auto lOrExp = new LOrExp();
    lOrExp->lOrExpType = LOrExpType::LAndExp;
    lOrExp->lAndExp = shared_ptr<LAndExp>((LAndExp* )$1);
    $$ = lOrExp;
}
| LOrExp LOR LAndExp {
    auto lOrExp = new LOrExp();
    lOrExp->lOrExpType = LOrExpType::LOrLAndExp;
    lOrExp->lOrExp = shared_ptr<LOrExp>((LOrExp* )$1);
    lOrExp->lAndExp = shared_ptr<LAndExp>((LAndExp* )$3);
    $$ = lOrExp;
}

INCLUDE_STMT
: INCLUDE FILE_NAME {
    //fprintf(stderr, "Error: Include statement is not supported\n");
}

%%

void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(int argc, const char *argv[])
{
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <output_file> <input_file>\n", argv[0]);
        return 1;
    }

    string input_file = argv[2];
    file_name = argv[1];

    std::cerr << "input file: " << input_file << std::endl;
    std::cerr << "output file: " << file_name << std::endl;
    
    freopen(argv[2], "r", stdin);
    freopen("AST.dot", "w", stdout);
    yyparse();
    fclose(stdin);
    fclose(stdout);
    return 0;
}

