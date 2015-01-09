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
        

        virtual void action() = 0;
        virtual void go(int dir);
        virtual void fight(Character * );
        virtual void pick_up(Item *);
        virtual void drop(Item *);
        virtual void talk_to(Character *);

        void change_room(Env *);
        bool has_backpack() const;
        Backpack * backpack() const;
        bool & alive();
        int go_to_random_neighbor();
        void check_kill(Character *);
        virtual void on_death();

        int & health() {return health_;};
        int & max_health() {return max_health_;};
        int damage() {return damage_+bonus_damage_;};
        int & bonus_damage() {return bonus_damage_;};
        int & bonus_health() {return bonus_health_;};
        Env * current_room() {return current_room_;};

        int add_health(int);

        bool is_player() const;

    protected:

        Env * current_room_;
        std::string name_;
        std::string type_;

        int health_;
        int max_health_;
        int damage_;
        bool alive_;

        int bonus_damage_ = 0;
        int bonus_health_ = 0;

        
        Backpack * backpack_ = nullptr;


    };


}

#endif