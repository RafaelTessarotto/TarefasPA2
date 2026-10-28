#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

// ==========================================
// 1. RECURSIVA PURA
// ==========================================
int mochila_recursiva(int W, int w[], int v[], int n) {
    if (n == 0 || W <= 0) {
        return 0; 
    }
    
    if (w[n - 1] > W) {
        return mochila_recursiva(W, w, v, n - 1); 
    } else {
    
        return MAX(mochila_recursiva(W, w, v, n - 1),
                   mochila_recursiva(W - w[n - 1], w, v, n - 1) + v[n - 1]);
    }
}

// ==========================================
// 2. TOP-DOWN COM MEMOIZATION
// ==========================================
int mochila_memoization_aux(int W, int w[], int v[], int n, int M[][W + 1]) {
    if (n == 0 || W <= 0) {
        return 0; 
    }
    
    if (M[n][W] != -1) {
        return M[n][W]; 
    }
    
    if (w[n - 1] > W) {
        M[n][W] = mochila_memoization_aux(W, w, v, n - 1, M); 
    } else {
        M[n][W] = MAX(mochila_memoization_aux(W, w, v, n - 1, M),
                      mochila_memoization_aux(W - w[n - 1], w, v, n - 1, M) + v[n - 1]); 
    }
    
    return M[n][W]; 
}

int mochila_memoization(int W, int w[], int v[], int n) {
    int M[n + 1][W + 1];
    
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            M[i][j] = -1;
        }
    }
    
    return mochila_memoization_aux(W, w, v, n, M);
}

// ==========================================
// 3. BOTTOM-UP COM TABULATION
// ==========================================
int mochila_tabulation(int W, int w[], int v[], int n) {
    int M[n + 1][W + 1];
    
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                M[i][j] = 0; 
            } else if (w[i - 1] > j) {
                M[i][j] = M[i - 1][j];
            } else {
                M[i][j] = MAX(M[i - 1][j], M[i - 1][j - w[i - 1]] + v[i - 1]); 
            }
        }
    }
    
    return M[n][W]; 
}

// ==========================================
// 4. MAIN PARA TESTES
// ==========================================
int main() {
    int v[] = {8, 3, 9, 6}; 
    int w[] = {3, 2, 4, 1}; 
    int W = 5; 
    int n = sizeof(v) / sizeof(v[0]); 

    printf("Problema da Mochila 0/1 (Knapsack)\n");
    printf("Capacidade: %d\n\n", W);
    
    // Teste Recursiva
    printf("1. Resultado Recursiva Pura: %d\n", mochila_recursiva(W, w, v, n));
    
    // Teste Memoization
    printf("2. Resultado Top-Down (Memoization): %d\n", mochila_memoization(W, w, v, n));
    
    // Teste Tabulation
    printf("3. Resultado Bottom-Up (Tabulation): %d\n", mochila_tabulation(W, w, v, n));
    
    return 0;
}