/**
 * @brief Classe que implementa a interface MyVensim.
 */
#ifndef MY_VENSIM_IMPL_HPP
#define MY_VENSIM_IMPL_HPP

#include "MyVensim.hpp"
#include <vector>

class MyVensimImpl : public MyVensim {
private:

    Model* model; 
    std::vector<Flow*> flows;
    std::vector<System*> systems;

    MyVensimImpl();
    ~MyVensimImpl();
    
    void add(Flow* flow) override;
    void ensureModelExists();

public:
    Model* createModel() override;
    System* createSystem(const std::string& name, double value) override;

    static MyVensim* createInstance();
};

#endif
