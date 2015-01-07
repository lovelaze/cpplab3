#include <iostream>
#include "room.h"
#include "player.h"
#include "wizard.h"
#include "common.h"
#include "cli.h"
#include "troll.h"

using namespace std;
using namespace adventure;

int main() {

    srand(time(0));

    Room r1("r1");
    Room r2("r2");
    Room r3("r3");
    Room r4("r4");

    r1.addNeighbor(0, &r2).addNeighbor(1, &r3).addNeighbor(2, &r4).addNeighbor(4, &r4);
    r4.addNeighbor(0, &r1);
    r2.addNeighbor(0, &r1);
    r3.addNeighbor(0, &r1);

    Item sword = Item("sword", 1,1,1);
    Backpack backpack = Backpack("backpack", 10, 50, 5, 100, 500);

    r1.drop(&sword);
    r1.drop(&backpack);




    Player p("player", &r1);

    Wizard w("wonka", &r1);

    Troll t("rebar", &r1);

    while (1) parse_input(get_input(), &p);
















    return 0;
}