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

// Algoritmo de backtracking para gerar sequências com repetição
void mostra_sequencias(vector<int>& s, int i, const vector<int>& v, int m, int n) {
    if (i == m) { 
        imprime_solucao(s);
    } else {
        for (int j = 0; j < n; j++) {
            s[i] = v[j];
            mostra_sequencias(s, i + 1, v, m, n);
        }
    }
}

int main() {
    cout << "=== Sequencias (v tamanho 4, s tamanho 3) ===\n";
    
    vector<int> v = {1, 2, 3, 4}; // Vetor de entrada (4 elementos)
    vector<int> s(3);             // Vetor solução de tamanho 3
    
    mostra_sequencias(s, 0, v, 3, 4);
    
    return 0;
}