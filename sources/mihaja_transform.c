#include <stdio.h>
#include "parametres.h"
#include "position.h"

struct position *mihaja_transform(struct position *p, struct constantes *cte) {
    return nouvelle_position(
        p->x + cte->t[0] * (p->x - p->y),
        p->y + (p->z) * (cte->t[1] - p->y) - cte->t[3],
        p->z + (p->y) - (cte->t[2] * p->x * p->z)
    );
}

#ifdef TESTS

int main() {
    
    struct constantes *constantes = (struct constantes *) malloc(sizeof(struct constantes));
    constantes->t= malloc(4*sizeof(float));
    struct position *position = (struct position *) malloc(sizeof(struct position));
    struct position *new_position=(struct position *) malloc(sizeof(struct position));
    position->x=1;
    position->y=2;
    position->z=3;
    constantes->t[0]=10;
    constantes->t[1]=28;
    constantes->t[2]=8/3;
    constantes->t[3]=5;
    constantes->nbre_constante=4;
    
    new_position=mihaja_transform(position,constantes);
    
    TEST_RES(new_position->x==-9);
    TEST_RES(new_position->y==75);
    TEST_RES(new_position->z==-3);
    TEST_RES(systeme->constantes->nbre_constantes==4);
    
    return 0;
}

#endif

