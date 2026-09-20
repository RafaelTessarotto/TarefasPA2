#include <stdio.h>
#include <stdlib.h>

int main() {
    // O problema menciona a leitura a partir do arquivo "tape.in"
    FILE *fin = fopen("tape.in", "r");
    if (fin == NULL) {
        // Se o ficheiro não existir no diretório, faz fallback para a entrada padrão (teclado)
        fin = stdin;
    }

    int N;
    // Lê o número de casos de teste
    if (fscanf(fin, "%d", &N) != 1) return 0;

    for (int c = 1; c <= N; c++) {
        int L, T;
        if (fscanf(fin, "%d %d", &L, &T) != 2) break;

        int M[55], S[55], duration[55];
        int total_duration = 0;

        // Leitura e conversão do tempo das músicas para segundos
        for (int i = 1; i <= T; i++) {
            fscanf(fin, "%d %d", &M[i], &S[i]);
            duration[i] = M[i] * 60 + S[i];
            total_duration += duration[i];
        }

        // Capacidade máxima de cada lado da fita em segundos
        int max_cap = (L * 60) / 2;

        printf("Caso:%d\n", c);

        // Verificação imediata: se o total ultrapassar a soma dos dois lados, é impossível
        if (total_duration > L * 60) {
            printf("Impossivel gravar as musicas nessa fita.\n");
            continue;
        }

        /* 
         * Matriz de Programação Dinâmica (DP)
         * dp[i][w] = 1 se for possível alcançar a soma w usando um subconjunto 
         * das primeiras 'i' músicas.
         */
        int **dp = (int **)malloc((T + 1) * sizeof(int *));
        for (int i = 0; i <= T; i++) {
            dp[i] = (int *)calloc((max_cap + 1), sizeof(int));
        }

        dp[0][0] = 1;

        // Preenchimento da matriz de DP
        for (int i = 1; i <= T; i++) {
            for (int w = 0; w <= max_cap; w++) {
                // Se a soma w já era alcançável sem a música 'i', mantém-se verdade
                dp[i][w] = dp[i-1][w];
                
                // Se conseguimos incluir a música 'i' e a soma residual era possível
                if (w >= duration[i] && dp[i-1][w - duration[i]]) {
                    dp[i][w] = 1;
                }
            }
        }

        // Procuramos o maior subconjunto (em segundos) que caiba no Lado A,
        // de tal forma que o excedente caiba obrigatoriamente no Lado B.
        int best_w = -1;
        int lower_bound = total_duration - max_cap;
        if (lower_bound < 0) lower_bound = 0;

        for (int w = max_cap; w >= lower_bound; w--) {
            if (dp[T][w]) {
                best_w = w;
                break;
            }
        }

        if (best_w == -1) {
            // Nenhuma combinação atendeu aos limites para ambos os lados
            printf("Impossivel gravar as musicas nessa fita.\n");
        } else {
            // Reconstrução de quais músicas foram escolhidas para o Lado A
            int in_A[55] = {0};
            int curr_w = best_w;

            for (int i = T; i >= 1; i--) {
                // Verifica se a música 'i' fez parte da composição do peso ótimo encontrado
                if (curr_w >= duration[i] && dp[i-1][curr_w - duration[i]]) {
                    in_A[i] = 1;
                    curr_w -= duration[i];
                } else {
                    in_A[i] = 0;
                }
            }

            // Impressão da alocação respeitando a formatação exata dos exemplos
            printf("Lado A\n");
            for (int i = 1; i <= T; i++) {
                if (in_A[i]) {
                    printf("%dm %ds\n", M[i], S[i]);
                }
            }

            printf("Lado B\n");
            for (int i = 1; i <= T; i++) {
                if (!in_A[i]) {
                    printf("%dm %ds\n", M[i], S[i]);
                }
            }
        }

        // Libertar memória para não causar memory leaks entre os casos
        for (int i = 0; i <= T; i++) {
            free(dp[i]);
        }
        free(dp);
    }

    if (fin != stdin) fclose(fin);
    return 0;
}