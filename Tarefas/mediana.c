#include <stdio.h>
#include <stdlib.h>

// Função auxiliar simples para caso base
void insertion_sort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

// Algoritmo de Seleção (Slide 70)
int selecao_linear(int k, int A[], int n) {
    // 1. Se n < 15 então "ordene A e devolva A_k";
    if (n < 15) {
        int *temp = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) temp[i] = A[i];
        insertion_sort(temp, n);
        int res = temp[k - 1]; // k-ésimo (índice 1-based)
        free(temp);
        return res;
    }

    // 2. Divida A em listas de 5 elementos cada;
    int num_grupos = (n + 4) / 5;
    int *M = (int*)malloc(num_grupos * sizeof(int));

    // 3. Ordene separadamente cada uma dessas listas;
    for (int i = 0; i < num_grupos; i++) {
        int inicio = i * 5;
        int tam_grupo = (inicio + 5 <= n) ? 5 : (n - inicio);
        
        int *grupo = (int*)malloc(tam_grupo * sizeof(int));
        for (int j = 0; j < tam_grupo; j++) {
            grupo[j] = A[inicio + j];
        }
        insertion_sort(grupo, tam_grupo);
        
        // 4. Seja M a lista das medianas das listas de 5 elementos;
        M[i] = grupo[(tam_grupo - 1) / 2]; 
        free(grupo);
    }

    // 5. m = seleção(|M|/2, M);
    int k_mediana = num_grupos / 2;
    if (num_grupos % 2 != 0) k_mediana++; // Equivalente a teto
    
    int m = selecao_linear(k_mediana, M, num_grupos);
    free(M);

    // 6. Sejam L1, L2 e L3 as sublistas (menores, iguais e maiores do que m);
    int *L1 = (int*)malloc(n * sizeof(int));
    int *L2 = (int*)malloc(n * sizeof(int));
    int *L3 = (int*)malloc(n * sizeof(int));
    int t1 = 0, t2 = 0, t3 = 0;

    for (int i = 0; i < n; i++) {
        if (A[i] < m) L1[t1++] = A[i];
        else if (A[i] == m) L2[t2++] = A[i];
        else L3[t3++] = A[i];
    }

    int resultado;
    // 7. Se |L1| >= k então devolva seleção(k, L1)
    if (t1 >= k) {
        resultado = selecao_linear(k, L1, t1);
    } 
    // 8. senão Se (|L1| + |L2|) >= k então devolva m
    else if ((t1 + t2) >= k) {
        resultado = m;
    } 
    // 9. senão devolva seleção(k - |L1| - |L2|, L3)
    else {
        resultado = selecao_linear(k - t1 - t2, L3, t3);
    }

    free(L1); free(L2); free(L3);
    return resultado;
}