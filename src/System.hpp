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
private:
    string name;      ///< O nome descritivo do sistema.
    double value;     ///< O valor associado ao sistema.

public:
    // Construtores
    /**
     * @brief Construtor da classe `System`.
     * @param name O nome descritivo do sistema.
     * @param value O valor associado ao sistema (padrão é 0.0).
     */
    System(const string name = "", const double value = 0.0);

    /**
     * @brief Construtor de cópia da classe `System`.
     * @param other Um objeto `System` a ser copiado.
     */
    System(const System* other);

    // Destrutor
    virtual ~System();

    // Setters
    /**
     * @brief Define o nome do sistema.
     * @param name O novo nome descritivo do sistema.
     */
    void setName(const string name);

    /**
     * @brief Define o valor associado ao sistema.
     * @param value O novo valor associado ao sistema.
     */
    void setValue(const double value);

    // Getters
    /**
     * @brief Obtém o nome do sistema.
     * @return O nome descritivo do sistema.
     */
    string getName() const;

    /**
     * @brief Obtém o valor associado ao sistema.
     * @return O valor associado ao sistema.
     */
    double getValue() const;

    // Operador de atribuição
    /**
     * @brief Sobrecarga do operador de atribuição.
     * @param other Um objeto `System` a ser atribuído.
     * @return Uma referência ao objeto `System` atual após a atribuição.
     */
    System& operator=(const System& other);
};

#endif
