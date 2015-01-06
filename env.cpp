#include "env.h"

#include <iostream>
#include <sstream>
#include <algorithm>
#include "character.h"
#include "common.h"
#include <stdexcept>

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

    std::cout << "in room: " << description() << std::endl;

    for (int i = 0; i < characters_.size(); ++i) {
        if (characters_[i] != nullptr) {
            std::cout << characters_[i]->name() << std::endl;
        }
    }
    std::cout << std::endl;
}

void Env::printItems() {
    for (int i = 0; i < items_.size(); ++i) {
        if (items_[i] != nullptr) {
            std::cout << items_[i]->name() << std::endl;
        }
    }
}

Item * Env::pick_up(Item * item) {
    auto tmp = std::find(items_.begin(), items_.end(), item);
    items_.erase(tmp);
    return item;
}

void Env::drop(Item * item) {
    items_.push_back(item);
}


/*
    if i < 0 pls exception
 */
int Env::get_random_valid_direction() {



    int temp = 0;
    for (int i = 0; i < neighbors_.size(); ++i) {
        if (neighbors_[i] != nullptr) ++temp;
    }

    //fixa sen!

    if (temp <= 0) {
        std::cout << "could not find a valid direction" << std::endl;
        return -1;

    }


    int n = get_rand(0, temp-1);

    int i = -1;
    while (n >= 0) {
        ++i;
        if (neighbors_[i] != nullptr) {
            --n;
        }
    }

    return i;

}


Character * Env::find_player() {
    for (int i = 0; i < characters_.size(); ++i)  {
        if (characters_[i]->type() == "player") return characters_[i];
    }

    return nullptr;

}

Character * Env::find_character(std::string name) {

    for (int i = 0; i < characters_.size(); ++i) {
        if (characters_[i]->name() == name) return characters_[i];
    }
    return nullptr;
}

Item *Env::find_item(std::string name) {

    for (int i = 0; i < items_.size(); ++i) {
        if (items_[i]->name() == name) return items_[i];
    }

    return nullptr;
}
