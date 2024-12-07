%option noyywrap

%{
#include <stdio.h>
#include <stdlib.h>
%}

%%

"class"         { printf("<keyword> class </keyword>\n"); } // 클래스/서브루틴: class, constructor, function, method
"constructor"   { printf("<keyword> constructor </keyword>\n"); }
"function"      { printf("<keyword> function </keyword>\n"); }
"method"        { printf("<keyword> method </keyword>\n"); }

"field"         { printf("<keyword> field </keyword>\n"); } // 변수 선언: field, static, var
"static"        { printf("<keyword> static </keyword>\n"); }
"var"           { printf("<keyword> var </keyword>\n"); }

"int"           { printf("<keyword> int </keyword>\n"); } // 자료형: int, char, boolean, void
"char"          { printf("<keyword> char </keyword>\n"); }
"boolean"       { printf("<keyword> boolean </keyword>\n"); }
"void"          { printf("<keyword> void </keyword>\n"); }

"true"          { printf("<keyword> true </keyword>\n"); } // 상수: true, false, null, this
"false"         { printf("<keyword> false </keyword>\n"); }
"null"          { printf("<keyword> null </keyword>\n"); }
"this"          { printf("<keyword> this </keyword>\n"); }

"let"           { printf("<keyword> let </keyword>\n"); } // 진술문: let, do, if, else, while, return
"do"            { printf("<keyword> do </keyword>\n"); }
"if"            { printf("<keyword> if </keyword>\n"); }
"else"          { printf("<keyword> else </keyword>\n"); }
"while"         { printf("<keyword> while </keyword>\n"); }
"return"        { printf("<keyword> return </keyword>\n"); }

"{"             { printf("<symbol> { </symbol>\n"); } // 구분자: ‘{’, ‘}’, ‘(’, ‘)’, ‘[’, ‘]’, ‘.’, ‘,’, ‘;’
"}"             { printf("<symbol> } </symbol>\n"); }
"("             { printf("<symbol> ( </symbol>\n"); }
")"             { printf("<symbol> ) </symbol>\n"); }
"["             { printf("<symbol> [ </symbol>\n"); }
"]"             { printf("<symbol> ] </symbol>\n"); }
"."             { printf("<symbol> . </symbol>\n"); }
","             { printf("<symbol> , </symbol>\n"); }
";"             { printf("<symbol> ; </symbol>\n"); }

"+"             { printf("<symbol> + </symbol>\n"); } // 연산자: ‘+’, ‘-’, ‘*’, ‘/’, ‘&’, ‘|’, ‘<’, ‘>’, ‘=’, ‘~’
"-"             { printf("<symbol> - </symbol>\n"); }
"*"             { printf("<symbol> * </symbol>\n"); }
"/"             { printf("<symbol> / </symbol>\n"); }
"&"             { printf("<symbol> &amp; </symbol>\n");} // &amp; 로 출력
"|"             { printf("<symbol> | </symbol>\n"); }
"<"             { printf("<symbol> &lt; </symbol>\n"); } // &lt; 로 출력
">"             { printf("<symbol> &gt; </symbol>\n"); } // &gt; 로 출력
"="             { printf("<symbol> = </symbol>\n"); }
"~"             { printf("<symbol> ~ </symbol>\n"); }

\/\*([^*]|\*+[^*/])*\*+\/     {} // 블록 주석 무시
"//".*                        {} // 한 줄 주석 무시
[ \t\n\r]+                    {} // 공백 무시

[0-9]+          { // 정수: 0 ~ 32767 범위의 값 
                    int value = atoi(yytext); // 정수로 변환
                    if (value >= 0 && value <= 32767) { // 범위 체크
                        printf("<integerConstant> %d </integerConstant>\n", value);
                    } else {
                        printf("Error: Integer out of range: %s\n", yytext);
                        exit(1);
                    }
                }

\"[^\"]*\"      { // 문자열: 큰 따옴표(“”)로 둘러싸인 문자열
                    char *buf = (char *)malloc(strlen(yytext) - 1); // 따옴표 제거
                    strncpy(buf, yytext + 1, strlen(yytext) - 2); // 따옴표 제거
                    buf[strlen(yytext) - 2] = '\0'; // 따옴표 제거
                    printf("<stringConstant> %s </stringConstant>\n", buf);
                }

[_a-zA-Z][_a-zA-Z0-9]*  { // 식별자: 문자/언더스코어(‘_’)로 시작, 숫자로 시작하면 안됨
                            printf("<identifier> %s </identifier>\n", yytext);
                            //yylval.sval = strdup(yytext);
                        }

.               { // 이외의 문자
                    printf("Error: Unrecognized token: %s\n", yytext);
                    exit(1);
                }

%%    

int main() {
    printf("<tokens>\n"); // 토큰s 태그로 감싸기
    yylex(); // lexer 실행
    printf("</tokens>\n");
}