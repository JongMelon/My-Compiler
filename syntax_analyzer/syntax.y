%{

#include <stdio.h>

int yylex(void);
void yyerror(const char *s);

%}

%start CompUnit

%token CONST VALTPYE INTCONST IF ELSE WHILE BREAK CONTINUE RETURN LEFTSQB RIGHTSQB LPAREN RPAREN LEFTBRACE RIGHTBRACE IDENT
%token '+' '-' '*' '/' '%' '<' '>' LE GE EQ NE LOR LAND '!' ',' ';' '='

%type Decl ConstDecl VarDecl ConstDef ConstDefList VarDef VarDefList ConstInitVal InitVal ConstInitValList InitValList
%type Exp ExpList ExpSQBList ConstExp ConstExpSQBList AddExp LOrExp PrimaryExp UnaryExp UnaryOp MulExp RelExp EqExp LAndExp
%type FuncDef FuncType FuncFParam FuncFParams FuncFParamList FuncRParams
%type Block BlockItem BlockItemList Stmt LVal Cond

%%

CompUnit
: CompUnit Decl {}
| Decl {}
| CompUnit FuncDef {}
| FuncDef {}

Decl
: ConstDecl {}
| VarDecl {}

ConstDecl
: CONST VALTPYE ConstDef ConstDefList ';' {}

ConstDefList
: ConstDefList ',' ConstDef {}
| /*empty*/ {}

ConstDef
: IDENT ConstExpSQBList '=' ConstInitVal {}

ConstInitVal
: ConstExp {}
| LEFTBRACE RIGHTBRACE {}
| LEFTBRACE ConstInitVal ConstInitValList RIGHTBRACE {}

ConstInitValList
: ConstInitValList ',' ConstInitVal {}
| /*empty*/ {}

VarDecl
: VALTPYE VarDef VarDefList ';' {}

VarDefList
: VarDefList ',' VarDef {}
| /*empty*/ {}

VarDef
: IDENT ConstExpSQBList {}
| IDENT ConstExpSQBList '=' InitVal {}

ConstExpSQBList
: ConstExpSQBList LEFTSQB ConstExp RIGHTSQB {}
| /*empty*/ {}

InitVal
: Exp {}
| LEFTBRACE RIGHTBRACE {}
| LEFTBRACE InitVal InitValList RIGHTBRACE {}

InitValList
: InitValList ',' InitVal {}
| /*empty*/ {}

FuncDef
: FuncType IDENT LPAREN RPAREN Block {}
| FuncType IDENT LPAREN FuncFParams RPAREN Block {}

FuncType
: 'void' {}
| VALTPYE {}

FuncFParams
: FuncFParam FuncFParamList {}

FuncFParamList
: ',' FuncFParam {}
| /*empty*/ {}

FuncFParam
: VALTPYE IDENT {}
| VALTPYE IDENT LEFTSQB RIGHTSQB ExpSQBList {}

ExpSQBList
: ExpSQBList LEFTSQB Exp RIGHTSQB {}
| /*empty*/ {}

Block
: LEFTBRACE BlockItemList RIGHTBRACE {}

BlockItemList
: BlockItemList BlockItem {}
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

Exp
: AddExp {}

Cond
: LOrExp {}

LVal
: IDENT ExpSQBList {}

PrimaryExp
: LPAREN Exp RPAREN {}
| LVal {}
| INTCONST {}

UnaryExp
: PrimaryExp {}
| IDENT LPAREN RPAREN {}
| IDENT LPAREN FuncRParams RPAREN {}
| UnaryOp UnaryExp {}

UnaryOp
: '+' {}
| '-' {}
| '!' {}

FuncRParams
: Exp ExpList {}

ExpList
: ExpList ',' Exp {}
| /*empty*/ {}

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

ConstExp
: AddExp {}

%%
