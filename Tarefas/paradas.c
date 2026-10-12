#include <stdio.h>

void algoritmo_de_parada(int p[], int n, int C) {
    int S[100];
    int S_size = 0;
    int ultima_parada = p[0];

    for (int i = 1; i < n; i++) {
        if (p[i] - ultima_parada > C) {
            ultima_parada = p[i - 1];
            
            int existe = 0;
            for(int k = 0; k < S_size; k++) {
                if(S[k] == (i - 1)) existe = 1;
            }
            if(!existe) {
                S[S_size++] = i - 1;
            }
        }
    }

    for (int i = 0; i < S_size; i++) {
        printf("%d ", S[i]);
    }
    printf("\n");
}

int main() {
    int p[] = {0, 40, 90, 130, 180, 240};
    int n = sizeof(p) / sizeof(p[0]);
    int C = 50;
    
    algoritmo_de_parada(p, n, C);
    
    return 0;
}