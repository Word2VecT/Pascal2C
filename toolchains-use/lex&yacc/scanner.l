%{
#include <stdio.h>
%}

%%
[a-zA-Z_][a-zA-Z0-9_]*    { printf("%s 单词\n", yytext); }
[0-9]+                    { printf("%s 数字\n", yytext); }
[+\-*/=<>!&|(){}\[\]"';:,.#] { printf("%s 符号\n", yytext); }
[ \t\n]                   { /* 忽略空白字符 */ }
.                         { printf("%s 符号\n", yytext); }
%%

int main(int argc, char *argv[]) {
    if (argc > 1) {
        if (!(yyin = fopen(argv[1], "r"))) {
            perror(argv[1]);
            return 1;
        }
    }
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}