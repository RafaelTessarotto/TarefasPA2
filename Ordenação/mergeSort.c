#include <stdio.h>

int contador(int p[], int n);
int mergeSort(int p[], int n);

int main (){
    int array[] = { 2, 4, 1, 9, 5, 3, 8, 6, 7};
    int tamanho = sizeof(array) / sizeof(array[0]);

    printf("Array original: ");
    for (int i = 0; i < tamanho; i++){
        printf("%d ", array[i]);
    }

    printf("\n");
    printf("O numero de inversoes no array e: %d\n", contador(array, tamanho));
    mergeSort(array, tamanho);
    printf("Array ordenado: ");
    for (int i = 0; i < tamanho; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int contador(int p[], int n){
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


int mergeSort(int p[], int n) {
    if (n < 2) {
        return 0; // Base case: array is already sorted
    }

    int mid = n / 2;
    int left[mid];
    int right[n - mid];

    // Split the array into left and right halves
    for (int i = 0; i < mid; i++) {
        left[i] = p[i];
    }
    for (int i = mid; i < n; i++) {
        right[i - mid] = p[i];
    }

    // Recursively sort both halves
    mergeSort(left, mid);
    mergeSort(right, n - mid);

    // Merge the sorted halves
    int i = 0, j = 0, k = 0;
    while (i < mid && j < n - mid) {
        if (left[i] <= right[j]) {
            p[k++] = left[i++];
        } else {
            p[k++] = right[j++];
        }
    }

    // Copy any remaining elements from left half
    while (i < mid) {
        p[k++] = left[i++];
    }

    // Copy any remaining elements from right half
    while (j < n - mid) {
        p[k++] = right[j++];
    }

    return 0;
}