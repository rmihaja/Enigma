#include <stdlib.h>
#include <stdio.h>
#include "trajectoire.h"

int main()
{
    printf("\n***************************\n");
    printf("* Bienvenue dans Enigma ! *");
    printf("\n***************************\n");

    struct trajectoire *lorenz = nouvelle_trajectoire();
    calcul_trajectoire(lorenz);

    printf("\nCourbe tracée avec succès !\n");
    printf("Ouverture de gnuplot...\n");
    printf("(Veuillez vous assurez que gnuplot est bien installé sur le système)\n");
    FILE *gnuplot_pipe;
    gnuplot_pipe = popen("gnuplot -p","w");
    fprintf(gnuplot_pipe, "set parametric\n");
    fprintf(gnuplot_pipe, "splot 'sortie.dat' u 2:3:4\n");
    return 0;
}
