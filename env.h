#ifndef ENV_H
#define ENV_H

#include <string>
#include "character.h"
#include "item.h"
#include <vector>

namespace adventure {

    class Env {

    public:
        Env();
        Env(std::string desc);
        virtual ~Env();

        void directions() const;
        void description() const;

        virtual void neighbor(int direction) = 0;
        virtual bool enter(Character &) = 0;
        virtual bool leave(Character &) = 0;
        virtual bool pick_up(Item &) = 0;
        virtual bool drop(Item &) = 0;


    protected:
        std::string description_;
        std::vector<std::string> directions_;

        int num_directions_;

    };


}



#endif