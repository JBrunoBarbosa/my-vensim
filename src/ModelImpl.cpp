#include "ModelImpl.hpp"

// Constructors and destructor
ModelImpl::ModelImpl() {}

// Destructor
ModelImpl::~ModelImpl() {} 

// Add methods
void ModelImpl::add(Flow* flow) { flows.push_back(flow); }
void ModelImpl::add(System* system) { systems.push_back(system); }

// Iterators
ModelImpl::systemIterator ModelImpl::beginSystems() { return systems.begin(); }
ModelImpl::systemIterator ModelImpl::endSystems() { return systems.end(); }
ModelImpl::flowIterator ModelImpl::beginFlows() { return flows.begin(); }
ModelImpl::flowIterator ModelImpl::endFlows() { return flows.end(); }
ModelImpl::historyIterator ModelImpl::beginHistory() { return history.begin(); }
ModelImpl::historyIterator ModelImpl::endHistory() { return history.end(); }

ModelImpl::ModelImpl(Model* obj){
    
    for(systemIterator it = obj->beginSystems(); it != obj->endSystems(); ++it){
        (systems).push_back(*it);
    }
    for(flowIterator it = obj->beginFlows(); it != obj->endFlows(); ++it){
        (flows).push_back(*it);
    }
}

void ModelImpl::execute(int timeInitial, int timeFinal) {

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

void ModelImpl::setInitialHistory() {
    vector<double> current;

    for (Model::systemIterator it = beginSystems(); it != endSystems(); ++it) {
        System* system = *it;
        current.push_back(system->getValue());
    }
    history.push_back(current);
}

void ModelImpl::report() {

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

void ModelImpl::clearModel() {
    for (auto flow : flows) delete flow;
    for (auto system : systems) delete system;
    flows.clear();
    systems.clear();
}
