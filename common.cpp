#include "common.h"


int adventure::get_rand(int lower, int higher) {
    return rand() %  (higher - lower+1) + lower ;
}


