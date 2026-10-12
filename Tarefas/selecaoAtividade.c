#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int s;
    int t;
} Atividade;

int comparar(const void *a, const void *b) {
    return ((Atividade *)a)->t - ((Atividade *)b)->t;
}

void seleciona_atividades(int s[], int t[], int n) {
    Atividade ativ[100];
    for (int i = 0; i < n; i++) {
        ativ[i].id = i;
        ativ[i].s = s[i];
        ativ[i].t = t[i];
    }

    qsort(ativ, n, sizeof(Atividade), comparar);

    int A[100];
    int A_size = 0;
    
    A[A_size++] = ativ[0].id;
    int j = 0;

    for (int i = 1; i < n; i++) {
        if (ativ[i].s >= ativ[j].t) {
            A[A_size++] = ativ[i].id;
            j = i;
        }
    }

    for (int i = 0; i < A_size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int s[] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
    int t[] = {4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
    int n = sizeof(s) / sizeof(s[0]);
    
    seleciona_atividades(s, t, n);
    
    return 0;
}