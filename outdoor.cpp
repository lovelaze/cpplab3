#include "outdoor.h"
#include <iostream>
#include "common.h"
#include "character.h"

using namespace adventure;


Outdoor::Outdoor() {
}

Outdoor::Outdoor(std::string desc) : Env(desc, true) {
}

Outdoor::~Outdoor() {
}

void Outdoor::climate_event(Character * c) {
	if (c->is_player()) {
		if (chance(40)) {
		std::cout << "The cold weather is freezing you to bits: -5 health" << std::endl;
		c->health() -= 5;
		}
	}
}

std::string Outdoor::class_name() const {
	return "Outdoor";
}
