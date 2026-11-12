#include <stdio.h>
#include <string.h>

void computar_funcao_prefixo(char P[], int m, int pi[]) {
    pi[0] = 0;
    int k = 0;
    
    for (int q = 1; q < m; q++) {
        while (k > 0 && P[k] != P[q]) { 
            k = pi[k - 1];
        }
        if (P[k] == P[q]) { 
            k = k + 1;
        }
        pi[q] = k;
    }
}

void casamento_padroes_KMP(char T[], char P[]) {
    int n = strlen(T);
    int m = strlen(P);
    
    int pi[m];
    computar_funcao_prefixo(P, m, pi);
    
    int q = 0;
    
    for (int i = 0; i < n; i++) {
        while (q > 0 && P[q] != T[i]) {
            q = pi[q - 1];
        }
        if (P[q] == T[i]) {
            q = q + 1;
        }
        if (q == m) {
            printf("KMP: Padrao encontrado com deslocamento: %d\n", i - m + 1);
            q = pi[q - 1];
        }
    }
}

int main() {
    char T[] = "abracadabra";
    char P[] = "bra";
    
    printf("Texto: %s\n", T);
    printf("Padrao: %s\n\n", P);
    
    casamento_padroes_KMP(T, P);
    
    return 0;
}