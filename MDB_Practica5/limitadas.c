
// includes
#include <stdio.h>
#include <time.h>


// cambioMonedasLimitadas
int cambioMonedasLimitadas( int coins[], int cantidades[], int n, int sum ) {

    int count = 0, i = 0;
    for ( i = n - 1; i >= 0; i-- ) {
        while ( sum >= coins[ i ] && cantidades[ i ] > 0 ) {
            printf( "%d ", coins[ i ] );
            count++;
            sum -= coins[ i ];
            cantidades[ i ]--;
        };
    };
    printf( "\n" );
    return count;

};


// main
int main() {

    clock_t inicio, fin;
    double tiempo;

    inicio = clock();

    int coins[] = { 1, 2, 5, 10 }; // ! PRUEBAS
    int cantidades[] = { 10, 2, 7, 3}; // ! PRUEBAS
    int n = sizeof( coins ) / sizeof( coins[ 0 ] );
    int sum = 78;

    printf( "Cambio: " );
    int count = cambioMonedasLimitadas( coins, cantidades, n, sum );

    printf( "Cantidad mínima de monedas necesarias: %d\n", count );

    fin = clock();
    tiempo = ((double) (fin - inicio)) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecucion: %.4f", tiempo);

    return 0;

};
