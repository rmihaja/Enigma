#include <stdio.h>
#include "parametres.h"
#include "position.h"

struct position *lorenz_transform(struct position *p, struct constantes *cte, float dt) {
    return nouvelle_position(
        p->x + (cte->sigma * (p->y - p->x)) * dt,
        p->y + ((p->x) * (cte->rho - p->z) - p->y) * dt,
        p->z + ((p->x * p->y) - (cte->beta * p->z)) * dt
    );
}

#ifdef TESTS

int main() {
    // tests here
    return 0;
}

#endif