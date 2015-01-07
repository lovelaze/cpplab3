#include <iostream>
#include "troll.h"
#include "common.h"

using namespace adventure;

Troll::Troll(std::string name, Env *current_room) : Monster(name, "troll", current_room, 100, 15, true){
}

void Troll::talk_to(Character * c) {
    std::cout << name() << " is ANGRY!" << std::endl;
    fight(c);
}

void Troll::action() {
}

void Troll::fight(Character * character) {

    if (!character->alive()) {
        std::cout << "Could not fight. " << character->name() << " is dead." << std::endl;
    } else {


        int rand = get_rand(0, 3);
        int dmg_mult = 1;
        if (rand == 0) {
            dmg_mult = 2;
        }

        character->health_ -= damage_*dmg_mult;
        std::cout << name() << " hits " << character->name() << " for " << damage_*dmg_mult << " damage." << " (" << character->health_ << "/" << character->max_health_ << ")" << std::endl;

        check_kill(character);
    }

}

void Troll::die() {

}
