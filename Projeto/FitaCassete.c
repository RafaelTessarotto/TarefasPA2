// Projeto: FitaCassete
// Aluno: Rafael Moutinho Tessarotto - 10395682

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fin = fopen("tape.in", "r");
    if (fin == NULL) {
        fin = stdin;
    }

    int N;
    if (fscanf(fin, "%d", &N) != 1) return 0;

    for (int c = 1; c <= N; c++) {
        int L, T;
        if (fscanf(fin, "%d %d", &L, &T) != 2) break;

        int M[55], S[55], duration[55];
        int total_duration = 0;

        for (int i = 1; i <= T; i++) {
            fscanf(fin, "%d %d", &M[i], &S[i]);
            duration[i] = M[i] * 60 + S[i];
            total_duration += duration[i];
        }

        int max_cap = (L * 60) / 2;

        printf("Caso:%d\n", c);

        if (total_duration > L * 60) {
            printf("Impossivel gravar as musicas nessa fita.\n");
            continue;
        }

        int **dp = (int **)malloc((T + 1) * sizeof(int *));
        for (int i = 0; i <= T; i++) {
            dp[i] = (int *)calloc((max_cap + 1), sizeof(int));
        }

        dp[0][0] = 1;

        for (int i = 1; i <= T; i++) {
            for (int w = 0; w <= max_cap; w++) {
                dp[i][w] = dp[i-1][w];
                
                if (w >= duration[i] && dp[i-1][w - duration[i]]) {
                    dp[i][w] = 1;
                }
            }
        }

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
            printf("Impossivel gravar as musicas nessa fita.\n");
        } else {
            int in_A[55] = {0};
            int curr_w = best_w;

            for (int i = T; i >= 1; i--) {
                if (curr_w >= duration[i] && dp[i-1][curr_w - duration[i]]) {
                    in_A[i] = 1;
                    curr_w -= duration[i];
                } else {
                    in_A[i] = 0;
                }
            }

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

        for (int i = 0; i <= T; i++) {
            free(dp[i]);
        }
        free(dp);
    }

    if (fin != stdin) fclose(fin);
    return 0;
}