#include "container.h"
#include <algorithm>


using namespace adventure;

Container::Container() {
}

Container::Container(std::string name, int weight, int volume, int price, int hold_weight, int hold_volume) : Item(name, weight, volume , price), hold_weight_(hold_weight), hold_volume_(hold_volume) {
}

Container::~Container() {
}

int Container::hold_volume() const {
    return hold_volume_;
}

int Container::hold_weight() const {
    return hold_weight_;
}


bool Container::add(Item * item) {
    if (!fits(item)) return false;

    items_weight += item->weight();
    items_volume += item->volume();
    items_.push_back(item);
    return true;
}

bool Container::remove(Item * item) {

    auto tmp = std::find(items_.begin(), items_.end(), item);
    if( tmp != items_.end())
    {
        items_weight -= item->weight();
        items_volume -= item->volume();
        items_.erase(tmp);
        return true;
    }

    return false;
}

bool Container::fits(Item * item) {
    if (items_volume + item->volume() > hold_volume()) {
        return false;
    }

    if (items_weight + item->weight() > hold_weight()) {
        return false;
    }

    return true;
}
