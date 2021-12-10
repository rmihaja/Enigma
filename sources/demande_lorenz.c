#include <stdlib.h>
#include <stdio.h>
#include "parametres.h"
#include "systeme_dynamique.h"

struct systeme_dynamique *demande_lorenz() {
    struct systeme_dynamique *systeme = (struct systeme_dynamique *)malloc(sizeof(struct systeme_dynamique));
    systeme->constantes = (struct constantes *) malloc(sizeof(struct constantes));
    systeme->constantes->t= malloc(3*sizeof(float));

    printf("\nVeuillez entrer la valeur de σ : ");
    scanf("%f", &systeme->constantes->t[0]);
    printf("\nVeuillez entrer la valeur de ρ : ");
    scanf("%f", &systeme->constantes->t[1]);
    printf("\nVeuillez entrer la valeur de β : ");
    scanf("%f", &systeme->constantes->t[2]);
    systeme->constantes->nombre_constantes=3;

    systeme->equation = &lorenz_transform;

    return systeme;
}

#ifdef TESTS

#include "tests.h"

int main() {
    struct systeme_dynamique *systeme = (struct systeme_dynamique *)malloc(sizeof(struct systeme_dynamique));
    systeme->constantes = (struct constantes *) malloc(sizeof(struct constantes));
    systeme->constantes->t= malloc(3*sizeof(float));
    systeme=demande_lorenz();
    
    TEST_RES(systeme->constantes->t[0]==10);
    TEST_RES(systeme->constantes->t[1]==28);
    TEST_RES(systeme->constantes->t[2]==8/3);
    TEST_RES(systeme->constantes->nbre_constantes==3);
    return 0;
}

#endif
