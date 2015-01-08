#include "food.h"
#include "character.h"
#include <iostream>
#include <sstream>
#include "env.h"

using namespace adventure;

Food::Food() {

}

Food::Food(std::string name, int weight, int volume, int health_bonus) : Item(name, weight, volume), health_bonus_(health_bonus) {

}

Food::~Food() {

}

int Food::health_bonus() const {
	return health_bonus_;
}

std::string Food::to_string() {
	std::ostringstream o;
	o << name_ << " : " << weight_ << " (weight) " << volume_ << " (volume) " << health_bonus_ << " (health)";
	return o.str();
}

void Food::eat(Character * c) {
    std::cout << c->name() << " ate " << name() << " and was healed for " << c->add_health(health_bonus_) << " health" << std::endl;
    c->drop(this);
    c->current_room()->pick_up(this);;
}