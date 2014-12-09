#ifndef HUMAN_H
#define HUMAN_H

#include "character.h"

namespace adventure {

    class Human : public Character {

    public:
        Human();
        Human(std::string name);
        ~Human();

    };
}


#endif
