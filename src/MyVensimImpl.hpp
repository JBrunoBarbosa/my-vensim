/**
 * @brief Classe que implementa a interface MyVensim.
 */
#ifndef MY_VENSIM_IMPL_HPP
#define MY_VENSIM_IMPL_HPP

#include "MyVensim.hpp"
#include "HandleBody.hpp"
#include <vector>

class MyVensimImpl : public Body {
private:
    std::vector<Model*> models;
    typedef std::vector<Model*>::iterator modelsIterator;
    virtual ~MyVensimImpl();

public:
    Model* createModel();
    void deleteModel(Model* const model);    
    static MyVensim* createInstance();
    modelsIterator endModels();
    modelsIterator beginModels();
};

#endif
