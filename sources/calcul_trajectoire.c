#include <stdlib.h>
#include <stdio.h>
#include "position.h"
#include "parametres.h"
#include "systeme_dynamique.h"
#include "trajectoire.h"

int calcul_trajectoire(struct trajectoire *trajectoire) {
    FILE *destination = fopen("lorenz.dat", "w+");
    struct position *position_actuelle = trajectoire->parametres->position_initiale;
    struct position *position_dt = (struct position *)malloc(sizeof(struct position));
    for (int i = 0; i < trajectoire->parametres->nbre_points; i++) {
        fprintf_position(destination, i * trajectoire->parametres->dt, position_actuelle);
        position_dt = trajectoire->equation_mouvement->equation(position_actuelle, trajectoire->equation_mouvement->constantes);
        position_actuelle = position_dt;
    }
    return 0;
}

#ifdef TESTS

int main() {
    // tests here
    return 0;
}

#endif