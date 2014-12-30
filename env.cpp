#include "env.h"

#include <iostream>
#include <sstream>
#include <algorithm>
#include "character.h"
#include "item.h"

using namespace adventure;

Env::Env() {
}

Env::Env(std::string desc) : description_(desc), neighbors_(std::vector<Env *>(8)) {
}

Env::~Env() {
}

std::string Env::directions() const {
    std::ostringstream oss;


    for (int i = 0; i < neighbors_.size(); ++i) {

        if (neighbors_[i] != nullptr) {

            oss << i << " - " << neighbors_[i]->description() << std::endl;
        }

    }

    return oss.str();
}

std::string Env::description() const {
    return description_;
}

Env * Env::neighbor(int direction) {
    return neighbors_[direction];
}

Env & Env::addNeighbor(int i, Env * env) {
    neighbors_[i] = env;
    return *this;
}

void Env::removeNeighbor(int i){
    neighbors_[i] = nullptr;
}


void Env::enter(Character * c) {
    if(std::find(characters_.begin(), characters_.end(), c) == characters_.end())
    {
        characters_.push_back(c);
    }
}



void Env::leave(Character *c) {

    auto tmp = std::find(characters_.begin(), characters_.end(), c);
    if( tmp != characters_.end())
    {
        characters_.erase(tmp);
    }


}

void Env::printCharacters() {
    for (int i = 0; i < characters_.size(); ++i) {
        if (characters_[i] != nullptr) {
            std::cout << characters_[i]->name() << std::endl;
        }
    }
}

void Env::printItems() {
    for (int i = 0; i < items_.size(); ++i) {
        if (items_[i] != nullptr) {
            // std::cout << items_[i]->name() << std::endl;
        }
    }
}