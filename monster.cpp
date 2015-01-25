#include "monster.h"

using namespace adventure;

Monster::Monster() {
}

Monster::Monster(std::string name, std::string type, Env * current_room, int health, int damage, bool alive) : Character(name, type, current_room, health, damage, alive) {

}

Monster::~Monster() {
}


std::string Monster::class_name() const {
	return "Monster";
}