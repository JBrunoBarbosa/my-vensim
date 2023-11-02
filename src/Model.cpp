#include "Model.hpp"

// Constructors and destructor
Model::Model() {}

// Destructor
Model::~Model() {} 

void Model::execute(int timeInitial, int timeFinal) {

   setInitialHistory();

   for (int tempo = timeInitial; tempo < timeFinal; tempo++) {
        // Vector to save flows and systems values
        vector<double> currentFlowValues(flows.size());
        vector<double> currentSystemValues;

        // Flow values
        for (Model::flowIterator it = beginFlows(); it != endFlows(); ++it) {
            Flow* flow = *it;
            currentFlowValues[it - beginFlows()] = flow->execute();
        }

        // Update systems by flows
        for (Model::flowIterator it = beginFlows(); it != endFlows(); ++it) {
            Flow* flow = *it;
            System* source = flow->getSource();
            System* target = flow->getTarget();

            // Update source and target systems
            source->setValue(source->getValue() - currentFlowValues[it - beginFlows()]);
            target->setValue(target->getValue() + currentFlowValues[it - beginFlows()]);
        }

        for (Model::systemIterator it = beginSystems(); it != endSystems(); ++it) {
            System* system = *it;
            currentSystemValues.push_back(system->getValue());
        }
        history.push_back(currentSystemValues);
    }
}

void Model::setInitialHistory() {
    vector<double> current;

    for (Model::systemIterator it = beginSystems(); it != endSystems(); ++it) {
        System* system = *it;
        current.push_back(system->getValue());
    }
    history.push_back(current);
}

void Model::report() {

    cout << "Time";
    for (Model::systemIterator it = beginSystems(); it != endSystems(); ++it) {
        System* system = *it;
        cout << "\t" << system->getName();
    }
    cout << endl;

    for (Model::historyIterator it1 = beginHistory(); it1 != endHistory(); ++it1) {
        cout << distance(beginHistory(), it1);
        for (vector<double>::iterator it2 = it1->begin(); it2 != it1->end(); ++it2) {
            cout << "\t" << *it2;
        }
        cout << endl;
    }
}

void Model::add(Flow* flow) { flows.push_back(flow); }
void Model::add(System* system) { systems.push_back(system); }

// Iterators
Model::systemIterator Model::beginSystems() { return systems.begin(); }
Model::systemIterator Model::endSystems() { return systems.end(); }
Model::flowIterator Model::beginFlows() { return flows.begin(); }
Model::flowIterator Model::endFlows() { return flows.end(); }
Model::historyIterator Model::beginHistory() { return history.begin(); }
Model::historyIterator Model::endHistory() { return history.end(); }

void Model::clearModel() {
    for (auto flow : flows) delete flow;
    for (auto system : systems) delete system;
    flows.clear();
    systems.clear();
}
