#include <iostream>

#include "Model.hpp"
#include "System.hpp"
#include "FlowExponential.hpp"

using namespace std;

int main () {

    Model* m1 = new Model();
    System* pop1 = new System("Pop 1", 100);
    System* pop2 = new System("Pop 2", 0);

    Flow* exponential = new FlowExponential("v", pop1, pop2);

    m1->add(pop1);
    m1->add(pop2);
    m1->add(exponential);

    m1->execute(0, 100);
    m1->report();

    delete m1;
    delete pop1;
    delete pop2;
    delete exponential;

    return 0;
}