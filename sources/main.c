#include <stdlib.h>
#include <stdio.h>

#include "parametres.h"
#include "position.h"
#include "systeme_dynamique.h"
#include "trajectoire.h"



int main(){
    
    struct trajectoire *lorenz = nouvelle_trajectoire();
    calcul_trajectoire(lorenz);
    
    return 0;
}
