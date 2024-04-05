%{

#include <stdio.h>
#include <string>

int yylex(void);
void yyerror(const char *s);

%}

%union {
    int ival;
    char chval;
    std::string sval;
}

%start CompUnit

%token <sval>CONST INT IF ELSE WHILE BREAK CONTINUE RETURN IDENT VOID
%token <ival>INTCONST
%token <chval>LEFTSQB RIGHTSQB LPAREN RPAREN LEFTBRACE RIGHTBRACE
%token <chval>'+' '-' '*' '/' '%' '<' '>' '!' ',' ';' '='
%token <sval>LE GE EQ NE LOR LAND

%type <sval>Decl ConstDecl VarDecl ConstDef ConstDefList VarDef VarDefList ConstInitVal InitVal ConstInitValList InitValList
%type <sval>Exp ExpSQBList ConstExp ConstExpSQBList AddExp LOrExp PrimaryExp UnaryExp UnaryOp MulExp RelExp EqExp LAndExp
%type <sval>FuncDef FuncType FuncFParam FuncFParams FuncRParams
%type <sval>Block BlockItem BlockItemList Stmt LVal Cond

%type <sval>CompList DecOrDef VarType

%left LOR
%left LAND
%left EQ NE
%left '<' '>' LE GE
%left '+' '-'
%left '*' '/' '%'
%right '!'

%%

CompUnit
: CompList {}

CompList
: DecOrDef {}
| CompList DecOrDef {}

DecOrDef
: Decl {}
| FuncDef {}

Decl
: ConstDecl {}
| VarDecl {}

ConstDecl
: CONST VarType ConstDefList ';' {}

ConstDefList
: ConstDef {}
| ConstDef ',' ConstDefList {}

ConstDef
: IDENT '=' ConstInitVal {}
| IDENT ConstExpSQBList '=' ConstInitVal {}

ConstInitVal
: ConstExp {}
| LEFTBRACE RIGHTBRACE {}
| LEFTBRACE ConstInitValList RIGHTBRACE {}

ConstInitValList
: ConstInitVal {}
| ConstInitValList ',' ConstInitVal {}

VarDecl
: FuncType VarDefList ';' {}

VarDefList
: VarDef {}
| VarDef ',' VarDefList {}

VarDef
: IDENT {}
| IDENT '=' InitVal {}
| IDENT ConstExpSQBList {}
| IDENT ConstExpSQBList '=' InitVal {}

ConstExpSQBList
: LEFTSQB ConstExp RIGHTSQB {}
| ConstExpSQBList LEFTSQB ConstExp RIGHTSQB {}

InitVal
: Exp {}
| LEFTBRACE RIGHTBRACE {}
| LEFTBRACE InitValList RIGHTBRACE {}

InitValList
: InitVal {}
| InitValList ',' InitVal {}

FuncDef
: FuncType IDENT LPAREN RPAREN Block {}
| FuncType IDENT LPAREN FuncFParams RPAREN Block {}

VarType
: INT {}

FuncType
: VOID {}
| INT {}

FuncFParams
: FuncFParam {}
| FuncFParam ',' FuncFParams {}


FuncFParam
: VarType IDENT {}
| VarType IDENT LEFTSQB RIGHTSQB {}
| VarType IDENT LEFTSQB RIGHTSQB ExpSQBList {}

ExpSQBList
: LEFTSQB Exp RIGHTSQB {}
| ExpSQBList LEFTSQB Exp RIGHTSQB {}

Block
: LEFTBRACE BlockItemList RIGHTBRACE {}

BlockItemList
: BlockItem BlockItemList {}
| /*empty*/ {}

BlockItem
: Decl {}
| Stmt {}

Stmt
: LVal '=' Exp ';' {}
| ';' {}
| Exp ';' {}
| Block {}
| IF LPAREN Cond RPAREN Stmt {}
| IF LPAREN Cond RPAREN Stmt ELSE Stmt {}
| WHILE LPAREN Cond RPAREN Stmt {}
| BREAK ';' {}
| CONTINUE ';' {}
| RETURN ';' {}
| RETURN Exp ';' {}

ConstExp
: Exp {}

Exp
: AddExp {}

Cond
: LOrExp {}

LVal
: IDENT {}
| IDENT ExpSQBList {}

PrimaryExp
: LPAREN Exp RPAREN {}
| LVal {}
| INTCONST {}

UnaryExp
: PrimaryExp {}
| IDENT LPAREN RPAREN {}
| IDENT LPAREN FuncRParams RPAREN {} // function call
| UnaryOp UnaryExp {}

UnaryOp
: '+' {}
| '-' {}
| '!' {}

FuncRParams
: Exp {}
| Exp ',' FuncRParams {}

MulExp
: UnaryExp {}
| MulExp '*' UnaryExp {}
| MulExp '/' UnaryExp {}
| MulExp '%' UnaryExp {}

AddExp
: MulExp {}
| AddExp '+' MulExp {}
| AddExp '-' MulExp {}

RelExp
: AddExp {}
| RelExp '<' AddExp {}
| RelExp '>' AddExp {}
| RelExp LE AddExp {}
| RelExp GE AddExp {}

EqExp
: RelExp {}
| EqExp EQ RelExp {}
| EqExp NE RelExp {}

LAndExp
: EqExp {}
| LAndExp LAND EqExp {}

LOrExp
: LAndExp {}
| LOrExp LOR LAndExp {}


%%
