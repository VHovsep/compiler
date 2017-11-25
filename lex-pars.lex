%{
#include <string.h>
#include "lex-pars.h"
#include "y.tab.h"

extern int line_num;

%}

DIGIT [0-9]
LETTER [a-zA-Z]

%%

"if"    {printf("<'if', keyword>\n"); return IF;}

"print"   { printf("<'print', keyword>\n"); return PRINT; }

{DIGIT}+  { printf("<num, NUMBER>\n"); yylval.num = atof(yytext); return NUMBER; }

{LETTER}[0-9a-zA-Z]* { printf("<id, ID>\n"); yylval.id = strdup(yytext); return ID; }

[ \t\f\r]                // ignore white space 

"\n"      { printf("<'\\n', NEWLINE>\n"); line_num++; return NEWLINE; }

"+"     { printf("<'+', PLUS>\n"); return PLUS;   }

"*"     { printf("<'*', TIMES>\n"); return TIMES;  }

"="     { printf("<'=', EQUALS>\n"); return EQUALS; }

"-"     { printf("<'-', MINUS>\n"); return MINUS; }

"/"     { printf("<'/', DIVIDED>\n"); return DIVIDED; }

"<"     { printf("<'<', SMALL>\n"); return SMALL; }
"<="    { printf("<'<=', SMALL_OR_EQUAL>\n"); return SMALL_OR_EQUAL; }

">"     { printf("<'>', GREAT>\n"); return GREAT; }

">="    { printf("<'>=', GREAT_OR_EQUAL>\n"); return GREAT_OR_EQUAL; }

"("     { printf("<'(', LPAREN>\n"); return LPAREN; }

")"     { printf("<')', RPAREN>\n"); return RPAREN; }

"{"     { printf("<'{', LBRACE>\n"); return LBRACE; }

"}"     { printf("<'}', RBRACE>\n"); return RBRACE; }

"["     { printf("<'[', LBRACK>\n"); return LBRACK; }

"]"     { printf("<']', RBRACK>\n"); return RBRACK; }

"!="    { printf("<'!=', NOT_EQUAL>\n"); return NOT_EQUAL; }

"&&"    { printf("<'&&', LOGICAL_AND>\n"); return LOGICAL_AND; }

"||"    { printf("<'||', LOGICAL_OR>\n"); return LOGICAL_OR; }

"->"    { printf("<'->', IMPLIES>\n"); return IMPLIES; }

"."     { printf("<'.', DOT>\n"); return DOT; }

";"     { printf("<';', SEMICOLON>\n"); return SEMICOLON; }

","     { printf("<',', COMMA>\n"); return COMMA; }

"#"     { printf("<'#, PREPROC>\n"); return PREPROC; }

. { printf("error token: %s on line %d\n", yytext, line_num); yymore(); }
%%
