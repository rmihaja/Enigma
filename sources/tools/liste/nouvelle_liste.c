#include <stdlib.h>
#include "liste.h"

struct liste_valeurs *nouvelle_liste() {
    struct liste_valeurs *l_valeurs = (struct liste_valeurs *) malloc(sizeof(struct liste_valeurs));
    struct valeur *valeur = (struct valeur *)malloc(sizeof(struct valeur));

    valeur->val = 0;
    valeur->suivant = NULL;
    
    l_valeurs->premier = valeur;
    l_valeurs->nbre_valeurs = 0;

    return l_valeurs;
}

#ifdef TESTS
#include "tests.h"

int main() {
    // tests here
    return 0;
}

#endif