#include <stdio.h>
#include "position.h"

int fprintf_position(FILE *destination, float temps, struct position *p) {
    fprintf(destination, "%f %f %f %f\n", temps, p->x, p->y, p->z);
    return 0;
}

#ifdef TESTS

int main() {
    // rien à tester car fonction d'écriture dans fichier
    return 0;
}

#endif
