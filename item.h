#ifndef ITEM_H
#define ITEM_H

#include <string>

namespace adventure {

    class Item {

    public:

        Item();
        Item(std::string name, int weight, int volume, int price);
        virtual ~Item();

        int weight() const;
        int volume() const;
        int price() const;
        std::string name() const;

    protected:

        std::string name_;
        int weight_;
        int volume_;
        int price_;
        int damage_bonus;
        int health_bonus;

    };
}


#endif