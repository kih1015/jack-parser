%option noyywrap

%{
#include "parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
%}

%%


\/\*([^*]|\*+[^*/])*\*+\/    {}
"//".*     {}
[ \t\n\r]+  {}

"class"          { return CLASS; }
"constructor"    { return CONSTRUCTOR; }
"function"       { return FUNCTION; }
"method"         { return METHOD; }
"field"          { return FIELD; }
"static"         { return STATIC; }
"var"            { return VAR; }
"int"            { return INT; }
"char"           { return CHAR; }
"boolean"        { return BOOLEAN; }
"void"           { return VOID; }
"true"           { return TRUE; }
"false"          { return FALSE; }
"null"           { return TK_NULL; }
"this"           { return THIS; }
"let"            { return LET; }
"do"             { return DO; }
"if"             { return IF; }
"else"           { return ELSE; }
"while"          { return WHILE; }
"return"         { return RETURN; }

"{"              { return LBRACE; }
"}"              { return RBRACE; }
"("              { return LPAREN; }
")"              { return RPAREN; }
"["              { return LBRACKET; }
"]"              { return RBRACKET; }
"."              { return DOT; }
","              { return COMMA; }
";"              { return SEMICOLON; }
"+"              { return PLUS; }
"-"              { return MINUS; }
"*"              { return MULTIPLY; }
"/"              { return DIVIDE; }
"&"              { return AND; }
"|"              { return OR; }
"<"              { return LT; }
">"              { return GT; }
"="              { return EQ; }
"~"              { return NOT; }

[0-9]+           { 
                    int value = atoi(yytext);
                    if (value >= 0 && value <= 32767) {
                        yylval.sval = strdup(yytext);
			return INTEGER_CONSTANT;
                    } else {
                        printf("Error: Integer out of range: %s\n", yytext);
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
