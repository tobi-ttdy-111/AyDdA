
// includes
#include <stdio.h>
#define MAX_N 100
#include <time.h>

// tabla
int tabla[ MAX_N ];


// fibonacci_bottom_up
int fibonacci_bottom_up( int n ) {

    if ( n < 2 ) return n;
    tabla[ 0 ] = 0;
    tabla[ 1 ] = 1;
    for ( int i = 2; i <= n; i++ ) tabla[ i ] = tabla[ i - 1 ] + tabla[ i - 2 ];
    return tabla[ n ];

};


// main
int main() {

    clock_t inicio, fin;
    double tiempo;

    inicio = clock();

    for ( int i = 0; i < MAX_N; i++ ) tabla[ i ] = -1;
    printf( "Fibonacci de 9: %d\n", fibonacci_bottom_up( 9 ) );

    fin = clock();
    tiempo = ((double) (fin - inicio)) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecucion: %.4f", tiempo);

    return 0;

};
