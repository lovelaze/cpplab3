#include <iostream>
#include "troll.h"
#include "common.h"

using namespace adventure;

Troll::Troll(std::string name, Env *current_room) : Monster(name, "troll", current_room, 100, 15, true){
}

void Troll::talk_to(Character * c) {
    std::cout << name() << " he is ANGRY!" << std::endl;
}

void Troll::action() {
}

void Troll::fight(Character * character) {

    if (!character->alive()) {
        std::cout << "Could not fight. " << character->name() << " is dead." << std::endl;
    } else {


        
        int dmg_mult = 1;
        if (chance(50)) {
            dmg_mult = 2;
        }

        character->health() -= damage()*dmg_mult;
        std::cout << name() << " hits " << character->name() << " for " << damage()*dmg_mult << " damage." << " (" << character->health() << "/" << character->max_health() << ")" << std::endl;

        check_kill(character);
    }

}
