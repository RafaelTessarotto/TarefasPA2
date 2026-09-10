#include <stdio.h>

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

void mostra_sequencias(int s[], int i, int v[], int m, int n) {
    if (i == m) { 
        imprime_solucao(s, m);
    } else {
        for (int j = 0; j < n; j++) {
            s[i] = v[j];
            mostra_sequencias(s, i + 1, v, m, n);
        }
    }
}

int main() {
    printf("=== Sequencias (v tamanho 3, s tamanho 3) ===\n");
    
    int v[3] = {1, 2, 3}; 
    int s[3];             
    
    int m = 3; 
    int n = 3; 
    
    mostra_sequencias(s, 0, v, m, n);
    
    return 0;
}