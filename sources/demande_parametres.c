
#include <stdlib.h>
#include "trajectoire.h"
#include "parametres.h"
#include "systeme_dynamique.h"

struct trajectoire *nouvelle_trajectoire() {
    struct trajectoire *trajectoire = (struct trajectoire *) malloc(sizeof(struct trajectoire));
    
    printf("quel systeme dynamique voulez-vous ? Lorentz, Hugo ou Mihaja ? \n");
    printf("Lorenz : \n dx/dt=σ(y − x) \n dy/dt=x(ρ − z) − y \n dz/dt=xy − βz \n");
    printf("Hugo : \n dx/dt=σ(y + x) \n dy/dt=ρ(x − z) − z \n dz/dt=x − βz \n");
    printf("Mihaja : \n dx/dt=σ(x − y) \n dy/dt=z(ρ − y) − x \n dz/dt=y − βxz \n");
    scanf("%s", &choix_systeme);
    trajectoire->parametres = demande_parametres();
    if (choix_systeme=Lorenz){
        trajectoire->equation_mouvement = demande_lorenz();
    }
    else{
        if (choix_systeme=Hugo){
            trajectoire->equation_mouvement = demande_Hugo();
        }
        else{
            if (choix_systeme=Mihaja){
                trajectoire->equation_mouvement = demande_Mihaja();
            }
        }
    }
    
    trajectoire->parametres->nbre_points = (int) (trajectoire->parametres->t_max / trajectoire->parametres->dt);

    return trajectoire;
}

#ifdef TESTS

int main() {
    // tests here
    return 0;
}

#endif
