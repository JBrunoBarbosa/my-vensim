/**
 * @brief Arquivo de testes unitários para a classe System.
 * 
 * Este arquivo contém declarações de métodos de teste para a classe System.
 */
#ifndef UNIT_SYSTEM_HPP
#define UNIT_SYSTEM_HPP

#include <assert.h>
#include "../../src/SystemImpl.hpp"

/**
 * @brief Testa o construtor da classe System.
 * 
 * Este método verifica se o construtor da classe System funciona conforme esperado.
 */
void unit_System_constructor();

/**
 * @brief Testa o método setName da classe System.
 * 
 * Este método verifica se o método setName atribui corretamente o nome ao sistema.
 */
void unit_System_setName();

/**
 * @brief Testa o método setValue da classe System.
 * 
 * Este método verifica se o método setValue atribui corretamente o valor ao sistema.
 */
void unit_System_setValue();

/**
 * @brief Testa o método getName da classe System.
 * 
 * Este método verifica se o método getName retorna corretamente o nome do sistema.
 */
void unit_System_getName();

/**
 * @brief Testa o método getValue da classe System.
 * 
 * Este método verifica se o método getValue retorna corretamente o valor do sistema.
 */
void unit_System_getValue();

/**
 * @brief Testa o operador de atribuição da classe System.
 * 
 * Este método verifica se o operador de atribuição da classe System funciona corretamente.
 */
void unit_System_operator();

/**
 * @brief Testa o método clone da classe System.
 * 
 * Este método verifica se o método clone cria corretamente uma cópia do sistema.
 */
void unit_System_clone();

/**
 * @brief Função para executar todos os testes unitários para a classe System.
 * 
 * Esta função chama todos os testes unitários definidos para a classe System.
 */
void run_unit_tests_System();

#endif
