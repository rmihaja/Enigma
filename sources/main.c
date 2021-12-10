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
    FILE *gnuplot_pipe = popen("gnuplot -p","w");
    fprintf(gnuplot_pipe, "set parametric\n");
    fprintf(gnuplot_pipe, "splot 'sortie.dat' u 2:3:4\n");
    return 0;
}
