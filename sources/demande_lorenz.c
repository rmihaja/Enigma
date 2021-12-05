#include <stdlib.h>
#include <stdio.h>
#include "parametres.h"
#include "systeme_dynamique.h"

struct systeme_dynamique *demande_lorenz() {
    struct systeme_dynamique *systeme = (struct systeme_dynamique *)malloc(sizeof(struct systeme_dynamique));
    systeme->constantes = (struct constantes *) malloc(sizeof(struct constantes));

    printf("\nVeuillez entrer la valeur de σ : ");
    scanf("%f", &systeme->constantes->sigma);
    printf("\nVeuillez entrer la valeur de ρ : ");
    scanf("%f", &systeme->constantes->rho);
    printf("\nVeuillez entrer la valeur de β : ");
    scanf("%f", &systeme->constantes->beta);

    systeme->equation = &lorenz_transform;

    return systeme;
}

#ifdef TESTS

int main() {
    // tests here
    return 0;
}

#endif