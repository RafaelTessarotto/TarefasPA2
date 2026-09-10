#include <iostream>
#include <vector>

using namespace std;

// Função auxiliar para imprimir o vetor solução
void imprime_solucao(const vector<int>& s) {
    cout << "{ ";
    for (int i = 0; i < s.size(); i++) {
        cout << s[i];
        if (i < s.size() - 1) cout << ", ";
    }
    cout << " }\n";
}

// Algoritmo de backtracking para gerar permutações (sem repetição)
void mostra_permutacoes(vector<int>& s, int i, const vector<int>& v, int n, vector<bool>& usados) {
    if (i == n) {
        imprime_solucao(s);
    } else {
        for (int j = 0; j < n; j++) {
            // Só utiliza o elemento se ele ainda não estiver na solução atual
            if (!usados[j]) {
                s[i] = v[j];
                usados[j] = true; // Marca como usado
                
                mostra_permutacoes(s, i + 1, v, n, usados);
                
                usados[j] = false; // Backtracking: desmarca para a próxima iteração
            }
        }
    }
}

int main() {
    cout << "=== Permutacoes (v tamanho 3) ===\n";
    
    vector<int> v = {1, 2, 3};     // Vetor de entrada
    vector<int> s(3);              // Vetor solução
    vector<bool> usados(3, false); // Vetor para controle de elementos já utilizados
    
    mostra_permutacoes(s, 0, v, 3, usados);
    
    return 0;
}