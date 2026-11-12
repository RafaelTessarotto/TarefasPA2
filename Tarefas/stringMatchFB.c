#include <stdio.h>
#include <string.h>

int forca_bruta(char T[], char P[]) {
    int n = strlen(T);
    int m = strlen(P);
    int c = 0;
    
    for (int s = 0; s <= n - m; s++) {
        int j = 0;
        
        while (j < m && P[j] == T[s + j]) {
            j++;
        }
        
        if (j == m) {
            printf("Forca Bruta: Padrao encontrado com deslocamento: %d\n", s);
            c++;
        }
    }
    
    return c;
}

int main() {
    char T[] = "abracadabra";
    char P[] = "bra";
    
    printf("Texto: %s\n", T);
    printf("Padrao: %s\n\n", P);
    
    int ocorrencias = forca_bruta(T, P);
    printf("Total de ocorrencias: %d\n", ocorrencias);
    
    return 0;
}