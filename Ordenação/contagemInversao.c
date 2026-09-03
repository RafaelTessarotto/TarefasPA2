#include <stdio.h>

int contador (int p[], int n);
int ordenador (int p[], int n);

int main(){
    int array[] = { 2, 4, 1, 9, 5, 3, 8, 6, 7};
    int tamanho = sizeof(array) / sizeof(array[0]);

    printf("Array original: ");
    for (int i = 0; i < tamanho; i++){
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("O numero de inversoes no array e: %d\n", contador(array, tamanho));
        return 0;

    printf("Array ordenado: ");
    ordenador(array, tamanho);
    for (int i = 0; i < tamanho; i++){
        printf("%d ", array[i]);
    }
    printf("\n");

    
}

int contador (int p[], int n){
    int c = 0;
    
    for (int i = 0; i < n - 1; i++){
        for (int j = i+1; j < n; j++){
            if (p[i] > p [j]){
                c = c + 1;
            }
        }
    }
    return c;
}

int ordenador (int p[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = i+1; j < n; j++){
            if (p[i] > p [j]){
                int aux = p[i];
                p[i] = p[j];
                p[j] = aux;
            }
        }
    }
    return 0;
}