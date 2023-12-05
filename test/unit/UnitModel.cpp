#include "UnitModel.hpp"
#include "../models/FlowExponential.hpp"
#include "../../src/MyVensim.hpp"
#include <iostream>
#include <cassert>

void unit_Model_constructor() {
    MyVensim* factory = MyVensim::getInstance();
    Model* model = factory->createModel();
    System* q1 = model->createSystem("Q1", 100.3);
    assert(q1->getName() == "Q1");
    assert(std::abs(q1->getValue() - 100.3) < 0.001);
}

void unit_Model_beginSystems() {
    MyVensim* factory = MyVensim::getInstance();
    Model* model = factory->createModel();
    System* sys1 = model->createSystem("System1", 100);
    auto it = model->beginSystems();
    assert(it != model->endSystems());
    assert(*it == sys1);
}

void unit_Model_endSystems() {
    MyVensim* factory = MyVensim::getInstance();
    Model* model = factory->createModel();
    model->createSystem("System1", 100);

    auto it = model->beginSystems();
    while (it != model->endSystems()) {
        ++it;
    }

    assert(it == model->endSystems());
}

void unit_Model_beginFlows() {
    MyVensim* factory = MyVensim::getInstance();
    Model* model = factory->createModel();
    Flow* flow1 = model->createFlow<FlowExponential>();
    auto it = model->beginFlows();
    assert(it != model->endFlows());
    assert(*it == flow1);
}

void unit_Model_endFlows() {
    MyVensim* factory = MyVensim::getInstance();
    Model* model = factory->createModel();
    model->createFlow<FlowExponential>();
    auto it = model->beginFlows();
    while (it != model->endFlows()) {
        ++it;
    }

    assert(it == model->endFlows());
}

void unit_Model_beginHistory() {
    MyVensim* factory = MyVensim::getInstance();
    Model* model = factory->createModel();
    model->execute(0, 10);
    auto it = model->beginHistory();
    assert(it != model->endHistory());
}

void unit_Model_endHistory() {
    MyVensim* factory = MyVensim::getInstance();
    Model* model = factory->createModel();
    assert(model->beginHistory() == model->endHistory());
}

void unit_Model_add() {
    MyVensim* factory = MyVensim::getInstance();
    Model* model = factory->createModel();
    System* sys = model->createSystem("System1", 100);
    Flow* flow = model->createFlow<FlowExponential>();
    assert(*model->beginSystems() == sys);
    assert(*model->beginFlows() == flow);
}

void unit_Model_setInitialHistory() {
    MyVensim* factory = MyVensim::getInstance();
    Model* model = factory->createModel();
    model->setInitialHistory();
    assert(model->beginHistory()->empty());
}

void unit_Model_execute() {
    MyVensim* factory = MyVensim::getInstance();
    Model* model = factory->createModel();
    model->execute(0, 10);
    assert(model->beginHistory() != model->endHistory());
}

void run_unit_tests_Model() {
    unit_Model_constructor();
    unit_Model_beginSystems();
    unit_Model_endSystems();
    unit_Model_beginFlows();
    unit_Model_endFlows();
    unit_Model_beginHistory();
    unit_Model_endHistory();
    unit_Model_add();
    unit_Model_setInitialHistory();
    unit_Model_execute();
    std::cout << "All Model unit tests passed!" << std::endl;
}
