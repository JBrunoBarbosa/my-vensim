#include <iostream>

#include "Model.hpp"
#include "System.hpp"
#include "FlowExponential.hpp"

using namespace std;

int main () {

    Model* m1 = new Model();
    System* q1 = new System("Q1", 100);
    System* q2 = new System("Q2", 0);
    System* q3 = new System("Q3", 100);
    System* q4 = new System("Q4", 0);
    System* q5 = new System("Q5", 0);

    Flow* v = new FlowExponential("v", q4, q1);
    Flow* u = new FlowExponential("u", q3, q4);
    Flow* g = new FlowExponential("g", q1, q3);
    Flow* f = new FlowExponential("f", q1, q2);
    Flow* t = new FlowExponential("t", q2, q3);
    Flow* r = new FlowExponential("r", q2, q5);

    m1->add(q1);
    m1->add(q2);
    m1->add(q3);
    m1->add(q4);
    m1->add(q5);
    m1->add(v);
    m1->add(u);
    m1->add(g);
    m1->add(f);
    m1->add(t);
    m1->add(r);

    m1->execute(0, 100);
    m1->report();

    delete m1;
    delete q1;
    delete q2;
    delete q3;
    delete q4;
    delete q5;
    delete v;
    delete u;
    delete g;
    delete f;
    delete t;
    delete r;

    return 0;
}