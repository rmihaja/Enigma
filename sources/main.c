#include <stdlib.h>
#include <stdio.h>

#include "fraction.h"

//fichiers include

#include "parametres.h"
#include "position.h"
#include "systeme_dynamique.h"
#include "tests.h"
#include "trajectoire.h"

//fichier sources/tools

#include "fprintf_position.c"
#include "nouvelle_position.c"

//fichier sources

#include "calcul_trajectoire.c"
#include "demande_hugo.c"
#include "demande_lorenz.c"
#include "demande_mihaja.c"
#include "demande_parametres.c"
#include "hugo_transform.c"
#include "lorenz_transform.c"
#include "mihaja_transform.c"
#include "nouvelle_trajectoire.c"


#ifdef TESTS

int main(){
    struct trajectoire *lorenz = nouvelle_trajectoire();
    TEST_RES(lorenz->parametres->position_initiale->x==1);
    TEST_RES(lorenz->parametres->position_initiale->y==2);
    TEST_RES(lorenz->parametres->position_initiale->z==3);
    TEST_RES(lorenz->parametres->position_initiale->dt==1);
    TEST_RES(lorenz->parametres->position_initiale->t_max==50);
    TEST_RES(lorenz->parametres->position_initiale->nbre_points==50);
    TEST_RES(lorenz->systeme_dynamique->constantes->sigm
    TEST_RES(lorenz->parametres->position_initiale->==50);
    TEST_RES(lorenz->parametres->position_initiale->nbre_points==50);
    
    //calcul_trajectoire(lorenz);
    
    
    
    
    //demande_hugo
    dh=demande_hugo();
    TEST_RES(dh
    
    //TEST_RES(denominateur(f)==2);
    //TEST_RES (f−>q == 3);
    
    
    return 0;
}

#endif


/*
int main(){
    struct fraction_s * f;
    f=nouvelle_fraction(1,2);
    VAL_INT(numerateur(f));
    TEST_RES(denominateur(f)==2);
    return 0;
}
#endif
*/

//struct fraction * f;
//f=nouvelle_fraction(2,3);
//VAL_INT(f->p);
//TEST_RES (f−>p == 2) ;
//VAL_INT (f−>q) ;
//TEST_RES (f−>q == 3) ;
//f = nouvelle_fraction (2 ,−3) ;
//TEST_RES(f−>p ==−2) ;
//TEST_RES(f−>q == 3) ;
//f = nouvelle_fraction (2,0) ;
//TEST_RES(f−>p == 1) ;
//TEST_RES(f−>q == 0) ;
//f = nouvelle_fraction (−3,0) ;
//TEST_RES(f−>p ==−1) ;
//TEST_RES(f−>q == 0) ;
//f = nouvelle_fraction (0,−4) ;
//TEST_RES(f−>p == 0) ;
//TEST_RES(f−>q == 1) ;
