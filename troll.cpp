#include <iostream>
#include "troll.h"
#include "common.h"

using namespace adventure;

Troll::Troll() {

}

Troll::Troll(std::string name, Env *current_room) : Monster(name, "troll", current_room, 100, 15, true){
}

Troll::~Troll() {
    
}

void Troll::talk_to(Character * c) {
    std::cout << name() << " he is ANGRY!" << std::endl;
}

void Troll::action() {

    
    

    if(health() < 15){
        add_health(10);
        std::cout << name() << " is sleeping." << std::endl;
    } else if(chance(30)) {
        Item * ip = current_room()->find_item("mushroom");
        if(ip != nullptr){
            current_room_->pick_up(ip);
            std::cout << name() << " SMASH MUSHROOM" << std::endl;
        }
    }
    
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


std::string Troll::class_name() const {
    return "Troll";
}