/**
 * @class Flow
 * @brief Classe que representa um fluxo de sistema puramente virtual.
 *
 * A classe `Flow` é responsável por representar um fluxo entre sistemas que ao executar 
 * aplica uma funcao ao valor de sistemas.
 *
 */
#ifndef FLOW_HPP
#define FLOW_HPP

#include "System.hpp"
#include <string>

class Flow {
public:
    /**
     * @brief Executa o fluxo.
     *
     * Este método virtual puro deve ser implementado nas classes derivadas para
     * executar o comportamento específico do fluxo.
     *
     * @return O resultado da execução do fluxo.
     */
    virtual double execute() = 0;

    /**
     * @brief Liga o fluxo a sistemas de origem e destino.
     *
     * Este método permite associar o fluxo aos sistemas de origem e destino.
     *
     * @param source O sistema de origem do fluxo.
     * @param target O sistema de destino do fluxo.
     */
    virtual void link(System* source, System* target) = 0;

    /**
     * @brief Define o sistema de origem do fluxo.
     *
     * @param source Sistema de origem do fluxo.
     */
    virtual void setSource(System* source) = 0;

    /**
     * @brief Define o sistema de destino do fluxo.
     *
     * @param target Sistema de destino do fluxo.
     */
    virtual void setTarget(System* target) = 0;

    /**
     * @brief Define o nome do fluxo.
     *
     * @param name Nome do fluxo.
     */
    virtual void setName(const std::string name) = 0;

    /**
     * @brief Obtém o sistema de origem do fluxo.
     *
     * @return O sistema de origem do fluxo.
     */
    virtual System* getSource() const = 0;

    /**
     * @brief Obtém o sistema de destino do fluxo.
     *
     * @return O sistema de destino do fluxo.
     */
    virtual System* getTarget() const = 0;

    /**
     * @brief Obtém o nome do fluxo.
     *
     * @return O nome do fluxo.
     */
    virtual std::string getName() const = 0;

    /**
     * @brief Destrutor virtual.
     */
    virtual ~Flow() {};
};

#endif
