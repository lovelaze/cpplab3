#ifndef PRIEST_H
#define PRIEST_H

#include "human.h"

namespace adventure {

    class Priest : public Human {


    public:
        Priest(std::string name, Env * current_room);

        void action();
        void fight(Character *character);
        void talk_to(Character *character);
        void die();
    };
}

#endif