/**
 * @class MyVensimHandle
 * @brief Classe que implementa o Handle de MyVensim.
 */
#ifndef MY_HANDLE_HPP
#define MY_HANDLE_HPP

#include "MyVensim.hpp"
#include "MyVensimImpl.hpp"
#include "HandleBody.hpp"
#include <vector>

class MyVensimHandle : public MyVensim, public Handle<MyVensimImpl> {
public:
    Model* createModel() {
        return pImpl_->createModel();
    }

    static MyVensimHandle* getInstance() {
        static MyVensimHandle instance;  
        return &instance;
    }   

    modelsIterator endModels() {
        return pImpl_->endModels();
    }

    modelsIterator beginModels() {
        return pImpl_->beginModels();
    }

    void deleteModel(Model* const model) {
        pImpl_->deleteModel(model);
    }
};

#endif
