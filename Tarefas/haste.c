#include <stdio.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int corte_haste_recursivo(int p[], int n) {
    if (n == 0) return 0;
    
    int q = -1; 
    
    for (int i = 1; i <= n; i++) {
        q = MAX(q, p[i] + corte_haste_recursivo(p, n - i));
    }
    return q;
}

int corte_haste_memoizado_aux(int p[], int n, int r[]) {
    if (r[n] >= 0) return r[n];
    
    if (n == 0) return 0;
    
    int q = -1;
    for (int i = 1; i <= n; i++) {
        q = MAX(q, p[i] + corte_haste_memoizado_aux(p, n - i, r));
    }
    
    r[n] = q;
    return q;
}

int corte_haste_topdown(int p[], int n) {
    int r[n + 1];
    for (int i = 0; i <= n; i++) {
        r[i] = -INT_MAX;
    }
    return corte_haste_memoizado_aux(p, n, r);
}

int corte_haste_bottomup(int p[], int n) {
    int r[n + 1];
    r[0] = 0;
    
    for (int j = 1; j <= n; j++) {
        int q = -1;
        for (int i = 1; i <= j; i++) {
            q = MAX(q, p[i] + r[j - i]);
        }
        r[j] = q;
    }
    
    return r[n];
}

int main() {
    int p[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int n = 10;
    
    printf("1. Recursivo puro: %d\n", corte_haste_recursivo(p, n));
    printf("2. Top-down (Memoization): %d\n", corte_haste_topdown(p, n));
    printf("3. Bottom-up (Tabulation): %d\n", corte_haste_bottomup(p, n));
    
    return 0;
}