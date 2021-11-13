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


struct parametres *
