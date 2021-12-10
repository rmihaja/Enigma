#include <stdlib.h>
#include "trajectoire.h"
#include "parametres.h"
#include "systeme_dynamique.h"

struct trajectoire *nouvelle_trajectoire() {
    struct trajectoire *trajectoire = (struct trajectoire *) malloc(sizeof(struct trajectoire));
    
    int choix_systeme;
    
    printf("quel systeme dynamique voulez-vous ? Lorentz, Hugo ou Mihaja ? \n");
    printf("Lorenz : \n dx/dt=σ(y − x) \n dy/dt=x(ρ − z) − y \n dz/dt=xy − βz \n tapez 1 \n");
    printf("hugo : \n dx/dt=σ(y + x) \n dy/dt=ρ(x − z) − z \n dz/dt=x − z \n tapez 2 \n");
    printf("mihaja : \n dx/dt=σ(x − y) \n dy/dt=z(ρ − y) − Ɛ \n dz/dt=y − βxz \n tapez 3 \n");
    scanf("%d", &choix_systeme);
    trajectoire->parametres = demande_parametres();
    if (choix_systeme==1){
        trajectoire->equation_mouvement = demande_lorenz();
    }
    else{
        if (choix_systeme==2){
            trajectoire->equation_mouvement = demande_hugo();
        }
        else{
            if (choix_systeme==3){
                trajectoire->equation_mouvement = demande_mihaja();
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
