#ifndef TROLL_H
#define TROLL_H

#include "monster.h"

namespace adventure {
    class Troll : public Monster {

    public:
    	Troll();
        Troll(std::string name, Env * current_room);
        virtual ~Troll();

        void action();
        void fight(Character * );
        void talk_to(Character *);


    };
}


#endif