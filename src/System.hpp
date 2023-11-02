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
    System(const string name = "", const double value = 0.0);
    System(const System* other);

    // Destructor
    virtual ~System();

    // Setters
    void setName(const string name);
    void setValue(const double value);

    // Getters
    string getName() const;
    double getValue() const;

    // Operador
    System& operator=(const System& other);
};

#endif