#include <stdio.h>
#include <stdbool.h>

void ordenar_decrescente(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

bool backtrack_quadrado(int palitos[], int n, int index, int lados[], int alvo) {
    if (index == n) {
        return lados[0] == alvo && lados[1] == alvo && lados[2] == alvo && lados[3] == alvo;
    }

    for (int i = 0; i < 4; i++) {
        if (lados[i] + palitos[index] <= alvo) {
            lados[i] += palitos[index];
            
            if (backtrack_quadrado(palitos, n, index + 1, lados, alvo)) {
                return true;
            }
            
            lados[i] -= palitos[index];
        }
        
        if (lados[i] == 0) {
            break;
        }
    }
    return false;
}

bool faz_quadrado(int palitos_de_fosforos[], int n) {
    if (n < 4) return false;

    long soma_total = 0;
    for (int i = 0; i < n; i++) {
        soma_total += palitos_de_fosforos[i];
    }

    if (soma_total % 4 != 0) return false;

    int alvo = soma_total / 4;
    int lados[4] = {0, 0, 0, 0};

    ordenar_decrescente(palitos_de_fosforos, n);

    if (palitos_de_fosforos[0] > alvo) return false;

    return backtrack_quadrado(palitos_de_fosforos, n, 0, lados, alvo);
}