#ifndef MONSTER_H
#define MONSTER_H

#include "character.h"
#include "env.h"

namespace adventure {
    class Monster : public Character {

    public:
        Monster();

        Monster(std::string name, std::string type, Env *current_room, int health, int damage, bool alive);

        virtual ~Monster();
    };
}



#endif
