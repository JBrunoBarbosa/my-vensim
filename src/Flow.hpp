/**
 * @class Flow
 * @brief Esta classe representa um fluxo em um sistema.
 *
 * A classe `Flow` é responsável por representar um fluxo entre dois sistemas em um modelo.
 * Ela pode ser usada para modelar o fluxo de recursos, informações ou qualquer outra entidade
 * entre sistemas.
 */
#ifndef FLOW_HPP
#define FLOW_HPP

#include "System.hpp"

using namespace std;

class Flow {
private:
    string name;      ///< O nome do fluxo.
    System* source;   ///< O sistema de origem do fluxo.
    System* target;   ///< O sistema de destino do fluxo.

public:
    // Construtores
    Flow(string name = "", System* source = nullptr, System* target = nullptr);
    Flow(const Flow* other);

    // Destrutor
    virtual ~Flow();

    // Métodos
    /**
     * @brief Executa o fluxo.
     *
     * Este método virtual puro deve ser implementado nas classes derivadas para
     * executar o comportamento específico do fluxo.
     *
     * @return O resultado da execução do fluxo.
     */
    double virtual execute() = 0;

    /**
     * @brief Liga o fluxo a sistemas de origem e destino.
     *
     * Este método permite associar o fluxo aos sistemas de origem e destino.
     *
     * @param source O sistema de origem do fluxo.
     * @param target O sistema de destino do fluxo.
     */
    void link(System* source, System* target);

    // Setters
    void setSource(System* source);
    void setTarget(System* target);
    void setName(string name);

    // Getters
    System* getSource() const;
    System* getTarget() const;
    string getName() const;

    // Operador de atribuição
    Flow& operator=(const Flow& other);
};

#endif
