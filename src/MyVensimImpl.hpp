/**
 * @brief Classe que implementa a interface MyVensim.
 */
#ifndef MY_VENSIM_IMPL_HPP
#define MY_VENSIM_IMPL_HPP

#include "MyVensim.hpp"

class MyVensimImpl : public MyVensim {
private:

    Model* model; 

    MyVensimImpl();
    ~MyVensimImpl();
    
    void ensureModelExists();

public:
    Model* createModel() override;    
    static MyVensim* createInstance();
};

#endif
