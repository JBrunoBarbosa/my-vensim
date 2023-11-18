/**
 * @class FlowLogistic
 * @brief Classe que representa um fluxo logístico em um sistema.
 *
 * A classe `FlowLogistic` é uma subclasse de `Flow` e representa um fluxo logístico
 * em um modelo de sistema. Ela herda construtores da classe `Flow` e implementa o método
 * `execute` para calcular o valor do fluxo logístico.
 */
#ifndef FLOW_LOGISTIC_HPP
#define FLOW_LOGISTIC_HPP

#include "../../src/Flow.hpp"

class FlowLogistic : public Flow {
public:
    using Flow::Flow;   ///< Herda construtores da classe `Flow`.

    /**
     * @brief Executa o fluxo logístico.
     *
     * Este método calcula o valor do fluxo logístico de acordo com a implementação específica.
     *
     * @return O valor calculado do fluxo logístico.
     */
    double execute() override;
};

#endif
