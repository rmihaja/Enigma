#include <stdlib.h>
#include "liste.h"

// * on supprime le premier élément de la liste
void supprimer_liste(struct liste_valeurs *l_valeurs) {
    if (l_valeurs->premier != NULL) {
        struct valeur *temp = l_valeurs->premier;
        l_valeurs->premier = l_valeurs->premier->suivant;
        l_valeurs->nbre_valeurs--;
        free(temp);
    }
}

#ifdef TESTS
#include "tests.h"

int main() {
    // tests here
    return 0;
}

#endif