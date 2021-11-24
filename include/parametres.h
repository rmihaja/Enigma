struct position {
    float x;
    float y;
    float z;
};

struct constantes {
    float sigma;
    float rho;
    float beta;
};

struct parametres {
    struct position *position_initiale;
    float dt;
    float t_max;
    struct constantes *cte;
};

struct parametres *demande_parametres();
