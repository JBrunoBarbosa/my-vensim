#include "FlowLogistic.hpp"

FlowLogistic::FlowLogistic(string name, System* source, System* target) : Flow(name, source, target) {}
FlowLogistic::FlowLogistic(string name): Flow(name) {}

double FlowLogistic::execute() {
    const double systemValue = getTarget()->getValue();
    return 0.01 * systemValue * (1 - systemValue / 70);
}
