#include <stdio.h>
#include <string.h>


#define DIAGONAL 1 
#define CIMA 2     
#define ESQUERDA 3

void recupera_SCM(int m, int n, int b[m + 1][n + 1], char X[], int i, int j) {
    if (i == 0 || j == 0) {
        return;
    }
    
    if (b[i][j] == DIAGONAL) {
        recupera_SCM(m, n, b, X, i - 1, j - 1);
        printf("%c", X[i - 1]); 
    } 
    else if (b[i][j] == CIMA) {
        recupera_SCM(m, n, b, X, i - 1, j);
    } 
    else {
        recupera_SCM(m, n, b, X, i, j - 1);
    }
}

void SCM(char X[], char Y[]) {
    int m = strlen(X);
    int n = strlen(Y);
    
    int c[m + 1][n + 1];
    int b[m + 1][n + 1];
    
    for (int i = 0; i <= m; i++) {
        c[i][0] = 0;
    }
    for (int j = 0; j <= n; j++) {
        c[0][j] = 0;
    }
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = DIAGONAL;
            } 
            else if (c[i][j - 1] > c[i - 1][j]) {
                c[i][j] = c[i][j - 1];
                b[i][j] = ESQUERDA;
            } 
            else {
                c[i][j] = c[i - 1][j];
                b[i][j] = CIMA;
            }
        }
    }
    
    printf("Comprimento da SCM: %d\n", c[m][n]);
    printf("Subsequencia encontrada: ");
    recupera_SCM(m, n, b, X, m, n);
    printf("\n");
}

int main() {
    char X[] = "ABCBDAB";
    char Y[] = "BDCABA";
    
    printf("--- Subsequencia Comum Maxima (SCM/LCS) ---\n");
    printf("Sequencia X: %s\n", X);
    printf("Sequencia Y: %s\n\n", Y);
    
    SCM(X, Y);
    
    return 0;
}