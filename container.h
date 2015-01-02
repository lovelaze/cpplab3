#ifndef CONTAINER_H
#define CONTAINER_H

#include "item.h"
#include <vector>

namespace adventure {

    class Container : public Item {
    public:
        Container();
        Container(std::string name, int weight, int volume, int price, int hold_weight, int hold_volume);
        virtual ~Container();

        int hold_weight() const;
        int hold_volume() const;

        int items_weight = 0;
        int items_volume = 0;

        bool add(Item *);
        bool remove(Item *);

        std::vector<Item *> items_;


    protected:
        int hold_weight_;
        int hold_volume_;


    private:
        bool fits(Item *);
    };


}


#endif