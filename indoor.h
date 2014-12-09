#ifndef INDOOR_H
#define INDOOR_H

#include "env.h"
#include <string>

namespace adventure {
    class Indoor : public Env {

    public:
        Indoor();
        Indoor(std::string desc);
        ~Indoor();
/*
        virtual void neighbor(int direction) = 0;
        virtual bool enter(Character &) = 0;
        virtual bool leave(Character &) = 0;
        virtual bool pick_up(Item &) = 0;
        virtual bool drop(Item &) = 0;

        */

    protected:



    };
}

#endif