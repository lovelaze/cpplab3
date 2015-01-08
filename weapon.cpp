#include "weapon.h"
#include "character.h"
#include <sstream>

using namespace adventure;

Weapon::Weapon() {

}

Weapon::Weapon(std::string name, int weight, int volume, int damage_bonus) : Item(name, weight, volume), damage_bonus_(damage_bonus) {

}

Weapon::~Weapon() {

}

int Weapon::damage_bonus() const {
	return damage_bonus_;
}

void Weapon::on_pick_up(Character * c) {
	c->bonus_damage() += damage_bonus();
}

void Weapon::on_drop(Character * c) {
	c->bonus_damage() -= damage_bonus();
}

std::string Weapon::to_string() {
	std::ostringstream o;
	o << name_ << " : " << weight_ << " (weight) " << volume_ << " (volume) " << damage_bonus_ << " (damage)";
	return o.str();
}
