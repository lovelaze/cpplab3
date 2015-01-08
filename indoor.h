#ifndef INDOOR_H
#define INDOOR_H

#include "env.h"
#include <string>
#include "character.h"
namespace adventure {

    class Indoor : public Env {

    public:
        Indoor();
        Indoor(std::string desc);
        ~Indoor();

        void climate_event(Character*);

    };

    class Cellar : public Indoor {
    	using Indoor::Indoor;
    	void on_enter(Character * c) {
    		Character * trollp = find_character("Trihx");
    		if (trollp != nullptr && c->type() == "player") {
    			c->talk_to(trollp);
    			trollp->fight(c);  
    		}
    	}
    };
}

#endif
