#include <stdio.h>

#define INF 99999999


int cadeia_matriz_rec(int p[], int i, int j) {
    if (i == j) {
        return 0; 
    }
    
    int min = INF; 
    
    for (int k = i; k <= j - 1; k++) {
        int q = cadeia_matriz_rec(p, i, k) + 
                cadeia_matriz_rec(p, k + 1, j) + 
                p[i - 1] * p[k] * p[j];
                
        if (q < min) {
            min = q;
        }
    }
    
    return min;
}


int cadeia_matriz_memo_aux(int p[], int i, int j, int n, int memo[][n + 1]) {
    if (i == j) return 0;
    
    if (memo[i][j] != -1) {
        return memo[i][j]; 
    }
    
    int min = INF;
    for (int k = i; k <= j - 1; k++) {
        int q = cadeia_matriz_memo_aux(p, i, k, n, memo) + 
                cadeia_matriz_memo_aux(p, k + 1, j, n, memo) + 
                p[i - 1] * p[k] * p[j];
                
        if (q < min) {
            min = q;
        }
    }
    
    memo[i][j] = min;
    return min;
}

int cadeia_matriz_memo(int p[], int n) {
    int memo[n + 1][n + 1];
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            memo[i][j] = -1;
        }
    }
    
    return cadeia_matriz_memo_aux(p, 1, n, n, memo);
}


int ordem_cadeia_matriz(int p[], int n) {
    int m[n + 1][n + 1];
    
    for (int i = 1; i <= n; i++) {
        m[i][i] = 0; 
    }
    
    for (int l = 2; l <= n; l++) { 
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INF; 
            
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]; 
                if (q < m[i][j]) {
                    m[i][j] = q; 
                }
            }
        }
    }
    
    return m[1][n]; 
}


int main() {
    
    int p[] = {30, 35, 15, 5, 10, 20};
    int tamanho_p = sizeof(p) / sizeof(p[0]);
    int n = tamanho_p - 1; 
    
    printf("--- Multiplicacao de Cadeia de Matrizes ---\n");
    printf("Quantidade de Matrizes: %d\n\n", n);
    
    int res_rec = cadeia_matriz_rec(p, 1, n);
    printf("1. Resultado Recursivo Puro: %d multiplicacoes escalares\n", res_rec);
    
    int res_memo = cadeia_matriz_memo(p, n);
    printf("2. Resultado Top-Down (Memoization): %d multiplicacoes escalares\n", res_memo);
    
    int res_tab = ordem_cadeia_matriz(p, n);
    printf("3. Resultado Bottom-Up (Tabulation): %d multiplicacoes escalares\n", res_tab);
    
    return 0;
}