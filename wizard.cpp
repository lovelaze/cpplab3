#include <iostream>
#include "wizard.h"

using namespace adventure;

Wizard::Wizard(std::string name, Env * current_room) : Human(name, current_room){
}

bool Wizard::action() {
    return false;
}

bool Wizard::fight(Character * character) {
    return false;
}
void Wizard::talk_to(Character * character) {

    std::cout << "Hello, " << character->name() << ". I am a " << type() << " and I like to fish." << std::endl;
}
