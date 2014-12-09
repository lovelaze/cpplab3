#include <iostream>
#include "wizard.h"
#include "backpack.h"

using namespace std;
using namespace adventure;

int main() {
    cout << "Hello, World! FISK" << endl;

    Wizard jokep("jokep");

    Backpack mark(10,10,10,10,10);

    cout << jokep.name() << ", " << jokep.type() << endl;

    cout << mark.weight() << ", " << mark.volume() << endl;


    return 0;
}