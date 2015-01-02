#ifndef HUMAN_H
#define HUMAN_H

#include "character.h"

namespace adventure {

    class Human : public Character {

    public:
        Human();
        Human(std::string name, Env * current_room);
        ~Human();

    };
}


#endif
