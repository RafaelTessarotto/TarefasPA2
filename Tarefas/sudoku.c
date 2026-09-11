#include <stdio.h>

#define N 4

// Imprime o Sudoku
void imprimirSudoku(int sudoku[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

// Verifica se o número pode ser colocado
int ehValido(int sudoku[N][N], int linha, int coluna, int numero) {

    // Verifica a linha
    for (int j = 0; j < N; j++) {
        if (sudoku[linha][j] == numero) {
            return 0;
        }
    }

    // Verifica a coluna
    for (int i = 0; i < N; i++) {
        if (sudoku[i][coluna] == numero) {
            return 0;
        }
    }

    return 1;
}

// Algoritmo de Backtracking
int resolverSudoku(int sudoku[N][N]) {

    // Procura a primeira posição vazia
    for (int linha = 0; linha < N; linha++) {
        for (int coluna = 0; coluna < N; coluna++) {

            if (sudoku[linha][coluna] == 0) {

                // Tenta os números de 1 até 4
                for (int numero = 1; numero <= N; numero++) {

                    // Verifica se a solução parcial é promissora
                    if (ehValido(sudoku, linha, coluna, numero)) {

                        // Coloca o número
                        sudoku[linha][coluna] = numero;

                        // Continua tentando resolver
                        if (resolverSudoku(sudoku)) {
                            return 1;
                        }

                        // Backtracking:
                        // desfaz a tentativa
                        sudoku[linha][coluna] = 0;
                    }
                }

                // Nenhum número funcionou nessa posição
                return 0;
            }
        }
    }

    // Não existem mais posições vazias
    return 1;
}

int main() {

    // Sudoku do exemplo apresentado no PDF
    int sudoku[N][N] = {
        {0, 2, 4, 0},
        {1, 0, 0, 3},
        {4, 0, 2, 0},
        {0, 1, 3, 0}
    };

    printf("Sudoku inicial:\n");
    imprimirSudoku(sudoku);

    if (resolverSudoku(sudoku)) {
        printf("\nSudoku resolvido:\n");
        imprimirSudoku(sudoku);
    } else {
        printf("\nNao existe solucao para este Sudoku.\n");
    }

    return 0;
}