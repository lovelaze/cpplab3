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

        int bonus_damage = 0;
        int bonus_health = 0;

        virtual void action() = 0;
        virtual void go(int dir);
        virtual void fight(Character * ) = 0;
        virtual bool pick_up(Item *);
        virtual bool drop(Item *);
        virtual void talk_to(Character *) = 0;

        void change_room(Env *);

        bool has_backpack() const;

        Backpack * backpack();

        bool alive();

        int go_to_random_neighbor();

        void check_kill(Character *);

        virtual void die() = 0;

    protected:
        std::string name_;
        std::string type_;
        Backpack * backpack_ = nullptr;


    };


}

#endif