#ifndef CONTAINER_H
#define CONTAINER_H

#include "item.h"
#include <vector>

namespace adventure {

    class Container : public Item {
    public:
        Container();
        Container(int weight, int volume, int price, int hold_weight, int hold_volume);
        virtual ~Container();

        int hold_weight() const;
        int hold_volume() const;

        virtual bool add(Item &) = 0;
        virtual bool remove(Item &) = 0;


    protected:
        int hold_weight_;
        int hold_volume_;



    };


}


#endif