#include <stdio.h>
#include <stdlib.h>
#include "structure parametres.c"

struct parametres * demande_parametres(){
  struct parametres * param;
  param=(struct parametres *) malloc (sizeof (struct parametres));
  printf("xi ? \n");
  float a;
  scanf("%f",&a);
  param->xi=a;
  
  printf("yi ? \n");
  float b;
  scanf("%f",&b);
  param->yi=b;
  
  printf("zi ? \n");
  float c;
  scanf("%f",&c);
  param->zi=c;
  
  printf("dt ? \n");
  float d;
  scanf("%f",&d);
  param->dt=d;
  
  printf("Tmax ? \n");
  float e;
  scanf("%f",&e);
  param->Tmax=e;
  
  printf("sigma ? \n");
  float f;
  scanf("%f",&f);
  param->sigma=f;
  
  printf("Ro ? \n");
  float g;
  scanf("%f",&g);
  param->Ro=g;
  
  printf("Beta ? \n");
  float h;
  scanf("%f",&h);
  param->Beta=h;
  
  return param;
};
