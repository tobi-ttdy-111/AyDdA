
// incldues
#include <stdio.h>


// max
int max( int a, int b ) { return (a > b) ? a : b; };


// mochila01BottomUp
int mochila01BottomUp( int W, int weights[], int values[], int n ) {

    int dp[ n + 1 ][ W + 1 ];

    for ( int i = 0; i <= n; i++ ) {
        for ( int w = 0; w <= W; w++ ) {
            if ( i == 0 || w == 0 )
                dp[ i ][ w ] = 0;
            else if ( weights[ i - 1 ] <= w )
                dp[ i ][ w ] = max( values[ i - 1 ] + dp[ i - 1 ][ w - weights[ i - 1 ] ], dp[ i - 1 ][ w ] );
            else dp[i][w] = dp[i - 1][w];
        };
    };

    return dp[ n ][ W ];

};


// main
int main() {

    int values[] = { 60, 100, 120 };
    int weights[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof( values ) / sizeof( values[ 0 ] );

    int maxValue = mochila01BottomUp( W, weights, values, n );
    printf( "Valor maximo en la mochila (Bottom-Up): %d\n", maxValue );
    return 0;

}
