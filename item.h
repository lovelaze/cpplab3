#ifndef ITEM_H
#define ITEM_H

#include <string>

namespace adventure {

    class Character;

    class Item {

    public:

        Item();
        Item(std::string name, int weight, int volume);
        virtual ~Item();

        int weight() const;
        int volume() const;
        std::string name() const;

        virtual void on_pick_up(Character *);
        virtual void on_drop(Character *);

        virtual std::string to_string();


    protected:

        std::string name_;
        int weight_;
        int volume_;

    };
}


#endif