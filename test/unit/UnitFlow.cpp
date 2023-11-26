#include "UnitFlow.hpp"
#include "../models/FlowExponential.hpp"
#include <iostream>

void unit_Flow_constructor() {
    FlowImpl* flow = new FlowExponential("Flow1");
    assert(flow->getName() == "Flow1");
    assert(flow->getSource() == nullptr);
    assert(flow->getTarget() == nullptr);
    delete flow;
}

void unit_Flow_execute() {
    SystemImpl* source = new SystemImpl("Source", 100);
    FlowExponential* flow = new FlowExponential("", source);
    
    double result = flow->execute();
    assert(result == 1.0);
    
    delete source;
    delete flow;
}

void unit_Flow_link() {
    SystemImpl* source = new SystemImpl("Source", 100);
    SystemImpl* target = new SystemImpl("Target", 200);
    FlowExponential* flow = new FlowExponential();
    flow->link(source, target);
    assert(flow->getSource() == source);
    assert(flow->getTarget() == target);
    
    delete source;
    delete target;
    delete flow;
}

void unit_Flow_setSource() {
    SystemImpl* source = new SystemImpl("Source", 100);
    FlowExponential* flow = new FlowExponential();
    flow->setSource(source);
    assert(flow->getSource() == source);
    
    delete source;
    delete flow;
}

void unit_Flow_setTarget() {
    SystemImpl* target = new SystemImpl("Target", 200);
    FlowExponential* flow = new FlowExponential();
    flow->setTarget(target);
    assert(flow->getTarget() == target);
    
    delete target;
    delete flow;
}

void unit_Flow_setName() {
    FlowExponential* flow = new FlowExponential();
    flow->setName("Flow1");
    assert(flow->getName() == "Flow1");
    
    delete flow;
}

void unit_Flow_getName() {
    FlowExponential* flow = new FlowExponential("Flow1");
    assert(flow->getName() == "Flow1");
    
    delete flow;
}

void unit_Flow_getSource() {
    SystemImpl* source = new SystemImpl("Source", 100);
    FlowExponential* flow = new FlowExponential("", source);
    assert(flow->getSource() == source);
    
    delete source;
    delete flow;
}

void unit_Flow_getTarget() {
    SystemImpl* target = new SystemImpl("Target", 200);
    FlowExponential* flow = new FlowExponential("", nullptr, target);
    assert(flow->getTarget() == target);
    
    delete target;
    delete flow;
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
