#include <stdio.h>

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Algoritmo do Slide 60
int particiona(int A[], int p, int r) {
    int x = A[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++) {
        if (A[j] <= x) {
            i = i + 1;
            troca(&A[i], &A[j]);
        }
    }
    troca(&A[i + 1], &A[r]);
    return i + 1;
}

// Algoritmo 'Select' do Slide 61
// Encontra o k-ésimo menor de A[p..r]
int select_k(int A[], int p, int r, int k) {
    if (p == r) {  // Slide diz "se p=q retorne A[p]" 
        return A[p];
    }
    
    int q = particiona(A, p, r);
    int m = q - p + 1; // m = pos(A[q]) relativo ao subarray
    
    if (k == m) {
        return A[q];
    }
    if (k < m) {
        return select_k(A, p, q - 1, k);
    } else {
        return select_k(A, q + 1, r, k - m);
    }
}