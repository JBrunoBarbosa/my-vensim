#include "System.hpp"

using namespace std;

// Constructors
System::System(string name, double value) : name(name), value(value) {}
System::System(string name) : name(name) {}

// Destructor
System::~System() {}

// Setters
void System::setName(string name) { this->name = name; }
void System::setValue(double value) { this->value = value; }

// Getters
string System::getName() const { return name; }
double System::getValue() const { return value; }