parser grammar C1Parser;

options { tokenVocab = C1Lexer; }

compilationUnit
    : (decl | funcdef)* EOF
    ;

decl
    : constdecl
    | vardecl
    ;

constdecl
    : 'const' btype constdef (',' constdef)* ';'
    ;

constdef
    : Identifier '=' exp
    ;

vardecl
    : btype vardef (',' vardef)* ';'
    ;

vardef
    : Identifier
    | Identifier '=' exp
    | Identifier '[' IntConst ']' ('[' IntConst ']')*
    ;

btype
    : 'int'
    | 'float'
    ;

funcdef
    : btype Identifier '(' (btype Identifier (',' btype Identifier)*)? ')' block
    ;

block
    : '{' stmt* '}'
    ;

stmt
    : lval '=' exp ';'
    | Identifier '(' (exp (',' exp)*)? ')' ';'
    | block
    | 'return' exp? ';'
    | 'if' '(' cond ')' stmt ('else' stmt)?
    | 'while' '(' cond ')' stmt
    | 'for' '(' stmt? ';' cond? ';' stmt? ')' stmt
    ;

lval
    : Identifier ('[' exp ']')*
    ;

cond
    : exp ('==' | '!=' | '<' | '>' | '<=' | '>=') exp
    ;

exp
    : (Plus | Minus)? exp
    | exp (Multiply | Divide | Modulo) exp
    | exp (Plus | Minus) exp
    | LeftParen exp RightParen
    | number
    | Identifier
    | Identifier '[' exp ']'
    ;

number
    : IntConst
    | FloatConst
    ;
