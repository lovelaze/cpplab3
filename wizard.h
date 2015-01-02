#ifndef WIZARD_H
#define WIZARD_H

#include "human.h"

namespace adventure {

    class Wizard : public Human {

    public:
        Wizard(std::string name, Env * current_room);

        bool action();
        bool fight(Character * );
        void talk_to(Character *);


    };

}


#endif