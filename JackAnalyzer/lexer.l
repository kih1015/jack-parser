%option noyywrap

%{
#include "JackAnalyzer.tab.h"
#include <stdio.h>
#include <stdlib.h>
%}

%%

"class"         { return CLASS; } // 클래스/서브루틴: class, constructor, function, method
"constructor"   { return CONSTRUCTOR; }
"function"      { return FUNCTION; }
"method"        { return METHOD; }

"field"         { return FIELD; } // 변수 선언: field, static, var
"static"        { return STATIC; }
"var"           { return VAR; }

"int"           { return INT; } // 자료형: int, char, boolean, void
"char"          { return CHAR; }
"boolean"       { return BOOLEAN; }
"void"          { return VOID; }

"true"          { return TRUE; } // 상수: true, false, null, this
"false"         { return FALSE; }
"null"          { return TK_NULL; }
"this"          { return THIS; }

"let"           { return LET; } // 진술문: let, do, if, else, while, return
"do"            { return DO; }
"if"            { return IF; }
"else"          { return ELSE; }
"while"         { return WHILE; }
"return"        { return RETURN; }

"{"             { return LBRACE; } // 구분자: ‘{’, ‘}’, ‘(’, ‘)’, ‘[’, ‘]’, ‘.’, ‘,’, ‘;’
"}"             { return RBRACE; }
"("             { return LPAREN; }
")"             { return RPAREN; }
"["             { return LBRACKET; }
"]"             { return RBRACKET; }
"."             { return DOT; }
","             { return COMMA; }
";"             { return SEMICOLON; }

"+"             { return PLUS; } // 연산자: ‘+’, ‘-’, ‘*’, ‘/’, ‘&’, ‘|’, ‘<’, ‘>’, ‘=’, ‘~’
"-"             { return MINUS; }
"*"             { return MULTIPLY; }
"/"             { return DIVIDE; }
"&"             { return AND; }
"|"             { return OR; }
"<"             { return LT; }
">"             { return GT; }
"="             { return EQ; }
"~"             { return NOT; }

\/\*([^*]|\*+[^*/])*\*+\/     {} // 블록 주석 무시
"//".*                        {} // 한 줄 주석 무시
[ \t\n\r]+                    {} // 공백 무시

[0-9]+          { // 정수: 0 ~ 32767 범위의 값 
                    int value = atoi(yytext); // 정수로 변환
                    if (value >= 0 && value <= 32767) { // 범위 체크
                        yylval.sval = strdup(yytext);
                        return INTEGER_CONSTANT;
                    } else {
                        printf("Error: Integer out of range: %s\n", yytext);
                        exit(1);
                    }
                }

\"[^\"]*\"      { // 문자열: 큰 따옴표(“”)로 둘러싸인 문자열
                    yylval.sval = strdup(yytext); // 따옴표 제거
                    yylval.sval[strlen(yylval.sval) - 1] = '\0'; // 따옴표 제거
                    yylval.sval = yylval.sval + 1; // 따옴표 제거
                    return STRING_CONSTANT; 
                }

[_a-zA-Z][_a-zA-Z0-9]*  {
                            yylval.sval = strdup(yytext);
                            return IDENTIFIER;
                        }

.               {
                    printf("Error: Integer out of range: %s\n", yytext);
                    exit(1);
                }

%%    
