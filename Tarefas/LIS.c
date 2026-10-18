#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

// ==========================================
// 2. SUBSEQUÊNCIA CRESCENTE MAIS LONGA (LIS)
// ==========================================

// Versão Recursiva
int lis_recursiva(int num[], int i) {
    if (i == 0) {
        return 1;
    }
    
    int maior = 1;
    for (int j = 0; j < i; j++) {
        if (num[j] < num[i]) {
            maior = MAX(maior, lis_recursiva(num, j) + 1);
        }
    }
    return maior;
}

int subsequencia_crescente_mais_longa_rec(int num[], int n) {
    int maior = 1;
    for (int i = 0; i < n; i++) {
        maior = MAX(maior, lis_recursiva(num, i));
    }
    return maior;
}

// Versão Memoization (Top-Down)
int lis_memoization(int num[], int i, int L[]) {
    if (L[i] != -1) {
        return L[i];
    }
    
    if (i == 0) {
        return L[i] = 1;
    }
    
    int maior = 1;
    for (int j = 0; j < i; j++) {
        if (num[j] < num[i]) {
            maior = MAX(maior, lis_memoization(num, j, L) + 1);
        }
    }
    
    return L[i] = maior;
}

int subsequencia_crescente_mais_longa_memo(int num[], int n) {
    int L[n];
    for (int i = 0; i < n; i++) {
        L[i] = -1; 
    }
    
    int maior = 1;
    for (int i = 0; i < n; i++) {
        maior = MAX(maior, lis_memoization(num, i, L));
    }
    
    return maior;
}

// Versão Tabulation (Bottom-Up)
int subsequencia_crescente_mais_longa_tab(int num[], int n) {
    int L[n];
    int maior = 0;
    
    for (int i = 0; i < n; i++) {
        L[i] = 1;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (num[j] < num[i]) {
                L[i] = MAX(L[i], L[j] + 1);
            }
        }
        maior = MAX(maior, L[i]);
    }
    
    return maior;
}

// ==========================================
// MAIN PARA TESTES (LIS)
// ==========================================
int main() {
    printf("===== TESTE LIS =====\n");
    
    int num_lis[] = {8, 7, 11, 4, 5, 1, 9, 10, 6, 3};
    int n_lis = sizeof(num_lis) / sizeof(num_lis[0]);
    
    printf("Vetor: ");
    for(int i = 0; i < n_lis; i++) {
        printf("%d ", num_lis[i]);
    }
    printf("\n");

    // Teste Recursivo
    printf("Tamanho LIS Recursivo: %d\n", subsequencia_crescente_mais_longa_rec(num_lis, n_lis));
    
    // Teste Memoization
    printf("Tamanho LIS Memoization: %d\n", subsequencia_crescente_mais_longa_memo(num_lis, n_lis));
    
    // Teste Tabulation
    printf("Tamanho LIS Tabulation: %d\n", subsequencia_crescente_mais_longa_tab(num_lis, n_lis));

    return 0;
}