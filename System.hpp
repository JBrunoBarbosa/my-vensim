#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <string>
#include <iostream>

using namespace std;

class System {
private:
    string name;
    double value;

public:

    // Constructors
    System(string name, double value);
    System(string name);

    // Destructor
    ~System();

    // Setters
    void setName(string name);
    void setValue(double value);

    // Getters
    string getName() const;
    double getValue() const;
};

#endif