#include <stdio.h>

void mochila_fracionaria(float w[], float v[], int n, float W, float x[]);
void print_vetor(float V[], int tamanho_V);

int main() {
    float w[] = {10.0, 20.0, 30.0};
    float v[] = {60.0, 100.0, 120.0};
    int n = sizeof(w) / sizeof(w[0]);
    
    float W = 50.0; // Capacidade máxima da mochila
    
    float x[50]; // Vetor solução
    
    // Chama a função passando a caixa vazia 'x'
    mochila_fracionaria(w, v, n, W, x);
    
    printf("Fracao pega de cada item (Vetor x):\n");
    print_vetor(x, n);
    
    return 0;
}

void mochila_fracionaria(float w[], float v[], int n, float W, float x[]) {
    // Zera o vetor solução primeiro (boa prática em C)
    for (int j = 0; j < n; j++) {
        x[j] = 0.0;
    }

    // 1. ordene w e v de tal forma que v[1]/w[1] >= v[2]/w[2] ...
    // Algoritmo de ordenação (Bubble Sort adaptado)
    for (int k = 0; k < n - 1; k++) {
        for (int j = 0; j < n - k - 1; j++) {
            float razao1 = v[j] / w[j];
            float razao2 = v[j+1] / w[j+1];
            
            if (razao1 < razao2) {
                // Troca os valores de posição
                float temp_v = v[j];
                v[j] = v[j+1];
                v[j+1] = temp_v;
                
                // Troca os pesos de posição (tem que acompanhar o valor!)
                float temp_w = w[j];
                w[j] = w[j+1];
                w[j+1] = temp_w;
            }
        }
    }

    // 2. i <- 0 (Lembre-se: em C o primeiro índice é 0, não 1)
    int i = 0;

    // 3. enquanto i < n e W > 0 faça
    while (i < n && W > 0.0) {
        // 4. se w[i] <= W
        if (w[i] <= W) {
            // 5. então x[i] <- 1 (coloca o objeto inteiro na mochila)
            x[i] = 1.0;
            // 6. W <- W - w[i]
            W = W - w[i];
            // 7. i <- i + 1
            i++;
        } 
        // 8. senão
        else {
            // coloca fração do objeto na mochila
            x[i] = W / w[i];
            // 9. W <- 0
            W = 0.0;
        }
    }
    // 10. retorne x (Como passamos 'x' por parâmetro, ele já está preenchido no main!)
}

void print_vetor(float V[], int tamanho_V) {
    for (int i = 0; i < tamanho_V; i++) {
        // Imprime com 2 casas decimais
        printf("Item %d: %.2f\n", i, V[i]);
    }
    printf("\n");
}