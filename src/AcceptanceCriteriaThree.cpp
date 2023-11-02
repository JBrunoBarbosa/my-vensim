#include <iostream>

#include "Model.hpp"
#include "System.hpp"
#include "FlowLogistic.hpp"

using namespace std;

int main () {

    Model* m1 = new Model();
    System* p1 = new System("P1", 100);
    System* p2 = new System("P2", 10);

    Flow* logistc = new FlowLogistic("logistc", p1, p2);

    m1->add(p1);
    m1->add(p2);
    m1->add(logistc);

    m1->execute(0, 100);
    m1->report();

    delete m1;

    return 0;
}