#include "priest.h"
#include "env.h"
#include <iostream>

using namespace adventure;


Priest::Priest(std::string name, Env *current_room) : Human(name, "priest", current_room, 50, 10, true) {

}

void Priest::action() {

}

void Priest::fight(Character * character) {

}

void Priest::talk_to(Character * character) {
	std::cout << "Hello " << character->name() << ". I'm a friendly priest.";

	if (character->health() < character->max_health()) {
		std::cout << " I healed you for " << character->add_health(10) << " health.";
	}
	std::cout << std::endl;
	

}