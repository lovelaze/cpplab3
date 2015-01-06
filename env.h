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
        Env(std::string desc);
        virtual ~Env();

        std::string directions() const;
        std::string description() const;



        Env * neighbor(int direction);

        void enter(Character *);
        void leave(Character *);
        Item * pick_up(Item *);
        void drop(Item *);



        Env & addNeighbor(int i, Env *);
        void removeNeighbor(int i);


        void printItems();
        void printCharacters();

        int get_random_valid_direction();

        Character * find_player();

        Character * find_character(std::string name);

        Item * find_item(std::string name);

    protected:
        std::string description_;
        std::vector<Env *> neighbors_;
        std::vector<Item *> items_;
        std::vector<Character *> characters_;

    };



}



#endif