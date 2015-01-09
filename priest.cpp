#include "priest.h"
#include "env.h"
#include <iostream>
#include "common.h"
#include "food.h"
#include "engine.h"

using namespace adventure;

Priest::Priest() {

}

Priest::Priest(std::string name, Env *current_room) : Human(name, "priest", current_room, 50, 10, true), max_mana_(20), mana_(20) {

}

Priest::~Priest() {
	
}

void Priest::action() {

	if (chance(30)) {

		if (mana_ < max_mana_) {
			mana_ += 10;
			if(mana_ > max_mana_) mana_ = max_mana_;

			std::cout << name() << " has regained some mana" << std::endl;	
		}
		
	} else if(chance(25)) {
		Food * i = new Food("mushroom", 5, 5, 5);

		int ran = get_rand(0, Engine::get_instance()->envs().size()-1);
		Env * e = Engine::get_instance()->envs()[ran];

		e->drop(i);
		std::cout << name() << " made a mushroom appear in the " << e->description() << std::endl;

	    Engine::get_instance()->items().push_back(i);
	}
        
}

void Priest::fight(Character * character) {

}

void Priest::talk_to(Character * character) {
	std::cout << "Hello " << character->name() << ". I'm a friendly priest.";

	if (character->health() < character->max_health()) {
		std::cout << " I healed you for " << character->add_health(20) << " health.";
	}
	std::cout << std::endl;
	

}