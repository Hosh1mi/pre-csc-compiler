%code requires {
#include "ast.h"
}

%{
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <FlexLexer.h>
#include "ast.h"

using namespace std;

extern FILE* yyin;
class yyFlexLexer;

static ASTNode* g_root = nullptr;
static yyFlexLexer* g_scanner = nullptr;

extern int yylex();

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

%type <node> CompUnit ExtDefList ExtDef VarDecl VarDefList VarDef Type FuncDef ParamListOpt ParamList Param Block BlockItems BlockItem Stmt Exp LOrExp LAndExp EqExp RelExp AddExp MulExp UnaryExp ArgListOpt ArgList PrimaryExp

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
    : ExtDefList ExtDef { $$ = makeAstNode("CompUnit", {$1, $2}); }
    | ExtDef { $$ = makeAstNode("CompUnit", {$1}); }
    ;

ExtDef
    : VarDecl { $$ = $1; }
    | FuncDef { $$ = $1; }
    ;

VarDecl
    : Type VarDefList SEMICOLON { $$ = makeAstNode("VarDecl", {$1, $2}); }
    ;

VarDefList
    : VarDefList COMMA VarDef { $$ = makeAstNode("VarDefList", {$1, $3}); }
    | VarDef { $$ = makeAstNode("VarDefList", {$1}); }
    ;

VarDef
    : ID { $$ = makeAstNode("Var", {}, sval($1)); free($1); }
    | ID ASSIGN Exp { $$ = makeAstNode("InitVar", {makeAstNode("Var", {}, sval($1)), $3}); free($1); }
    ;

Type
    : INT { $$ = makeAstNode("Type", {}, "int"); }
    | FLOAT { $$ = makeAstNode("Type", {}, "float"); }
    | VOID { $$ = makeAstNode("Type", {}, "void"); }
    ;

FuncDef
    : Type ID LP ParamListOpt RP Block { $$ = makeAstNode("FuncDef", {$1, makeAstNode("Name", {}, sval($2)), $4, $6}); free($2); }
    ;

ParamListOpt
    : /* empty */ { $$ = makeAstNode("Params", {}); }
    | ParamList { $$ = $1; }
    ;

ParamList
    : ParamList COMMA Param { $$ = makeAstNode("Params", {$1, $3}); }
    | Param { $$ = makeAstNode("Params", {$1}); }
    ;

Param
    : Type ID { $$ = makeAstNode("Param", {$1, makeAstNode("Name", {}, sval($2))}); free($2); }
    ;

Block
    : LC BlockItems RC { $$ = makeAstNode("Block", {$2}); }
    ;

BlockItems
    : BlockItems BlockItem { $$ = makeAstNode("BlockItems", {$1, $2}); }
    | /* empty */ { $$ = makeAstNode("BlockItems", {}); }
    ;

BlockItem
    : VarDecl { $$ = $1; }
    | Stmt { $$ = $1; }
    ;

Stmt
    : SEMICOLON { $$ = makeAstNode("EmptyStmt", {}); }
    | Exp SEMICOLON { $$ = makeAstNode("ExprStmt", {$1}); }
    | RETURN Exp SEMICOLON { $$ = makeAstNode("Return", {$2}); }
    | IF LP Exp RP Stmt { $$ = makeAstNode("If", {$3, $5}); }
    | IF LP Exp RP Stmt ELSE Stmt { $$ = makeAstNode("IfElse", {$3, $5, $7}); }
    | WHILE LP Exp RP Stmt { $$ = makeAstNode("While", {$3, $5}); }
    | BREAK SEMICOLON { $$ = makeAstNode("Break", {}); }
    | CONTINUE SEMICOLON { $$ = makeAstNode("Continue", {}); }
    | Block { $$ = $1; }
    ;

Exp
    : ID ASSIGN Exp { $$ = makeAstNode("Assign", {makeAstNode("Name", {}, sval($1)), $3}); free($1); }
    | LOrExp { $$ = $1; }
    ;

LOrExp
    : LOrExp OR LAndExp { $$ = makeAstNode("||", {$1, $3}); }
    | LAndExp { $$ = $1; }
    ;

LAndExp
    : LAndExp AND EqExp { $$ = makeAstNode("&&", {$1, $3}); }
    | EqExp { $$ = $1; }
    ;

EqExp
    : EqExp EQ RelExp { $$ = makeAstNode("==", {$1, $3}); }
    | EqExp NE RelExp { $$ = makeAstNode("!=", {$1, $3}); }
    | RelExp { $$ = $1; }
    ;

RelExp
    : RelExp LT AddExp { $$ = makeAstNode("<", {$1, $3}); }
    | RelExp LE AddExp { $$ = makeAstNode("<=", {$1, $3}); }
    | RelExp GT AddExp { $$ = makeAstNode(">", {$1, $3}); }
    | RelExp GE AddExp { $$ = makeAstNode(">=", {$1, $3}); }
    | AddExp { $$ = $1; }
    ;

AddExp
    : AddExp ADD MulExp { $$ = makeAstNode("+", {$1, $3}); }
    | AddExp MINUS MulExp { $$ = makeAstNode("-", {$1, $3}); }
    | MulExp { $$ = $1; }
    ;

MulExp
    : MulExp MUL UnaryExp { $$ = makeAstNode("*", {$1, $3}); }
    | MulExp DIV UnaryExp { $$ = makeAstNode("/", {$1, $3}); }
    | MulExp MOD UnaryExp { $$ = makeAstNode("%", {$1, $3}); }
    | UnaryExp { $$ = $1; }
    ;

UnaryExp
    : PrimaryExp { $$ = $1; }
    | MINUS UnaryExp %prec UMINUS { $$ = makeAstNode("neg", {$2}); }
    | NOT UnaryExp { $$ = makeAstNode("!", {$2}); }
    | TILDE UnaryExp { $$ = makeAstNode("~", {$2}); }
    | ID LP ArgListOpt RP { $$ = makeAstNode("Call", {makeAstNode("Name", {}, sval($1)), $3}); free($1); }
    ;

ArgListOpt
    : /* empty */ { $$ = makeAstNode("Args", {}); }
    | ArgList { $$ = $1; }
    ;

ArgList
    : ArgList COMMA Exp { $$ = makeAstNode("Args", {$1, $3}); }
    | Exp { $$ = makeAstNode("Args", {$1}); }
    ;

PrimaryExp
    : LP Exp RP { $$ = $2; }
    | ID { $$ = makeAstNode("Name", {}, sval($1)); free($1); }
    | INT_LIT { $$ = makeAstNode("Int", {}, sval($1)); free($1); }
    | FLOAT_LIT { $$ = makeAstNode("Float", {}, sval($1)); free($1); }
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
        printAst(g_root);
        return 0;
    }
    return 1;
}
