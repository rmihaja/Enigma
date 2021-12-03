struct trajectoire {
    struct parametres *parametres;
    struct systeme_dynamique *equation_mouvement;
    struct position **coordonnees;
};

struct trajectoire *nouvelle_trajectoire();