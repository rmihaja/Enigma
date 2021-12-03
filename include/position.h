struct position {
    float x;
    float y;
    float z;
};

struct position *nouvelle_position(float x, float y, float z);
int fprintf_position(FILE *destination, float temps, struct position *p);