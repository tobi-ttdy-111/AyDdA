
// incldues
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void merge(int arr[], int l, int m, int r) {

    // variables principales
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    // copiar datos
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // fusionar arreglos
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // copiar restantes de l
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // copiar restantes de r
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

}

// mergeSort
void mergeSort(int arr[], int l, int r) {

    if (l < r) {
        int m = l + (r - l) / 2; // evitar desbordamiento
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {

    clock_t inicio, fin;
    double tiempo;

    inicio = clock();

    FILE *archivo;
    int num_datos;

    // abrir archivo
    archivo = fopen("numeros10millones.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    // entrada
    printf("Ingrese el numero de datos a ordenar (entre 2 y 10000000): ");
    scanf("%d", &num_datos);
    if (num_datos < 2 || num_datos > 10000000) {
        printf("Numero de datos no valido.\n");
        fclose(archivo);
        return 1;
    }

    // leer archivo y cerrar
    int arr[num_datos];
    for (int i = 0; i < num_datos; i++) {
        fscanf(archivo, "%d", &arr[i]);
    }
    fclose(archivo);

    // llamar a la funcion mergeSort
    mergeSort(arr, 0, num_datos - 1);

    // escribir un archivo con los datos ordenados
    archivo = fopen("numeros10millones.txt", "w");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para escribir los datos ordenados.\n");
        return 1;
    }
    for (int i = 0; i < num_datos; i++) {
        fprintf(archivo, "%d\n", arr[i]);
    }
    fclose(archivo);

    printf("Datos ordenados exitosamente.\n");

    fin = clock();
    tiempo = ((double) (fin - inicio)) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecucion: %.4f", tiempo);

    return 0;
}
