/**
 * @brief Arquivo de testes unitários para a classe Model.
 * 
 * Este arquivo contém declarações de métodos de teste para a classe Model.
 */
#ifndef UNIT_MODEL_HPP
#define UNIT_MODEL_HPP

#include <math.h>
#include "UnitSystem.hpp"
#include "UnitFlow.hpp"
#include "../../src/ModelImpl.hpp"
 
/**
 * @brief Testa o construtor da classe Model.
 * 
 * Este método verifica se o construtor da classe Model funciona conforme esperado.
 */
void unit_Model_constructor();

/**
 * @brief Testa o método beginSystems da classe Model.
 * 
 * Este método verifica se o método beginSystems inicia adequadamente os sistemas no modelo.
 */
void unit_Model_beginSystems();

/**
 * @brief Testa o método endSystems da classe Model.
 * 
 * Este método verifica se o método endSystems conclui adequadamente os sistemas no modelo.
 */
void unit_Model_endSystems();

/**
 * @brief Testa o método beginFlows da classe Model.
 * 
 * Este método verifica se o método beginFlows inicia adequadamente os fluxos no modelo.
 */
void unit_Model_beginFlows();

/**
 * @brief Testa o método endFlows da classe Model.
 * 
 * Este método verifica se o método endFlows conclui adequadamente os fluxos no modelo.
 */
void unit_Model_endFlows();

/**
 * @brief Testa o método beginHistory da classe Model.
 * 
 * Este método verifica se o método beginHistory inicia adequadamente o histórico no modelo.
 */
void unit_Model_beginHistory();

/**
 * @brief Testa o método endHistory da classe Model.
 * 
 * Este método verifica se o método endHistory conclui adequadamente o histórico no modelo.
 */
void unit_Model_endHistory();

/**
 * @brief Testa o método add da classe Model.
 * 
 * Este método verifica se o método add adiciona corretamente um elemento ao modelo.
 */
void unit_Model_add();

/**
 * @brief Testa o método setInitialHistory da classe Model.
 * 
 * Este método verifica se o método setInitialHistory atribui corretamente o histórico inicial ao modelo.
 */
void unit_Model_setInitialHistory();

/**
 * @brief Testa o método clearModel da classe Model.
 * 
 * Este método verifica se o método clearModel limpa corretamente o modelo.
 */
void unit_Model_clearModel();

/**
 * @brief Testa o método execute da classe Model.
 * 
 * Este método verifica se o método execute executa corretamente a lógica do modelo.
 */
void unit_Model_execute();

/**
 * @brief Função para executar todos os testes unitários para a classe Model.
 * 
 * Esta função chama todos os testes unitários definidos para a classe Model.
 */
void run_unit_tests_Model();

#endif
