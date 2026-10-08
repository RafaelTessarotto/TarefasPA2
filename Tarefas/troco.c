#include <stdio.h>

int troco (int C[], int tamanho_C, int valor, int S[]);
void print_vetor (int V[], int tamanho_V);

int main(){
    int C[] = {5,2,1}; //conjunto C(Valores das Moedas) ordenado de forma decrescente
    int valor = 12; //int valor = valor do troco 
    int S[50]; //vetor S = solucao
    int tamanho_C = sizeof(C)/sizeof(C[0]);

    int tamanho_S = troco(C, tamanho_C, valor, S);
    print_vetor(S, tamanho_S);

    printf("Tamanho do vetor solucao: %i\n", tamanho_S);
}

int troco (int C[], int tamanho_C, int valor, int S[]){
    int indice_S = 0; //index para adicionar valor em vetor S
    int soma = 0; //soma para diminuir o valor
    int indice_C = 0;

    while (indice_C < tamanho_C && soma < valor){
        int m = C[indice_C];//pega primeiro valor de C

        //verifica se troco possivel e guarda ele no vetor solucao
        if (soma + m <= valor){
            soma = soma + m;
            S[indice_S] = m;//copia valor de moeda pra S
            indice_S++; //pula pra proxima posicao de S
        }
        //se o valor da moeda for muito alto pra troco
        else{
            indice_C++;//vai pro proximo valor de C
        }
    }

    //quando troco chegar em valor retorna solucao
    if (soma == valor){
        return indice_S;
    }
    return -1; // Retorna -1 se não for possível dar o troco
}

void print_vetor (int V[], int tamanho_V){
    printf("Vetor Solucao: ");
    for (int i = 0; i < tamanho_V; i++){
        printf("%i ", V[i]);
    }
    printf("\n");
}