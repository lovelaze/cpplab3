#include <iostream>
#include "player.h"


using namespace adventure;

Player::Player(std::string name, Env * current_room) : Human(name, current_room, 100, 10, true){
}

Player::~Player() {

}


void Player::action() {



}

void Player::fight(Character * character) {
    if (!character->alive()) {
        std::cout << "Could not fight. " << character->name() << " is dead." << std::endl;
    } else {
        character->health_ -= damage_;
        std::cout << name() << " hit " << character->name() << " for " << damage_ << " damage." << " (" << character->health_ << "/" << character->max_health_ << ")" << std::endl;

        character->alive_ = character->health_ > 0;
        if ( !character->alive()) {
            std::cout << name() << " killed " << character->name() << "." << std::endl;
        }

    }
}

void Player::talk_to(Character * character) {
    character->talk_to(this);

}


