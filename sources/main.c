#include "trajectoire.h"

int main()
{
    struct trajectoire *lorenz = nouvelle_trajectoire();
    calcul_trajectoire(lorenz);
    return 0;
}
