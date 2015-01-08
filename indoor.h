#ifndef INDOOR_H
#define INDOOR_H

#include "env.h"
#include <string>

namespace adventure {
    class Indoor : public Env {

    public:
        Indoor();
        Indoor(std::string desc);
        ~Indoor();

    };
}

#endif