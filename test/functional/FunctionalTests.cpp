#include <iostream>
#include <assert.h>
#include "FunctionalTests.hpp" 
#include "../models/FlowExponential.hpp"
#include "../models/FlowLogistic.hpp"
#include "../../src/MyVensim.hpp"

using namespace std;

void exponentialFuncionalTest(){

    MyVensim* factory = MyVensim::getInstance();
    Model* expModel = factory->createModel();
    System* pop = factory->createSystem("Populacao 1", 100);
    System* pop2 = factory->createSystem("Populacao 2", 0);
    Flow* expFlow = factory->createFlow<FlowExponential>("Crescimento", pop, pop2);

    assert(pop->getName() == "Populacao 1");
    assert(pop2->getName() == "Populacao 2");
    assert(expFlow->getName() == "Crescimento");

    assert(abs(pop->getValue() - 100.0) < 0.0001);
    assert(abs(pop2->getValue() - 0.0) < 0.0001);

    expModel->execute(0, 100);

    assert(abs(pop->getValue() - 36.6032) < 0.0001);
    assert(abs(pop2->getValue() - 63.3968) < 0.0001);
    
    cout << "Teste Exponencial Bem Sucedido" << endl;
}

void logisticalFuncionalTest(){

    MyVensim* factory = MyVensim::getInstance();
    Model* logModel = factory->createModel();
    System* p = factory->createSystem("Populacao 1", 100);
    System* p2 = factory->createSystem("Populacao 2", 10);
    Flow* logFlow = factory->createFlow<FlowLogistic>("Crescimento", p, p2);

    assert(p->getName() == "Populacao 1");
    assert(p2->getName() == "Populacao 2");    
    assert(logFlow->getName() == "Crescimento");

    assert(abs(p->getValue() - 100.0) < 0.0001);
    assert(abs(p2->getValue() - 10.0) < 0.0001);

    logModel->execute(0, 100);

    assert(abs(p->getValue() - 88.2167) < 0.0001);
    assert(abs(p2->getValue() - 21.7833) < 0.0001);

    cout << "Teste Logistico Bem Sucedido" << endl;
}

void complexFuncionalTest(){

    MyVensim* factory = MyVensim::getInstance();
    Model* comModel = factory->createModel();
    System* q1 = factory->createSystem("Q1", 100);
    System* q2 = factory->createSystem("Q2", 0);
    System* q3 = factory->createSystem("Q3", 100);
    System* q4 = factory->createSystem("Q4", 0);
    System* q5 = factory->createSystem("Q5", 0);
    Flow* comFlowF = factory->createFlow<FlowExponential>("Fluxo f", q1, q2);
    Flow* comFlowT = factory->createFlow<FlowExponential>("Fluxo t", q2, q3);
    Flow* comFlowU = factory->createFlow<FlowExponential>("Fluxo u", q3, q4);
    Flow* comFlowV = factory->createFlow<FlowExponential>("Fluxo v", q4, q1);
    Flow* comFlowG = factory->createFlow<FlowExponential>("Fluxo g", q1, q3);
    Flow* comFlowR = factory->createFlow<FlowExponential>("Fluxo r", q2, q5);

    assert(q1->getName() == "Q1");
    assert(q2->getName() == "Q2");
    assert(q3->getName() == "Q3");
    assert(q4->getName() == "Q4");
    assert(q5->getName() == "Q5");
    assert(comFlowF->getName() == "Fluxo f");
    assert(comFlowT->getName() == "Fluxo t");
    assert(comFlowU->getName() == "Fluxo u");
    assert(comFlowV->getName() == "Fluxo v");
    assert(comFlowG->getName() == "Fluxo g");
    assert(comFlowR->getName() == "Fluxo r");

    assert(abs(q1->getValue() - 100.0) < 0.0001);
    assert(abs(q2->getValue() - 0.0) < 0.0001);
    assert(abs(q3->getValue() - 100.0) < 0.0001);
    assert(abs(q4->getValue() - 0.0) < 0.0001);
    assert(abs(q5->getValue() - 0.0) < 0.0001);

    comModel->execute(0, 100);

    assert(abs(q1->getValue() - 31.8513) < 0.0001);
    assert(abs(q2->getValue() - 18.4003) < 0.0001);
    assert(abs(q3->getValue() - 77.1143) < 0.0001);
    assert(abs(q4->getValue() - 56.1728) < 0.0001);
    assert(abs(q5->getValue() - 16.4612) < 0.0001);

    cout << "Teste Complexo Bem Sucedido" << endl;
}