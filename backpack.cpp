#include "backpack.h"

using namespace adventure;

Backpack::Backpack() {
}

Backpack::Backpack(std::string name, int weight, int volume, int price, int hold_weight, int hold_volume) : Container(name, weight, volume, price, hold_weight, hold_volume) {
}

Backpack::~Backpack() {
}
