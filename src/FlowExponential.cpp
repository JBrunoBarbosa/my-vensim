#include "FlowExponential.hpp"

FlowExponential::FlowExponential(string name, System* source, System* target) : Flow(name, source, target) {}
FlowExponential::FlowExponential(string name): Flow(name) {}

double FlowExponential::execute() {
    return 0.01 * getSource()->getValue();
}


