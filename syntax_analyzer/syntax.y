%{

#include <stdio.h>

int yylex(void);
void yyerror(const char *s);

%}

%start CompUnit

%token CONST VALTPYE FUCTIONTYPE IF ELSE WHILE BREAK RETURN
