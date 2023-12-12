#include <iostream>
#include <assert.h>
#include "FunctionalTests.hpp" 
#include "../models/FlowExponential.hpp"
#include "../models/FlowLogistic.hpp"
#include "../../src/MyVensim.hpp"

using namespace std;

void exponentialFuncionalTest(){

    MyVensim* factory = MyVensim::getInstance();
    Model* model = factory->createModel();
    System* pop = model->createSystem("Populacao 1", 100);
    System* pop2 = model->createSystem("Populacao 2", 0);
    Flow* expFlow = model->createFlow<FlowExponential>("Crescimento", pop, pop2);

    assert(pop->getName() == "Populacao 1");
    assert(pop2->getName() == "Populacao 2");
    assert(expFlow->getName() == "Crescimento");

    assert(abs(pop->getValue() - 100.0) < 0.0001);
    assert(abs(pop2->getValue() - 0.0) < 0.0001);

    model->execute(0, 100);

    assert(abs(pop->getValue() - 36.6032) < 0.0001);
    assert(abs(pop2->getValue() - 63.3968) < 0.0001);
    
    cout << "Teste Exponencial Bem Sucedido" << endl;
}

void logisticalFuncionalTest(){

    MyVensim* factory = MyVensim::getInstance();
    Model* model = factory->createModel();
    System* p = model->createSystem("Populacao 1", 100);
    System* p2 = model->createSystem("Populacao 2", 10);
    Flow* logFlow = model->createFlow<FlowLogistic>("Crescimento", p, p2);

    assert(p->getName() == "Populacao 1");
    assert(p2->getName() == "Populacao 2");    
    assert(logFlow->getName() == "Crescimento");

    assert(abs(p->getValue() - 100.0) < 0.0001);
    assert(abs(p2->getValue() - 10.0) < 0.0001);

    model->execute(0, 100);

    assert(abs(p->getValue() - 88.2167) < 0.0001);
    assert(abs(p2->getValue() - 21.7833) < 0.0001);

    cout << "Teste Logistico Bem Sucedido" << endl;
}

void complexFuncionalTest(){

    MyVensim* factory = MyVensim::getInstance();
    Model* model = factory->createModel();
    System* q1 = model->createSystem("Q1", 100);
    System* q2 = model->createSystem("Q2", 0);
    System* q3 = model->createSystem("Q3", 100);
    System* q4 = model->createSystem("Q4", 0);
    System* q5 = model->createSystem("Q5", 0);
    Flow* comFlowF = model->createFlow<FlowExponential>("Fluxo f", q1, q2);
    Flow* comFlowT = model->createFlow<FlowExponential>("Fluxo t", q2, q3);
    Flow* comFlowU = model->createFlow<FlowExponential>("Fluxo u", q3, q4);
    Flow* comFlowV = model->createFlow<FlowExponential>("Fluxo v", q4, q1);
    Flow* comFlowG = model->createFlow<FlowExponential>("Fluxo g", q1, q3);
    Flow* comFlowR = model->createFlow<FlowExponential>("Fluxo r", q2, q5);

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

    model->execute(0, 100);

    assert(abs(q1->getValue() - 31.8513) < 0.0001);
    assert(abs(q2->getValue() - 18.4003) < 0.0001);
    assert(abs(q3->getValue() - 77.1143) < 0.0001);
    assert(abs(q4->getValue() - 56.1728) < 0.0001);
    assert(abs(q5->getValue() - 16.4612) < 0.0001);

    cout << "Teste Complexo Bem Sucedido" << endl;
}