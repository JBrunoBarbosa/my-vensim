#include "Flow.hpp"

// Constructors
Flow::Flow(string name, System* source, System* target) : name(name), source(source), target(target) {}

Flow::Flow(const Flow* other) : name(other->name), source(nullptr), target(nullptr) {
    if (other->source != nullptr) {
        source = new System(*(other->source));
    }
    if (other->target != nullptr) {
        target = new System(*(other->target));
    }
}

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

// Operator 
Flow& Flow::operator=(const Flow& other) {
    if (this != &other) {
        // Copia o nome
        name = other.name;

        if (source != nullptr) {
            delete source;
            source = nullptr;
        }
        if (target != nullptr) {
            delete target;
            target = nullptr;
        }
        if (other.source != nullptr) {
            source = new System(other.source);
        }
        if (other.target != nullptr) {
            target = new System(other.target);
        }
    }
    return *this;
}