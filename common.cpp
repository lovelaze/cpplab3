#include "common.h"
#include <iostream>


int adventure::get_rand(int lower, int higher) {
    return rand() %  (higher - lower+1) + lower ;
}

int adventure::direction_to_int(std::string in1, std::string in2) {
    
    if (in1=="north" && in2 =="") {
        return 0;
    } else if (in1=="north" && in2 =="east") {
        return 1;
    } else if (in1=="east" && in2 =="") {
        return 2;
    } else if (in1=="south" && in2== "east" ) {
        return 3;
    } else if (in1=="south" && in2=="" ) {
        return 4;
    } else if (in1 =="south" && in2=="west") {
        return 5;
    } else if (in1 =="west" && in2=="") {
        return 6;
    } else if (in1 =="north" && in2=="west") {
        return 7;
    }
    return -1;
}

std::string adventure::int_to_direction(int x) {

    switch (x) {
        case 0:
            return "north";
        case 1:
            return "north east";
        case 2:
            return "east";
        case 3:
            return "south east";
        case 4:
            return "south";
        case 5:
            return "south west";
        case 6:
            return "west";
        case 7:
            return "north west";

    }
    return "error";

}

bool adventure::chance(int x) {
    int randnr = rand() %  (100 - 1) ;
    return x >= randnr;

}


