#include <iostream>
#include "room.h"
#include "player.h"
#include "wizard.h"

using namespace std;
using namespace adventure;

int main() {

    Room r1("adrian");
    Room r2("den stora lokalen");
    Room r3("korv");
    Room r4("apa");

    r1.addNeighbor(0, &r2).addNeighbor(1, &r3).addNeighbor(2, &r4);
    r4.addNeighbor(0, &r1);

    Item sword = Item("sword", 1,1,1);
    Backpack backpack = Backpack("backpack", 10, 50, 5, 100, 500);

    r1.drop(&sword);
    r1.drop(&backpack);


    Player p("player", &r1);
   
    Wizard w("adrian", &r2);

    p.talk_to(&w);





    return 0;
}