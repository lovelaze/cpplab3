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

		Engine();
		~Engine();

		static Engine * get_instance();


		std::vector<Env *> & envs();
		std::vector<Character *> & chars();
		std::vector<Item *> & items();

		void init_game();

		void run();

		void update_chars();


	private:

		Player * player;

		std::vector<Env *> envs_;
		std::vector<Character *> chars_;
		std::vector<Item *> items_;

		template <class T>
		void clear_vector(std::vector<T *> &);
	};
}


#endif