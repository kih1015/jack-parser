%option noyywrap

%{
#include "JackAnalyzer.tab.h"
#include <stdio.h>
#include <stdlib.h>
%}

%%

\/\*([^*]|\*+[^*/])*\*+\/    {}  // 블록 주석 무시
"//".*                      {}  // 한 줄 주석 무시
[ \t\n\r]+                  {}  // 공백, 탭, 줄바꿈 무시

"class"          { yylval.sval = "class"; return CLASS; }
"constructor"    { yylval.sval = "constructor"; return CONSTRUCTOR; }
"function"       { yylval.sval = "function"; return FUNCTION; }
"method"         { yylval.sval = "method"; return METHOD; }
"field"          { yylval.sval = "field"; return FIELD; }
"static"         { yylval.sval = "static"; return STATIC; }
"var"            { yylval.sval = "var"; return VAR; }
"int"            { yylval.sval = "int"; return INT; }
"char"           { yylval.sval = "char"; return CHAR; }
"boolean"        { yylval.sval = "boolean"; return BOOLEAN; }
"void"           { yylval.sval = "void"; return VOID; }
"true"           { yylval.sval = "true"; return TRUE; }
"false"          { yylval.sval = "false"; return FALSE; }
"null"           { yylval.sval = "null"; return TK_NULL; }
"this"           { yylval.sval = "this"; return THIS; }
"let"            { yylval.sval = "let"; return LET; }
"do"             { yylval.sval = "do"; return DO; }
"if"             { yylval.sval = "if"; return IF; }
"else"           { yylval.sval = "else"; return ELSE; }
"while"          { yylval.sval = "while"; return WHILE; }
"return"         { yylval.sval = "return"; return RETURN; }

"{"              { yylval.sval = "{"; return LBRACE; }
"}"              { yylval.sval = "}"; return RBRACE; }
"("              { yylval.sval = "("; return LPAREN; }
")"              { yylval.sval = ")"; return RPAREN; }
"["              { yylval.sval = "["; return LBRACKET; }
"]"              { yylval.sval = "]"; return RBRACKET; }
"."              { yylval.sval = "."; return DOT; }
","              { yylval.sval = ","; return COMMA; }
";"              { yylval.sval = ";"; return SEMICOLON; }
"+"              { yylval.sval = "+"; return PLUS; }
"-"              { yylval.sval = "-"; return MINUS; }
"*"              { yylval.sval = "*"; return MULTIPLY; }
"/"              { yylval.sval = "/"; return DIVIDE; }
"&"              { yylval.sval = "&"; return AND; }
"|"              { yylval.sval = "|"; return OR; }
"<"              { yylval.sval = "&lt"; return LT; }
">"              { yylval.sval = "&gt"; return GT; }
"="              { yylval.sval = "="; return EQ; }
"~"              { yylval.sval = "~"; return NOT; }
[0-9]+           { 
                    int value = atoi(yytext);
                    if (value >= 0 && value <= 32767) {
                        yylval.sval = strdup(yytext);
                        return INTEGER_CONSTANT;
                    } else {
                        printf("Error: Integer out of range: %s\n", yytext);
                        exit(1); // 에러 처리
                    }
                 }

\"[^\"]*\"       { 
                    yylval.sval = strdup(yytext);
                    return STRING_CONSTANT; 
                 }

[_a-zA-Z][_a-zA-Z0-9]* {
                    yylval.sval = strdup(yytext);
                    return IDENTIFIER;
                 }

%%    
