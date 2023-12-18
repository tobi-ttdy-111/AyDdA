
// includes
#include <stdio.h>


// coef_bino
int coef_bino( int n, int k ) {

    int tabla[ n + 1 ][ k + 1 ];
    int i, j;

    for( i = 0; i <= n; i++ ) tabla[ i ][ 0 ] = 1;
    for( i = 1; i <= n; i++ ) tabla[ i ][ 1 ] = i;
    for( i = 2; i <= k; i++ ) tabla[ i ][ i ] = 1;
    for( i = 3; i <= n; i++ )
        for(j = 2; j <= i-1; j++)
            if(j <= k) tabla[ i ][ j ] = tabla[ i - 1 ][ j - 1] + tabla[ i - 1 ][ j ];
    return tabla[ n ][ k ];

};


// binomialCoeff
int binomialCoeff( int n, int k ) {

    if ( k == 0 || k == n ) return 1;
    return binomialCoeff( n - 1, k - 1 ) + binomialCoeff( n - 1, k );

};


// pascal
void pascal( int n ) {

    int pasc[ n ];
    int x, i, j;
    x = 0;

    for ( i = 1; i <= n+1; i++ ) {
        for ( j = x; j >= 0; j-- ) {
            if ( j == x || j == 0 ) { pasc[ j ] = 1; }
            else { pasc[ j ] = pasc[ j ] + pasc[ j - 1 ]; }
        };
        x++;
        for ( j = 1; j <= n-i; j++ ) printf("   ");
        for ( j = 0; j < x; j++ ) { printf("%3d   ", pasc[j]); };
        printf("\n");
    };

};


// main
int main() {

    int n, k;
    printf( "Dame el valor de n: " );
    scanf( "%d", &n );
    printf( "Dame el valor de k: " );
    scanf( "%d", &k );

    printf( "El valor de C(%d, %d) es %d \n", n, k, coef_bino( n, k ) );
    pascal( n );

    return 0;

};
