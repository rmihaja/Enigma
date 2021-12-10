#include "position.h"

float get_position(struct position *p, char c) {
    if (c == 'x') {
        return p->x;
    }
    else if (c == 'y') {
        return p->y;
    }
    else if (c == 'z') {
        return p->z;
    }
    else {
        return 0;
    }
}

#ifdef TESTS
#include "tests.h"

int main() {
    // tests here
    return 0;
}

#endif