#include "MyVensimImpl.hpp"
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

void MyVensimImpl::ensureModelExists() {
    if (!model) {
        createModel(); 
    }
}

MyVensimImpl::MyVensimImpl() {
    model = nullptr; 
}

MyVensimImpl::~MyVensimImpl() {
    delete model;
}
