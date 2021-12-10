#include <string.h>
#include <ctype.h>

// 1 == entrée valide
// 0 == entrée non valide
int is_entree_valide(char *entree, char *caracteres_autorises) {
    int nbre_variables = 0;
    int nbre_operations = 0;

    // ? strlen renvoie la taille d'une chaîne de caractères
    if (entree == NULL) {
        return 0;
    }

    for (int i = 0; i < (int) strlen(entree); i++) {
        if (isspace(entree[i])) {
            continue;
        }
        // ? strchr renvoie l'adresse d'un caractère recherché (argument 2) si elle existe
        if (strchr(caracteres_autorises, entree[i]) == NULL) {
            return 0;
        }

        if (strchr("+-*/", entree[i])) {
            nbre_operations++;
        } 
        else {
            nbre_variables++;
        }
    }

    // on vérifie que nombre de variables - 1 = nombre d'opérations
    // sinon, il y aura trop d'opérations à faire => erreur
    if (nbre_variables - 1 != nbre_operations) {
        return 0;
    }

    return 1;
}

#ifdef TESTS
#include "tests.h"

int main() {
    // tests here
    return 0;
}

#endif