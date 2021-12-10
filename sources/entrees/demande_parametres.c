#include <stdio.h>
#include <stdlib.h>
#include "position.h"
#include "parametres.h"

struct parametres *demande_parametres() {
  struct parametres *param;
  param = (struct parametres *) malloc(sizeof(struct parametres));

  param->position_initiale = (struct position *) malloc(sizeof(struct position));
  printf("\nVeuillez entrer la position initial du système:\n");
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
  
  param->nbre_points = (int) (param->t_max / param->dt);
    
  return param;
}

#ifdef TESTS

int main() {
    // tests here
    return 0;
}

#endif
