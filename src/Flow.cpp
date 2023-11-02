#include "Flow.hpp"

// Constructors
Flow::Flow(string name, System* source, System* target) : name(name), source(source), target(target) {}
Flow::Flow(string name) : name(name){}

// Destructor
Flow::~Flow() {} 

// Link source and target
void Flow::link(System* source, System* target) {
    this->source = source;
    this->target = target;
}

// Setters
void Flow::setSource(System* source) { this->source = source; }
void Flow::setTarget(System* target) { this->target = target; }
void Flow::setName(string name) { this->name = name; }

// Getters
System* Flow::getSource() const { return source; }
System* Flow::getTarget() const { return target; }
string Flow::getName() const { return name; }