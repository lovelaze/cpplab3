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
        character->health() -= damage();
        std::cout << name() << " hit " << character->name() << " for " << damage() << " damage." << " (" << character->health() << "/" << character->max_health() << ")" << std::endl;

        character->alive() = character->health() > 0;

        check_kill(character);

    }    
}

void Player::talk_to(Character * character) {
    character->talk_to(this);

}


void Player::die() {
    //alive_ = false;
}

bool Player::has_crystal_ball() const {
    if (has_backpack()) {
        return backpack()->exists("kristallkula");
    }
    return false;
}