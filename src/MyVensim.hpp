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

     /**
     * @brief Declaração dos iteradores.
     */
    typedef std::vector<Model *>::iterator modelsIterator;
    virtual Model* createModel() = 0;
    virtual void deleteModel(Model* const model) = 0;
    virtual modelsIterator endModels() = 0;
    virtual modelsIterator beginModels() = 0;
};

#endif
