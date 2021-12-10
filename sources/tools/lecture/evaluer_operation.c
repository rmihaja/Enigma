#include <stdio.h>

float evaluer_operation(float a, float b, char operation) {
    // printf("evalmarche\n");
    if (operation == '+')
    {
        return a + b;
    }
    else if (operation == '-') {
        // printf("bouuh\n");
        // printf("%f", a - b);
        float resultat = a - b;
        return resultat;
    }
    else if (operation == '*') {
        return a * b;
    }
    else if (operation == '/') {
        return a / b;
    }
    else {
        return 0;
    }
}

#ifdef TESTS

#include "tests.h"
#include <stdlib.h>

int main() {
    float a, b;
    float *resultat = malloc(sizeof(float));
    char operation;
    printf("Veuillez entrer a, b et l'operation dans cette ordre :\n");
    printf("a operation b\n");
    scanf("%f %c %f", &a, &operation, &b);
    VAL_FLOAT(evaluer_operation(a, b, operation));
    // test(evaluer_operation(a, b, operation, resultat) == 0);
    VAL_FLOAT(*resultat);

    a = 2;
    b = 1;
    VAL_FLOAT(evaluer_operation(a, b, operation));

    return 0;
}

#endif