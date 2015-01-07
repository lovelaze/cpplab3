#ifndef COMMON_H
#define COMMON_H

#include "stdlib.h"
#include <string>
#include <ctime>
#include <memory>
#include <vector>

namespace adventure {
    int get_rand(int, int);

    int direction_to_int(std::string, std::string);

    std::string int_to_direction(int);



}

#endif