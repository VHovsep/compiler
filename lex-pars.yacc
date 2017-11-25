%{
#include <iostream>
#include <string>
#include <stdlib.h>
#include <map>
#include <list>
#include "lex-pars.h"

using namespace std;

 pgm *root;

 int line_num = 1;

int yylex();
void yyerror(char * s);

%}

%start program

%union {
  float num;
  char *id;
  exp_node *expnode;
  list<statement *> *stmts;
  statement *st;
  pgm *prog;
}

%error-verbose

%token <num> NUMBER
%token <id> ID
%token <if> IF
%token NEWLINE
%token EQUALS PRINT
%token NOT_EQUAL
%token SMALL GREAT
%token SMALL_OR_EQUAL
%token GREAT_OR_EQUAL
%token DOT
%token LOGICAL_AND
%token LOGICAL_OR
%token SEMICOLON COMMA
%token PREPROC
%token IMPLIES
%left LBRACK RBRACK
%left LBRACE RBRACE
%left PLUS MINUS
%left TIMES DIVIDED
%left LPAREN RPAREN
%type <expnode> exp
%type <stmts> stmtlist
%type <st> stmt
%type <prog> program

%%

program : stmtlist { $$ = new pgm($1); root = $$; }
;

stmtlist : stmtlist NEWLINE
           {
             $$ = $1;
           }
         | stmtlist stmt NEWLINE
            {
              $$ = $1;
              $1->push_back($2);
            }
         | stmtlist error NEWLINE
           {
             $$ = $1;
             yyclearin; }
         |
           { $$ = new list<statement *>(); }
;

stmt: ID EQUALS exp {
$$ = new assignment_stmt($1, $3);
           }

| PRINT ID {
  $$ = new print_stmt($2);
 }

| IF {
  printf("Unsuppored inst\n");
 }


 ;

exp:    LPAREN exp RPAREN  {
          $$ = $2; }

        |       NUMBER {
          $$ = new number_node($1); }

        |       ID {
          $$ = new id_node($1); }

;

%%
main()
{
  //  yydebug = 1;
  yyparse();
  //root->evaluate();
  //root->print();
}

void yyerror(char * s)
{
  fprintf(stderr, "line %d: %s\n", line_num, s);
}
