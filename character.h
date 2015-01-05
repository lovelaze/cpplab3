#ifndef CHARACTER_H
#define CHARACTER_H


#include <string>
#include "item.h"
#include "container.h"
#include "backpack.h"
#include <vector>



namespace adventure {

    class Env;

    class Character {



    public:

        Character();
        Character(std::string name, std::string type, Env * current_room, int health, int damage, bool alive);
        virtual ~Character();

        std::string name() const;
        std::string type() const;
        Env * current_room_;

        int health_;
        int max_health_;
        int damage_;
        bool alive_;

        virtual void action() = 0;
        void go(int dir);
        virtual void fight(Character * ) = 0;
        bool pick_up(Item *);
        bool drop(Item *);
        virtual void talk_to(Character *) = 0;

        void change_room(Env *);

        bool has_backpack() const;

        void print_backpack() const;

        bool alive();

        int go_to_random_neighbor();

    protected:
        std::string name_;
        std::string type_;
        Backpack * backpack_ = nullptr;


    };


}

#endif