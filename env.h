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
        /*
        virtual bool pick_up(Item &) = 0;
        virtual bool drop(Item &) = 0;
        */


        Env & addNeighbor(int i, Env *);
        void removeNeighbor(int i);


        void printItems();
        void printCharacters();


    protected:
        std::string description_;
        std::vector<Env *> neighbors_;
        std::vector<Item *> items_;
        std::vector<Character *> characters_;

    };



}



#endif