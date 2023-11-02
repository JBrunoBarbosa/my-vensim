#include "Model.hpp"

// Constructors and destructor
Model::Model() {}
Model::~Model() {
    for(auto flow : flows) delete flow;
    for(auto system : systems) delete system;
}

void Model::execute(int timeInitial, int timeFinal) {

   setInitialHistory();

   for (int tempo = timeInitial; tempo < timeFinal; tempo++) {
        // Vetor para armazenar valores dos fluxos
        vector<double> currentFlowValues(flows.size());
        vector<double> currentSystemValues;

        // Calcula os valores dos fluxos
        for (size_t i = 0; i < flows.size(); i++) {
            currentFlowValues[i] = flows[i]->execute();  
        }

        // Atualiza os sistemas de acordo com os fluxos
        for (size_t i = 0; i < flows.size(); i++) {
            System* sistemaOrigem = flows[i]->getSource();
            System* sistemaDestino = flows[i]->getTarget();

            // Atualiza os valores dos sistemas de origem e destino
            sistemaOrigem->setValue(sistemaOrigem->getValue() - currentFlowValues[i]);
            sistemaDestino->setValue(sistemaDestino->getValue() + currentFlowValues[i]);
        }

        for(auto& sistem : systems) {
            currentSystemValues.push_back(sistem->getValue());
        }
        history.push_back(currentSystemValues);
    }
}

void Model::setInitialHistory() {
    vector<double> current;

    for(auto& sistem : systems) {
       current.push_back(sistem->getValue());
    }
    history.push_back(current);
}

void Model::report() {

    cout << "Time";
    for (auto& sistem : systems) {
        cout << "\t" << sistem->getName();
    }
    cout << endl;

    for (size_t i = 0; i < history.size(); i++) {
        cout << i;  
        for (size_t j = 0; j < history[i].size(); j++) {
            cout << "\t" << history[i][j];
        }
        cout << endl;
    }
}

void Model::add(Flow* flow) { flows.push_back(flow); }
void Model::add(System* system) { systems.push_back(system); }

void Model::clearModel() {
    for(auto flow : flows) delete flow;
    for(auto system : systems) delete system;
    flows.clear();
    systems.clear();
}
