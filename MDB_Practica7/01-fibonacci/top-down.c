
// includes
#include <stdio.h>
#define MAX_N 100
#include <time.h>


// tabla
int tabla[ MAX_N ];


// fibonacci_top_down
int fibonacci_top_down( int n ) {

    if ( n < 2 ) return n;
    if ( tabla[ n - 1 ] == -1 ) tabla[ n - 1 ] = fibonacci_top_down( n - 1 );
    if ( tabla[ n - 2 ] == -1 ) tabla[ n - 2 ] = fibonacci_top_down( n - 2 );
    tabla[ n ] = tabla[ n - 1 ] + tabla[ n - 2 ];
    return tabla[ n ];

};


// main
int main() {

    clock_t inicio, fin;
    double tiempo;

    inicio = clock();

    for ( int i = 0; i < MAX_N; i++ ) tabla[ i ] = -1;

    printf( "Fibonacci de 9: %d\n", fibonacci_top_down( 9 ) );


    fin = clock();
    tiempo = ((double) (fin - inicio)) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecucion: %.4f", tiempo);

    return 0;

};
