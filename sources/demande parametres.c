struct matrice ∗
nouvelle_matrice ( int n , int m ) {
struct matrice ∗m ;
m = ( struct matrice ∗) malloc ( sizeof ( struct matrice ) ) ;
m−>n = n ;
m−>m = m ;
m−>t = ( float ∗∗) malloc ( n ∗sizeof ( float ∗) ) ;
for ( int i = 0 ; i < n ; i++ ) {
m−>t [ i ] = ( float ∗) malloc ( m ∗sizeof ( float ) ) ;
}
return m ;
}

printf("Quels sont les coefficients de la ligne %d ? \n",i+1);

scanf("%f",&a);

#include <stdio.h>
#include <stdlib.h>

struct parametres * demande_parametres(){
  struct parametres * param;
  param=(struct parametres *) malloc (sizeof (struct parametres));
  scanf("%d
  param->
