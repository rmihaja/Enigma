#include <stdlib.h>
#include <stdio.h>
#include "trajectoire.h"
#include "parametres.h"
#include "systeme_dynamique.h"

struct trajectoire *nouvelle_trajectoire() {
    struct trajectoire *trajectoire = (struct trajectoire *) malloc(sizeof(struct trajectoire));

    int choix_systeme;
    int choix_vitesse;

    printf("\n(1) Prédéfini\n");
    printf("(2) Manuel\n");
    printf("Comment souhaiteriez-vous parametrez la mise à jour de la vitesse (1 ou 2) ? ");
    scanf("%d", &choix_vitesse);
    
    if (choix_vitesse == 1) {
        printf("\n(1) Lorenz :\n  dx/dt = σ(y − x)\n  dy/dt = x(ρ − z) − y\n  dz/dt = xy − βz\n");
        printf("(2) Hugo :\n  dx/dt = σ(y + x)\n  dy/dt = ρ(x − z) − z\n  dz/dt = x − z\n");
        printf("(3) Mihaja :\n  dx/dt = σ(x − y)\n  dy/dt = z(ρ − y) − Ɛ\n  dz/dt = y − βxz\n");
    }
    else {
        printf("\n(1) Lorenz\n");
        printf("(2) Hugo\n");
        printf("(3) Mihaja\n");

    }
    printf("Choix du systeme dynamique ? ");
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
    
    if (choix_vitesse == 2) {
        trajectoire->equation_mouvement->equation = &custom_transform;
    }

    return trajectoire;
}

#ifdef TESTS

int main() {
    // tests here
    return 0;
}

#endif
