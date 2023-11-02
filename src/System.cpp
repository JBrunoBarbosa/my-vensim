#include "System.hpp"

using namespace std;

// Constructors
System::System(string name, double value) : name(name), value(value) {}

System::System(const System* other) {
    if (other) {
        name = other->name;
        value = other->value;
    } else {
        name = "";
        value = 0.0;
    }
}

// Destructor
System::~System() {}

// Setters
void System::setName(string name) { this->name = name; }
void System::setValue(double value) { this->value = value; }

// Getters
string System::getName() const { return name; }
double System::getValue() const { return value; }

// Operator
System& System::operator=(const System& other) {
    if (this != &other) {
        name = other.name;
        value = other.value;
    }
    return *this;
}