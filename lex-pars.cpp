#include <iostream>
#include <stdlib.h>
#include <string>
#include <map>
#include <list>
#include "lex-pars.h"

using namespace std;

operator_node::operator_node(exp_node *L, exp_node *R) {
        left    = L;
        right   = R;
}

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

plus_node::plus_node(exp_node *L, exp_node *R) : operator_node(L,R) {
}

void plus_node::print() {
        cout << "(";
        left->print();
        cout << " + ";
        right->print();
        cout << ")";
}

float plus_node::evaluate() {
        float left_num, right_num;

        left_num  = left->evaluate();
        right_num = right->evaluate();

        num = left_num + right_num;
        cout << "plus_node: " << left_num << " + " << right_num << " = " << num << "\n";
        return (num);
}

times_node::times_node(exp_node *L, exp_node *R) : operator_node(L,R) {
}

void times_node:: print() {
        cout << "(";
        left->print();
        cout << " * ";
        right->print();
        cout << ")";
}

float times_node::evaluate() {
        float left_num, right_num;

        left_num = left->evaluate();
        right_num = right->evaluate();

        num = left_num * right_num;
        cout << "times_node: " << left_num << " * " << right_num << " = " << num << "\n";
        return (num);
}

minus_node::minus_node(exp_node *L, exp_node *R) : operator_node(L, R) {
}

void minus_node::print(){
        cout<<"(";
        left->print();
        cout<<"-";
        right->print();
        cout<<")";
}

float minus_node::evaluate(){
        float left_num,right_num;

        left_num = left->evaluate();
        right_num = right->evaluate();

        num = left_num - right_num;
        cout<<"minus_node: "<<left_num<<"-"<<right_num<<"="<<num<<"\n";

        return (num);
}

divided_node::divided_node(exp_node *L, exp_node *R) : operator_node(L, R){
}

void divided_node::print(){
        cout<<"(";
        left->print();
        cout<<"/";
        right->print();
        cout<<")";
}

float divided_node::evaluate(){
        float left_num,right_num;

        left_num = left->evaluate();
        right_num = right->evaluate();

        num = left_num / right_num;

        cout<<"divided_node: "<<left_num<<"/"<<right_num<<"="<<num<<"\n";

        return (num);
}

small_node::small_node(string left, string right)
        :id_1(left)
        ,id_2(right)
{

}

void small_node::print() {
        cout<<"(";
        cout<<id_1;
        cout<<" < ";
        cout<<id_2;
        cout<<")";
}


float small_node::evaluate() {
        float left_num,right_num;

        left_num = idTable[id_1];
        right_num = idTable[id_2];

        result = (left_num < right_num);

        if(result == 1)
          cout<<"small_node: "<<id_1<<" < "<<id_2<<" "<<"true"<<endl;
        else
          cout<<"small_node: "<<id_1<<" < "<<id_2<<" "<<"false"<<endl;

        return (result);
}

great_node::great_node(string left, string right)
        :id_1(left)
        ,id_2(right)
{

}

void great_node::print() {
        cout<<"(";
        cout<<id_1;
        cout<<" > ";
        cout<<id_2;
        cout<<")";
}

float great_node::evaluate() {
        float left_num, right_num;

        left_num = idTable[id_1];
        right_num = idTable[id_2];

        result = (left_num > right_num);

        if(result == 1)
          cout<<"great_node: "<<id_1<<" > "<<id_2<<" "<<"true"<<endl;
        else
          cout<<"great_node: "<<id_1<<" > "<<id_2<<" "<<"false"<<endl;

        return (result);
}

logical_or_node::logical_or_node(string left, string right)
        :id_1(left)
        ,id_2(right)
{

}

void logical_or_node::print() {
        cout<<"(";
        cout<<id_1;
        cout<<" || ";
        cout<<id_2;
        cout<<")";
}

float logical_or_node::evaluate() {
        float left_num, right_num;

        left_num = idTable[id_1];
        right_num = idTable[id_2];

        result = (left_num || right_num);

        if(result == 1)
          cout<<"logical_or_node: "<<id_1<<" || "<<id_2<<" "<<"true"<<endl;
        else
          cout<<"logical_or_node: "<<id_1<<" || "<<id_2<<" "<<"false"<<endl;

        return (result);
}

logical_or_node::logical_or_node(string left, string right)
        :id_1(left)
        ,id_2(right)
{

}

void logical_or_node::print() {
        cout<<"(";
        cout<<id_1;
        cout<<" || ";
        cout<<id_2;
        cout<<")";
}

float logical_or_node::evaluate() {
        float left_num, right_num;

        left_num = idTable[id_1];
        right_num = idTable[id_2];

        result = (left_num || right_num);

        if(result == 1)
          cout<<"logical_or_node: "<<id_1<<" || "<<id_2<<" "<<"true"<<endl;
        else
          cout<<"logical_or_node: "<<id_1<<" || "<<id_2<<" "<<"false"<<endl;

        return (result);
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
