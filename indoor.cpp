#include "indoor.h"
#include <iostream>
#include "common.h"
#include "character.h"

using namespace adventure;

Indoor::Indoor() {
}

Indoor::Indoor(std::string desc) : Env(desc, false) {
}

Indoor::~Indoor() {
}

void Indoor::climate_event(Character * c) {
	if (c->is_player()) {
		if (chance(10)) {
			if (c->health() < c->max_health()) std::cout << "The warmth is so cozy: " << c->add_health(10) << " health." << std::endl;
		}
	}
	
}