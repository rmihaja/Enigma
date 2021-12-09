#include <stdlib.h>
#include "trajectoire.h"
#include "parametres.h"
#include "systeme_dynamique.h"

struct trajectoire *nouvelle_trajectoire() {
    struct trajectoire *trajectoire = (struct trajectoire *) malloc(sizeof(struct trajectoire));

    trajectoire->parametres = demande_parametres();
    trajectoire->equation_mouvement = demande_lorenz();
    trajectoire->parametres->nbre_points = (int) (trajectoire->parametres->t_max / trajectoire->parametres->dt);

    return trajectoire;
}

#ifdef TESTS

int main() {
    // tests here
    return 0;
}

#endif