#include <iostream>
#include "engine.h"

using namespace std;
using namespace adventure;



int main() {

    Engine * e = Engine::get_instance();
    e->init_game();
    e->run();
    delete e;

    return 0;
}