#include "FlowExponential.hpp"

double FlowExponential::execute() {
    return 0.01 * getSource()->getValue();
}


