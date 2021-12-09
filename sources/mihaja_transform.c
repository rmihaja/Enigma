#include <stdio.h>
#include "parametres.h"
#include "position.h"

struct position *mihaja_transform(struct position *p, struct constantes *cte) {
    return nouvelle_position(
        p->x + cte->sigma * (p->x - p->y),
        p->y + (p->z) * (cte->rho - p->y) - p->x,
        p->z + (p->y) - (cte->beta * p->x * p->z)
    );
}

#ifdef TESTS

int main() {
    // tests here
    return 0;
}

#endif

