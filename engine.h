#ifndef ENGINE_H
#define ENGINE_H

#include "constants.h"
#include <vector>
#include "env.h"
#include "item.h"
#include "player.h"



namespace adventure {

	

	class Engine {

	public:

		typedef std::vector<std::string> &(Engine::*load_func)(std::vector<std::string> &);
		
		Engine();
		virtual ~Engine();

		static Engine * get_instance();
		std::vector<Env *> & envs();
		std::vector<Character *> & chars();
		std::vector<Item *> & items();

		void add_item(Item *);
		static bool remove_item(Item *);

		void init_game();
		void run();
		void update_chars();
		void printIntro() const;

	private:

		Player * player;

		std::vector<Env *> envs_;
		std::vector<Character *> chars_;
		std::vector<Item *> items_;

		template <class T>
		void clear_vector(std::vector<T *> &);

		void load_file(std::string);

		std::map<std::string, load_func> loads;

		/***** function ptrs ****/
		std::vector<std::string> & new_indoor(std::vector<std::string> &);
		std::vector<std::string> & new_outdoor(std::vector<std::string> &);
		std::vector<std::string> & new_cellar(std::vector<std::string> &);
		std::vector<std::string> & new_balcony(std::vector<std::string> &);
		std::vector<std::string> & new_item(std::vector<std::string> &);
		std::vector<std::string> & new_food(std::vector<std::string> &);
		std::vector<std::string> & new_weapon(std::vector<std::string> &);
		std::vector<std::string> & new_troll(std::vector<std::string> &);
		std::vector<std::string> & new_wizard(std::vector<std::string> &);
		std::vector<std::string> & new_priest(std::vector<std::string> &);

	};
}


#endif