#include "UnitModel.hpp"
#include "../models/FlowExponential.hpp"
#include <iostream>
#include <cassert>

void unit_Model_constructor() {
    System* q1 = new SystemImpl("Q1", 100.3);
    assert(q1->getName() == "Q1");
    assert(std::abs(q1->getValue() - 100.3) < 0.001);
    delete q1;
}

void unit_Model_beginSystems() {
    ModelImpl* model = new ModelImpl();
    SystemImpl* sys1 = new SystemImpl("System1", 100);
    model->add(sys1);

    auto it = model->beginSystems();
    assert(it != model->endSystems());
    assert(*it == sys1);

    delete model;
}

void unit_Model_endSystems() {
    ModelImpl* model = new ModelImpl();
    SystemImpl* sys1 = new SystemImpl("System1", 100);
    model->add(sys1);

    auto it = model->beginSystems();
    while (it != model->endSystems()) {
        ++it;
    }

    assert(it == model->endSystems());
    delete model;
}

void unit_Model_beginFlows() {
    ModelImpl* model = new ModelImpl();
    FlowExponential* flow1 = new FlowExponential();
    model->add(flow1);

    auto it = model->beginFlows();
    assert(it != model->endFlows());
    assert(*it == flow1);

    delete model;
}

void unit_Model_endFlows() {
    ModelImpl* model = new ModelImpl();
    FlowExponential* flow1 = new FlowExponential();
    model->add(flow1);

    auto it = model->beginFlows();
    while (it != model->endFlows()) {
        ++it;
    }

    assert(it == model->endFlows());
    delete model;
}

void unit_Model_beginHistory() {
    ModelImpl* model = new ModelImpl();

    model->execute(0, 10);

    auto it = model->beginHistory();
    assert(it != model->endHistory());

    delete model;
}

void unit_Model_endHistory() {
    ModelImpl* model = new ModelImpl();
    assert(model->beginHistory() == model->endHistory());
    delete model;
}

void unit_Model_add() {
    ModelImpl* model = new ModelImpl();
    System* sys = new SystemImpl("System1", 100);
    Flow* flow = new FlowExponential();
    model->add(sys);
    model->add(flow);

    assert(*model->beginSystems() == sys);
    assert(*model->beginFlows() == flow);

    delete model;
}

void unit_Model_setInitialHistory() {
    ModelImpl* model = new ModelImpl();
    model->setInitialHistory();
    assert(model->beginHistory()->empty());
    delete model;
}

void unit_Model_clearModel() {
    ModelImpl* model = new ModelImpl();
    System* sys = new SystemImpl("System1", 100);
    Flow* flow = new FlowExponential();
    model->add(sys);
    model->add(flow);
    model->clearModel();

    assert(model->beginSystems() == model->endSystems());
    assert(model->beginFlows() == model->endFlows());

    delete model;
}

void unit_Model_execute() {
    ModelImpl* model = new ModelImpl();
    model->execute(0, 10);
    assert(model->beginHistory() != model->endHistory());
    delete model;
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
    unit_Model_clearModel();
    unit_Model_execute();
    std::cout << "All Model unit tests passed!" << std::endl;
}
