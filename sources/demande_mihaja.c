#include <stdlib.h>
#include <stdio.h>
#include "parametres.h"
#include "systeme_dynamique.h"

struct systeme_dynamique *demande_mihaja() {
    struct systeme_dynamique *systeme = (struct systeme_dynamique *)malloc(sizeof(struct systeme_dynamique));
    systeme->constantes = (struct constantes *) malloc(sizeof(struct constantes));
    systeme->constantes->t= malloc(4*sizeof(float));

    printf("\nVeuillez entrer la valeur de σ : ");
    scanf("%f", &systeme->constantes->t[0]);
    printf("\nVeuillez entrer la valeur de ρ : ");
    scanf("%f", &systeme->constantes->t[1]);
    printf("\nVeuillez entrer la valeur de β : ");
    scanf("%f", &systeme->constantes->t[2]);
    printf("\nVeuillez entrer la valeur de Ɛ : ");
    scanf("%f", &systeme->constantes->t[3]);
    systeme->constantes->nbre_constantes=4;

    systeme->equation = &mihaja_transform;

    return systeme;
}

#ifdef TESTS

int main() {
    // tests here
    return 0;
}

#endif
