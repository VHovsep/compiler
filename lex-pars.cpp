#include <iostream>
#include <stdlib.h>
#include <string>
#include <map>
#include <list>
#include "lex-pars.h"

using namespace std;

number_node::number_node(float value) {
        num = value;
}

void number_node:: print() {
        cout << num;
}

float number_node::evaluate() {
        cout << "number_node: operand = " << num << endl;
        return num; }

        id_node::id_node(string value) : id(value) {}

        void id_node:: print() {
                cout << id;
        }

float id_node::evaluate() {
        cout << "id_node: " << id << " = " << idTable[id] << endl;
        return idTable[id];
}

assignment_stmt::assignment_stmt(string name, exp_node *expression)
        : id(name), exp(expression) {}

        void assignment_stmt::print() {
                cout << id << " = ";
                exp->print();
                cout << endl;
        }
void assignment_stmt::evaluate() {
        float result = exp->evaluate();
        cout << "assignment_node: " << id << " = " << result << endl << endl;
        idTable[id] = result;
}

print_stmt::print_stmt (string name) : id(name) { }

void print_stmt::evaluate() {
        cout << "print_node: " << id << " = " << idTable[id] << endl << endl;
}

pgm::pgm(list<statement *> *stmtList) : stmts(stmtList) {}

void pgm::evaluate() {
        list<statement *>::iterator stmtIter;
        for (stmtIter = stmts->begin(); stmtIter != stmts->end();
                        stmtIter++) {
                (*stmtIter)->print();
                (*stmtIter)->evaluate();
        }
}

void pgm::print() {
        list<statement *>::iterator stmtIter;
        cout<<"\nGoing to print AST\n";
        for (stmtIter = stmts->begin(); stmtIter != stmts->end();
                        stmtIter++) {
                (*stmtIter)->print();
        }
        cout<<"\nAST printed \n";
}

map<string, float> idTable;
