#include <stdio.h>
#include <string.h>

void calcular_funcao_z(char S[], int Z[]) {
    int n = strlen(S); 
    int l = 0, r = 0;  
    
    Z[0] = 0; 
    
    for (int i = 1; i < n; i++) {
        if (i > r) {
            l = i;
            r = i;
            
            while (r < n && S[r - l] == S[r]) {
                r++;
            }
            Z[i] = r - l; 
            r--;          
        } 
        
        else {
            int i_linha = i - l; 
            
            if (Z[i_linha] < r - i + 1) {
                Z[i] = Z[i_linha];
            } 
            
            else {
                l = i;
                while (r < n && S[r - l] == S[r]) {
                    r++;
                }
                Z[i] = r - l;
                r--;
            }
        }
    }
}


void casamento_padroes_Z(char T[], char P[]) {
    int m = strlen(P);
    int n = strlen(T);
    
    char S[m + n + 2];
    sprintf(S, "%s$%s", P, T);
    
    int Z[m + n + 1];
    
    calcular_funcao_z(S, Z);
    
    int encontrou = 0;
    
    for (int i = 0; i < m + n + 1; i++) {
        
        if (Z[i] == m) {
            printf("Padrao encontrado com deslocamento: %d\n", i - m - 1);
            encontrou = 1;
        }
    }
    
    if (!encontrou) {
        printf("Padrao nao encontrado no texto.\n");
    }
}

int main() {
    char T[] = "bananana";
    char P[] = "ana";
    
    printf("--- Casamento de Padroes: Algoritmo Z ---\n");
    printf("Texto: %s\n", T);
    printf("Padrao: %s\n\n", P);
    
    casamento_padroes_Z(T, P);
    
    return 0;
}