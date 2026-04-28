%code requires {
#include "ast.hpp"
}

%{
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <FlexLexer.h>
#include "ast.hpp"
#include "checker/checker.hpp"
#include "checker/errReporter.hpp"

using namespace std;

extern FILE* yyin;
class yyFlexLexer;

static ASTNode* g_root = nullptr;
static yyFlexLexer* g_scanner = nullptr;

extern int yylex();

static int currentLine() { return g_scanner ? g_scanner->lineno() : 0; }
static string sval(char* s) { return s ? string(s) : string(); }

void yyerror(const char* s);
%}

%define parse.error verbose
%union { char* str; ASTNode* node; }

%token INT FLOAT VOID CONST RETURN IF ELSE WHILE BREAK CONTINUE
%token LP RP LB RB LC RC COMMA SEMICOLON QUESTION COLON
%token MINUS NOT TILDE ASSIGN ADD MUL DIV MOD AND OR EQ NE LT LE GT GE
%token <str> ID INT_LIT FLOAT_LIT
%token LEX_ERR

%type <node> CompUnit ExtDefList ExtDef VarDecl VarDefList VarDef Type FuncDef ParamListOpt ParamList Param Block BlockItems BlockItem Stmt Exp LOrExp LAndExp EqExp RelExp AddExp MulExp UnaryExp ArgListOpt ArgList PrimaryExp LVal ArrayDimsOpt ArrayDims

%left OR
%left AND
%left EQ NE
%left LT LE GT GE
%left ADD MINUS
%left MUL DIV MOD
%right NOT UMINUS

%%

CompUnit
    : ExtDefList { g_root = $1; }
    ;

ExtDefList
    : ExtDefList ExtDef { $$ = makeAstNode("CompUnit", $1->children, "CompUnit", $1 ? $1->line : currentLine()); $$->children.push_back($2); }
    | ExtDef { $$ = makeAstNode("CompUnit", {$1}, "CompUnit", currentLine()); }
    ;

ExtDef
    : VarDecl { $$ = $1; }
    | FuncDef { $$ = $1; }
    ;

VarDecl
    : Type VarDefList SEMICOLON { $$ = makeAstNode("VarDecl", {$1, $2}, "VarDecl", currentLine()); }
    ;

VarDefList
    : VarDefList COMMA VarDef { $$ = makeAstNode("VarDefList", $1->children, "VarDefList", currentLine()); $$->children.push_back($3); }
    | VarDef { $$ = makeAstNode("VarDefList", {$1}, "VarDefList", currentLine()); }
    ;

VarDef
    : ID ArrayDimsOpt { $$ = makeAstNode("Var", {$2}, sval($1), currentLine()); free($1); }
    | ID ArrayDimsOpt ASSIGN Exp { $$ = makeAstNode("InitVar", {makeAstNode("Var", {$2}, sval($1), currentLine()), $4}, "InitVar", currentLine()); free($1); }
    ;

ArrayDimsOpt
    : /* empty */ { $$ = makeAstNode("ArrayDims", {}, "ArrayDims", currentLine()); }
    | ArrayDims { $$ = $1; }
    ;

ArrayDims
    : ArrayDims LB Exp RB { $$ = makeAstNode("ArrayDims", {$1, $3}, "ArrayDims", currentLine()); }
    | LB Exp RB { $$ = makeAstNode("ArrayDims", {$2}, "ArrayDims", currentLine()); }
    ;

Type
    : INT { $$ = makeAstNode("Type", {}, "int", currentLine()); }
    | FLOAT { $$ = makeAstNode("Type", {}, "float", currentLine()); }
    | VOID { $$ = makeAstNode("Type", {}, "void", currentLine()); }
    ;

FuncDef
    : Type ID LP ParamListOpt RP Block { $$ = makeAstNode("FuncDef", {$1, makeAstNode("Name", {}, sval($2), currentLine()), $4, $6}, "FuncDef", currentLine()); free($2); }
    ;

ParamListOpt
    : /* empty */ { $$ = makeAstNode("Params", {}, "Params", currentLine()); }
    | ParamList { $$ = $1; }
    ;

ParamList
    : ParamList COMMA Param { $$ = makeAstNode("Params", $1->children, "Params", currentLine()); $$->children.push_back($3); }
    | Param { $$ = makeAstNode("Params", {$1}, "Params", currentLine()); }
    ;

Param
    : Type ID { $$ = makeAstNode("Param", {$1, makeAstNode("Name", {}, sval($2), currentLine()), makeAstNode("ArrayDims", {}, "ArrayDims", currentLine())}, "Param", currentLine()); free($2); }
    | Type ID ArrayDimsOpt { $$ = makeAstNode("Param", {$1, makeAstNode("Name", {}, sval($2), currentLine()), $3}, "Param", currentLine()); free($2); }
    ;

Block
    : LC BlockItems RC { $$ = makeAstNode("Block", {$2}, "Block", currentLine()); }
    ;

BlockItems
    : BlockItems BlockItem { $$ = makeAstNode("BlockItems", $1->children, "BlockItems", currentLine()); $$->children.push_back($2); }
    | /* empty */ { $$ = makeAstNode("BlockItems", {}, "BlockItems", currentLine()); }
    ;

BlockItem
    : VarDecl { $$ = $1; }
    | Stmt { $$ = $1; }
    ;

Stmt
    : SEMICOLON { $$ = makeAstNode("EmptyStmt", {}, "EmptyStmt", currentLine()); }
    | Exp SEMICOLON { $$ = makeAstNode("ExprStmt", {$1}, "ExprStmt", currentLine()); }
    | RETURN Exp SEMICOLON { $$ = makeAstNode("Return", {$2}, "Return", currentLine()); }
    | IF LP Exp RP Stmt { $$ = makeAstNode("If", {$3, $5}, "If", currentLine()); }
    | IF LP Exp RP Stmt ELSE Stmt { $$ = makeAstNode("IfElse", {$3, $5, $7}, "IfElse", currentLine()); }
    | WHILE LP Exp RP Stmt { $$ = makeAstNode("While", {$3, $5}, "While", currentLine()); }
    | BREAK SEMICOLON { $$ = makeAstNode("Break", {}, "Break", currentLine()); }
    | CONTINUE SEMICOLON { $$ = makeAstNode("Continue", {}, "Continue", currentLine()); }
    | Block { $$ = $1; }
    ;

Exp
    : LVal ASSIGN Exp { $$ = makeAstNode("Assign", {$1, $3}, "Assign", currentLine()); }
    | LOrExp { $$ = $1; }
    ;

LVal
    : ID { $$ = makeAstNode("Name", {}, sval($1), currentLine()); free($1); }
    | ID ArrayDimsOpt { $$ = makeAstNode("Name", {$2}, sval($1), currentLine()); free($1); }
    ;

LOrExp
    : LOrExp OR LAndExp { $$ = makeAstNode("||", {$1, $3}, "||", currentLine()); }
    | LAndExp { $$ = $1; }
    ;

LAndExp
    : LAndExp AND EqExp { $$ = makeAstNode("&&", {$1, $3}, "&&", currentLine()); }
    | EqExp { $$ = $1; }
    ;

EqExp
    : EqExp EQ RelExp { $$ = makeAstNode("==", {$1, $3}, "==", currentLine()); }
    | EqExp NE RelExp { $$ = makeAstNode("!=", {$1, $3}, "!=", currentLine()); }
    | RelExp { $$ = $1; }
    ;

RelExp
    : RelExp LT AddExp { $$ = makeAstNode("<", {$1, $3}, "<", currentLine()); }
    | RelExp LE AddExp { $$ = makeAstNode("<=", {$1, $3}, "<=", currentLine()); }
    | RelExp GT AddExp { $$ = makeAstNode(">", {$1, $3}, ">", currentLine()); }
    | RelExp GE AddExp { $$ = makeAstNode(">=", {$1, $3}, ">=", currentLine()); }
    | AddExp { $$ = $1; }
    ;

AddExp
    : AddExp ADD MulExp { $$ = makeAstNode("+", {$1, $3}, "+", currentLine()); }
    | AddExp MINUS MulExp { $$ = makeAstNode("-", {$1, $3}, "-", currentLine()); }
    | MulExp { $$ = $1; }
    ;

MulExp
    : MulExp MUL UnaryExp { $$ = makeAstNode("*", {$1, $3}, "*", currentLine()); }
    | MulExp DIV UnaryExp { $$ = makeAstNode("/", {$1, $3}, "/", currentLine()); }
    | MulExp MOD UnaryExp { $$ = makeAstNode("%", {$1, $3}, "%", currentLine()); }
    | UnaryExp { $$ = $1; }
    ;

UnaryExp
    : PrimaryExp { $$ = $1; }
    | MINUS UnaryExp %prec UMINUS { $$ = makeAstNode("neg", {$2}, "neg", currentLine()); }
    | NOT UnaryExp { $$ = makeAstNode("!", {$2}, "!", currentLine()); }
    | TILDE UnaryExp { $$ = makeAstNode("~", {$2}, "~", currentLine()); }
    | ID LP ArgListOpt RP { $$ = makeAstNode("Call", {makeAstNode("Name", {}, sval($1), currentLine()), $3}, "Call", currentLine()); free($1); }
    ;

ArgListOpt
    : /* empty */ { $$ = makeAstNode("Args", {}, "Args", currentLine()); }
    | ArgList { $$ = $1; }
    ;

ArgList
    : ArgList COMMA Exp { $$ = makeAstNode("Args", $1->children, "Args", currentLine()); $$->children.push_back($3); }
    | Exp { $$ = makeAstNode("Args", {$1}, "Args", currentLine()); }
    ;

PrimaryExp
    : LP Exp RP { $$ = $2; }
    | LVal { $$ = $1; }
    | INT_LIT { $$ = makeAstNode("Int", {}, sval($1), currentLine()); free($1); }
    | FLOAT_LIT { $$ = makeAstNode("Float", {}, sval($1), currentLine()); free($1); }
    ;

%%

int yylex() { return g_scanner ? g_scanner->yylex() : 0; }

void yyerror(const char* s) {
    cerr << "Parse error: " << s << endl;
}

int main(int argc, char** argv) {
    if (argc < 2) return 1;
    ifstream in(argv[1]);
    if (!in) return 1;
    yyFlexLexer scanner(&in);
    g_scanner = &scanner;
    int ret = yyparse();
    if (ret == 0 && g_root) {
#ifndef DISABLE_SEMANTIC_CHECK
        ErrReporter reporter;
        Checker checker(reporter);
        checker.check(g_root);
        if (reporter.hasError()) {
            reporter.print();
            return 1;
        }
#endif
        printAst(g_root);
        return 0;
    }
    return 1;
}
