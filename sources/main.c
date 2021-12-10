#include <stdlib.h>
#include <stdio.h>

//fichiers include

#include "parametres.h"
#include "position.h"
#include "systeme_dynamique.h"
#include "tests.h"
#include "trajectoire.h"




int main(){
    struct trajectoire *lorenz = nouvelle_trajectoire();
    
    #ifdef TESTS
    
    TEST_RES(lorenz->parametres->position_initiale->x==1);
    TEST_RES(lorenz->parametres->position_initiale->y==2);
    TEST_RES(lorenz->parametres->position_initiale->z==3);
    TEST_RES(lorenz->parametres->position_initiale->dt==1);
    TEST_RES(lorenz->parametres->position_initiale->t_max==50);
    TEST_RES(lorenz->parametres->position_initiale->nbre_points==50);
    
    TEST_RES(lorenz->systeme_dynamique->constantes->t[0]==10);
    TEST_RES(lorenz->systeme_dynamique->constantes->t[1]==28);
    TEST_RES(lorenz->systeme_dynamique->constantes->t[2]==8/3);
    TEST_RES(lorenz->systeme_dynamique->constantes->nbre_constantes==3);
    
    #endif
    
    calcul_trajectoire(lorenz);
    
    return 0;
}
