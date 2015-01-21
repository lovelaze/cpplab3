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
    int direction_to_int(std::string);

    std::string int_to_direction(int);

    bool chance(int);


    void split(const std::string & s, char c, std::vector<std::string> & v);

}

#endif