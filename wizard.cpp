#include <iostream>
#include "wizard.h"
#include "common.h"
#include "env.h"
#include "engine.h"


using namespace adventure;

Wizard::Wizard(std::string name, Env * current_room) : Human(name, "wizard", current_room, 70, 5, true){
}

Wizard::~Wizard() {
    
}

void Wizard::action() {

    if (chance(30)) {
        go_to_random_neighbor();
    } else if(chance(25)) {
        Character * ptr = current_room()->find_player();
        if (ptr != nullptr) {
            fight(ptr);
        } else {
            std::cout << name() << " tried to fight player but could not find him." << std::endl;
        }
    }

}

/*
    Wizard does 20% of maximum health + 5 as damage with one attack.
*/
void Wizard::fight(Character * character) {
    if (!character->alive()) {
        std::cout << "Could not fight. " << character->name() << " is dead." << std::endl;
    } else {
        character->health() -= character->max_health()/5 + damage_;
        std::cout << name() << " blasts " << character->name() << " for " << character->max_health()/5+damage() << " damage." << " (" << character->health() << "/" << character->max_health() << ")" << std::endl;

        check_kill(character);

    }
}
void Wizard::talk_to(Character * character) {

    std::cout << "Hello, " << character->name() << ". I am a " << type() << " and I like to fish." << std::endl;
}


void Wizard::on_death() {
    drop_sapphire();
}

void Wizard::drop_sapphire() {
    Item * i = new Item("sapphire", 20, 5);
    current_room_->drop(i);
    std::cout << name() << " dropped an item on the ground" << std::endl;
    Engine::get_instance()->items().push_back(i);
}

std::string Wizard::class_name() const {
    return "Wizard";
}