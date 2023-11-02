#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(&arr[i], &arr[minIndex]);
        }
    }
}

int main(void) {
    int n;
    printf("Ingrese el número de elementos (N): ");
    scanf("%d", &n);

    if (n < 1 || n > 30) {
        printf("El número de elementos debe estar en el rango de 1 a 30.\n");
        return 1;
    }

    int arr[n];

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 30 + 1;
    }

    printf("Elementos generados aleatoriamente:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    selectionSort(arr, n);

    printf("\nElementos ordenados:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nEl elemento más pequeño es: %d\n", arr[0]);
    printf("El elemento más grande es: %d\n", arr[n - 1]);

    double media = 0.0;
    for (int i = 0; i < n; i++) {
        media += arr[i];
    }
    media /= n;
    printf("La media es: %.2f\n", media);

    int moda = arr[0];
    int frecuencia = 1;
    int maxFrecuencia = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            frecuencia++;
        } else {
            if (frecuencia > maxFrecuencia) {
                maxFrecuencia = frecuencia;
                moda = arr[i - 1];
            }
            frecuencia = 1;
        }
    }
    printf("La moda es: %d\n", moda);

    double mediana = (n % 2 == 0) ? (arr[n / 2 - 1] + arr[n / 2]) / 2.0 : arr[n / 2];
    printf("La mediana es: %.2f\n", mediana);

    printf("Histograma:\n");

    for (int i = 1; i <= 30; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == i) {
                count++;
            }
        }
        int asteriscos = (count * 30) / n;

        printf("%2d: ", i);
        for (int j = 0; j < asteriscos; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}

