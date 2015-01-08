#ifndef BACKPACK_H
#define BACKPACK_H

#include "container.h"

namespace adventure {

    class Backpack : public Container {
    public:
        Backpack();
        Backpack(std::string name, int weight, int volume, int hold_weight, int hold_volume);
        ~Backpack();

        void print() const;

    protected:
    };

}

#endif