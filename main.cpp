#include <iostream>
#include "room.h"
#include "player.h"

using namespace std;
using namespace adventure;

int main() {

    Room r1("adrian");
    Room r2("den stora lokalen");
    Room r3("korv");
    Room r4("apa");

    r1.addNeighbor(0, &r2).addNeighbor(1, &r3).addNeighbor(2, &r4);



    Player p("player");


    r1.printCharacters();
    p.change_room(&r1);
    r1.printCharacters();

    r2.printCharacters();
    p.go(EAST);
    cout << p.current_room_->description() << endl;
    r2.printCharacters();

    //OBS
    //ha ngn slags setroom i characterkontruktorn
    //vill undvika rad 23


    return 0;
}