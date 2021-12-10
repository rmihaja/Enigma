#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include "position.h"
#include "parametres.h"
#include "entree.h"
#include "liste.h"

float demande_vitesse(struct position *p, struct constantes *cte, char *composante) {
    char *lettres_positions = "xyz";
    char *lettres_operations = "+-*/";
    
    // ? on alloue la mémoire pour mettre les caractères autorisés ensemble
    // 8 = 3 variables positions + 4 opérations + fin char* '\0'
    char *caracteres_autorisees = (char *) malloc((cte->nbre_constantes + 8) * sizeof(char));
    strcpy(caracteres_autorisees, cte->lettres_constantes);
    strcat(caracteres_autorisees, lettres_positions);
    strcat(caracteres_autorisees, lettres_operations);

    char *entree_utilisateur;
    while (1)
    {
        printf("\nVeuillez entrer les paramètres de la mise à jour de la vitesse %s : ", composante);
        scanf("%ms", &entree_utilisateur);
        printf("parametre entrée: %s\n", entree_utilisateur);
        if (is_entree_valide(entree_utilisateur, caracteres_autorisees))
        {
            break;
        }
        else {
            free(entree_utilisateur);
            printf("Désolé, vos paramètres sont invalides\n");
        }
    }

    // on crée la pile pour traiter la chaîne d'équation
    struct liste_valeurs *l_val = nouvelle_liste();

    for (int i = 0; i < (int) strlen(entree_utilisateur); i++) {
        char c_entree = entree_utilisateur[i];
        if (isspace(entree_utilisateur[i]))
        {
            continue;
        }
        else {
            if (strchr(cte->lettres_constantes, c_entree)) {
                int var_i = strchr(cte->lettres_constantes, c_entree) - cte->lettres_constantes;
#ifdef DEBUG
                printf("Constante %c détectée : %f\n", c_entree, cte->t[var_i]);
#endif
                ajouter_liste(l_val, cte->t[var_i]);
            }
            else if (strchr(lettres_positions, c_entree)) {
#ifdef DEBUG
                printf("Variable %c détectée : %f\n", c_entree, get_position(p, c_entree));
#endif
                ajouter_liste(l_val, get_position(p, c_entree));
            }
            // on assume que l'utilisateur NE METTRA JAMAIS une opération avant les lettres variables
            else if (strchr(lettres_operations, c_entree)) {
                float resultat_operation = evaluer_operation(l_val->premier->val, l_val->premier->suivant->val, c_entree);
#ifdef DEBUG
                printf("Opération (%f %c %f) détectée. Résultat : %f\n", l_val->premier->val, c_entree, l_val->premier->suivant->val, resultat_operation);
#endif
                supprimer_liste(l_val);
                l_val->premier->val = resultat_operation;
            }
        }
    }
    free(entree_utilisateur);
    return l_val->premier->val;
}

#ifdef TESTS
#include "tests.h"

int main() {
    struct position *p = nouvelle_position(1, 2, 3);
    struct constantes *cte = (struct constantes *) malloc(sizeof(struct constantes));
    cte->nbre_constantes = 3;
    cte->lettres_constantes = "srb";
    cte->t = malloc(3 * sizeof(float));
    cte->t[0] = 10;
    cte->t[1] = 28;
    cte->t[2] = 2.66;
    VAL_FLOAT(demande_vitesse(p, cte, "dx"));
    return 0;
}

#endif