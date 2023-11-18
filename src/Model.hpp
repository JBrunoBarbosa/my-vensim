/**
 * @class Model
 * @brief Classe que representa um modelo de sistema.
 *
 * A classe `Model` é responsável por representar um modelo de sistema que consiste em
 * uma coleção de fluxos (Flows) e sistemas (Systems). Ela fornece métodos para executar o
 * modelo, gerar relatórios e modificar o modelo.
 *
 */
#ifndef MODEL_HPP
#define MODEL_HPP

#include <vector>
#include "System.hpp"
#include "Flow.hpp"

using namespace std;

class Model {
private:
    vector<Flow*> flows;               ///< Vetor de ponteiros para os fluxos no modelo.
    vector<System*> systems;           ///< Vetor de ponteiros para os sistemas no modelo.
    vector<vector<double>> history;    ///< Histórico de valores durante a execução do modelo.
    void operator= (const Model&);

public:
    // Construtor
    Model();
    Model(Model* other);

    // Iteradores
    typedef vector<System *>::iterator systemIterator;
    typedef vector<Flow *>::iterator flowIterator;
    typedef vector<vector<double>>::iterator historyIterator;

    /**
     * @brief Retorna um iterador para o início dos sistemas no modelo.
     * @return Iterador para o início dos sistemas.
     */
    systemIterator beginSystems();

    /**
     * @brief Retorna um iterador para o final dos sistemas no modelo.
     * @return Iterador para o final dos sistemas.
     */
    systemIterator endSystems();

    /**
     * @brief Retorna um iterador para o início dos fluxos no modelo.
     * @return Iterador para o início dos fluxos.
     */
    flowIterator beginFlows();

    /**
     * @brief Retorna um iterador para o final dos fluxos no modelo.
     * @return Iterador para o final dos fluxos.
     */
    flowIterator endFlows();

    /**
     * @brief Retorna um iterador para o início do histórico no modelo.
     * @return Iterador para o início do histórico.
     */
    historyIterator beginHistory();

    /**
     * @brief Retorna um iterador para o final do histórico no modelo.
     * @return Iterador para o final do histórico.
     */
    historyIterator endHistory();

    // Destrutor
    virtual ~Model();

    // Métodos
    /**
     * @brief Executa o modelo de tempo inicial a tempo final.
     * @param timeInitial O tempo inicial da execução do modelo.
     * @param timeFinal O tempo final da execução do modelo.
     */
    void execute(const int timeInitial, const int timeFinal);

    /**
     * @brief Gera um relatório do modelo.
     */
    void report();

    /**
     * @brief Define o histórico inicial com valores padrão.
     */
    void setInitialHistory();

    // Modifica o modelo
    void add(Flow* flow);
    void add(System* system);

    /**
     * @brief Limpa o modelo, removendo todos os sistemas e fluxos.
     */
    void clearModel();
};

#endif
