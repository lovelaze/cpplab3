#ifndef GAME_STORAGE_H
#define GAME_STORAGE_H

#include "unique_storage.hpp"

namespace adventure {

    template <class T>
    class Game_Storage : public Unique_Storage<T> {

    public:
        Game_Storage() {};
        virtual ~Game_Storage() {};



    };
}

#endif