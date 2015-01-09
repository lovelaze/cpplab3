#include <iostream>
#include "engine.h"
#include "common.h"

using namespace std;
using namespace adventure;



int main() {


    Engine * e = Engine::get_instance();
    e->init_game();
    std::cout <<e->envs().size() << std::endl;
    std::cout <<Engine::get_instance()->envs().size() << std::endl;
    e->run();



    return 0;
}