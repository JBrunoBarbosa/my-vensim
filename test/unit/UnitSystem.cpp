#include "UnitSystem.hpp"
#include <iostream>
#include <cmath>

void unit_System_constructor() {
    SystemImpl sys("System1", 100.0);
    assert(sys.getName() == "System1");
    assert(std::abs(sys.getValue() - 100.0) < 0.001);
}

void unit_System_setName() {
    SystemImpl sys;
    sys.setName("System2");
    assert(sys.getName() == "System2");
}

void unit_System_setValue() {
    SystemImpl sys;
    sys.setValue(150.0);
    assert(std::abs(sys.getValue() - 150.0) < 0.001);
}

void unit_System_getName() {
    SystemImpl sys("System1");
    assert(sys.getName() == "System1");
}

void unit_System_getValue() {
    SystemImpl sys("", 200.0);
    assert(std::abs(sys.getValue() - 200.0) < 0.001);
}

void unit_System_operator() {
    SystemImpl sys1("System1", 100.0);
    SystemImpl sys2 = sys1;
    assert(sys2.getName() == "System1");
    assert(std::abs(sys2.getValue() - 100.0) < 0.001);
}

void unit_System_clone() {
    SystemImpl sys1("System1", 100.0);
    System* sys2 = sys1.clone();
    assert(sys2->getName() == "System1");
    assert(std::abs(sys2->getValue() - 100.0) < 0.001);
    delete sys2; 
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
