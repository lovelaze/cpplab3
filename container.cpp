#include "container.h"


using namespace adventure;

Container::Container() {
}

Container::Container(int weight, int volume, int price, int hold_weight, int hold_volume) : Item(weight, volume , price), hold_weight_(hold_weight), hold_volume_(hold_volume) {
}

Container::~Container() {
}

int Container::hold_volume() const {
    return hold_volume_;
}

int Container::hold_weight() const {
    return hold_weight_;
}

