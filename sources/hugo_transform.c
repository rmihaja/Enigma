#include <stdio.h>
#include "parametres.h"
#include "position.h"

struct position *hugo_transform(struct position *p, struct constantes *cte) {
    return nouvelle_position(
        p->x + cte->t[0] * (p->y + p->x),
        p->y + (cte->t[1]) * (p->x - p->z) - p->z,
        p->z + (p->x) - (p->z)
    );
}

#ifdef TESTS

int main() {
    
    struct constantes *constantes = (struct constantes *) malloc(sizeof(struct constantes));
    constantes->t= malloc(2*sizeof(float));
    struct position *position = (struct position *) malloc(sizeof(struct position));
    struct position *new_position=(struct position *) malloc(sizeof(struct position));
    position->x=1;
    position->y=2;
    position->z=3;
    constantes->t[0]=10;
    constantes->t[1]=28;
    constantes->nbre_constante=2;
    
    new_position=hugo_transform(position,constantes);
    
    TEST_RES(new_position->x==31);
    TEST_RES(new_position->y==-57);
    TEST_RES(new_position->z==1);
    TEST_RES(systeme->constantes->nbre_constantes==2);
    
    return 0;
}

#endif
