#include "player.h"

using namespace adventure;

Player::Player(std::string name, Env * current_room) : Human(name, current_room){
}

Player::~Player() {

}


bool Player::action() {
    return false;
}

bool Player::fight(Character * character) {
    return false;
}

void Player::talk_to(Character * character) {
    character->talk_to(this);

}
