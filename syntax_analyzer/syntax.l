%option noyywrap

%{

#include<stdio.h>
#include<stdlib.h>
#include<string>
#include "syntax.tab.h"

using std::string;

%}

letter [a-zA-Z]

digit [0-9]
binary_digit [01]
hex_digit [0-9a-fA-F]

deci_num [1-9][0-9]*
binary_num (0[b]){binary_digit}+
octal_num 0[0-7]*
hex_num (0[xX]){hex_digit}+

id (\_)*{letter}(\_)*({letter}|{digit})*

blank [ \t]
line_break [\n]+

comment_line \/\/[^\n]*
comment_block \/\*([^*]|\*[^/])*\*\/

STRING_LITERAL \"([^\\"]|\\.)*\"

FILE_NAME [a-zA-Z_\-\.]+

%%

"#include" {
    yylval.sval = new string(yytext);
    return INCLUDE;
}

"int" {
    return INT;
}

"void" {
    return VOID;
}

"if" {
    return IF;
}

"else" {
    return ELSE;
}

"while" {
    return WHILE;
}

"return" {
    return RETURN;
}

"break" {
    return BREAK;
}

"continue" {
    return CONTINUE;
}

"const" {
    return CONST;
}

"==" {
    return EQ;
}

"!=" {
    return NE;
}

"<=" {
    return LE;
}

">=" {
    return GE;
}

"&&" {
    return LAND;
}

"||" {
    return LOR;
}

"(" {
    return LPAREN;
}

")" {
    return RPAREN;
}

"[" {
    return LEFTSQB;
}

"]" {
    return RIGHTSQB;
}

"{" {
    return LEFTBRACE;
}

"}" {
    return RIGHTBRACE;
}

"-" {
    return MINUS;
}

{STRING_LITERAL} {
    yytext[strlen(yytext) - 1] = '\0';
    yylval.sval = new string(yytext + 1);
    return STRING;
}

{id} {
    yylval.sval = new string(yytext);
    return IDENT;
}

{deci_num} {
    yylval.ival = strtol(yytext, nullptr, 10);
    return INTCONST;
}

{binary_num} {
    yylval.ival = strtol(yytext, nullptr, 2);
    return INTCONST;
}

{octal_num} {
    yylval.ival = strtol(yytext, nullptr, 8);
    return INTCONST;
}

{hex_num} {
    yylval.ival = strtol(yytext, nullptr, 16);
    return INTCONST;
}

{FILE_NAME} {
    yylval.sval = new string(yytext);
    return FILE_NAME;
}

{blank} {}

{comment_line} {}

{comment_block} {}

{line_break} {}

"\r\n" {}

. {
    return yytext[0];
}

%%
