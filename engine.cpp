#include "engine.h"

#include "room.h"
#include "player.h"
#include "troll.h"
#include "wizard.h"
#include "backpack.h"
#include <iostream>
#include "cli.h"

using namespace adventure;

Engine::Engine() {

}

Engine::~Engine() {
	clear_vector(envs_);
	clear_vector(chars_);
	clear_vector(items_);
}

template <class T>
void Engine::clear_vector(std::vector<T *> & v) {
	for (T * t : v) {
		delete t;
	}
}

Engine * Engine::get_instance() {
	static Engine instance;
	return &instance;
}

void Engine::init_game() {
	srand(time(0));

	auto spawnItem = [=](Item * i,Env * env) {
		env->drop(i);
		items_.push_back(i);
	};


	// ENVS
	Room * mainhall = new Room("main hall");
	Room * kitchen = new Room("kitchen");
	Room * bedroom = new Room("bedroom");
	Room * cellar = new Room("cellar");
	Room * garden = new Room("garden");      //utomhus
	Room * forest = new Room("forest");      //utomhus
	Room * balcony = new Room("balcony");  //utombus

	mainhall->addNeighbor(NORTH, kitchen)->addNeighbor(EAST, bedroom)->addNeighbor(SOUTH, garden);
	kitchen->addNeighbor(SOUTH, mainhall)->addNeighbor(NORTH, cellar);
	bedroom->addNeighbor(WEST, mainhall)->addNeighbor(EAST, balcony);
	cellar->addNeighbor(SOUTH, kitchen)->addNeighbor(EAST, forest);
	garden->addNeighbor(NORTH_WEST, mainhall)->addNeighbor(SOUTH_WEST, forest);
	forest->addNeighbor(NORTH_EAST, garden)->addNeighbor(WEST, cellar);
	balcony->addNeighbor(NORTH_WEST, bedroom);

	// CHARS
	player = new Player("Adrian the almighty god of godness", mainhall);
	
	//Wizard * w = new Wizard("Galotrix", forest);
	
	Troll * t = new Troll("Guupa", kitchen);
	Troll * tt = new Troll("Trihx", cellar);
	Troll * ttt = new Troll("Ghrar", balcony);

    // ITEMS
    spawnItem(new Backpack("rugsack", 10, 100, 20, 100, 500), mainhall);
    spawnItem(new Item("poop", 20, 5, 1), garden);
    spawnItem(new Item("megastone", 1000, 1000, 20), garden);

	// push
	envs_.push_back(mainhall);
	envs_.push_back(kitchen);
	envs_.push_back(bedroom);
	envs_.push_back(cellar);
	envs_.push_back(garden);
	envs_.push_back(forest);
	envs_.push_back(balcony);

	chars_.push_back(player);
	chars_.push_back(new Wizard("Galotrix", forest));
	chars_.push_back(t);
	chars_.push_back(tt);
	chars_.push_back(ttt);

	//items_.push_back(rugsack);
}

void Engine::run() {
	std::cout << "start message" << std::endl;

	while (player->alive() && !player->has_crystal_ball()) {
		parse_input(get_input(), player);

	}
	
    if(player->alive() && player->has_crystal_ball()){
        std::cout << player->name() << " grabs the crystalball from the ground... power runs through him like a redbull on the afternoon." << std::endl;
        std::cout << "YOU WIN!" << std::endl;
    } else {
        std::cout << "GAME OVER!" << std::endl;
    }
	
	
}


std::vector<Env *> & Engine::envs() {
	return envs_;
}
std::vector<Character *> & Engine::chars() {
	return chars_;
}
std::vector<Item *> & Engine::items() {
	return items_;
}