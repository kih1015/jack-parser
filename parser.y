%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
    char *tag;                  // XML tag
    char *value;                // Value (if leaf node)
    struct TreeNode **children; // Array of child nodes
    int child_count;            // Number of children
} TreeNode;

TreeNode* create_node(const char *tag, const char *value);
void add_child(TreeNode *parent, TreeNode *child);
void print_tree(TreeNode *node, int depth);
void free_tree(TreeNode *node);
void free_node(TreeNode *node);
void take_children(TreeNode *master, TreeNode *slave);

void yyerror(const char *s);
int yylex();
extern int yylineno;
%}

%union {
    struct TreeNode *node;
    char *sval;
}

%token CLASS CONSTRUCTOR FUNCTION METHOD FIELD STATIC VAR INT CHAR BOOLEAN VOID TRUE FALSE TK_NULL THIS LET DO IF ELSE WHILE RETURN
%token LBRACE RBRACE LPAREN RPAREN LBRACKET RBRACKET DOT COMMA SEMICOLON PLUS MINUS MULTIPLY DIVIDE AND OR LT GT EQ NOT
%token <sval> IDENTIFIER STRING_CONSTANT INTEGER_CONSTANT

%type <node> class classVarDecList subroutineDecList classVarDec classVarType type
%type <node> subroutineDec subroutineType returnType parameterList subroutineBody
%type <node> varDec className subroutineName varDecList varName

%type <node> statements statementList statement letStatement ifStatement whileStatement varNameList doStatement returnStatement

%type <node> expressions expression term subroutineCall expressionList op unaryOp keywordConstant

%start program

%%
program:
    expressions {
        print_tree($1, 0);
        free_tree($1);
    }
    | statements {
        print_tree($1, 0);
        free_tree($1);
    }
    | subroutineDec {
        print_tree($1, 0);
        free_tree($1);
    }
    | class {
        print_tree($1, 0);
        free_tree($1);
    }
;

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

/* middle node */
classVarDecList:
    {
        $$ = create_node("classVarDecList", NULL);
    }
    | classVarDecList classVarDec {
        $$ = $1;
        add_child($$, $2);
    }
;

/* middle node */
subroutineDecList:
    {
        $$ = create_node("subroutineDecList", NULL);
    }
    | subroutineDecList subroutineDec {
        $$ = $1;
        add_child($$, $2);
    }
;

classVarDec:
    classVarType type varNameList SEMICOLON {
        $$ = create_node("classVarDec", NULL);
        add_child($$, $1);
        add_child($$, $2);
        take_children($$, $3);
        add_child($$, create_node("symbol", ";"));
    }
;

/* middle node */
classVarType:
    STATIC {
        $$ = create_node("keyword", "static");
    }
    | FIELD {
        $$ = create_node("keyword", "field");
    }
;

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

/* middle node */
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

/* middle node */
returnType:
    VOID {
        $$ = create_node("keyword", "void");
    }
    | type {
        $$ = $1;
    }
;

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

subroutineBody:
    LBRACE varDecList statements RBRACE {
        $$ = create_node("subroutineBody", NULL);
        add_child($$, create_node("symbol", "{"));
        take_children($$, $2);
        add_child($$, $3); // statements
        add_child($$, create_node("symbol", "}"));
    }
;

/* middle node */
varDecList:
    /* Empty */ {
        $$ = create_node("varDecList", NULL);
    }
    | varDecList varDec {
        $$ = $1;
        add_child($$, $2);
    }
;

varDec:
    VAR varNameList SEMICOLON {
        $$ = create_node("varDec", NULL);
        add_child($$, create_node("keyword", "var"));
        take_children($$, $2);
        add_child($$, create_node("symbol", ";"));
    }
;

/* middle node */
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

className:
    IDENTIFIER {
        $$ = create_node("identifier", $1);
    }
;

subroutineName:
    IDENTIFIER {
        $$ = create_node("identifier", $1);
    }
;

varName:
    IDENTIFIER {
        $$ = create_node("identifier", $1);
    }
;

statements:
    statementList {
        $$ = $1;
    }
;

/* middle node */
statementList:
    /* Empty */ {
        $$ = create_node("statements", NULL);
    }
    | statementList statement {
        $$ = $1;
        add_child($$, $2);
    }
;

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

letStatement:
    LET varName EQ expression SEMICOLON {
        $$ = create_node("letStatement", NULL);
        add_child($$, create_node("keyword", "let"));
        add_child($$, $2);
        add_child($$, create_node("symbol", "="));
        add_child($$, $4);
        add_child($$, create_node("symbol", ";"));
    }
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

doStatement:
    DO subroutineCall SEMICOLON {
        $$ = create_node("doStatement", NULL);
        add_child($$, create_node("keyword", "do"));
        take_children($$, $2);
        add_child($$, create_node("symbol", ";"));
    }
;

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

term:
    INTEGER_CONSTANT {
        $$ = create_node("term", NULL);
        add_child($$, create_node("integerConstant", $1));
    }
    | STRING_CONSTANT {
        $$ = create_node("term", NULL);
        add_child($$, create_node("stringConstant", $1));
    }
    | keywordConstant {
        $$ = create_node("term", NULL);
        add_child($$, $1);
    }
    | varName {
        $$ = create_node("term", NULL);
        add_child($$, $1);
    }
    | varName LBRACKET expression RBRACKET {
        $$ = create_node("term", NULL);
        add_child($$, $1);
        add_child($$, create_node("symbol", "["));
        add_child($$, $3);
        add_child($$, create_node("symbol", "]"));
    }
    | subroutineCall {
        $$ = create_node("term", NULL);
        take_children($$, $1);
    }
    | LPAREN expression RPAREN {
        $$ = create_node("term", NULL);
        add_child($$, create_node("symbol", "("));
        add_child($$, $2);
        add_child($$, create_node("symbol", ")"));
    }
    | unaryOp term {
        $$ = create_node("term", NULL);
        add_child($$, $1);
        add_child($$, $2);
    }
;

subroutineCall:
    subroutineName LPAREN expressionList RPAREN {
        $$ = create_node("subroutineCall", NULL);
        add_child($$, $1);
        add_child($$, create_node("symbol", "("));
        add_child($$, $3);
        add_child($$, create_node("symbol", ")"));
    }
    | className DOT subroutineName LPAREN expressionList RPAREN {
        $$ = create_node("subroutineCall", NULL);
        add_child($$, $1);
        add_child($$, create_node("symbol", "."));
        add_child($$, $3);
        add_child($$, create_node("symbol", "("));
        add_child($$, $5);
        add_child($$, create_node("symbol", ")"));
    }
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

op:
    PLUS {
        $$ = create_node("op", NULL);
        add_child($$, create_node("symbol", "+"));
    }
    | MINUS {
        $$ = create_node("op", NULL);
        add_child($$, create_node("symbol", "-"));
    }
    | MULTIPLY {
        $$ = create_node("op", NULL);
        add_child($$, create_node("symbol", "*"));
    }
    | DIVIDE {
        $$ = create_node("op", NULL);
        add_child($$, create_node("symbol", "/"));
    }
    | AND {
        $$ = create_node("op", NULL);
        add_child($$, create_node("symbol", "&"));
    }
    | OR {
        $$ = create_node("op", NULL);
        add_child($$, create_node("symbol", "|"));
    }
    | LT {
        $$ = create_node("op", NULL);
        add_child($$, create_node("symbol", "<"));
    }
    | GT {
        $$ = create_node("op", NULL);
        add_child($$, create_node("symbol", ">"));
    }
    | EQ {
        $$ = create_node("op", NULL);
        add_child($$, create_node("symbol", "="));
    }
;

unaryOp:
    MINUS {
        $$ = create_node("unaryOp", NULL);
        add_child($$, create_node("symbol", "-"));
    }
    | NOT {
        $$ = create_node("unaryOp", NULL);
        add_child($$, create_node("symbol", "~"));
    }
;

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
TreeNode* create_node(const char *tag, const char *value) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->tag = strdup(tag);
    node->value = value ? strdup(value) : NULL;
    node->children = NULL;
    node->child_count = 0;
    return node;
}

void add_child(TreeNode *parent, TreeNode *child) {
    parent->children = realloc(parent->children, sizeof(TreeNode *) * (parent->child_count + 1));
    parent->children[parent->child_count++] = child;
}

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

void free_node(TreeNode *node) {
    if (!node) return;
    free(node->tag);
    if (node->value) free(node->value);
    free(node->children);
    free(node);
}

void take_children(TreeNode *master, TreeNode *slave) {
    if (!master) return;
    if (!slave) return;
    for (int i = 0; i < slave->child_count; i++)
        add_child(master, slave->children[i]);
    free_node(slave);
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s at line %d\n", s, yylineno);
}

int main(int argc, char **argv) {
    if (yyparse() != 0) printf("Parsing failed!\n");
    return 0;
}
