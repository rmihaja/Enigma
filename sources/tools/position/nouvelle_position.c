#include <stdlib.h>
#include "position.h"

struct position *nouvelle_position(float x, float y, float z) {
    struct position *position = (struct position *) malloc(sizeof(struct position));
    position->x = x;
    position->y = y;
    position->z = z;
    return position;
}

#ifdef TESTS

int main() {
    // tests here
    return 0;
}

#endif