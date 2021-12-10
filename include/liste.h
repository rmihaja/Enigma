struct valeur {
    float val;
    struct valeur *suivant;
};

struct liste_valeurs
{
    int nbre_valeurs;
    struct valeur *premier;
};

struct liste_valeurs *nouvelle_liste();
int ajouter_liste(struct liste_valeurs *l_valeurs, float val);
void supprimer_liste(struct liste_valeurs *l_valeurs);