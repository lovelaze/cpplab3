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
        virtual ~Indoor();

        void climate_event(Character*);
        
        virtual std::string class_name() const;

    };

    class Cellar : public Indoor {
    	using Indoor::Indoor;
    	
    	std::string class_name() const {
            return "Cellar";
        }
    	
    	void on_enter(Character * c) {

            if (c->is_player()) {
                Character * trollp = find_character("Trihx");
                if (trollp != nullptr) {
                    c->talk_to(trollp);
                    trollp->fight(c);  
                }
            }
    		
    	}
    };
}

#endif
