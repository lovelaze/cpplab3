#include "human.h"

using namespace adventure;

Human::Human() {
}

Human::Human(std::string name, Env * current_room, int health, int damage, bool alive) : Character(name, "Human", current_room, health, damage, alive) {

}

Human::~Human() {
}

