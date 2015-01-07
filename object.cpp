#include "object.h"

using namespace adventure;

Object::Object(std::string type, std::string name) : type_(type), name_(name){

}

Object::~Object() {

}

std::string Object::type() const {
    return type_;
}

std::string Object::name() const {
    return name_;
}