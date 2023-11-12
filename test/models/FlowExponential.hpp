#ifndef FLOW_EXPONENTIAL_HPP
#define FLOW_EXPONENTIAL_HPP

#include "../../src/Flow.hpp"

class FlowExponential : public Flow {
public:
    using Flow::Flow;   
    double execute() override;
};

#endif