#include <stdio.h>

#define N 4

void imprimirSudoku(int sudoku[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", sudoku[i][j]);
        }

        printf("\n");
    }
}

int ehValido(int sudoku[N][N], int linha, int coluna, int numero)
{
    for (int j = 0; j < N; j++)
    {
        if (sudoku[linha][j] == numero)
        {
            return 0;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (sudoku[i][coluna] == numero)
        {
            return 0;
        }
    }

    return 1;
}

//Backtracking
int resolverSudoku(int sudoku[N][N])
{
    for (int linha = 0; linha < N; linha++)
    {
        for (int coluna = 0; coluna < N; coluna++)
        {
            if (sudoku[linha][coluna] == 0)
            {
                for (int numero = 1; numero <= N; numero++)
                {
                    if (ehValido(sudoku, linha, coluna, numero))
                    {
                        sudoku[linha][coluna] = numero;

                        if (resolverSudoku(sudoku))
                        {
                            return 1;
                        }

                        // BACKTRACKING:
                        // desfaz a tentativa
                        sudoku[linha][coluna] = 0;
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int sudoku[N][N] =
    {
        {0, 2, 4, 0},
        {1, 0, 0, 3},
        {4, 0, 0, 2},
        {0, 1, 3, 0}
    };

    printf("Sudoku inicial:\n");
    imprimirSudoku(sudoku);

    if (resolverSudoku(sudoku))
    {
        printf("\nSudoku resolvido:\n");
        imprimirSudoku(sudoku);
    }
    else
    {
        printf("\nNao existe solucao para o Sudoku.\n");
    }

    return 0;
}