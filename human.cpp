#include "human.h"

using namespace adventure;

Human::Human() {
}

Human::Human(std::string name) {
    name_ = name;
    type_ = "Human";
}

Human::~Human() {
}

