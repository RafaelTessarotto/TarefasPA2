#include <stdio.h>

int main(int argc, char const *argv[])
{

//ordenar conjunto C




//conjunto C = valores das moedas
//int valor = valor do troco
//vetor S = solucao

}

int troco (int C[], int tamanho_C, int valor, int S[]){
    int indice_S = 0; //index para adicionar valor em vetor S
    int soma = 0; //soma para diminuir o valor
    int indice_C = 0;

    while (indice_C > tamanho_C && soma < valor){
        int m = C[indice_C];//pega primeiro valro de C

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
}

void print_vetor (int V[], int tamanho_V){
    for (int i = 0, i < tamanho_V, i++){
        printf("%i", V[i]);
    }
}