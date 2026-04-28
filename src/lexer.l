%option noyywrap
%option yylineno
%option c++

%{
#include "parser.tab.hh"
#include <string>

int yycolumn = 1;
/* Update yycolumn whenever a token is matched */
#define YY_USER_ACTION \
  yylloc.first_line = yylloc.last_line = yylineno; \
  yylloc.first_column = yycolumn; \
  yylloc.last_column = yycolumn + yyleng - 1; \
  yycolumn += yyleng;
%}

INT_LIT [1-9][0-9]*|0[xX][0-9A-Fa-f]+|0[0-7]*|0

FLOAT_SUFFIX  [fFlL]
DEC_EXP       [Ee][-+]?[0-9]+
DEC_FLOAT_LIT (([0-9]*\.[0-9]+|[0-9]+\.){DEC_EXP}?|[0-9]+{DEC_EXP}){FLOAT_SUFFIX}?
HEX_EXP       [Pp][-+]?[0-9]+
HEX_FLOAT_LIT (0[xX]([a-fA-F0-9]*\.[a-fA-F0-9]+|[a-fA-F0-9]+\.?){HEX_EXP}){FLOAT_SUFFIX}?
FLOAT_LIT     {DEC_FLOAT_LIT}|{HEX_FLOAT_LIT}

Identifier [A-Za-z_][A-Za-z0-9_]*

MultilineComment "/*"([^*]|[*][^/])*"*/"
SingleLineComment "//"[^\n]*

%%

{MultilineComment} {}
{SingleLineComment} {}

{INT_LIT}       { yylval.int_val = strtol(yytext, nullptr, 0); return INT; }
{FLOAT_LIT}     { yylval.float_val = strtof(yytext, nullptr); return FLOAT; }

"int"           { return INT_TYPE; }
"float"         { return FLOAT_TYPE; }
"void"          { return VOID; }
"const"         { return CONST; }
"return"        { return RETURN; }
"if"            { return IF; }
"else"          { return ELSE; }
"while"         { return WHILE; }
"break"         { return BREAK; }
"continue"      { return CONTINUE; }

{Identifier}    { yylval.token = new string(yytext); return ID; }

"("             { return LP; }
")"             { return RP; }
"["             { return LB; }
"]"             { return RB; }
"{"             { return LC; }
"}"             { return RC; }
","             { return COMMA; }
";"             { return SEMICOLON; }

"!"             { return NOT; }
"="             { return ASSIGN; }
"-"             { return MINUS; }
"+"             { return ADD; }
"*"             { return MUL; }
"/"             { return DIV; }
"%"             { return MOD; }
"&&"            { return AND; }
"||"            { return OR; }
           
"=="            { return EQ; }
"!="            { return NE; }
"<"             { return LT; }
"<="            { return LE; }
">"             { return GT; }
">="            { return GE; }

[\n]            { yycolumn=1; }
[ \r\t]         { /* Ignore useless whitespaces */ }
.               { printf("Error : Mysterious character \"%s\"\n\t at Line %d\n", yytext, yylineno);}

%%
