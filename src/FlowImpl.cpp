#include "FlowImpl.hpp"

// Constructors
FlowImpl::FlowImpl(string name, System* source, System* target) : name(name), source(source), target(target) {}

FlowImpl::FlowImpl(const FlowImpl& other) : name(other.name), source(nullptr), target(nullptr) {
    if (other.source != nullptr) {
        source = other.source->clone();
    }
    if (other.target != nullptr) {
        target = other.target->clone(); 
    }
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
Flow& FlowImpl::operator=(const Flow& other) {
    if (this != &other) {
        // Define o nome
        this->setName(other.getName());

        // Libera a memória dos objetos existentes
        if (source != nullptr) {
            delete source;
            source = nullptr;
        }
        if (target != nullptr) {
            delete target;
            target = nullptr;
        }

        // Realiza uma cópia profunda dos objetos source e target
        if (other.getSource() != nullptr) {
            source = other.getSource()->clone();
        }
        if (other.getTarget() != nullptr) {
            target = other.getTarget()->clone();
        }
    }
    return *this;
}
