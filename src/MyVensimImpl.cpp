#include "MyVensimImpl.hpp"
#include "SystemImpl.hpp"
#include "ModelImpl.hpp"

MyVensim* MyVensim::getInstance() {
    return MyVensimImpl::createInstance();
}

MyVensim* MyVensimImpl::createInstance() {
    static MyVensimImpl instance;
    return &instance;
}

Model* MyVensimImpl::createModel() {
    Model* model = new ModelImpl();
    this->model = model;
    return model;
}

System* MyVensimImpl::createSystem(const std::string& name, double value) {
    ensureModelExists();
    System* system = new SystemImpl(name, value);
    model->add(system);
    return system;
}

void MyVensimImpl::add(Flow* flow) {
    ensureModelExists();
    model->add(flow); 
    flows.push_back(flow);
}

void MyVensimImpl::ensureModelExists() {
    if (!model) {
        createModel(); 
    }
}

MyVensimImpl::MyVensimImpl() {
    model = nullptr; // Inicializa o atributo model como nulo no construtor
}

MyVensimImpl::~MyVensimImpl() {
    delete model; // Libera a memória do modelo no destrutor, se necessário
    for (Flow* flow : flows) {
        delete flow;
    }
    for (System* system : systems) {
        delete system;
    }
}
