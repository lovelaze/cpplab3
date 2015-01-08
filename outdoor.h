#ifndef OUTDOOR_H
#define OUTDOOR_H

#include "env.h"
#include <string>

namespace adventure {
    class Outdoor : public Env {

    public:
        Outdoor();
        Outdoor(std::string desc);
        ~Outdoor();
        void climate_event(Character*);
        
    };

    class Garden : public Outdoor {
    	using Outdoor::Outdoor;
    	void on_enter(Character * c) {
    		
    	}
    };
}

#endif
