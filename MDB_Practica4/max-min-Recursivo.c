
// incldues
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void buscarMaximoMinimo(int n, int *maximo, int *minimo) {
    if (n <= 0) {
        printf("El arreglo está vacío.\n");
        return;
    }

    srand(time(NULL));

    *maximo = rand();
    *minimo = rand();

    for (int i = 1; i < n; i++) {
        int numero = rand();

        if (numero > *maximo) {
            *maximo = numero;
        } else if (numero < *minimo) {
            *minimo = numero;
        }
    }
}

int main() {

    clock_t inicio, fin;
    double tiempo;

    inicio = clock();

    int n;
    printf("Ingrese el número de elementos: ");
    scanf("%d", &n);

    int maximo, minimo;

    buscarMaximoMinimo(n, &maximo, &minimo);

    printf("Máximo: %d\n", maximo);
    printf("Mínimo: %d\n", minimo);


    fin = clock();
    tiempo = ((double) (fin - inicio)) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecucion: %.4f", tiempo);

    return 0;
}
