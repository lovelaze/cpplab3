#include <iostream>
#include "player.h"
#include "cli.h"


using namespace adventure;

Player::Player(std::string name, Env * current_room) : Human(name, "player", current_room, 60, 20, true){
}

Player::Player(std::string name, Env * current_room, int health) : Human(name, "player", current_room, health, 20, true){
}

Player::~Player() {

}


void Player::action() {


    cli.parse_input(cli.get_input(), this);
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


bool Player::has_sapphire() const {
    if (has_backpack()) {
        return backpack()->exists("sapphire");
    }
    return false;
}

std::string Player::class_name() const {
    return "Player";
}