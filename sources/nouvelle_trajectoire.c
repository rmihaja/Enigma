#include <stdlib.h>
#include "parametres.h"
#include "trajectoire.h"

struct trajectoire *nouvelle_trajectoire() {
    struct trajectoire *trajectoire = (struct trajectoire *) malloc(sizeof(struct trajectoire));

    trajectoire->parametres = demande_parametres();

    int nbre_points = (int) (trajectoire->parametres->t_max / trajectoire->parametres->dt);

    trajectoire->coordonnees = (struct position **) malloc(nbre_points * sizeof(struct position *));

    return trajectoire;
}

#ifdef TESTS

int main() {
    // tests here
    return 0;
}

#endif