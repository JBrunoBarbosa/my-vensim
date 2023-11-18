#ifndef SYSTEM_IMPL_HPP
#define SYSTEM_IMPL_HPP

#include <string>
#include <iostream>
#include "System.hpp"

using namespace std;

class SystemImpl: public System {
protected:
    string name;      
    double value;     

public:
    SystemImpl(const string name = "", const double value = 0.0);
    SystemImpl(const System* other);
    virtual ~SystemImpl();

    void setName(const string name) override;
    void setValue(const double value) override;
    string getName() const override;
    double getValue() const override;
    System& operator=(const System& other);
    System* clone() const override;
};

#endif
