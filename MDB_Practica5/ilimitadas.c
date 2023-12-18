
// includes
#include <stdio.h>
#include <time.h>


// cambioMonedas
void cambioMonedas( int coins[], int n, int sum ) {

    int i;
    printf( "Cambio: " );
    for ( i = n - 1; i >= 0; i-- ) {
        while ( sum >= coins[ i ] ) {
            printf( "%d ", coins[ i ] );
            sum -= coins[ i ];
        };
    };
    printf( "\n" );

};


// main
int main() {

    clock_t inicio, fin;
    double tiempo;

    inicio = clock();

    int coins[] = { 1, 2, 5, 10 }; // ! PRUEBAS
    int n = sizeof( coins ) / sizeof( coins[ 0 ] );
    int sum = 90;
    cambioMonedas( coins, n, sum );


    fin = clock();
    tiempo = ((double) (fin - inicio)) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecucion: %.4f", tiempo);

    return 0;

};
