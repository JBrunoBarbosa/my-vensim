#include "SystemImpl.hpp"

using namespace std;

// Constructors
SystemImpl::SystemImpl(string name, double value) : name(name), value(value) {}

SystemImpl::SystemImpl(const System* other) {
    if (other) {
        name = other->getName();
        value = other->getValue();
    } else {
        name = "";
        value = 0.0;
    }
}

// Destructor
SystemImpl::~SystemImpl() {}

// Setters
void SystemImpl::setName(string name) { this->name = name; }
void SystemImpl::setValue(double value) { this->value = value; }

// Getters
string SystemImpl::getName() const { return name; }
double SystemImpl::getValue() const { return value; }

// Operator
SystemImpl& SystemImpl::operator=(const SystemImpl& other) {
    if (this == &other) {
        // Verificação de auto-atribuição
        return *this;
    }

    // Copiando os dados
    this->name = other.name;
    this->value = other.value;

    return *this;
}