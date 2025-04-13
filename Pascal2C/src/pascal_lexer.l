%{
#include <string>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "pascal_parser.h"

// 避免由flex生成的未使用函数警告
#define YY_NO_UNPUT
#define YY_NO_INPUT

// 取消extern "C"声明，让Flex生成的yylex与Bison期望的一致
%}

%option noyywrap
%option yylineno
%option outfile="pascal_lexer.cpp"
%option header-file="pascal_lexer.h"

/* 定义常见的字符集 */
DIGIT       [0-9]
LETTER      [a-zA-Z]
IDENTIFIER  {LETTER}({LETTER}|{DIGIT}|_)*
INTEGER     {DIGIT}+
REAL        {DIGIT}+\.{DIGIT}+([eE][+-]?{DIGIT}+)?
WHITESPACE  [ \t\r\n]+
STRING      '([^'\n]|\'\')+'
COMMENT     \{[^\}]*\}|"(*"([^*]|"*"[^)])*"*)"

%%

{WHITESPACE}    { /* 忽略空白字符 */ }
{COMMENT}       { /* 忽略注释 */ }

"program"       { return T_PROGRAM; }
"begin"         { return T_BEGIN; }
"end"           { return T_END; }
"var"           { return T_VAR; }
"function"      { return T_FUNCTION; }
"procedure"     { return T_PROCEDURE; }
"if"            { return T_IF; }
"then"          { return T_THEN; }
"else"          { return T_ELSE; }
"while"         { return T_WHILE; }
"do"            { return T_DO; }
"for"           { return T_FOR; }
"to"            { return T_TO; }
"downto"        { return T_DOWNTO; }
"repeat"        { return T_REPEAT; }
"until"         { return T_UNTIL; }
"case"          { return T_CASE; }
"of"            { return T_OF; }
"const"         { return T_CONST; }
"type"          { return T_TYPE; }
"array"         { return T_ARRAY; }
"record"        { return T_RECORD; }
"div"           { return T_DIV; }
"mod"           { return T_MOD; }
"and"           { return T_AND; }
"or"            { return T_OR; }
"not"           { return T_NOT; }
"true"          { yylval.boolVal = true; return T_BOOL_CONST; }
"false"         { yylval.boolVal = false; return T_BOOL_CONST; }

"integer"       { yylval.strVal = strdup(yytext); return T_TYPE_ID; }
"real"          { yylval.strVal = strdup(yytext); return T_TYPE_ID; }
"boolean"       { yylval.strVal = strdup(yytext); return T_TYPE_ID; }
"string"        { yylval.strVal = strdup(yytext); return T_TYPE_ID; }
"char"          { yylval.strVal = strdup(yytext); return T_TYPE_ID; }

{IDENTIFIER}    { yylval.strVal = strdup(yytext); return T_IDENTIFIER; }
{INTEGER}       { yylval.intVal = atoi(yytext); return T_INT_CONST; }
{REAL}          { yylval.realVal = atof(yytext); return T_REAL_CONST; }
{STRING}        { 
                  // 移除首尾的引号并转义内部的双引号
                  std::string str(yytext + 1, strlen(yytext) - 2);
                  size_t pos = 0;
                  while((pos = str.find("''", pos)) != std::string::npos) {
                    str.replace(pos, 2, "'");
                    pos++;
                  }
                  yylval.strVal = strdup(str.c_str());
                  return T_STRING_CONST;
                }

":="            { return T_ASSIGN; }
"+"             { return T_PLUS; }
"-"             { return T_MINUS; }
"*"             { return T_MULTIPLY; }
"/"             { return T_DIVIDE; }
"="             { return T_EQUAL; }
"<>"            { return T_NOT_EQUAL; }
"<"             { return T_LESS; }
"<="            { return T_LESS_EQUAL; }
">"             { return T_GREATER; }
">="            { return T_GREATER_EQUAL; }
"("             { return T_LPAREN; }
")"             { return T_RPAREN; }
"["             { return T_LBRACKET; }
"]"             { return T_RBRACKET; }
":"             { return T_COLON; }
";"             { return T_SEMICOLON; }
","             { return T_COMMA; }
"."             { return T_DOT; }
".."            { return T_DOTDOT; }

.               { std::cerr << "Lexical error: unexpected character '" << yytext << "' at line " << yylineno << std::endl; }

%% 