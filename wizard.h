#ifndef WIZARD_H
#define WIZARD_H

#include "human.h"

namespace adventure {

    class Wizard : public Human {

    public:
        Wizard(std::string name, Env * current_room);
        virtual ~Wizard();

        void action();
        void fight(Character * );
        void talk_to(Character *);
        void on_death();

        virtual std::string class_name() const;

    private:
    	void drop_sapphire();
    };

}


#endif