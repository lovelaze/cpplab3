#ifndef FOOD_H
#define FOOD_H

#include "item.h"
#include <string>

namespace adventure {

	class Food : public Item {

	public:
		Food();
		Food(std::string name, int weight, int volume, int health_bonus);
		~Food();

		int health_bonus() const;

		void eat(Character *);

        std::string to_string() const;

        virtual std::string class_name() const;

	private:
		int health_bonus_;

	};
}


#endif