%option c++
%option noyywrap
%option yylineno

%{
#include <stdio.h>
#include <fstream>      // std::filebuf
#include <iostream>     // std::ios, std::istream, std::cout

enum Token {
    INT=258, 
    FLOAT, 
    VOID, 
    CONST, 
    RETURN, 
    IF, 
    ELSE, 
    WHILE, 
    BREAK, 
    CONTINUE,
    LP, 
    RP,
    LB, 
    RB,
    LC, 
    RC, 
    COMMA, 
    SEMICOLON, 
    QUESTION, 
    COLON,
    MINUS, 
    NOT, 
    TILDE, 
    ASSIGN, 
    ADD, 
    MUL, 
    DIV, 
    MOD, 
    AND,
    OR,
    EQ, 
    NE, 
    LT, 
    LE, 
    GT, 
    GE,
    ID, 
    INT_LIT, 
    FLOAT_LIT,
    LEX_ERR
};
%}

Digit [0-9]
Letter [A-Za-z]
Identifier [A-Za-z_][A-Za-z0-9_]*
Integer [1-9]{Digit}*|0[xX][0-9A-Fa-f]+|0[0-7]*
Float (([.]{Digit}+([eE][+-]?{Digit}+)?[fF]?)|({Digit}+[.]{Digit}*([eE][+-]?{Digit}+)?[fF]?)|({Digit}+[eE][+-]?{Digit}+[fF]?))

ERR_OCT 0{Digit}*
ERR_IDENTITIFER {Digit}[A-Za-z0-9_]+
ERR_FLOAT {Digit}[fF]

MultilineComment "/*"([^\*]|(\*)*[^\*/])*(\*)*"*/"
SingleLineComment "//"[^\n]*

%%

{MultilineComment} {}
{SingleLineComment} {}

"int"      { return INT; }
"float"    { return FLOAT; }
"void"     { return VOID; }
"const"    { return CONST; }
"return"   { return RETURN; }
"if"       { return IF; }
"else"     { return ELSE; }
"while"    { return WHILE; }
"break"    { return BREAK; }
"continue" { return CONTINUE; }

"("  { return LP; }
")"  { return RP; }
"["  { return LB; }
"]"  { return RB; }
"{"  { return LC; }
"}"  { return RC; }
","  { return COMMA; }
";"  { return SEMICOLON; }
"?"  { return QUESTION; }
":"  { return COLON; }
"!"  { return NOT; }
"="  { return ASSIGN; }
"-"  { return MINUS; }
"+"  { return ADD; }
"*"  { return MUL; }
"/"  { return DIV; }
"%"  { return MOD; }
"&&" { return AND; }
"||" { return OR; }
"==" { return EQ; }
"!=" { return NE; }
"<"  { return LT; }
"<=" { return LE; }
">"  { return GT; }
">=" { return GE; }
"~"  { return TILDE; }

{Identifier}      { return ID; }
{Integer}         { return INT_LIT; }
{Float}           { return FLOAT_LIT; }
{ERR_FLOAT}       { printf("Lexical error - line %d : %s\n", yylineno, yytext); return LEX_ERR;}
{ERR_OCT}         { printf("Lexical error - line %d : %s\n", yylineno, yytext); return LEX_ERR;}
{ERR_IDENTITIFER} { printf("Lexical error - line %d : %s\n", yylineno, yytext); return LEX_ERR;}

[ \t\r\n]+ {}
. { return LEX_ERR; }

%%

int main(int argc, char** argv) { 
    if(argc > 1) { 
        std::filebuf fb ; 
        fb.open(argv[1], std::ios::in); 
        std::istream in(&fb); 
        FlexLexer* lexer = new yyFlexLexer(&in); 
        int symbol; while( symbol = lexer->yylex()) { }; 
        fb.close(); 
    } else 
        printf("No source file given!\n"); 
    return 0; 
}