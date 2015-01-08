#include <iostream>
#include "backpack.h"

using namespace adventure;

Backpack::Backpack() {
}

Backpack::Backpack(std::string name, int weight, int volume, int price, int hold_weight, int hold_volume) : Container(name, weight, volume, price, hold_weight, hold_volume) {
}

Backpack::~Backpack() {
}

void Backpack::print() const {
	std::cout << name() << " (" << items_weight() << "/" << hold_weight() << ")" << std::endl;
    for (std::size_t i = 0; i < items_.size(); ++i) {
        std::cout  << items_[i]->name() << " : " << items_[i]->weight() << ", " << items_[i]->volume() << ", " << items_[i]->price() << std::endl;
    }

}
