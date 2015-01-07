#include <iostream>
#include "player.h"


using namespace adventure;

Player::Player(std::string name, Env * current_room) : Human(name, "player", current_room, 60, 20, true){
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

        check_kill(character);

    }
}

void Player::talk_to(Character * character) {
    character->talk_to(this);

}


void Player::die() {
    //alive_ = false;
}
