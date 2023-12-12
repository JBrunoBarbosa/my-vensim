#include "MyVensimImpl.hpp"
#include "ModelHandle.hpp"
#include "MyVensimHandle.hpp"

MyVensim* MyVensim::getInstance() {
    return MyVensimHandle::getInstance();
}

MyVensim* MyVensimImpl::createInstance() {
    static MyVensimHandle instance;
    return &instance;
}

Model* MyVensimImpl::createModel() {
    Model* model = new ModelHandle();
    models.push_back(model);
    return model;
}

void MyVensimImpl::deleteModel(Model* const model) {
    for (auto it = beginModels(); it != endModels(); ) {
        if (*it == model) {
            delete *it;
            it = models.erase(it);
        } else {
            ++it;
        }
    }
}

MyVensimImpl::~MyVensimImpl() {
    for (modelsIterator it = beginModels(); it != endModels(); ) {
        delete *it; 
        it = models.erase(it);
    }
}

// Iterators
MyVensimImpl::modelsIterator MyVensimImpl::beginModels() { return models.begin(); }
MyVensimImpl::modelsIterator MyVensimImpl::endModels() { return models.end(); }
