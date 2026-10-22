#include <stdio.h>

#define INF 999999


int conta_moedas_topdown(int T, int M[], int n, int memo[]) {
    if (T == 0) return 0;
    if (T < 0) return INF;
    
    if (memo[T] != -1) {
        return memo[T];
    }
    
    int menor = INF; 
    
    for (int i = 0; i < n; i++) {
        int resultado_parcial = conta_moedas_topdown(T - M[i], M, n, memo);
        if (resultado_parcial != INF && resultado_parcial + 1 < menor) {
            menor = resultado_parcial + 1; 
        }
    }
    
    memo[T] = menor; 
    return menor;
}


int conta_moedas_bottomup(int T, int M[], int n) {
    int troco[T + 1];
    
    for (int i = 1; i <= T; i++) {
        troco[i] = INF; 
    }
    troco[0] = 0; 
    
    for (int i = 1; i <= T; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= M[j]) { 
                if (troco[i - M[j]] + 1 < troco[i]) {
                    troco[i] = troco[i - M[j]] + 1; 
                }
            }
        }
    }
    
    return troco[T]; 
}

int main() {
    int M[] = {1, 4, 6};
    int n = sizeof(M) / sizeof(M[0]);
    int T = 8; 
    
    // --- Teste Top-Down ---
    int memo[T + 1];
    for (int i = 0; i <= T; i++) {
        memo[i] = -1; 
    }
    
    int resultado_td = conta_moedas_topdown(T, M, n, memo);
    printf("Resultado Top-Down (Memoization): ");
    if (resultado_td >= INF) printf("Sem solucao\n");
    else printf("%d moedas\n", resultado_td);
    
    // --- Teste Bottom-Up ---
    int resultado_bu = conta_moedas_bottomup(T, M, n);
    printf("Resultado Bottom-Up (Tabulation): ");
    if (resultado_bu >= INF) printf("Sem solucao\n");
    else printf("%d moedas\n", resultado_bu); 
    
    return 0;
}