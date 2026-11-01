#include <stdio.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

void SCM_2_linhas(char X[], char Y[]) {
    int m = strlen(X);
    int n = strlen(Y);
    
    int c[2][n + 1]; 
    
    for (int j = 0; j <= n; j++) {
        c[0][j] = 0;
        c[1][j] = 0;
    }
    
    for (int i = 1; i <= m; i++) {
        int linha_atual = i % 2;
        int linha_anterior = (i - 1) % 2;
        
        c[linha_atual][0] = 0;
        
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                c[linha_atual][j] = c[linha_anterior][j - 1] + 1;
            } 
            else {
                c[linha_atual][j] = MAX(c[linha_atual][j - 1], c[linha_anterior][j]);
            }
        }
    }
    
    int linha_final = m % 2;
    printf("Comprimento da SCM (Memoria Otimizada): %d\n", c[linha_final][n]);
}

int main() {
    char X[] = "ABCBDAB";
    char Y[] = "BDCABA";
    
    printf("Sequencia X: %s\n", X);
    printf("Sequencia Y: %s\n\n", Y);
    
    SCM_2_linhas(X, Y);
    
    return 0;
}