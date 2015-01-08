#include "container.h"
#include <algorithm>


using namespace adventure;

Container::Container() {
}

Container::Container(std::string name, int weight, int volume, int price, int hold_weight, int hold_volume) : Item(name, weight, volume , price), hold_weight_(hold_weight), hold_volume_(hold_volume), items_weight_(0), items_volume_(0) {
}

Container::~Container() {
}

int Container::hold_volume() const {
    return hold_volume_;
}

int Container::hold_weight() const {
    return hold_weight_;
}

int Container::items_weight() const {
    return items_weight_;
}

int Container::items_volume() const {
    return items_volume_;
}


bool Container::add(Item * item) {
    if (!fits(item)) return false;

    items_weight_ += item->weight();
    items_volume_ += item->volume();
    items_.push_back(item);
    return true;
}

bool Container::remove(Item * item) {

    auto tmp = std::find(items_.begin(), items_.end(), item);
    if( tmp != items_.end())
    {
        items_weight_ -= item->weight();
        items_volume_ -= item->volume();
        items_.erase(tmp);
        return true;
    }

    return false;
}

bool Container::fits(Item * item) {
    if (items_volume() + item->volume() > hold_volume()) {
        return false;
    }

    if (items_weight() + item->weight() > hold_weight()) {
        return false;
    }

    return true;
}


Item * Container::find_item(std::string name) const {

    for (std::size_t i = 0; i < items_.size(); ++i) {
        if (items_[i]->name() == name) return items_[i];
    }
    return nullptr;
}

bool Container::exists(std::string name) const {
    return find_item(name) != nullptr;
}