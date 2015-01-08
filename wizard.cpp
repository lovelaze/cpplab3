#include <iostream>
#include "wizard.h"
#include "common.h"
#include "env.h"
#include "engine.h"


using namespace adventure;

Wizard::Wizard(std::string name, Env * current_room) : Human(name, "wizard", current_room, 50, 5, true){
}

void Wizard::action() {

    switch(get_rand(0,1)) {
        case 0:     //move to another room
            go_to_random_neighbor();
            break;

        case 1:     //fight with player
            Character * ptr = current_room_->find_player();
            if (ptr != nullptr) {
                fight(ptr);
            } else {
                std::cout << name() << " tried to fight player but could not find him." << std::endl;
            }
            
            break;

    }




}

/*
    Wizard does 20% of maximum health + 5 as damage with one attack.
*/
void Wizard::fight(Character * character) {
    if (!character->alive()) {
        std::cout << "Could not fight. " << character->name() << " is dead." << std::endl;
    } else {
        character->health_ -= character->max_health_/5 + damage_;
        std::cout << name() << " blasts " << character->name() << " for " << character->max_health_/5+damage_ << " damage." << " (" << character->health_ << "/" << character->max_health_ << ")" << std::endl;

        check_kill(character);

    }
}
void Wizard::talk_to(Character * character) {

    std::cout << "Hello, " << character->name() << ". I am a " << type() << " and I like to fish. Also I dropped my ball for you." << std::endl;

    Item * i = new Item("kristallkula", 20, 5, 1);
    current_room_->drop(i);
    Engine::get_instance()->items().push_back(i);
}


void Wizard::die() {
    
}
