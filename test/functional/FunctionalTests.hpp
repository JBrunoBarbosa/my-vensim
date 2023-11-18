/**
 * @file FuncionalTest.hpp
 * @brief Arquivo de cabeçalho para testes funcionais.
 *
 * Este arquivo contém declarações de funções para testes funcionais do sistema, incluindo
 * testes para fluxos exponenciais, fluxos logísticos e testes complexos. Cada função de teste
 * executa cenários de teste específicos e verifica o comportamento do sistema.
 */
#ifndef FUNCIONAL_TEST_HPP
#define FUNCIONAL_TEST_HPP

#include "../../src/System.hpp"
#include "../../src/Flow.hpp"

/**
 * @brief Executa o teste funcional para fluxos exponenciais.
 *
 * Este teste executa cenários de teste específicos para fluxos exponenciais e verifica
 * o comportamento do sistema com esses fluxos.
 */
void exponentialFuncionalTest();

/**
 * @brief Executa o teste funcional para fluxos logísticos.
 *
 * Este teste executa cenários de teste específicos para fluxos logísticos e verifica
 * o comportamento do sistema com esses fluxos.
 */
void logisticalFuncionalTest();

/**
 * @brief Executa o teste funcional em modelo complexo.
 *
 * Este teste executa cenários de teste complexos que podem envolver vários fluxos
 * e sistemas interagindo, verificando o comportamento do sistema em situações mais
 * complexas.
 */
void complexFuncionalTest();

#endif
