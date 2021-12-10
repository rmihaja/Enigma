#include <stdlib.h>
#include "position.h"


struct position *nouvelle_position(float x, float y, float z) {
    struct position *position = (struct position *) malloc(sizeof(struct position));
    position->x = x;
    position->y = y;
    position->z = z;
    return position;
};

#ifdef TESTS
#include "tests.h"

int main() {
    struct position *position = (struct position *) malloc(sizeof(struct position));
    position=nouvelle_position(1.0,2.0,3.0);
    TEST_RES(position->x==1);
    TEST_RES(position->y==2);
    TEST_RES(position->x==3);
    
    return 0;
};

#endif
