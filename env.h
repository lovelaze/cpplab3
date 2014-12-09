#ifndef ENV_H
#define ENV_H

#include <string>
#include "character.h"
#include "item.h"
#include <vector>
#include <tuple>

namespace adventure {

    class Env {

    public:
        Env();
        Env(std::string desc);
        virtual ~Env();

        std::string directions() const;
        std::string description() const;


        Env & neighbor(int direction);
        /*
        virtual bool enter(Character &) = 0;
        virtual bool leave(Character &) = 0;
        virtual bool pick_up(Item &) = 0;
        virtual bool drop(Item &) = 0;
        */


        Env & addNeighbor(int i, Env *);
        void removeNeighbor(int i);


    protected:
        std::string description_;
        std::vector<std::string * > directions_;
        std::vector<Env *> neighbors_;

        std::vector<Item *> items_;
        std::vector<Character *> characters_;




    };


}



#endif