#ifndef ITEM_H
#define ITEM_H

namespace adventure {

    class Item {

    public:

        Item();
        Item(int weight, int volume, int price);
        virtual ~Item();


        int weight() const;
        int volume() const;
        int price() const;

    protected:

        int weight_;
        int volume_;
        int price_;

    };
}


#endif