#ifndef OBJECT_H
#define OBJECT_H

#include <string>

namespace adventure {

    class Object {
        std::string type_;
        std::string name_;

    public:
        Object(std::string type, std::string name);
        virtual ~Object();

        std::string type() const;
        std::string name() const;


    };



}

#endif