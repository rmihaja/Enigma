#include <stdio.h>
#include <stdlib.h>
#include "parametres.h"

struct parametres *demande_parametres() {
  struct parametres *param;
  param = (struct parametres *) malloc(sizeof(struct parametres));

  param->position_initiale = (struct position *) malloc(sizeof(struct position));
  printf("Veuillez entrer la position initial du système:\n");
  printf("\nCoordonnée x : ");
  scanf("%f", &param->position_initiale->x);
  printf("\nCoordonnée y : ");
  scanf("%f", &param->position_initiale->y);
  printf("\nCoordonnée z : ");
  scanf("%f", &param->position_initiale->z);
  
  printf("\nVeuillez entrer l'incrément dt du mouvement: ");
  scanf("%f", &param->dt);
  printf("\nVeuillez entrer le temps d'arrêt du système: ");
  scanf("%f", &param->t_max);

  param->cte = (struct constantes *) malloc(sizeof(struct constantes));
  printf("\nVeuillez entrer la valeur de σ : ");
  scanf("%f", &param->cte->sigma);
  printf("\nVeuillez entrer la valeur de ρ : ");
  scanf("%f", &param->cte->rho);
  printf("\nVeuillez entrer la valeur de β : ");
  scanf("%f", &param->cte->beta);
    
  return param;
}

#ifdef TESTS

int main() {
    // tests here
    return 0;
}

#endif
