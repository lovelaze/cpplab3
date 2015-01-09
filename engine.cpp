#include "engine.h"

#include "indoor.h"
#include "outdoor.h"
#include "player.h"
#include "troll.h"
#include "wizard.h"
#include "backpack.h"
#include <iostream>
#include "cli.h"
#include "priest.h"
#include "weapon.h"
#include "food.h"

using namespace adventure;

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
	return & instance;
}

void Engine::init_game() {
	srand(time(0));

	auto spawnItem = [=](Item * i,Env * env) {
		env->drop(i);
		items_.push_back(i);
	};

	auto spawnChar = [=](Character * c) {
		chars_.push_back(c);
	};


	// ENVS
	Indoor * mainhall = new Indoor("main hall");
	Indoor * kitchen = new Indoor("kitchen");
	Indoor * bedroom = new Indoor("bedroom");
	Cellar * cellar = new Cellar("cellar");
	Outdoor * garden = new Outdoor("garden");      //utomhus
	Outdoor * forest = new Outdoor("forest");      //utomhus
	Balcony * balcony = new Balcony("balcony");    //utombus

	mainhall->addNeighbor(NORTH, kitchen)->addNeighbor(EAST, bedroom)->addNeighbor(SOUTH, garden);
	kitchen->addNeighbor(SOUTH, mainhall)->addNeighbor(NORTH, cellar);
	bedroom->addNeighbor(WEST, mainhall)->addNeighbor(EAST, balcony);
	cellar->addNeighbor(SOUTH, kitchen)->addNeighbor(EAST, forest);
	garden->addNeighbor(NORTH, mainhall)->addNeighbor(SOUTH_WEST, forest);
	forest->addNeighbor(NORTH_EAST, garden)->addNeighbor(WEST, cellar);
	balcony->addNeighbor(NORTH_WEST, bedroom);

	// CHARS
	player = new Player("Adrian the almighty god of godness", mainhall);
	chars_.push_back(player);

    // ITEMS
    spawnItem(new Backpack("rugsack", 10, 100, 100, 500), mainhall);
    spawnItem(new Item("poop", 20, 5), garden);
    spawnItem(new Item("poop", 20, 5), garden);
    spawnItem(new Item("megastone", 1000, 1000), garden);
    spawnItem(new Weapon("excalibur", 25, 1, 15), garden);
    spawnItem(new Food("chicken", 2, 1, 20), kitchen);
    spawnItem(new Food("apple", 2, 1, 15), balcony);

    spawnItem(new Food("sapphire", 2, 1, 15), mainhall);

    spawnChar(new Troll("Guupa", kitchen));
    spawnChar(new Troll("Trihx", cellar));
    spawnChar(new Troll("Ghrar", balcony));
    spawnChar(new Priest("Velen", garden));
    spawnChar(new Wizard("Galotrix", forest));

	// push
	envs_.push_back(mainhall);
	envs_.push_back(kitchen);
	envs_.push_back(bedroom);
	envs_.push_back(cellar);
	envs_.push_back(garden);
	envs_.push_back(forest);
	envs_.push_back(balcony);

	
}

void Engine::run() {
    //skriv story här
	printIntro();

	while (player->alive() && !player->has_sapphire()) {
		//printar allt som AIs gör
		//std::cout << "Activity on the map: " << std::endl;

		update_chars();

	}
	
    if(player->alive() && player->has_sapphire()){
        std::cout << "Power runs through him like a redbull on the afternoon. Mahama!" << std::endl;
        std::cout << "YOU WIN!" << std::endl;
    } else {
        std::cout << "YOU ARE DEAD. GAME OVER!" << std::endl;
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

void Engine::update_chars() {
	for (Character * c : chars_) {
		if (c->alive()) {
			c->action();
			if (c->type() == "player") {
				std::cout <<  std::endl;
			}
		}
	}
}

void Engine::printIntro() const{
    std::cout << "Welcome to Mad Wizard 2000!" << std::endl;
	std::cout << "You have been placed in a secluded area and need to find the magic sapphire to be able to teleport home safely. The sapphire is held by an evil wizard name Galotrix, keep yourself healthy and defeat him with weapons or with your fists of thunder!"<<std::endl;
	std::cout << "You can interact and move around using 'go DIR', 'take ITEM', 'drop ITEM', 'map', 'fight AI', 'talk AI', 'backpack', 'items', 'chars', 'stats', and 'eat ITEM' commands" << std::endl;
	std::cout << "Use the help command to find out what you can do with your character if you forget, GOOD LUCK!." <<std::endl;
}