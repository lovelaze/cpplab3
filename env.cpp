#include "env.h"

using namespace adventure;

#include <iostream>
#include <sstream>

Env::Env() {
}

Env::Env(std::string desc) : description_(desc), directions_(std::vector<std::string * >(8)), neighbors_(std::vector<Env *>(8)) {
}

Env::~Env() {
}

std::string Env::directions() const {
    std::ostringstream oss;


    for (int i = 0; i < directions_.size(); ++i) {

        if (directions_[i] != nullptr) {

            oss << i << " - " << *directions_[i] << std::endl;
        }

    }
    return oss.str();
}

std::string Env::description() const {
    return description_;
}

Env & Env::neighbor(int direction) {
    return *neighbors_[direction];
}

Env & Env::addNeighbor(int i, Env * env) {
    neighbors_[i] = env;
    directions_[i] = & env->description_;

    return *this;
}




void Env::removeNeighbor(int i){
    neighbors_[i] = nullptr;
}