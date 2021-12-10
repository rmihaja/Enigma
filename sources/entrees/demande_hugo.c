#include <stdlib.h>
#include <stdio.h>
#include "parametres.h"
#include "systeme_dynamique.h"

struct systeme_dynamique *demande_hugo() {
    struct systeme_dynamique *systeme = (struct systeme_dynamique *)malloc(sizeof(struct systeme_dynamique));
    systeme->constantes = (struct constantes *) malloc(sizeof(struct constantes));
    systeme->constantes->t=malloc(2*sizeof(float));

    printf("\nVeuillez entrer la valeur de σ : ");
    scanf("%f", &systeme->constantes->t[0]);
    printf("\nVeuillez entrer la valeur de ρ : ");
    scanf("%f", &systeme->constantes->t[1]);
    systeme->constantes->nbre_constantes=2;

    systeme->constantes->lettres_constantes = "sr";
    systeme->equation = &hugo_transform;

    return systeme;
}

#ifdef TESTS

int main() {
    // tests here
    return 0;
}

#endif
