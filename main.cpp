#include <iostream>
#include "room.h"

using namespace std;
using namespace adventure;

int main() {

    Room r1("adrian");
    Room r2("den stora lokalen");
    Room r3("korv");
    Room r4("apa");

    r1.addNeighbor(0, &r2).addNeighbor(1, &r3).addNeighbor(2, &r4);

    cout << r1.directions() << endl;



    return 0;
}