
// incldues
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxSubarraySum(int n, int arr[]) {
    if (n <= 0) {
        printf("El arreglo esta vacío.\n");
        return 0;
    }

    srand(time(NULL));

    int maxSum = arr[0];
    int currentSum = arr[0];

    for (int i = 1; i < n; i++) {
        arr[i] = rand(); // Generar número aleatorio
        currentSum = max(arr[i], currentSum + arr[i]);
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main() {

    clock_t inicio, fin;
    double tiempo;

    inicio = clock();

    int n;
    printf("Ingrese el numero de elementos: ");
    scanf("%d", &n);

    int arreglo[n];

    int maxSum = maxSubarraySum(n, arreglo);

    printf("Suma maxima de un subarreglo: %d\n", maxSum);


    fin = clock();
    tiempo = ((double) (fin - inicio)) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecucion: %.4f", tiempo);

    return 0;
}
