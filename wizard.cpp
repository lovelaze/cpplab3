#include <iostream>
#include "wizard.h"
#include "common.h"


using namespace adventure;

Wizard::Wizard(std::string name, Env * current_room) : Human(name, current_room, 50, 5, true){
}

void Wizard::action() {

    if (health_ <= max_health_/2) {
        switch(get_rand(0, 1)) {
            case 0:

                break;

            case 1:
                std::cout << "1" << std::endl;
                break;
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
        character->health_ -= character->max_health_/5 + damage_;
        std::cout << name() << " blasts " << character->name() << " for " << character->max_health_/5+damage_ << " damage." << " (" << character->health_ << "/" << character->max_health_ << ")" << std::endl;

        character->alive_ = character->health_ > 0;
        if ( !character->alive()) {
            std::cout << name() << " killed " << character->name() << "." << std::endl;
        }

    }
}
void Wizard::talk_to(Character * character) {

    std::cout << "Hello, " << character->name() << ". I am a " << type() << " and I like to fish." << std::endl;
}


