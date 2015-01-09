#ifndef ENV_H
#define ENV_H


#include <string>

#include "item.h"
#include <vector>
#include <tuple>



namespace adventure {

    class Character;

    class Env {


    public:
        Env();
        Env(std::string desc, bool outdoor);
        virtual ~Env();

        std::string directions() const;
        std::string description() const;

        Env * neighbor(int direction);

        void enter(Character *);
        void leave(Character *);
        Item * pick_up(Item *);
        void drop(Item *);

        virtual void on_enter(Character *);
        virtual void climate_event(Character *) = 0;

        Env * addNeighbor(int i, Env *);
        void removeNeighbor(int i);


        void printItems() const;
        void printCharacters() const;

        int get_random_valid_direction() const;

        Character * find_player() const;

        Character * find_character(std::string name) const;

        Item * find_item(std::string name) const;

        void add_char(Character *);

    protected:
        std::string description_;
        std::vector<Env *> neighbors_;
        std::vector<Item *> items_;
        std::vector<Character *> characters_;

        bool outdoor_;

    };



}



#endif