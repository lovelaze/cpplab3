#include "player.h"

using namespace adventure;

Player::Player(std::string name) : Human(name){
}

Player::~Player() {

}


bool Player::action() {
    return false;
}

bool Player::fight(Character &character) {
    return false;
}

bool Player::pick_up(Item &item) {
    return false;
}


bool Player::drop(Item &item) {
    return false;
}

bool Player::talk_to(Character &character) {
    return false;
}
