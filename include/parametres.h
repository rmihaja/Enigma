struct constantes {
    float sigma;
    float rho;
    float beta;
};

struct parametres {
    struct position *position_initiale;
    float dt;
    float t_max;
    int nbre_points;
};

struct parametres *demande_parametres();
