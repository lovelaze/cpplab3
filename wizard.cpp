#include "wizard.h"

using namespace adventure;

Wizard::Wizard(std::string name) : Human(name){
}

bool Wizard::action() {
    return false;
}

void Wizard::go(int direction) {
}

bool Wizard::fight(Character &character) {
    return false;
}

bool Wizard::pick_up(Item &item) {
    return false;
}

bool Wizard::drop(Item &item) {
    return false;
}

bool Wizard::talk_to(Character &character) {
    return false;
}
