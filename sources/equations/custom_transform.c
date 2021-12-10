#include <stdio.h>
#include "parametres.h"
#include "position.h"
#include "vitesse.h"

struct position *custom_transform(struct position *p, struct constantes *cte, float dt) {
    return nouvelle_position(
        p->x + demande_vitesse(p, cte) * dt,
        p->y + demande_vitesse(p, cte) * dt,
        p->z + demande_vitesse(p, cte) * dt
    );
}

#ifdef TESTS

int main() {
    // tests here
    return 0;
}

#endif
