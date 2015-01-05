#include "common.h"


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
}


