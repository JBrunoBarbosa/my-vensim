/**
 * @brief Arquivo de testes unitários para a classe Flow.
 * 
 * Este arquivo contém declarações de métodos de teste para a classe Flow.
*/
#ifndef UNIT_FLOW_HPP
#define UNIT_FLOW_HPP

#include "../../src/SystemImpl.hpp"
#include "../../src/FlowImpl.hpp"
#include <assert.h>

/**
 * @brief Testa o construtor da classe Flow.
 * 
 * Este método verifica se o construtor da classe Flow funciona conforme esperado.
*/
void unit_Flow_construtor();

/**
 * @brief Testa o método execute da classe Flow.
 * 
 * Este método verifica se o método execute da classe Flow funciona corretamente.
*/
void unit_Flow_execute();

/**
 * @brief Testa o método link da classe Flow.
 * 
 * Este método verifica se o método link da classe Flow está corretamente implementado.
*/
void unit_Flow_link();

/**
 * @brief Testa o método setSource da classe Flow.
 * 
 * Este método verifica se o método setSource da classe Flow atribui corretamente o componente de origem.
*/
void unit_Flow_setSource();

/**
 * @brief Testa o método setTarget da classe Flow.
 * 
 * Este método verifica se o método setTarget da classe Flow atribui corretamente o componente de destino.
*/
void unit_Flow_setTarget();

/**
 * @brief Testa o método setName da classe Flow.
 * 
 * Este método verifica se o método setName da classe Flow atribui corretamente o nome ao fluxo.
*/
void unit_Flow_setName();

/**
 * @brief Testa o método getName da classe Flow.
 * 
 * Este método verifica se o método getName da classe Flow retorna corretamente o nome do fluxo.
*/
void unit_Flow_getName();

/**
 * @brief Testa o método getSource da classe Flow.
 * 
 * Este método verifica se o método getSource da classe Flow retorna corretamente o componente de origem.
*/
void unit_Flow_getSource();

/**
 * @brief Testa o método getTarget da classe Flow.
 * 
 * Este método verifica se o método getTarget da classe Flow retorna corretamente o componente de destino.
*/
void unit_Flow_getTarget();

/**
 * @brief Executa todos os testes unitários para a classe Flow.
 * 
 * Este método chama todos os testes unitários definidos para a classe Flow.
*/
void run_unit_tests_Flow();

#endif
