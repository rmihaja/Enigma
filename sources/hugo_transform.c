#include <stdio.h>
#include "parametres.h"
#include "position.h"

struct position *hugo_transform(struct position *p, struct constantes *cte) {
    return nouvelle_position(
        p->x + cte->sigma * (p->y + p->x),
        p->y + (cte->rho) * (p->x - p->z) - p->z,
        p->z + (p->x) - (cte->beta * p->z)
    );
}

#ifdef TESTS

int main() {
    // tests here
    return 0;
}

#endif
