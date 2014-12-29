#ifndef PLAYER_H
#define PLAYER_H

#include "item.h"
#include "human.h"
#include "env.h"


namespace adventure {
class Player : public Human {

    public:
        Player(std::string name);
        ~Player();

        bool action();
        bool fight(Character & );
        bool pick_up(Item &);
        bool drop(Item &);
        bool talk_to(Character &);


    };
}





#endif