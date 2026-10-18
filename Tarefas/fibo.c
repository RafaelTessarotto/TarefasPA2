#include <stdio.h>

// ==========================================
// 1. NÚMEROS DE FIBONACCI
// ==========================================

// 1.1 Versão Recursiva
int fib_recursiva(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    return fib_recursiva(n - 1) + fib_recursiva(n - 2);
}

// 1.2 Versão Memoization (Top-Down)
int fib_memoization(int n, int memo[]) {
    if (memo[n] != -1) {
        return memo[n];
    }
    
    if (n == 0 || n == 1) {
        memo[n] = n;
    } else {
        memo[n] = fib_memoization(n - 1, memo) + fib_memoization(n - 2, memo);
    }
    
    return memo[n];
}

// 1.3 Versão Tabulation (Bottom-Up)
int fib_tabulation(int n) {
    if (n == 0) return 0;
    
    int f[n + 1];
    f[0] = 0;
    f[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    
    return f[n];
}

// ==========================================
// MAIN PARA TESTES (FIBONACCI)
// ==========================================
int main() {
    printf("===== TESTE FIBONACCI =====\n");
    int n_fib = 10;
    
    // Teste Recursivo
    printf("Fibonacci (%d) Recursivo: %d\n", n_fib, fib_recursiva(n_fib));
    
    // Teste Memoization
    int memo_fib[n_fib + 1];
    for (int i = 0; i <= n_fib; i++) {
        memo_fib[i] = -1; // Inicializando o "caderninho"
    }
    printf("Fibonacci (%d) Memoization: %d\n", n_fib, fib_memoization(n_fib, memo_fib));
    
    // Teste Tabulation
    printf("Fibonacci (%d) Tabulation: %d\n", n_fib, fib_tabulation(n_fib));

    return 0;
}