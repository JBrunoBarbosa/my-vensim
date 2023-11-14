/**
 * @class FlowExponential
 * @brief Classe que representa um fluxo exponencial em um sistema.
 *
 * A classe `FlowExponential` é uma subclasse de `Flow` e representa um fluxo exponencial
 * em um modelo de sistema. Ela herda construtores da classe `Flow` e implementa o método
 * `execute` para calcular o valor do fluxo exponencial.
 */
#ifndef FLOW_EXPONENTIAL_HPP
#define FLOW_EXPONENTIAL_HPP

#include "../../src/Flow.hpp"

class FlowExponential : public Flow {
public:
    using Flow::Flow;   ///< Herda construtores da classe `Flow`.

    /**
     * @brief Executa o fluxo exponencial.
     *
     * Este método calcula o valor do fluxo exponencial de acordo com a implementação específica.
     *
     * @return O valor calculado do fluxo exponencial.
     */
    double execute() override;
};

#endif
