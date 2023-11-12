#ifndef FLOW_HPP
#define FLOW_HPP

#include "System.hpp"

using namespace std;

class Flow {
private:
    string name;
    System* source;
    System* target;

public:
    // Constuctors
    Flow(string name = "", System* source = nullptr, System* target = nullptr);
    Flow(const Flow* other);

    // Destructor
    virtual ~Flow(); 

    // Methods
    double virtual execute() = 0;
    void link(System* source, System* target);

    // Setters
    void setSource(System* source);
    void setTarget(System* target);
    void setName(string name);

    // Getters
    System* getSource() const;
    System* getTarget() const;
    string getName() const;
    
    // Operator 
    Flow& operator=(const Flow& other);
};

#endif 