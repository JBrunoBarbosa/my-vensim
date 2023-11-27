#include "UnitSystem.hpp"
#include "../models/FlowExponential.hpp"
#include "../../src/MyVensim.hpp"
#include <iostream>
#include <cmath>

void unit_System_constructor() {
    MyVensim* factory = MyVensim::getInstance();
    System* sys = factory->createSystem("System1", 100.0);
    assert(sys->getName() == "System1");
    assert(std::abs(sys->getValue() - 100.0) < 0.001);
}

void unit_System_setName() {
    MyVensim* factory = MyVensim::getInstance();
    System* sys = factory->createSystem("", 0);
    sys->setName("System1");
    assert(sys->getName() == "System1");
}

void unit_System_setValue() {
    MyVensim* factory = MyVensim::getInstance();
    System* sys = factory->createSystem("", 0);
    sys->setValue(150.0);
    assert(std::abs(sys->getValue() - 150.0) < 0.001);
}

void unit_System_getName() {
    MyVensim* factory = MyVensim::getInstance();
    System* sys = factory->createSystem("System1", 0);
    assert(sys->getName() == "System1");
}

void unit_System_getValue() {
    MyVensim* factory = MyVensim::getInstance();
    System* sys = factory->createSystem("", 200.0);
    assert(std::abs(sys->getValue() - 200.0) < 0.001);
}

void unit_System_operator() {
    MyVensim* factory = MyVensim::getInstance();
    System* sys1 = factory->createSystem("System1", 100.0);
    assert(sys1->getName() == "System1");
    assert(std::abs(sys1->getValue() - 100.0) < 0.001);
}

void unit_System_clone() {
    MyVensim* factory = MyVensim::getInstance();
    System* sys1 = factory->createSystem("System1", 100.0);
    System* sys2 = sys1->clone();
    assert(sys2->getName() == "System1");
    assert(std::abs(sys2->getValue() - 100.0) < 0.001);
}

void run_unit_tests_System() {
    unit_System_constructor();
    unit_System_setName();
    unit_System_setValue();
    unit_System_getName();
    unit_System_getValue();
    unit_System_operator();
    unit_System_clone();
    std::cout << "All System unit tests passed!" << std::endl;
}
