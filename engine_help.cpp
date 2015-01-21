#include "engine.h"
#include <iostream>
#include "indoor.h"
#include "outdoor.h"

using namespace std;

namespace adventure {

	std::vector<std::string> & Engine::new_indoor(std::vector<std::string> & v) {	
		std::cout << "indoor" << std::endl;

		Indoor * ip = new Indoor(v[0]);
		Engine::get_instance()->add_env(ip);
		return v;
	}

	std::vector<std::string> & Engine::new_outdoor(std::vector<std::string> & v) {
		std::cout << "outdoor" << std::endl;

		Outdoor * ip = new Outdoor(v[0]);
		Engine::get_instance()->add_env(ip);
		return v;
	}

	std::vector<std::string> & Engine::new_cellar(std::vector<std::string> & v) {
		std::cout << "cellar" << std::endl;

		Cellar * ip = new Cellar(v[0]);
		Engine::get_instance()->add_env(ip);
		return v;
	}

	std::vector<std::string> & Engine::new_balcony(std::vector<std::string> & v) {
		std::cout << "balcony" << std::endl;

		Balcony * ip = new Balcony(v[0]);
		Engine::get_instance()->add_env(ip);
		return v;
	}

	std::vector<std::string> & Engine::new_item(std::vector<std::string> & v) {
		return v;
	}

	std::vector<std::string> & Engine::new_food(std::vector<std::string> & v) {
		return v;
	}

	std::vector<std::string> & Engine::new_weapon(std::vector<std::string> & v) {
		return v;
	}

	std::vector<std::string> & Engine::new_troll(std::vector<std::string> & v) {
		return v;
	}

	std::vector<std::string> & Engine::new_wizard(std::vector<std::string> & v) {
		return v;
	}

	std::vector<std::string> & Engine::new_priest(std::vector<std::string> & v) {
		return v;
	}

}