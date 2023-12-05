#ifndef MY_VENSIM_HPP
#define MY_VENSIM_HPP

#include <string>
#include "Model.hpp"

/**
 * @class MyVensim
 * @brief Interface para a fábrica de objetos Vensim.
 */
class MyVensim {
public:
    virtual ~MyVensim() {}

    static MyVensim* getInstance();

    /**
     * @brief Cria uma instância de Model.
     * @return Um ponteiro para a instância de Model criada.
     */
    virtual Model* createModel() = 0;
};

#endif
