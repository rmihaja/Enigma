#include <stdio.h>
#include "parametres.h"
#include "position.h"

struct position *lorenz_transform(struct position *p, struct constantes *cte) {
    return nouvelle_position(
        p->x + cte->t[0] * (p->y - p->x),
        p->y + (p->x) * (cte->t[1] - p->z) - p->y,
        p->z + (p->x * p->y) - (cte->t[2] * p->z)
    );
}

#ifdef TESTS

int main() {
    // tests here
    return 0;
}

#endif
