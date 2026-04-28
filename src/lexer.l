%option noyywrap
%option yylineno

%{
#include "parser.tab.hh"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
%}

Digit [0-9]
Letter [A-Za-z]
Identifier [A-Za-z_][A-Za-z0-9_]*
Integer [1-9]{Digit}*|0[xX][0-9A-Fa-f]+|0[0-7]*|0
Float (([.]{Digit}+([eE][+-]?{Digit}+)?[fF]?)|({Digit}+[.]{Digit}*([eE][+-]?{Digit}+)?[fF]?)|({Digit}+[eE][+-]?{Digit}+[fF]?))

ERR_OCT 0{Digit}+
ERR_IDENTITIFER {Digit}[A-Za-z0-9_]+
ERR_FLOAT {Digit}[fF]

MultilineComment "/*"([^*]|[*][^/])*"*/"
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

{Identifier}      { yylval.str = strdup(yytext); return ID; }
{Integer}         { yylval.str = strdup(yytext); return INT_LIT; }
{Float}           { yylval.str = strdup(yytext); return FLOAT_LIT; }
{ERR_FLOAT}       { printf("Lexical error - line %d : %s\n", yylineno, yytext); return LEX_ERR;}
{ERR_OCT}         { printf("Lexical error - line %d : %s\n", yylineno, yytext); return LEX_ERR;}
{ERR_IDENTITIFER} { printf("Lexical error - line %d : %s\n", yylineno, yytext); return LEX_ERR;}

[ \t\r\n]+ {}
. { return LEX_ERR; }

%%
