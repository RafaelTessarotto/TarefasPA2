#include <stdio.h>

void salto_sapo(int p[], int n, int delta) {
    int u[100];
    int u_size = 0;
    
    u[u_size++] = p[0];
    int ultima_pos = p[0];

    for (int i = 1; i < n; i++) {
        if (p[i] - ultima_pos > delta) {
            ultima_pos = p[i - 1];
            
            int existe = 0;
            for (int k = 0; k < u_size; k++) {
                if (u[k] == p[i - 1]) existe = 1;
            }
            if (!existe) {
                u[u_size++] = p[i - 1];
            }
        }
    }

    int existe = 0;
    for (int k = 0; k < u_size; k++) {
        if (u[k] == p[n - 1]) existe = 1;
    }
    if (!existe) {
        u[u_size++] = p[n - 1];
    }

    for (int i = 0; i < u_size; i++) {
        printf("%d ", u[i]);
    }
    printf("\n");
}

int main() {
    int p[] = {0, 3, 4, 7, 10, 14, 15};
    int n = sizeof(p) / sizeof(p[0]);
    int delta = 4;
    
    salto_sapo(p, n, delta);
    
    return 0;
}