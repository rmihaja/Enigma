#include <stdio.h>
#include "parametres.h"
#include "position.h"

struct position *mihaja_transform(struct position *p, struct constantes *cte) {
    return nouvelle_position(
        p->x + cte->t[0] * (p->x - p->y),
        p->y + (p->z) * (cte->t[1] - p->y) - cte->t[3],
        p->z + (p->y) - (cte->t[2] * p->x * p->z)
    );
}

#ifdef TESTS

int main() {
    // tests here
    return 0;
}

#endif

