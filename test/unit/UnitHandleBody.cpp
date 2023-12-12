#include <iostream>
#include <cassert>

#include "../../src/MyVensim.hpp"
#include "../../src/SystemHandle.hpp"
#include "../models/FlowExponential.hpp"
#include "../models/FlowLogistic.hpp"

using namespace std;

#define DEBUGING
#ifdef DEBUGING
    int numHandleCreated = 0;
    int numHandleDeleted = 0;
    int numBodyCreated = 0;
    int numBodyDeleted = 0;
#endif

// Função de teste para criar e manipular sistemas e fluxos
void test_systems_and_flows() {
    MyVensim* factory = MyVensim::getInstance();
    Model* model = factory->createModel();
    System* system1 = model->createSystem("Populacao 1", 10.0);
    System* system2 = model->createSystem("Populacao 2", 7.20);
    Flow* flow1 = model->createFlow<FlowLogistic>("Logistico", system1, system2);  
    
    *system1 = *system2;
    factory->deleteModel(model);

    assert(numHandleCreated == numHandleDeleted);
    assert(numBodyCreated == numBodyDeleted);
}

// Função de teste para criar e manipular objetos Body
void test_body_objects() {
    SystemHandle system3("Bruno Barbosa", 7), system4("Tiago", 8);
    system3 = system4; 
    system3 = system3;

    assert(numBodyCreated == numBodyDeleted);
}

// Função de teste para criar e manipular objetos Handle
void test_handle_objects() {
    SystemHandle system3("Bruno Barbosa", 7), system4("Tiago", 8);
    system3 = system4; 
    system3 = system3;

    assert(numHandleCreated == numHandleDeleted);
}

void run_handle_body_unit_tests() {
    test_systems_and_flows();
    test_body_objects();
    test_handle_objects();
    std::cout << "All Handle Body unit tests passed!" << std::endl;
}
