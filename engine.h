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

		typedef void(Engine::*load_func)(std::vector<std::string> &);
		
		Engine();
		virtual ~Engine();

		static Engine * get_instance();
		std::vector<Env *> & envs();
		std::vector<Character *> & chars();
		std::vector<Item *> & items();

		void add_item(Item *);
		void add_char(Character *);
		void add_env(Env *);

		bool remove_item(Item *);
		bool remove_char(Character *);
		bool remove_env(Env *);

		Env * find_env(std::string);
		Player * find_player();

		void init_game();
		void run();
		void update_chars();
		void printIntro() const;

		void load_file(std::string);
		void save_file(std::string);

	private:

		Player * player;

		std::vector<Env *> envs_;
		std::vector<Character *> chars_;
		std::vector<Item *> items_;

		template <class T>
		void clear_vector(std::vector<T *> &);
		void reset();

		std::map<std::string, load_func> loads;

		/***** function ptrs ****/
		void new_indoor(std::vector<std::string> &);
		void new_outdoor(std::vector<std::string> &);
		void new_cellar(std::vector<std::string> &);
		void new_balcony(std::vector<std::string> &);
		void new_item(std::vector<std::string> &);
		void new_food(std::vector<std::string> &);
		void new_weapon(std::vector<std::string> &);
		void new_backpack(std::vector<std::string> &);
		void new_troll(std::vector<std::string> &);
		void new_wizard(std::vector<std::string> &);
		void new_priest(std::vector<std::string> &);
		void new_player(std::vector<std::string> &);
		void connect_envs(std::vector<std::string> &);
	};
}


#endif