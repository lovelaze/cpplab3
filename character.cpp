#include <iostream>
#include "character.h"
#include "env.h"
#include <ctime>


using namespace adventure;

Character::Character() {
}

Character::~Character() {
}

Character::Character(std::string name, std::string type, Env *current_room, int health, int damage, bool alive) : name_(name), type_(type), current_room_(current_room), health_(health), damage_(damage), alive_(alive) {
    max_health_ = health_;
    current_room->enter(this);
}

std::string Character::name() const {
    return name_;
}

std::string Character::type() const {
    return type_;
}

void Character::change_room(Env * env) {
    if (current_room_ != nullptr) {
        current_room_->leave(this);
    }

    current_room_ = env;
    current_room_->enter(this);
}

void Character::go(int dir) {
    if (current_room_ == nullptr) {
        std::cout << "nullptr current_room_" << std::endl;
    }

    change_room(current_room_->neighbor(dir));

}

bool Character::has_backpack() const {
    return backpack_ != nullptr;
}

bool Character::pick_up(Item *item) {
    if (!has_backpack()) {

        if (dynamic_cast<const Backpack *>(item) != 0) {
            backpack_ = (Backpack *)item;
            current_room_->pick_up(item);
            return true;
        }
        return false;
    }


    if(backpack_->add(item)) {
        current_room_->pick_up(item);
    }


    return true;
}

bool Character::drop(Item *item) {

    if (item == backpack_) {
        current_room_->drop(backpack_);
        backpack_ = nullptr;
    } else {
        backpack_->remove(item);
    }


}

void Character::print_backpack() const {

    if (!has_backpack()) {
        std::cout << "no backpack" << std::endl;
    } else {
        std::cout << backpack_->name() << ":" << std::endl;
        for (int i = 0; i < backpack_->items_.size(); ++i) {
            std::cout  << backpack_->items_[i]->name() << std::endl;
        }
    }

}


bool Character::alive() {
    return alive_;
}



int Character::go_to_random_neighbor() {

    int temp = current_room_->get_random_valid_direction();
    if(temp >=0){
        go(temp);
    }
    return temp;

}
