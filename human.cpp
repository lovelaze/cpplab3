#include "human.h"

using namespace adventure;

Human::Human() {
}

Human::Human(std::string name, Env * current_room) : Character(name, "Human", current_room) {

}

Human::~Human() {
}

