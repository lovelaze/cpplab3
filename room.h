#ifndef ROOM_H
#define ROOM_H

#include "indoor.h"

namespace adventure {

    class Room : public Indoor {
    public:
        Room();
        Room(std::string desc);
        virtual ~Room();

    };


}

#endif