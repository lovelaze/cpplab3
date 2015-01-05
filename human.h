#ifndef HUMAN_H
#define HUMAN_H

#include "character.h"

namespace adventure {

    class Human : public Character {

    public:
        Human();
        Human(std::string name, std::string type, Env * current_room, int health, int damage, bool alive);
        ~Human();

    };
}


#endif
