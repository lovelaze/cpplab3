#ifndef PLAYER_H
#define PLAYER_H

#include "item.h"
#include "human.h"
#include "env.h"


namespace adventure {
class Player : public Human {

    public:
        Player(std::string name, Env * current_room);
        ~Player();

        bool action();
        bool fight(Character * );
        void talk_to(Character *);


    };
}





#endif