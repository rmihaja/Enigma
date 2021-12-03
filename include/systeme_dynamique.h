typedef struct position* (*deplacement)(struct position *p, struct constantes *cte);

struct systeme_dynamique {
    struct constantes *constantes;
    deplacement equation;
};

// * génération (création) des systèmes dynamiques

struct systeme_dynamique *demande_lorenz();

// * équations de la trajectoire des systèmes dynamiques du projet
// les équations sont à normaliser avec une fin/début unique
// TODO: définir si normalisation "_transform" OK

struct position *lorenz_transform(struct position *p, struct constantes *cte);