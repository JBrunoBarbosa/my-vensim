/**
 * @class Model
 * @brief Classe que representa um modelo de sistema puramente virtual.
 *
 * A classe `Model` é responsável por representar um modelo de sistema que consiste em
 * uma coleção de fluxos (Flows) e sistemas (Systems). Ela fornece métodos para executar o
 * modelo, gerar relatórios e modificar o modelo.
 *
 */
#ifndef MODEL_HPP
#define MODEL_HPP

#include "System.hpp"
#include "Flow.hpp"
#include <vector>

class Model {
public:

    /**
     * @brief Destrutor virtual.
    */
    virtual ~Model() {};

    /**
     * @brief Declaração dos iteradores.
     */
    typedef std::vector<System *>::iterator systemIterator;
    typedef std::vector<Flow *>::iterator flowIterator;
    typedef std::vector<std::vector<double>>::iterator historyIterator;

    /**
     * @brief Retorna um iterador para o início dos sistemas no modelo.
     * @return Iterador para o início dos sistemas.
     */
    virtual systemIterator beginSystems() = 0;

    /**
     * @brief Retorna um iterador para o final dos sistemas no modelo.
     * @return Iterador para o final dos sistemas.
     */
    virtual systemIterator endSystems() = 0;

    /**
     * @brief Retorna um iterador para o início dos fluxos no modelo.
     * @return Iterador para o início dos fluxos.
     */
    virtual flowIterator beginFlows() = 0;

    /**
     * @brief Retorna um iterador para o final dos fluxos no modelo.
     * @return Iterador para o final dos fluxos.
     */
    virtual flowIterator endFlows() = 0;

    /**
     * @brief Retorna um iterador para o início do histórico no modelo.
     * @return Iterador para o início do histórico.
     */
    virtual historyIterator beginHistory() = 0;

    /**
     * @brief Retorna um iterador para o final do histórico no modelo.
     * @return Iterador para o final do histórico.
     */
    virtual historyIterator endHistory() = 0;
    
    /**
     * @brief Adiciona um flow no model.
     * @param flow Adicionando um flow.
    */
    virtual void add(Flow* flow) = 0;

    /**
     * @brief Adiciona um sytem no model.
     * @param system Adicionando um system.
    */
    virtual void add(System* system) = 0;

    /**
     * @brief Gera um relatório do modelo.
     */
    virtual void report() = 0;

    /**
     * @brief Define o histórico inicial com valores padrão.
     */
    virtual void setInitialHistory() = 0;

    /**
     * @brief Limpa o modelo, removendo todos os sistemas e fluxos.
     */
    virtual void clearModel() = 0;
    
    /**
     * @brief Executa o modelo de tempo inicial a tempo final.
     * @param timeInitial O tempo inicial da execução do modelo.
     * @param timeFinal O tempo final da execução do modelo.
     */
    virtual void execute(const int timeInitial, const int timeFinal) = 0;
};

#endif
