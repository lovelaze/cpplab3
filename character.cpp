
#include "character.h"


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