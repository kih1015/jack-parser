%option noyywrap

%{
#include <stdio.h>
#include <stdlib.h>
%}

%%

"class"         { printf("<keyword> class </keyword>\n");}
"constructor"   { printf("<keyword> constructor </keyword>\n");}
"function"      { printf("<keyword> function </keyword>\n");}
"method"        { printf("<keyword> method </keyword>\n"); }
"field"         { printf("<keyword> field </keyword>\n"); }
"static"        { printf("<keyword> static </keyword>\n");  }
"var"           { printf("<keyword> var </keyword>\n");}
"int"           { printf("<keyword> int </keyword>\n");  }
"char"          { printf("<keyword> char </keyword>\n");  }
"boolean"       { printf("<keyword> boolean </keyword>\n");  }
"void"          { printf("<keyword> void </keyword>\n");  }
"true"          { printf("<keyword> true </keyword>\n"); }
"false"         { printf("<keyword> false </keyword>\n");  }
"null"          { printf("<keyword> null </keyword>\n"); }
"this"          { printf("<keyword> this </keyword>\n");  }
"let"           { printf("<keyword> let </keyword>\n");  }
"do"            { printf("<keyword> do </keyword>\n"); }
"if"            { printf("<keyword> if </keyword>\n");  }
"else"          { printf("<keyword> else </keyword>\n");  }
"while"         { printf("<keyword> while </keyword>\n");  }
"return"        { printf("<keyword> return </keyword>\n"); }

"{"             { printf("<symbol> { </symbol>\n");  }
"}"             { printf("<symbol> } </symbol>\n");  }
"("             { printf("<symbol> ( </symbol>\n");  }
")"             { printf("<symbol> ) </symbol>\n");  }
"["             { printf("<symbol> [ </symbol>\n"); }
"]"             { printf("<symbol> ] </symbol>\n");  }
"."             { printf("<symbol> . </symbol>\n");  }
","             { printf("<symbol> , </symbol>\n");  }
";"             { printf("<symbol> ; </symbol>\n");  }
"+"             { printf("<symbol> + </symbol>\n");  }
"-"             { printf("<symbol> - </symbol>\n");  }
"*"             { printf("<symbol> * </symbol>\n");  }
"/"             { printf("<symbol> / </symbol>\n");  }
"&"             { printf("<symbol> &amp; </symbol>\n");  }
"|"             { printf("<symbol> | </symbol>\n");  }
"<"             { printf("<symbol> &lt; </symbol>\n");  }
">"             { printf("<symbol> &gt; </symbol>\n");  }
"="             { printf("<symbol> = </symbol>\n");  }
"~"             { printf("<symbol> ~ </symbol>\n");  }

[0-9]+          { 
                    int value = atoi(yytext);
                    if (value >= 0 && value <= 32767) {
                        printf("<integerConstant> %d </integerConstant>\n", value);
                        //yylval.sval = strdup(yytext);
                    } else {
                        printf("Error: Integer out of range: %s\n", yytext);
                        exit(1);
                    }
                }

\"[^\"]*\"      { 
                    char *buf = (char *)malloc(strlen(yytext) - 1); // 따옴표 제거
                    strncpy(buf, yytext + 1, strlen(yytext) - 2);
                    buf[strlen(yytext) - 2] = '\0';
                    printf("<stringConstant> %s </stringConstant>\n", buf);
                    //yylval.sval = buf;
                }

[_a-zA-Z][_a-zA-Z0-9]*  {
                            printf("<identifier> %s </identifier>\n", yytext);
                            //yylval.sval = strdup(yytext);
                        }

\/\*([^*]|\*+[^*/])*\*+\/     {}  // 주석 무시
"//".*                        {}  // 주석 무시
[ \t\n\r]+                    {}  // 공백 무시

.               {
                    printf("Error: Unrecognized token: %s\n", yytext);
                    exit(1);
                }

%%    

int main() {
    printf("<tokens>\n");
    yylex();
    printf("</tokens>\n");
}