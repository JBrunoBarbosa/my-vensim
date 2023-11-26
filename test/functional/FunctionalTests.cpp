#include <iostream>
#include <assert.h>
#include "FunctionalTests.hpp" 
#include "../models/FlowExponential.hpp"
#include "../models/FlowLogistic.hpp"
#include "../../src/SystemImpl.hpp"
#include "../../src/FlowImpl.hpp"
#include "../../src/ModelImpl.hpp"

using namespace std;

void exponentialFuncionalTest(){
    System* pop = new SystemImpl("Populacao 1", 100);
    System* pop2 = new SystemImpl("Populacao 2", 0);
    Flow* expFlow = new FlowExponential("Crescimento", pop, pop2);
    Model* expModel = new ModelImpl();

    expModel->add(pop);
    expModel->add(pop2);
    expModel->add(expFlow);

    assert(pop->getName() == "Populacao 1");
    assert(pop2->getName() == "Populacao 2");
    assert(expFlow->getName() == "Crescimento");

    assert(abs(pop->getValue() - 100.0) < 0.0001);
    assert(abs(pop2->getValue() - 0.0) < 0.0001);

    expModel->execute(0, 100);

    assert(abs(pop->getValue() - 36.6032) < 0.0001);
    assert(abs(pop2->getValue() - 63.3968) < 0.0001);

    delete expModel;
    delete pop;
    delete pop2;
    delete expFlow;
    
    cout << "Teste Exponencial Bem Sucedido" << endl;
}

void logisticalFuncionalTest(){
    System* p = new SystemImpl("Populacao 1", 100);
    System* p2 = new SystemImpl("Populacao 2", 10);
    Flow* logFlow = new FlowLogistic("Crescimento", p, p2);
    Model* logModel = new ModelImpl();
   
    logModel->add(p);
    logModel->add(p2);
    logModel->add(logFlow);

    assert(p->getName() == "Populacao 1");
    assert(p2->getName() == "Populacao 2");    
    assert(logFlow->getName() == "Crescimento");

    assert(abs(p->getValue() - 100.0) < 0.0001);
    assert(abs(p2->getValue() - 10.0) < 0.0001);

    logModel->execute(0, 100);

    assert(abs(p->getValue() - 88.2167) < 0.0001);
    assert(abs(p2->getValue() - 21.7833) < 0.0001);

    delete p;
    delete p2;
    delete logFlow;
    delete logModel;

    cout << "Teste Logistico Bem Sucedido" << endl;
}

void complexFuncionalTest(){

    System* q1 = new SystemImpl("Q1", 100);
    System* q2 = new SystemImpl("Q2", 0);
    System* q3 = new SystemImpl("Q3", 100);
    System* q4 = new SystemImpl("Q4", 0);
    System* q5 = new SystemImpl("Q5", 0);
    Flow* comFlowF = new FlowExponential("Fluxo f", q1, q2);
    Flow* comFlowT = new FlowExponential("Fluxo t", q2, q3);
    Flow* comFlowU = new FlowExponential("Fluxo u", q3, q4);
    Flow* comFlowV = new FlowExponential("Fluxo v", q4, q1);
    Flow* comFlowG = new FlowExponential("Fluxo g", q1, q3);
    Flow* comFlowR = new FlowExponential("Fluxo r", q2, q5);
    Model* comModel = new ModelImpl();

    comModel->add(q1);
    comModel->add(q2);
    comModel->add(q3);
    comModel->add(q4);
    comModel->add(q5);
    comModel->add(comFlowF);
    comModel->add(comFlowT);
    comModel->add(comFlowU);
    comModel->add(comFlowV);
    comModel->add(comFlowG);
    comModel->add(comFlowR);

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

    delete q1;
    delete q2;
    delete q3;
    delete q4;
    delete q5;
    delete comFlowF;
    delete comFlowT;
    delete comFlowU;
    delete comFlowV;
    delete comFlowG;
    delete comFlowR;
    delete comModel;

    cout << "Teste Complexo Bem Sucedido" << endl;
}