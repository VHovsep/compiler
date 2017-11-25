#include <iostream>
#include <stdlib.h>
#include <string>
#include <map>
#include <list>

using namespace std;

class exp_node {
        public:
                float num;
                virtual void print() = 0;
                virtual float evaluate() = 0;
};

class number_node : public exp_node {

        public:
                number_node(float value);
                void print();
                float evaluate();
};

class id_node : public exp_node {
        protected:
                string id;

        public:
                id_node(string value);
                void print();
                float evaluate();
};

class statement {
        public:
                virtual void print() {}
                virtual void evaluate() = 0;
};

class assignment_stmt : public statement {
        protected:
                string id;
                exp_node *exp;
        public:
                assignment_stmt(string name, exp_node *expression);
                void print();
                void evaluate();
};

class print_stmt: public statement {
        protected:
                string id;
        public:
                print_stmt(string id);
                void evaluate();
};

class pgm {
        protected:
                list<statement *> *stmts;
        public:
                pgm(list<statement *> *stmtlist);
                void evaluate();
                void print();
};

extern map<string, float> idTable;
extern pgm *root;
