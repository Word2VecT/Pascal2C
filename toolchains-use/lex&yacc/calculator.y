%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(char *s);
int yylex(void);

%}

%union {
    int ival;
}

%token <ival> NUMBER 
%token END PLUS TIMES
%type <ival> expression
%left PLUS
%left TIMES

%%

program:
    expression END  { printf("%d\n", $1); exit(0); }
    ;

expression:
    NUMBER          { $$ = $1; }
    | expression PLUS expression   { $$ = $1 + $3; }
    | expression TIMES expression  { $$ = $1 * $3; }
    ;

%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int yylex(void) {
    int c;
    c = getchar();
    
    while (c == ' ' || c == '\t' || c == '\n') {
        c = getchar();
    }
    
    if (c == '#') {
        return END;
    }
    
    if (c >= '0' && c <= '9') {
        int value = 0;
        
        while (c >= '0' && c <= '9') {
            value = value * 10 + (c - '0');
            c = getchar();
        }
        
        ungetc(c, stdin);
        yylval.ival = value;
        return NUMBER;
    }
    
    if (c == '+') return PLUS;
    if (c == '*') return TIMES;
    
    return c;
}

int main(void) {
    yyparse();
    return 0;
} 