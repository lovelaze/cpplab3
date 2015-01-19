#ifndef CLI_H
#define CLI_H

#include <string>
#include <vector>
#include <map>
#include "character.h"

namespace adventure {

	class Cli {

	public:


		Cli();
		~Cli();

		typedef void(Character::*any_func)(int);

	    std::string get_input();

	    void parse_input(std::string, Character *);

	    bool valid_command(std::string);

	    bool valid_direction(std::string, std::string);

	    void battle(Character *, Character *);


	private:
		void init();
		std::map <std::string, void(*)> inner_map;



	};


}


#endif