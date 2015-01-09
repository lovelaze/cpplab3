#ifndef PLAYER_H
#define PLAYER_H

#include "item.h"
#include "human.h"
#include "env.h"


namespace adventure {
class Player : public Human {

    public:
        Player(std::string name, Env * current_room);
        virtual  ~Player();

        void action();
        void fight(Character * );
        void talk_to(Character *);
        bool has_sapphire() const;



    };
}





#endif