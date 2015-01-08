#include <iostream>
#include "character.h"
#include "env.h"
#include <ctime>


using namespace adventure;

Character::Character() {
}

Character::~Character() {
}

Character::Character(std::string name, std::string type, Env *current_room, int health, int damage, bool alive) :  current_room_(current_room), name_(name), type_(type), health_(health), damage_(damage), alive_(alive) {
    max_health_ = health_;
    current_room->add_char(this);
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
    if (current_room_->neighbor(dir) == nullptr) {
        std::cout << "can't go there" << std::endl;
        return;
    }

    std::cout << name() << " went from " << current_room_->description() << " to " << current_room_->neighbor(dir)->description() << std::endl;
    change_room(current_room_->neighbor(dir));

}

bool Character::has_backpack() const {
    return backpack_ != nullptr;
}

void Character::pick_up(Item *item) {

    if (!has_backpack()) {

        if (dynamic_cast<const Backpack *>(item) != 0) {

            backpack_ = (Backpack *)item;
            current_room_->pick_up(item);
            item->on_pick_up(this);
            std::cout << name() << " picked up " << item->name() << std::endl;
            return;
        }
        std::cout << "I have no backpack" << std::endl;
        return;
    }

    if(backpack_->add(item)) {
        current_room_->pick_up(item);
        item->on_pick_up(this);
        std::cout << name() << " picked up " << item->name() << std::endl;
    } else {
        std::cout << name() << " can't pick up " << item->name() << std::endl;
    }


}

void Character::drop(Item *item) {

    if (item == backpack_) {
        current_room_->drop(backpack_);
        backpack_ = nullptr;

    } else {
       if (has_backpack() && backpack()->find_item(item->name()) != nullptr) {
            backpack_->remove(item);
            current_room_->drop(item);
            item->on_drop(this);
            std::cout << name() << " dropped " << name() << std::endl;
        } else {
            std::cout << name() << " does not have " << item->name() << std::endl;
        }

    }


}



bool & Character::alive() {
    return alive_;
}



int Character::go_to_random_neighbor() {

    int temp = current_room_->get_random_valid_direction();
    if(temp >=0){
        go(temp);
    }
    return temp;

}


Backpack *Character::backpack() const {
    return backpack_;
}


void Character::check_kill(Character *c) {
    c->alive_ = c->health_ > 0;
    if ( !c->alive()) {
        std::cout << name() << " killed " << c->name() << "." << std::endl;
        c->on_death();
        current_room_->leave(c);
    }



}


void Character::fight(Character * c) {
    std::cout << name() << "doesn't want to fight" << std::endl;
}

void Character::talk_to(Character * c) {
    std::cout << name() << "doesn't want to talk" << std::endl;
}

int Character::add_health(int x) {
    if (health() >= max_health()) {
        return 0;
    } else if (health() + x > max_health()) {
        int i = max_health() - health();
        health() = max_health();    
        return i;
    }

    health() += x;
    return x;

}

void Character::on_death() {

}