#ifndef WEAPON_H
#define WEAPON_H

#include "item.h"
#include <string>

namespace adventure {

	class Weapon : public Item {

	public:
		Weapon();
		Weapon(std::string name, int weight, int volume, int damage_bonus);
		~Weapon();

		int damage_bonus() const;

		void on_pick_up(Character *);
        void on_drop(Character *);

        std::string to_string();

	private:
		int damage_bonus_;

	};
}


#endif