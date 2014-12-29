#ifndef CHARACTER_H
#define CHARACTER_H


#include <string>
#include "item.h"




namespace adventure {

    class Env;

    enum Direction {
        NORTH,
        NORTH_EAST,
        EAST,
        SOUTH_EAST,
        SOUTH,
        SOUTH_WEST,
        WEST,
        NORTH_WEST
    };

    class Character {



    public:



        Character();
        virtual ~Character();

        std::string name() const;
        std::string type() const;

        Env * current_room_;

        virtual bool action() = 0;
        void go(Direction dir);
        virtual bool fight(Character & ) = 0;
        virtual bool pick_up(Item &) = 0;
        virtual bool drop(Item &) = 0;
        virtual bool talk_to(Character &) = 0;

        void change_room(Env *);


    protected:
        std::string name_;
        std::string type_;

    };


}

#endif