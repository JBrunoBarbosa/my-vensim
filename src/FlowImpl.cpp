#include "FlowImpl.hpp"

using namespace std;

// Constructors
FlowImpl::FlowImpl(string name, System* source, System* target) : name(name), source(source), target(target) {}

FlowImpl::FlowImpl(const FlowImpl& other) : name(other.name), source(nullptr), target(nullptr) {
    this->name = other.name;
    this->source = other.source;
    this->target = other.target;
}

// Destructor
FlowImpl::~FlowImpl() {} 

// Link source and target
void FlowImpl::link(System* source, System* target) {
    this->source = source;
    this->target = target;
}

// Setters
void FlowImpl::setSource(System* source) { this->source = source; }
void FlowImpl::setTarget(System* target) { this->target = target; }
void FlowImpl::setName(const string name) { this->name = name; }

// Getters
System* FlowImpl::getSource() const { return source; }
System* FlowImpl::getTarget() const { return target; }
string FlowImpl::getName() const { return name; }

// Operator 
FlowImpl& FlowImpl::operator=(const FlowImpl& other) {
    if(this == &other)
        return *this;

    this->name = other.name;

    delete this->source;
    delete this->target;

    this->source = other.source;
    this->target = other.target;

    return *this;
}
