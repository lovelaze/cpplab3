#include "indoor.h"

using namespace adventure;

Indoor::Indoor() {
}

Indoor::Indoor(std::string desc, int num_dirs) : Env(desc) {
    num_directions_ = num_dirs;
}

Indoor::~Indoor() {
}