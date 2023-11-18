/**
 * @class System
 * @brief Classe que representa um sistema.
 *
 * A classe `System` é responsável por representar um sistema em um modelo. Ela armazena
 * um nome descritivo e um valor associado ao sistema. Essa classe fornece métodos para
 * definir e obter o nome e o valor do sistema.
 */
#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <string>
#include <iostream>

using namespace std;

class System {
public:

    /**
     * @brief Destrutor do sistema.
     */
    virtual ~System() {};

    /**
     * @brief Define o nome do sistema.
     * @param name O novo nome descritivo do sistema.
     */
    virtual void setName(const string name) = 0;

    /**
     * @brief Define o valor associado ao sistema.
     * @param value O novo valor associado ao sistema.
     */
    virtual void setValue(const double value) = 0;

    // Getters
    /**
     * @brief Obtém o nome do sistema.
     * @return O nome descritivo do sistema.
     */
    virtual string getName() const = 0;

    /**
     * @brief Obtém o valor associado ao sistema.
     * @return O valor associado ao sistema.
     */
    virtual double getValue() const = 0;
    
    /**
     * @brief Clona um sistema.
     * @return O valor associado ao sistema.
     */
    virtual System* clone() const = 0;
};

#endif
