#include "engine.h"
#include <iostream>

using namespace std;

namespace adventure {

	std::vector<std::string> & Engine::new_indoor(std::vector<std::string> & v) {	
		std::cout << "indoor" << std::endl;
		return v;
	}

	std::vector<std::string> & Engine::new_outdoor(std::vector<std::string> & v) {
		return v;
	}

	std::vector<std::string> & Engine::new_cellar(std::vector<std::string> & v) {
		return v;
	}

	std::vector<std::string> & Engine::new_balcony(std::vector<std::string> & v) {
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