#ifndef FLOW_LOGISTIC_HPP
#define FLOW_LOGISTIC_HPP

#include "Flow.hpp"

class FlowLogistic : public Flow {
public:
    FlowLogistic(string name, System* source, System* target);
    FlowLogistic(string name);
    double execute() override;
};

#endif