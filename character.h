#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "item.h"



namespace adventure {

    class Character {

    public:
        Character();
        virtual ~Character();

        std::string name() const;
        std::string type() const;

        virtual bool action() = 0;
        virtual void go(int direction) = 0;
        virtual bool fight(Character & ) = 0;
        virtual bool pick_up(Item &) = 0;
        virtual bool drop(Item &) = 0;
        virtual bool talk_to(Character &) = 0;

    protected:
        std::string name_;
        std::string type_;

    };


}

#endif