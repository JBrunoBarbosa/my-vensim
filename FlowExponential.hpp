#ifndef FLOW_EXPONENTIAL_HPP
#define FLOW_EXPONENTIAL_HPP

#include "Flow.hpp"

class FlowExponential : public Flow {
public:
    FlowExponential(string name, System* source, System* target);
    FlowExponential(string name);
    double execute() override;
};

#endif