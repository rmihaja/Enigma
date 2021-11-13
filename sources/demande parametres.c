#include <stdio.h>
#include <stdlib.h>

struct parametres * demande_parametres(){
  struct parametres * param;
  param=(struct parametres *) malloc (sizeof (struct parametres));
  printf("xi ? \n");
  scanf("%f",&a);
  param->xi=a;
  
  printf("yi ? \n");
  scanf("%f",&b);
  param->yi=b;
  
  printf("zi ? \n");
  scanf("%f",&c);
  param->zi=c;
  
  printf("dt ? \n");
  scanf("%f",&d);
  param->dt=d;
  
  printf("Tmax ? \n");
  scanf("%f",&e);
  param->Tmax=e;
  
  printf("σ ? \n");
  scanf("%f",&f);
  param->σ=f;
  
  printf("ρ ? \n");
  scanf("%f",&g);
  param->ρ=g;
  
  printf("β ? \n");
  scanf("%f",&h);
  param->β=h;
  
  return param;
}
