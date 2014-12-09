#include "backpack.h"

using namespace adventure;

Backpack::Backpack() {
}

Backpack::Backpack(int weight, int volume, int price, int hold_weight, int hold_volume) : Container(weight, volume, price, hold_weight, hold_volume) {
}

Backpack::~Backpack() {
}

bool Backpack::add(Item &item) {
    return false;
}

bool Backpack::remove(Item &item) {
    return false;
}
