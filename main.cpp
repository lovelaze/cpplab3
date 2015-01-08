#include <iostream>
#include "engine.h"

using namespace std;
using namespace adventure;



int main() {

    Engine * e = new Engine();
    e->init_game();
    e->run();
    delete e;

    //om trollkarlen droppar sin glaskula i garden/forest måste man kolla ut över balkongen för att se den (och sen kunna gå och hämta den), inomhus hittar man den bara genom att bara i samma rum typ.
    //undergångs väg från cellar till forest, kanske gömd.

    



    return 0;
}