#include "UnitFlow.hpp"
#include "../models/FlowExponential.hpp"
#include "../../src/MyVensim.hpp"
#include <iostream>

void unit_Flow_constructor() {
    MyVensim* factory = MyVensim::getInstance();
    Model* model = factory->createModel();
    Flow* flow = model->createFlow<FlowExponential>("Flow1", nullptr, nullptr);
    assert(flow->getName() == "Flow1");
    assert(flow->getSource() == nullptr);
    assert(flow->getTarget() == nullptr);
}

void unit_Flow_execute() {
    MyVensim* factory = MyVensim::getInstance();
    Model* model = factory->createModel();
    System* source = model->createSystem("Source", 100);
    Flow* flow = model->createFlow<FlowExponential>("", source);
    
    double result = flow->execute();
    assert(result == 1.0);
}

void unit_Flow_link() {
    MyVensim* factory = MyVensim::getInstance();
    Model* model = factory->createModel();
    System* source = model->createSystem("Source", 100);
    System* target = model->createSystem("Target", 200);
    Flow* flow = model->createFlow<FlowExponential>("", source, target);
    assert(flow->getSource() == source);
    assert(flow->getTarget() == target);
}

void unit_Flow_setSource() {
    MyVensim* factory = MyVensim::getInstance();
    Model* model = factory->createModel();
    System* source = model->createSystem("Source", 100);
    Flow* flow = model->createFlow<FlowExponential>();
    flow->setSource(source);
    assert(flow->getSource() == source);
}

void unit_Flow_setTarget() {
    MyVensim* factory = MyVensim::getInstance();
    Model* model = factory->createModel();
    System* target = model->createSystem("Target", 200);
    Flow* flow = model->createFlow<FlowExponential>();
    flow->setTarget(target);
    assert(flow->getTarget() == target);
}

void unit_Flow_setName() {
    MyVensim* factory = MyVensim::getInstance();
    Model* model = factory->createModel();
    Flow* flow =  model->createFlow<FlowExponential>();
    flow->setName("Flow1");
    assert(flow->getName() == "Flow1");
}

void unit_Flow_getName() {
    MyVensim* factory = MyVensim::getInstance();
    Model* model = factory->createModel();
    Flow* flow = model->createFlow<FlowExponential>("Flow1");
    assert(flow->getName() == "Flow1");
}

void unit_Flow_getSource() {
    MyVensim* factory = MyVensim::getInstance();
    Model* model = factory->createModel();
    System* source = model->createSystem("Source", 100);
    Flow* flow = model->createFlow<FlowExponential>("", source);
    assert(flow->getSource() == source);
}

void unit_Flow_getTarget() {
    MyVensim* factory = MyVensim::getInstance();
    Model* model = factory->createModel();
    System* target = model->createSystem("Target", 200);
    Flow* flow = model->createFlow<FlowExponential>("", nullptr, target);
    assert(flow->getTarget() == target);
}

void run_unit_tests_Flow() {
    unit_Flow_constructor();
    unit_Flow_execute();
    unit_Flow_link();
    unit_Flow_setSource();
    unit_Flow_setTarget();
    unit_Flow_setName();
    unit_Flow_getName();
    unit_Flow_getSource();
    unit_Flow_getTarget();
    std::cout << "All Flow unit tests passed!" << std::endl;
}
