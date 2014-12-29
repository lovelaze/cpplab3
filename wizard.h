#ifndef WIZARD_H
#define WIZARD_H

#include "human.h"

namespace adventure {

    class Wizard : public Human {

    public:
        Wizard(std::string name);

        bool action();
        bool fight(Character & );
        bool pick_up(Item &);
        bool drop(Item &);
        bool talk_to(Character &);


    };

}


#endif