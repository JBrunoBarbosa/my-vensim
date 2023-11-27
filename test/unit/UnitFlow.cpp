#include "UnitFlow.hpp"
#include "../models/FlowExponential.hpp"
#include "../../src/MyVensim.hpp"
#include <iostream>

void unit_Flow_constructor() {
    MyVensim* factory = MyVensim::getInstance();
    Flow* flow = factory->createFlow<FlowExponential>("Flow1", nullptr, nullptr);
    assert(flow->getName() == "Flow1");
    assert(flow->getSource() == nullptr);
    assert(flow->getTarget() == nullptr);
}

void unit_Flow_execute() {
    System* source = MyVensim::getInstance()->createSystem("Source", 100);
    Flow* flow = MyVensim::getInstance()->createFlow<FlowExponential>("", source);
    
    double result = flow->execute();
    assert(result == 1.0);
}

void unit_Flow_link() {
    MyVensim* factory = MyVensim::getInstance();
    System* source = factory->createSystem("Source", 100);
    System* target = factory->createSystem("Target", 200);
    Flow* flow = factory->createFlow<FlowExponential>("", source, target);
    assert(flow->getSource() == source);
    assert(flow->getTarget() == target);
}

void unit_Flow_setSource() {
    MyVensim* factory = MyVensim::getInstance();
    System* source = factory->createSystem("Source", 100);
    Flow* flow = factory->createFlow<FlowExponential>();
    flow->setSource(source);
    assert(flow->getSource() == source);
}

void unit_Flow_setTarget() {
    MyVensim* factory = MyVensim::getInstance();
    System* target = factory->createSystem("Target", 200);
    Flow* flow = factory->createFlow<FlowExponential>();
    flow->setTarget(target);
    assert(flow->getTarget() == target);
}

void unit_Flow_setName() {
    MyVensim* factory = MyVensim::getInstance();
    Flow* flow = factory->createFlow<FlowExponential>();
    flow->setName("Flow1");
    assert(flow->getName() == "Flow1");
}

void unit_Flow_getName() {
    MyVensim* factory = MyVensim::getInstance();
    Flow* flow = factory->createFlow<FlowExponential>("Flow1");
    assert(flow->getName() == "Flow1");
}

void unit_Flow_getSource() {
    MyVensim* factory = MyVensim::getInstance();
    System* source = factory->createSystem("Source", 100);
    Flow* flow = factory->createFlow<FlowExponential>("", source);
    assert(flow->getSource() == source);
}

void unit_Flow_getTarget() {
    MyVensim* factory = MyVensim::getInstance();
    System* target = factory->createSystem("Target", 200);
    Flow* flow = factory->createFlow<FlowExponential>("", nullptr, target);
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
