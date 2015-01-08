#include "item.h"
#include <sstream>

using namespace adventure;

Item::Item() {
}

Item::Item(std::string name, int weight, int volume) : name_(name), weight_(weight), volume_(volume) {

}

Item::~Item() {

}

int Item::weight() const {
    return weight_;
}

int Item::volume() const {
    return volume_;
}

std::string Item::name() const {
    return name_;
}

void Item::on_pick_up(Character * c) {

}

void Item::on_drop(Character * c) {
	
}

std::string Item::to_string() {
	std::ostringstream o;
	o << name_ << " : " << weight_ << " (weight) " << volume_ << " (volume) ";
	return o.str();
}
