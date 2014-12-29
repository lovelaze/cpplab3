#include <iostream>
#include "character.h"
#include "env.h"

using namespace adventure;

Character::Character() {
}

Character::~Character() {
}

std::string Character::name() const {
    return name_;
}

std::string Character::type() const {
    return type_;
}

void Character::change_room(Env * env) {
    if (current_room_ != nullptr) {
        current_room_->removeCharacter(this);
    }

    current_room_ = env;
    current_room_->addCharacter(this);
}

void Character::go(Direction dir) {
    if (current_room_ == nullptr) {
        std::cout << "nullptr current_room_" << std::endl;
    }

    change_room(current_room_->neighbor(dir));

}
