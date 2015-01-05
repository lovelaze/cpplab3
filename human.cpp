#include "human.h"

using namespace adventure;

Human::Human() {
}

Human::Human(std::string name, std::string type, Env * current_room, int health, int damage, bool alive) : Character(name, type, current_room, health, damage, alive) {

}

Human::~Human() {
}

