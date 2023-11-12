#include "FlowLogistic.hpp"

double FlowLogistic::execute() {
    const double systemValue = getTarget()->getValue();
    return 0.01 * systemValue * (1 - systemValue / 70);
}
