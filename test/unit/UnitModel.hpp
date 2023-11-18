#ifndef UNIT_MODEL_HPP
#define UNIT_MODEL_HPP
#include <math.h>
#include "UnitSystem.hpp"
#include "UnitFlow.hpp"
#include "../../src/ModelImpl.hpp"

void unit_Model_constructor();
void unit_Model_beginSystems();
void unit_Model_endSystems();
void unit_Model_beginFlows();
void unit_Model_endFlows();
void unit_Model_beginHistory();
void unit_Model_endHistory();
void unit_Model_add();
void unit_Model_setInitialHistory();
void unit_Model_clearModel();
void unit_Model_execute();
void run_unit_tests_Model();


#endif