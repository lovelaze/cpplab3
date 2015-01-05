#ifndef CLI_H
#define CLI_H

#include <string>
#include <vector>
#include "character.h"

namespace adventure {

    std::string get_input();

    void parse_input(std::string, Character *);

    bool valid_command(std::string);

    bool valid_direction(std::string, std::string);




}


#endif