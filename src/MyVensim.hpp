#ifndef MY_VENSIM_HPP
#define MY_VENSIM_HPP

#include <string>
#include "Model.hpp"
#include "System.hpp"
#include "Flow.hpp"

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

    /**
     * @brief Cria uma instância de System.
     * @param name Nome do sistema.
     * @param value Valor associado ao sistema.
     * @return Um ponteiro para a instância de System criada.
     */
    virtual System* createSystem(const std::string& name, double value) = 0;

    /**
     * @brief Cria uma instância de Flow.
     * @param name Nome do fluxo.
     * @param source Sistema de origem do fluxo.
     * @param target Sistema de destino do fluxo.
     * @return Um ponteiro para a instância de Flow criada.
     */
    template <typename FlowType>
    Flow* createFlow(std::string name = "", System* source = nullptr, System* destiny = nullptr) {
        Flow* f = new FlowType(name, source, destiny);
        add(f);
        return f;
    }

    /**
     * @brief Adiciona um fluxo ao modelo.
     * @param flow Ponteiro para o fluxo a ser adicionado.
     */
    virtual void add(Flow* flow) = 0;
};

#endif
