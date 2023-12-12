#include "UnitFlow.hpp"
#include "UnitModel.hpp"
#include "UnitSystem.hpp"
#include "UnitHandleBody.hpp"

using namespace std;

int main(){

    run_unit_tests_Flow();
    run_unit_tests_System();
    run_unit_tests_Model();
    run_handle_body_unit_tests();
    return 0;
}