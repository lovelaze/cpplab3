#include "item.h"

using namespace adventure;

Item::Item() {
}

Item::Item(std::string name, int weight, int volume, int price) : name_(name), weight_(weight), volume_(volume), price_(price) {

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

std::string Item::name() const {
    return name_;
}
