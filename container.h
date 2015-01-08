#ifndef CONTAINER_H
#define CONTAINER_H

#include "item.h"
#include <vector>

namespace adventure {

    class Container : public Item {
    public:
        Container();
        Container(std::string name, int weight, int volume, int hold_weight, int hold_volume);
        virtual ~Container();

        int hold_weight() const;
        int hold_volume() const;

        int items_weight() const;
        int items_volume() const;

        

        bool add(Item *);
        bool remove(Item *);

        Item * find_item(std::string name) const;

        bool exists(std::string name) const;

        std::vector<Item *> items_;


    protected:
        int hold_weight_;
        int hold_volume_;
        int items_weight_;
        int items_volume_;


    private:
        bool fits(Item *);
    };


}


#endif