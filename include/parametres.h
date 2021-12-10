struct constantes {
    int nbre_constantes;
    // * l'ordre des lettres est important : il permet d'identifier sa place dans float *t
    char *lettres_constantes;
    float *t;
};


struct parametres {
    struct position *position_initiale;
    float dt;
    float t_max;
    int nbre_points;
};

struct parametres *demande_parametres();
