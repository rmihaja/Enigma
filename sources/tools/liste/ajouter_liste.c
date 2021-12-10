#include <stdlib.h>
#include "liste.h"

// * on ajoute au début de la liste
int ajouter_liste(struct liste_valeurs *l_valeurs, float val) {
    if (l_valeurs->nbre_valeurs == 0) {
        l_valeurs->premier->val = val;
    } 
    else {
        struct valeur *nouvelle_valeur = (struct valeur *) malloc(sizeof(struct valeur));
        nouvelle_valeur->val = val;
        nouvelle_valeur->suivant = l_valeurs->premier;
        l_valeurs->premier = nouvelle_valeur;
    }
    l_valeurs->nbre_valeurs++;
    return 0;
}

#ifdef TESTS
#include "tests.h"

int main() {
    // tests here
    return 0;
}

#endif