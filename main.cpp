#include <iostream>
#include "room.h"
#include "player.h"
#include "wizard.h"
#include "common.h"
#include "cli.h"
#include "troll.h"
#include "unique_storage.hpp"
#include "game_storage.hpp"
#include "object.h"
#include "constants.h"

using namespace std;
using namespace adventure;

int main() {

    srand(time(0));

    Room mainhall("main hall");
    Room kitchen("kitchen");
    Room bedroom("bedroom");
    Room cellar("cellar");
    Room garden("garden");      //utomhus
    Room forest("forest");      //utomhus
    Room balcony("balcony"); //utombus

    mainhall.addNeighbor(NORTH, &kitchen).addNeighbor(EAST, &bedroom).addNeighbor(SOUTH, &garden);
    kitchen.addNeighbor(SOUTH, &mainhall).addNeighbor(NORTH, &cellar);
    bedroom.addNeighbor(WEST, &mainhall).addNeighbor(EAST, &balcony);
    cellar.addNeighbor(SOUTH, &kitchen).addNeighbor(EAST, &forest);
    garden.addNeighbor(NORTH_WEST, &mainhall).addNeighbor(SOUTH_WEST, &forest);
    forest.addNeighbor(NORTH_EAST, &garden).addNeighbor(WEST, &cellar);
    balcony.addNeighbor(NORTH_WEST, &bedroom);


    //om trollkarlen droppar sin glaskula i garden/forest måste man kolla ut över balkongen för att se den (och sen kunna gå och hämta den), inomhus hittar man den bara genom att bara i samma rum typ.
    //undergångs väg från cellar till forest, kanske gömd.

    Player p("adrian",&mainhall);

    cout << p.current_room_->directions() << endl;



    return 0;
}