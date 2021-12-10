struct constantes {
    int nbre_constantes;
    float *t;
};


struct parametres {
    struct position *position_initiale;
    float dt;
    float t_max;
    int nbre_points;
};

struct parametres *demande_parametres();
