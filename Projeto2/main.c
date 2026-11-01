/*
 * Grupo:
 * Rafael Moutinho Tessarotto - RA: 10395682
 
 * Referências consultadas: 
 * - Material da disciplina / Slides sobre Grafos e Algoritmo de Dijkstra
 * - https://share.gemini.google/z0JxMT8m9pJf
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INFINITO 999999

int main() {
    FILE *file = fopen("pizzaria.txt", "r");
    if (!file) {
        printf("Erro ao abrir o ficheiro pizzaria.txt\n");
        return 1;
    }

    int destino, num_esquinas;
    
    if (fscanf(file, "%d", &destino) != 1) return 1;
    if (fscanf(file, "%d", &num_esquinas) != 1) return 1;

    int adj[num_esquinas + 1][num_esquinas + 1];
    for (int i = 1; i <= num_esquinas; i++) {
        for (int j = 1; j <= num_esquinas; j++) {
            adj[i][j] = INFINITO;
        }
    }

    int u, v, tempo;
    while (fscanf(file, "%d", &u) == 1 && u != 0) {
        fscanf(file, "%d %d", &v, &tempo);
        adj[u][v] = tempo;
    }
    fclose(file);

    int T[num_esquinas + 1]; 
    int R[num_esquinas + 1]; 
    bool E[num_esquinas + 1]; 

    for (int i = 1; i <= num_esquinas; i++) {
        T[i] = INFINITO;
        R[i] = 0; 
        E[i] = true; 
    }

    int inicio = 1;
    T[inicio] = 0;

    for (int i = 1; i <= num_esquinas; i++) {

        int min_T = INFINITO;
        int v_atual = -1;
        for (int j = 1; j <= num_esquinas; j++) {
            if (E[j] && T[j] < min_T) {
                min_T = T[j];
                v_atual = j;
            }
        }

        if (v_atual == -1) break; 

        E[v_atual] = false; 

        for (int e = 1; e <= num_esquinas; e++) {
            if (adj[v_atual][e] != INFINITO && E[e]) {

                if (T[e] > T[v_atual] + adj[v_atual][e]) {

                    T[e] = T[v_atual] + adj[v_atual][e];

                    R[e] = v_atual; 
                }
            }
        }
    }

    int caminho[num_esquinas + 1];
    int tam_caminho = 0;
    int passo_atual = destino;

    while (passo_atual != 0) {
        caminho[tam_caminho] = passo_atual;
        tam_caminho++;
        passo_atual = R[passo_atual];
    }

    printf("Rota ate a esquina #%d: ", destino);
    for (int i = tam_caminho - 1; i >= 0; i--) {
        printf("%d ", caminho[i]);
    }
    printf("\nTempo calculado para rota = %d min.\n", T[destino]);

    return 0;
}