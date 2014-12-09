#include "env.h"

using namespace adventure;

#include <iostream>

Env::Env() {
}

Env::Env(std::string desc) : description_(desc) {
}

Env::~Env() {
}

void Env::directions() const {
    for (std::string s : directions_) {
        std::cout << s << ", " << std::endl;
    }
}

void Env::description() const {
    std::cout << description_ << std::endl;
}
