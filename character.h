#ifndef CHARACTER_H
#define CHARACTER_H


#include <string>
#include "item.h"
#include "container.h"
#include "backpack.h"
#include <vector>



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
        Character(std::string name, std::string type, Env * current_room);
        virtual ~Character();

        std::string name() const;
        std::string type() const;

        Env * current_room_;



        virtual bool action() = 0;
        void go(Direction dir);
        virtual bool fight(Character * ) = 0;
        bool pick_up(Item *);
        bool drop(Item *);
        virtual void talk_to(Character *) = 0;

        void change_room(Env *);

        bool has_backpack() const;

        void print_backpack() const;


    protected:
        std::string name_;
        std::string type_;
        Backpack * backpack_ = nullptr;


    };


}

#endif