#ifndef OUTDOOR_H
#define OUTDOOR_H

#include "env.h"
#include <string>
#include <iostream>
#include "character.h"
#include "engine.h"

namespace adventure {
    class Outdoor : public Env {

    public:
        Outdoor();
        Outdoor(std::string desc);
        virtual ~Outdoor();
        void climate_event(Character*);
        
    };

    class Balcony : public Outdoor {
    	using Outdoor::Outdoor;
    	void on_enter(Character * c) {
    		if(c->is_player()) {
                std::cout << "I can see the garden and a priest from here" << std::endl;
            }
    	}
    };
}

#endif
