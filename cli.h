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
		virtual ~Cli();

		typedef void(Cli::*help_func)(std::vector<std::string> &, Character *);

	    std::string get_input();
	    void parse_input(std::string, Character *);
	    bool valid_command(std::string);
	    bool valid_direction(std::string, std::string);
	    void battle(Character *, Character *);

    private:

		std::map<std::string, help_func> commands;

		const std::vector<std::string> valid_commands = {"go", "take", "drop", "map", "fight", "talk", "backpack", "items", "chars", "stats", "eat", "help"};
		const std::vector<std::string> valid_directions = {"north", "east", "south", "west"};

        // function pointer functions
        void go(std::vector<std::string> &, Character *);
		void take(std::vector<std::string> &, Character *);
		void help(std::vector<std::string> &, Character *);
		void drop(std::vector<std::string> &, Character *);
		void backpack(std::vector<std::string> &, Character *);
		void map(std::vector<std::string> &, Character *);
		void fight(std::vector<std::string> &, Character *);
		void items(std::vector<std::string> &, Character *);
		void characters(std::vector<std::string> &, Character *);
		void stats(std::vector<std::string> &, Character *);
		void eat(std::vector<std::string> &, Character *);
		void talk(std::vector<std::string> &, Character *);
        // YOU CAN NOT SEE WHAT IS ABOVE



	};


}


#endif