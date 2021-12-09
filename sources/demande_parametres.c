
#include <stdlib.h>
#include "trajectoire.h"
#include "parametres.h"
#include "systeme_dynamique.h"

struct trajectoire *nouvelle_trajectoire() {
    struct trajectoire *trajectoire = (struct trajectoire *) malloc(sizeof(struct trajectoire));
    
    printf("quel systeme dynamique voulez-vous ? Lorentz, Hugo ou Mihaja ? \n");
    printf("Lorenz : \n dx/dt=σ(y − x) \n dy/dt=x(ρ − z) − y \n dz/dt=xy − βz \n tapez 1 \n");
    printf("Hugo : \n dx/dt=σ(y + x) \n dy/dt=ρ(x − z) − z \n dz/dt=x − βz \n tapez 2 \n");
    printf("Mihaja : \n dx/dt=σ(x − y) \n dy/dt=z(ρ − y) − x \n dz/dt=y − βxz \n tapez 3 \n");
    scanf("%d", &choix_systeme);
    trajectoire->parametres = demande_parametres();
    if (choix_systeme=1){
        trajectoire->equation_mouvement = demande_lorenz();
    }
    else{
        if (choix_systeme=2){
            trajectoire->equation_mouvement = demande_Hugo();
        }
        else{
            if (choix_systeme=3){
                trajectoire->equation_mouvement = demande_Mihaja();
            }
        }
    }
    

    return trajectoire;
}

#ifdef TESTS

int main() {
    // tests here
    return 0;
}

#endif
