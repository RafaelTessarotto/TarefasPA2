#include <stdio.h>
#include <stdbool.h>

void imprime_solucao(int s[], int tamanho) {
    printf("{ ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d", s[i]);
        if (i < tamanho - 1) {
            printf(", ");
        }
    }
    printf(" }\n");
}

void mostra_permutacoes(int s[], int i, int v[], int n, bool usados[]) {
    if (i == n) {
        imprime_solucao(s, n);
    } else {
        for (int j = 0; j < n; j++) {
            if (!usados[j]) {
                s[i] = v[j];
                usados[j] = true; 
                
                mostra_permutacoes(s, i + 1, v, n, usados);
                
                usados[j] = false; 
            }
        }
    }
}

int main() {
    printf("=== Permutacoes (v tamanho 3) ===\n");
    
    int v[3] = {1, 2, 3}; 
    int s[3];             
    
    bool usados[3] = {false, false, false}; 
    
    int n = 3; 
    
    mostra_permutacoes(s, 0, v, n, usados);
    
    return 0;
}