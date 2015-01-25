#include "engine.h"
#include <iostream>
#include "indoor.h"
#include "outdoor.h"
#include "common.h"
#include "food.h"
#include "weapon.h"
#include "backpack.h"
#include "troll.h"
#include "wizard.h"
#include "priest.h"




using namespace std;

namespace adventure {

	void Engine::new_indoor(std::vector<std::string> & v) {	
		std::cout << "indoor" << std::endl;
		Engine::get_instance()->add_env(new Indoor(v[1]));
	}

	void Engine::new_outdoor(std::vector<std::string> & v) {
		std::cout << "outdoor" << std::endl;
		Engine::get_instance()->add_env(new Outdoor(v[1]));
	}

	void Engine::new_cellar(std::vector<std::string> & v) {
		std::cout << "cellar" << std::endl;
		Engine::get_instance()->add_env(new Cellar(v[1]));
	}

	void Engine::new_balcony(std::vector<std::string> & v) {
		std::cout << "balcony" << std::endl;
		Engine::get_instance()->add_env(new Balcony(v[1]));
	}

	void Engine::new_item(std::vector<std::string> & v) {
		std::cout << "item" << std::endl;

		Item * item = new Item(v[1],std::stoi(v[2]),std::stoi(v[3]));
		
		if (v[4] == "PLAYER") {
			Player * p = find_player();
			p->current_room()->drop(item);
			p->pick_up(item);
		} else {
			Engine::get_instance()->find_env(v[4])->drop(item);
		}
		Engine::get_instance()->add_item(item);
		
	}

	void Engine::new_food(std::vector<std::string> & v) {
		std::cout << "food" << std::endl;

		Food * food = new Food(v[1],std::stoi(v[2]),std::stoi(v[3]), std::stoi(v[4]));
		
		if (v[5] == "PLAYER") {
			Player * p = find_player();
			p->current_room()->drop(food);
			p->pick_up(food);
		} else {
			Engine::get_instance()->find_env(v[5])->drop(food);
		}
		Engine::get_instance()->add_item(food);

	}

	void Engine::new_weapon(std::vector<std::string> & v) {
		std::cout << "weapon" << std::endl;

		Weapon * weapon = new Weapon(v[1],std::stoi(v[2]),std::stoi(v[3]), std::stoi(v[4]));
		
		if (v[5] == "PLAYER") {
			Player * p = find_player();
			p->current_room()->drop(weapon);
			p->pick_up(weapon);
		} else {
			Engine::get_instance()->find_env(v[5])->drop(weapon);
		}
		Engine::get_instance()->add_item(weapon);
	}

	void Engine::new_backpack(std::vector<std::string> & v) {
		std::cout << "backpack" << std::endl;

		Backpack * backpack = new Backpack(v[1],std::stoi(v[2]),std::stoi(v[3]), std::stoi(v[4]),std::stoi(v[5]));

		if (v[6] == "PLAYER") {
			Player * p = find_player();
			p->current_room()->drop(backpack);
			p->pick_up(backpack);

		} else {
			Engine::get_instance()->find_env(v[6])->drop(backpack);
		}
		
		Engine::get_instance()->add_item(backpack);
		
	}

	void Engine::new_troll(std::vector<std::string> & v) {
		std::cout << "troll" << std::endl;

		Env * env = Engine::get_instance()->find_env(v[2]);
		Troll * troll = new Troll(v[1], env);
		troll->health() = std::stoi(v[3]);
		Engine::get_instance()->add_char(troll);
	}

	void Engine::new_wizard(std::vector<std::string> & v) {
		std::cout << "wizard" << std::endl;

		Env * env = Engine::get_instance()->find_env(v[2]);
		Wizard * wizard = new Wizard(v[1], env);
		wizard->health() = std::stoi(v[3]);
		Engine::get_instance()->add_char(wizard);
	}

	void Engine::new_priest(std::vector<std::string> & v) {
	
		std::cout << "priest" << std::endl;

		Env * env = Engine::get_instance()->find_env(v[2]);
		Priest * priest = new Priest(v[1], env);
		priest->health() = std::stoi(v[3]);
		Engine::get_instance()->add_char(priest);
	}


	void Engine::connect_envs(std::vector<std::string> & v) {
		std::cout << "connect" << std::endl;

        Env * e = Engine::get_instance()->find_env(v[1]);
        v.erase(v.begin(), v.begin()+2);

        std::vector<std::string> temp;
        for (string s : v) {
        	split(s, ',',temp);
        	e->addNeighbor(direction_to_int(temp[0]), Engine::get_instance()->find_env(temp[1]));
        	temp.clear();
        }

	}

	void Engine::new_player(std::vector<std::string> & v) {
		std::cout << "player" << std::endl;

		Env * env = Engine::get_instance()->find_env(v[2]);
		Player * player = new Player(v[1], env);
		player->health() = std::stoi(v[3]);
		Engine::get_instance()->add_char(player);

	}
}