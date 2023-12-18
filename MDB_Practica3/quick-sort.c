
// incldues
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// swap
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


// particion
int particion(int arr[], int low, int high) {

    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);

}


// quickSort
void quickSort(int arr[], int low, int high) {

    if (low < high) {
        int pi = particion(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }

}

// main
int main() {

    clock_t inicio, fin;
    double tiempo;

    inicio = clock();

    FILE *archivo;
    int num_datos;

    // abrir el archivo
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

    // leer archivo y cerrarlo
    int arr[num_datos];
    for (int i = 0; i < num_datos; i++) {
        fscanf(archivo, "%d", &arr[i]);
    }
    fclose(archivo);

    // aplicar la funcion quick
    quickSort(arr, 0, num_datos - 1);

    // crear archivo con la salida
    archivo = fopen("numerosOrdenados.txt", "w");
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
