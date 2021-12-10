// ? include necéssaire pour avoir le type FILE
#include <stdio.h>

struct position {
    float x;
    float y;
    float z;
};

struct position *nouvelle_position(float x, float y, float z);
int fprintf_position(FILE *destination, float temps, struct position *p);
float get_position(struct position *p, char c);