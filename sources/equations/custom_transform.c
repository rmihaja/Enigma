#include <stdio.h>
#include "parametres.h"
#include "position.h"
#include "vitesse.h"

struct position *custom_transform(struct position *p, struct constantes *cte, float dt) {
    return nouvelle_position(
        p->x + demande_vitesse(p, cte, "dx/dt") * dt,
        p->y + demande_vitesse(p, cte, "dy/dt") * dt,
        p->z + demande_vitesse(p, cte, "dz/dt") * dt
    );
}

#ifdef TESTS

int main() {
    // tests here
    return 0;
}

#endif
