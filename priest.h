#ifndef PRIEST_H
#define PRIEST_H

#include "human.h"

namespace adventure {

    class Priest : public Human {


    public:
    	Priest();
        Priest(std::string name, Env * current_room);
        virtual ~Priest();

        void action();
        void fight(Character *character);
        void talk_to(Character *character);

        virtual std::string class_name() const;

    private:

    	int max_mana_;
    	int mana_;
    	
    };
}

#endif