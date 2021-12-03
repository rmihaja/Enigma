#include "parametres.h"
#include "position.h";

struct position *lorenz_transform(struct position *p, struct constantes *cte) {
    return nouvelle_position(
        p->x + cte->sigma * (p->y - p->x),
        p->y + (p->x) * (cte->rho - p->z) - p->y,
        p->z + (p->x * p->y) - (cte->beta * p->z)
    );
}

#ifdef TESTS

int main() {
    // tests here
    return 0;
}

#endif