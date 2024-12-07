%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
    char *tag;                  // 태그 명
    char *value;                // 태그 값 (터미널 노드)
    struct TreeNode **children; // 자식노드 배열
    int child_count;            // 자식노드 갯수
} TreeNode;

// 노드 생성
TreeNode* create_node(const char *tag, const char *value);

// 자식 추가
void add_child(TreeNode *parent, TreeNode *child);

// tree 출력
void print_tree(TreeNode *node, int depth);

// tree 메모리 해제
void free_tree(TreeNode *node);

// tree node 메모리 해제
void free_node(TreeNode *node);

// 자식 노드 흡수
void take_children(TreeNode *master, TreeNode *slave);

void yyerror(const char *s);
int yylex();
extern int yylineno;
%}

%union {
    struct TreeNode *node;
    char *sval;
}

// 클래스/서브루틴
%token CLASS CONSTRUCTOR FUNCTION METHOD 

// 변수 선언
%token FIELD STATIC VAR

// 자료형
%token INT CHAR BOOLEAN VOID

// 상수
%token TRUE FALSE TK_NULL THIS 

// 진술문
%token LET DO IF ELSE WHILE RETURN

// 심볼: 구분자
%token LBRACE RBRACE LPAREN RPAREN LBRACKET RBRACKET DOT COMMA SEMICOLON 

// 심볼: 연산자
%token PLUS MINUS MULTIPLY DIVIDE AND OR LT GT EQ NOT

// 식별자, 문자열상수, 정수상수
%token <sval> IDENTIFIER STRING_CONSTANT INTEGER_CONSTANT

// 클래스 선언
%type <node> class classVarDecList subroutineDecList

// 클래스 변수 선언
%type <node> classVarDec classVarType type

// 서브루틴 선언
%type <node> subroutineDec subroutineType returnType parameterList subroutineBody
%type <node> varDec className subroutineName varDecList varName varNameList

// 진술문
%type <node> statements statementList statement letStatement ifStatement whileStatement doStatement returnStatement 

// 표현식
%type <node> expressions expression term subroutineCall expressionList op unaryOp keywordConstant

%start program

%%
program:
    // 표현식만 출력 for test
    expressions {
        print_tree($1, 0);
        free_tree($1);
    }
    // 진술문만 출력 for test
    | statements {
        print_tree($1, 0);
        free_tree($1);
    }
    // 서브루틴만 출력 for test
    | subroutineDecList {
        print_tree($1, 0);
        free_tree($1);
    }
    // 클래스 (program structure)
    | class {
        print_tree($1, 0);
        free_tree($1);
    }
;

// 클래스 선언 (class)
class:
    CLASS className LBRACE classVarDecList subroutineDecList RBRACE {
        $$ = create_node("class", NULL);
        add_child($$, create_node("keyword", "class"));
        add_child($$, $2);
        add_child($$, create_node("symbol", "{"));
        take_children($$, $4);
        take_children($$, $5);
        add_child($$, create_node("symbol", "}"));
    }
;

// for classVarDec*
classVarDecList:
    {
        $$ = create_node("classVarDecList", NULL);
    }
    | classVarDecList classVarDec {
        $$ = $1;
        add_child($$, $2);
    }
;

// for subroutineDec*
subroutineDecList:
    {
        $$ = create_node("subroutineDecList", NULL);
    }
    | subroutineDecList subroutineDec {
        $$ = $1;
        add_child($$, $2);
    }
;

// 클래스 변수 선언 (class VarDec)
classVarDec:
    classVarType type varNameList SEMICOLON {
        $$ = create_node("classVarDec", NULL);
        add_child($$, $1);
        add_child($$, $2);
        take_children($$, $3);
        add_child($$, create_node("symbol", ";"));
    }
;

// for 클래스 변수 타입
classVarType:
    STATIC {
        $$ = create_node("keyword", "static");
    }
    | FIELD {
        $$ = create_node("keyword", "field");
    }
;

// 자료형
type:
    INT {
        $$ = create_node("keyword", "int");
    }
    | CHAR {
        $$ = create_node("keyword", "char");
    } 
    | BOOLEAN {
        $$ = create_node("keyword", "boolean");
    } 
    | className {
        $$ = $1;
    }
;

// 서브루틴 선언 (subroutineDec)
subroutineDec:
    subroutineType returnType subroutineName LPAREN parameterList RPAREN subroutineBody {
        $$ = create_node("subroutineDec", NULL);
        add_child($$, $1);
        add_child($$, $2);
        add_child($$, $3);
        add_child($$, create_node("symbol", "("));
        add_child($$, $5);
        add_child($$, create_node("symbol", ")"));
        add_child($$, $7);
    }
;

// for 서브루틴 타입
subroutineType:
    CONSTRUCTOR {
        $$ = create_node("keyword", "constructor");
    }
    | FUNCTION {
        $$ = create_node("keyword", "function");
    }
    | METHOD {
        $$ = create_node("keyword", "method");
    }
;

// for 서브루틴 반환 타입
returnType:
    VOID {
        $$ = create_node("keyword", "void");
    }
    | type {
        $$ = $1;
    }
;

// 매개변수 리스트
parameterList:
    /* Empty */ {
        $$ = create_node("parameterList", NULL);
    }
    | type varName {
        $$ = create_node("parameterList", NULL);
        add_child($$, $1);
        add_child($$, $2);
    }
    | parameterList COMMA type varName {
        $$ = $1;
        add_child($$, create_node("symbol", ","));
        add_child($$, $3);
        add_child($$, $4);
    }
;

// 서브루틴 구현
subroutineBody:
    LBRACE varDecList statements RBRACE {
        $$ = create_node("subroutineBody", NULL);
        add_child($$, create_node("symbol", "{"));
        take_children($$, $2);
        add_child($$, $3); // statements
        add_child($$, create_node("symbol", "}"));
    }
;

// for varDec*
varDecList:
    /* Empty */ {
        $$ = create_node("varDecList", NULL);
    }
    | varDecList varDec {
        $$ = $1;
        add_child($$, $2);
    }
;

// 변수 선언
varDec:
    VAR varNameList SEMICOLON {
        $$ = create_node("varDec", NULL);
        add_child($$, create_node("keyword", "var"));
        take_children($$, $2);
        add_child($$, create_node("symbol", ";"));
    }
;

// for varName (',' varName)*
varNameList:
    varName {
        $$ = create_node("varNameList", NULL);
        add_child($$, $1);
    }
    | varNameList COMMA varName {
        $$ = $1;
        add_child($$, create_node("symbol", ","));
        add_child($$, $3);
    }
;

// 클래스 이름
className:
    IDENTIFIER {
        $$ = create_node("identifier", $1);
    }
;

// 서브루틴 이름
subroutineName:
    IDENTIFIER {
        $$ = create_node("identifier", $1);
    }
;

// 변수 이름
varName:
    IDENTIFIER {
        $$ = create_node("identifier", $1);
    }
;

// 진술문(Statements)
statements:
    statementList {
        $$ = $1;
    }
;

// for statement*
statementList:
    /* Empty */ {
        $$ = create_node("statements", NULL);
    }
    | statementList statement {
        $$ = $1;
        add_child($$, $2);
    }
;

// 단일 진술문
statement:
    letStatement {
        $$ = $1;
    }
    | ifStatement {
        $$ = $1;
    }
    | whileStatement {
        $$ = $1;
    }
    | doStatement {
        $$ = $1;
    }
    | returnStatement {
        $$ = $1;
    }
;

// let 문
letStatement:
    LET varName EQ expression SEMICOLON {
        $$ = create_node("letStatement", NULL);
        add_child($$, create_node("keyword", "let"));
        add_child($$, $2);
        add_child($$, create_node("symbol", "="));
        add_child($$, $4);
        add_child($$, create_node("symbol", ";"));
    }
    // ([인덱스])?
    | LET varName LBRACKET expression RBRACKET EQ expression SEMICOLON {
        $$ = create_node("letStatement", NULL);
        add_child($$, create_node("keyword", "let"));
        add_child($$, $2);
        add_child($$, create_node("symbol", "["));
        add_child($$, $4);
        add_child($$, create_node("symbol", "]"));
        add_child($$, create_node("symbol", "="));
        add_child($$, $7);
        add_child($$, create_node("symbol", ";"));
    }
;

// if 문
ifStatement:
    IF LPAREN expression RPAREN LBRACE statements RBRACE {
        $$ = create_node("ifStatement", NULL);
        add_child($$, create_node("keyword", "if"));
        add_child($$, create_node("symbol", "("));
        add_child($$, $3);
        add_child($$, create_node("symbol", ")"));
        add_child($$, create_node("symbol", "{"));
        add_child($$, $6);
        add_child($$, create_node("symbol", "}"));
    }
    | IF LPAREN expression RPAREN LBRACE statements RBRACE ELSE LBRACE statements RBRACE {
        $$ = create_node("ifStatement", NULL);
        add_child($$, create_node("keyword", "if"));
        add_child($$, create_node("symbol", "("));
        add_child($$, $3);
        add_child($$, create_node("symbol", ")"));
        add_child($$, create_node("symbol", "{"));
        add_child($$, $6);
        add_child($$, create_node("symbol", "}"));
        add_child($$, create_node("keyword", "else"));
        add_child($$, create_node("symbol", "{"));
        add_child($$, $10);
        add_child($$, create_node("symbol", "}"));
    }
;

// while 문
whileStatement:
    WHILE LPAREN expression RPAREN LBRACE statements RBRACE {
        $$ = create_node("whileStatement", NULL);
        add_child($$, create_node("keyword", "while"));
        add_child($$, create_node("symbol", "("));
        add_child($$, $3);
        add_child($$, create_node("symbol", ")"));
        add_child($$, create_node("symbol", "{"));
        add_child($$, $6);
        add_child($$, create_node("symbol", "}"));
    }
;

// do 문
doStatement:
    DO subroutineCall SEMICOLON {
        $$ = create_node("doStatement", NULL);
        add_child($$, create_node("keyword", "do"));
        take_children($$, $2);
        add_child($$, create_node("symbol", ";"));
    }
;

// return 문
returnStatement:
    RETURN SEMICOLON {
        $$ = create_node("returnStatement", NULL);
        add_child($$, create_node("keyword", "return"));
        add_child($$, create_node("symbol", ";"));
    }
    | RETURN expression SEMICOLON {
        $$ = create_node("returnStatement", NULL);
        add_child($$, create_node("keyword", "return"));
        add_child($$, $2);
        add_child($$, create_node("symbol", ";"));
    }
;

// 표현식 테스트를 위한 구문
expressions:
    expression {
        $$ = create_node("expressions", NULL);
        add_child($$, $1);
    }
    | expressions expression {
        $$ = $1;
        add_child($$, $2);
    }
;

// 표현식 (term (op term)*)
expression:
    term {
        $$ = create_node("expression", NULL);
        add_child($$, $1);
    }
    | expression op term {
        $$ = $1;
        add_child($$, $2);
        add_child($$, $3);
    }
;

// 상수/변수 참조
term:
    // 정수 상수 참조
    INTEGER_CONSTANT {
        $$ = create_node("term", NULL);
        add_child($$, create_node("integerConstant", $1));
    }
    // 문자열 상수 참조
    | STRING_CONSTANT {
        $$ = create_node("term", NULL);
        add_child($$, create_node("stringConstant", $1));
    }
    // 키워드 상수 참조
    | keywordConstant {
        $$ = create_node("term", NULL);
        add_child($$, $1);
    }
    // 변수 참조
    | varName {
        $$ = create_node("term", NULL);
        add_child($$, $1);
    }
    // 변수[인덱스] 참조
    | varName LBRACKET expression RBRACKET {
        $$ = create_node("term", NULL);
        add_child($$, $1);
        add_child($$, create_node("symbol", "["));
        add_child($$, $3);
        add_child($$, create_node("symbol", "]"));
    }
    // 서브루틴 호출
    | subroutineCall {
        $$ = create_node("term", NULL);
        take_children($$, $1);
    }
    // (표현식) 참조
    | LPAREN expression RPAREN {
        $$ = create_node("term", NULL);
        add_child($$, create_node("symbol", "("));
        add_child($$, $2);
        add_child($$, create_node("symbol", ")"));
    }
    // 단항 연산 참조
    | unaryOp term {
        $$ = create_node("term", NULL);
        add_child($$, $1);
        add_child($$, $2);
    }
;

// 서브루틴 호출
subroutineCall:
    // 클래스내 서브루틴 호출
    subroutineName LPAREN expressionList RPAREN {
        $$ = create_node("subroutineCall", NULL);
        add_child($$, $1);
        add_child($$, create_node("symbol", "("));
        add_child($$, $3);
        add_child($$, create_node("symbol", ")"));
    }
    // 정적 서브루틴 호출
    | className DOT subroutineName LPAREN expressionList RPAREN {
        $$ = create_node("subroutineCall", NULL);
        add_child($$, $1);
        add_child($$, create_node("symbol", "."));
        add_child($$, $3);
        add_child($$, create_node("symbol", "("));
        add_child($$, $5);
        add_child($$, create_node("symbol", ")"));
    }
    // 필드 서브루틴 호출
    | varName DOT subroutineName LPAREN expressionList RPAREN {
        $$ = create_node("subroutineCall", NULL);
        add_child($$, $1);
        add_child($$, create_node("symbol", "."));
        add_child($$, $3);
        add_child($$, create_node("symbol", "("));
        add_child($$, $5);
        add_child($$, create_node("symbol", ")"));
    }
;

// 표현식 리스트 (expression, (',' expression)*)?
expressionList:
    /* Empty */ {
        $$ = create_node("expressionList", NULL);
    }
    | expression {
        $$ = create_node("expressionList", NULL);
        add_child($$, $1);
    }
    | expressionList COMMA expression {
        $$ = $1;
        add_child($$, create_node("symbol", ","));
        add_child($$, $3);
    }
;

// 산술/논리연산
op:
    PLUS {
        $$ = create_node("symbol", "+");       
    }
    | MINUS {
        $$ = create_node("symbol", "-"); 
    }
    | MULTIPLY {
        $$ = create_node("symbol", "*");    
    }
    | DIVIDE {
        $$ = create_node("symbol", "/");
    }
    | AND {
        $$ = create_node("symbol", "&amp;");
    }
    | OR {
        $$ = create_node("symbol", "|");
    }
    | LT {
        $$ = create_node("symbol", "&lt;");
    }
    | GT {
        $$ = create_node("symbol", "&gt;");
    }
    | EQ {
        $$ = create_node("symbol", "=");
    }
;

// 단항연산
unaryOp:
    MINUS {
        $$ = create_node("symbol", "-");
    }
    | NOT {
        $$ = create_node("symbol", "~");
    }
;

// 키워드 상수
keywordConstant:
    TRUE {
        $$ = create_node("keyword", "true");
    }
    | FALSE {
        $$ = create_node("keyword", "false");
    }
    | TK_NULL {
        $$ = create_node("keyword", "null");
    }
    | THIS {
        $$ = create_node("keyword", "this");
    }
;

%%
// 노드 생성 구현
TreeNode* create_node(const char *tag, const char *value) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->tag = strdup(tag);
    node->value = value ? strdup(value) : NULL;
    node->children = NULL;
    node->child_count = 0;
    return node;
}

// 자식 노드 추가 구현
void add_child(TreeNode *parent, TreeNode *child) {
    parent->children = realloc(parent->children, sizeof(TreeNode *) * (parent->child_count + 1));
    parent->children[parent->child_count++] = child;
}

// 트리 출력 구현
void print_tree(TreeNode *node, int depth) {
    for (int i = 0; i < depth; i++) printf("  ");
    printf("<%s>", node->tag);
    if (node->value) {
        printf(" %s ", node->value);
        printf("</%s>\n", node->tag);
    } else {
        printf("\n");
	    for (int i = 0; i < node->child_count; i++) {
            print_tree(node->children[i], depth + 1);
        }
        for (int i = 0; i < depth; i++) printf("  ");
        printf("</%s>\n", node->tag);
    }  
}

// 트리 메모리 해제 구현
void free_tree(TreeNode *node) {
    if (!node) return;
    free(node->tag);
    if (node->value) free(node->value);
    for (int i = 0; i < node->child_count; i++) {
        free_tree(node->children[i]);
    }
    free(node->children);
    free(node);
}

// 트리 노드 메모리 해제 구현
void free_node(TreeNode *node) {
    if (!node) return;
    free(node->tag);
    if (node->value) free(node->value);
    free(node->children);
    free(node);
}

// 자식 노드 흡수 구현
void take_children(TreeNode *master, TreeNode *slave) {
    if (!master) return;
    if (!slave) return;
    for (int i = 0; i < slave->child_count; i++)
        add_child(master, slave->children[i]);
    free_node(slave);
}

// 디버깅
void yyerror(const char *s) {
    fprintf(stderr, "Error: %s at line %d\n", s, yylineno);
}

// 진입점
int main(int argc, char **argv) {
    if (yyparse() != 0) printf("Parsing failed!\n");
    return 0;
}
