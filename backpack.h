#ifndef BACKPACK_H
#define BACKPACK_H

#include "container.h"

namespace adventure {

    class Backpack : public Container {
    public:
        Backpack();
        Backpack(int weight, int volume, int price, int hold_weight, int hold_volume);
        ~Backpack();


        virtual bool add(Item &item);
        virtual bool remove(Item &item);

    protected:


    protected:
    };

}

#endif