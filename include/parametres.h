struct constantes {
    float sigma;
    float rho;
    float beta;
};

struct parametres {
    struct position *position_initiale;
    float dt;
    float t_max;
};

struct parametres *demande_parametres();
