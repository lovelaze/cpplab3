#include "item.h"

using namespace adventure;

Item::Item() {
}

Item::Item(int weight, int volume, int price) : weight_(weight), volume_(volume), price_(price) {

}

Item::~Item() {

}

int Item::weight() const {
    return weight_;
}

int Item::volume() const {
    return volume_;
}

int Item::price() const {
    return price_;
}
