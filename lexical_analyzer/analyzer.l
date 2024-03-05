%option noyywrap

%{

#include<stdio.h>
#include<stdlib.h>

int lines = 1;
int columns = 1;

%}

letter [a-zA-Z]

digit [0-9]
binary_digit [01]
hex_digit [0-9a-fA-F]
octal_digit [0-7]

binary_num (0[b]){binary_digit}+
octal_num ^(0){octal_digit}+$
hex_num (0[xX]){hex_digit}+

id (\_)*{letter}(\_)*({letter}|{digit})*

special_char [(),;.:=<>#{}\[\]]
blank [ \t]
calculate_opp [\+\-\*\/]
bit_opp [\&\|\~\^]
line_break [\n]+

comment_line \/\/[^\n]*
comment_block \/\*([^*]|\*[^/])*\*\/

%%

"int"|"void"|"for"|"do"|"while"|"break"|"continue"|"if"|"else"|"goto"|"switch"|"case"|"default"|"const"|"return" {
    int n_col = columns + yyleng;
    //printf("Keyword: %s, line: %d, column: (%d,%d)\n", yytext, lines, columns, n_col);
    printf("%s     %d     (%d,%d)\n", yytext, lines, columns, n_col);
    columns = n_col;
}

{id} {
    int n_col = columns + yyleng;
    //printf("ID: %s, line: %d, column: (%d,%d)\n", yytext, lines, columns, n_col);
    printf("%s     %d     (%d,%d)     Ident\n", yytext, lines, columns, n_col);
    columns = n_col;
}

{digit}+ {
    int n_col = columns + yyleng;
    //printf("NUM: %s, line: %d, column: (%d,%d)\n", yytext, lines, columns, n_col);
    printf("%s     %d     (%d,%d)     IntConst\n", yytext, lines, columns, n_col);
    columns = n_col;
}

{binary_num} {
    int n_col = columns + yyleng;
    //printf("NUM: %s, line: %d, column: (%d,%d)\n", yytext, lines, columns, n_col);
    printf("%s     %d     (%d,%d)     IntConst\n", yytext, lines, columns, n_col);
    columns = n_col;
}

{octal_num} {
    int n_col = columns + yyleng;
    //printf("NUM: %s, line: %d, column: (%d,%d)\n", yytext, lines, columns, n_col);
    printf("%s     %d     (%d,%d)     IntConst\n", yytext, lines, columns, n_col);
    columns = n_col;
}

{hex_num} {
    int n_col = columns + yyleng;
    //printf("NUM: %s, line: %d, column: (%d,%d)\n", yytext, lines, columns, n_col);
    printf("%s     %d     (%d,%d)     IntConst\n", yytext, lines, columns, n_col);
    columns = n_col;
}

{special_char} {
    int n_col = columns + yyleng;
    //printf("SPECIAL_CHAR: %s, line: %d, column: (%d,%d)\n", yytext, lines, columns, n_col);
    printf("%s     %d     (%d,%d)\n", yytext, lines, columns, n_col);
    columns = n_col;
}

{calculate_opp} {
    int n_col = columns + yyleng;
    //printf("CALCULATE_OPP: %s, line: %d, column: (%d,%d)\n", yytext, lines, columns, n_col);
    printf("%s     %d     (%d,%d)\n", yytext, lines, columns, n_col);
    columns = n_col;
}

{blank} {
    columns += yyleng;
}

{bit_opp} {
    int n_col = columns + yyleng;
    //printf("BIT_OPP: %s, line: %d, column: (%d,%d)\n", yytext, lines, columns, n_col);
    printf("%s     %d     (%d,%d)\n", yytext, lines, columns, n_col);
    columns = n_col;
}

"&&"|"||"|"!" {
    int n_col = columns + yyleng;
    //printf("LOGIC_OPP: %s, line: %d, column: (%d,%d)\n", yytext, lines, columns, n_col);
    printf("%s     %d     (%d,%d)\n", yytext, lines, columns, n_col);
    columns = n_col;
}

"==" {
    int n_col = columns + yyleng;
    //printf("EQUAL_OPP: %s, line: %d, column: (%d,%d)\n", yytext, lines, columns, n_col);
    printf("%s     %d     (%d,%d)\n", yytext, lines, columns, n_col);
    columns = n_col;
}

{comment_line} {
    int n_col = columns + yyleng;
    //printf("%s     %d     (%d,%d)\n", yytext, lines, columns, n_col);
    //lines += 1;
    columns = 1;
}

{comment_block} {
    int start_lines = lines;
    int start_columns = columns;
    for (int i = 0; i < yyleng; i++) {
        columns++;
        if (yytext[i] == '\n') {
            lines++;
            columns = 1;
        }
    }
    //printf("/* ... */     %d     (%d,%d)\n", start_lines, start_columns, columns);
}

{line_break} {
    lines += yyleng;
    columns = 1;
}

"\r\n" {
    lines += 1;
    columns = 1;
}

%%

int main(int argc, char *argv[]) {
    for (int i = 1; i <= 6; i++) {
        char file[6];
        file[0] = '0' + i;
        file[1] = '.';
        file[2] = 's';
        file[3] = 'y';
        file[4] = 0;
        file[5] = 0;
        freopen(file, "r", stdin);
        file[2] = 't';
        file[3] = 'x';
        file[4] = 't';
        freopen(file, "w", stdout);
        yyin = stdin;
        yylex();
        //printf("lines = %d\n", lines);
        lines = 1;
        columns = 1;
    }
    return 0;
}