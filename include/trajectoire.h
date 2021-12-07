struct trajectoire {
    struct parametres *parametres;
    struct systeme_dynamique *equation_mouvement;
};

struct trajectoire *nouvelle_trajectoire();
int calcul_trajectoire(struct trajectoire *trajectoire);