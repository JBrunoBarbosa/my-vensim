#ifndef FLOW_LOGISTIC_HPP
#define FLOW_LOGISTIC_HPP

#include "../../src/Flow.hpp"

class FlowLogistic : public Flow {
public:
    using Flow::Flow;
    double execute() override;
};

#endif