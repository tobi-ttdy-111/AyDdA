
// includes
#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100
#define MAX_W 100


// dp
int dp[ MAX_N ][ MAX_W ];


// max
int max( int a, int b ) {

    return ( a > b ) ? a : b;

};


// mochila01TopDown
int mochila01TopDown( int W, int weights[], int values[], int n ) {

    if ( n == 0 || W == 0 ) { return 0; };
    if ( dp[ n ][ W ] != -1) { return dp[ n ][ W ]; };

    if ( weights[ n - 1 ] > W ) {
        dp[ n ][ W ] = mochila01TopDown( W, weights, values, n - 1 );
    } else {
        dp[ n ][ W ] = max( values[n - 1] + mochila01TopDown(W - weights[n - 1], weights, values, n - 1),
                       mochila01TopDown(W, weights, values, n - 1 ) );
    };
    return dp[ n ][ W ];

};


// main
int main() {

    int values[] = { 60, 100, 120 };
    int weights[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof( values ) / sizeof( values[ 0 ] );

    for ( int i = 0; i < MAX_N; i++ ) {
        for ( int j = 0; j < MAX_W; j++ ) {
            dp[ i ][ j ] = -1;
        };
    };

    int maxValue = mochila01TopDown(W, weights, values, n);
    printf( "Valor maximo en la mochila (Top-Down): %d\n", maxValue );
    return 0;

};
