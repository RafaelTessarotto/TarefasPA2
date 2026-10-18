#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 256

// Tabela para armazenar os códigos gerados (256 caracteres ASCII possíveis)
char codigos[256][MAX_TREE_HT];

// ==========================================
// 1. ESTRUTURAS DE DADOS (Árvore e Min-Heap)
// ==========================================
struct NoHuffman {
    char data;
    unsigned freq;
    struct NoHuffman *esq, *dir;
};

struct MinHeap {
    unsigned tamanho;
    unsigned capacidade;
    struct NoHuffman** array;
};

// Cria um novo nó da árvore
struct NoHuffman* novoNo(char data, unsigned freq) {
    struct NoHuffman* temp = (struct NoHuffman*)malloc(sizeof(struct NoHuffman));
    temp->esq = temp->dir = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

// Cria a Fila de Prioridades (Min-Heap)
struct MinHeap* criaMinHeap(unsigned capacidade) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->tamanho = 0;
    minHeap->capacidade = capacidade;
    minHeap->array = (struct NoHuffman**)malloc(minHeap->capacidade * sizeof(struct NoHuffman*));
    return minHeap;
}

void trocaNo(struct NoHuffman** a, struct NoHuffman** b) {
    struct NoHuffman* t = *a;
    *a = *b;
    *b = t;
}

// Mantém a propriedade do Min-Heap
void minHeapify(struct MinHeap* minHeap, int idx) {
    int menor = idx;
    int esq = 2 * idx + 1;
    int dir = 2 * idx + 2;

    if (esq < minHeap->tamanho && minHeap->array[esq]->freq < minHeap->array[menor]->freq)
        menor = esq;

    if (dir < minHeap->tamanho && minHeap->array[dir]->freq < minHeap->array[menor]->freq)
        menor = dir;

    if (menor != idx) {
        trocaNo(&minHeap->array[menor], &minHeap->array[idx]);
        minHeapify(minHeap, menor);
    }
}

// Extrai o nó com menor frequência (Extrai-Min)
struct NoHuffman* extraiMin(struct MinHeap* minHeap) {
    struct NoHuffman* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->tamanho - 1];
    --minHeap->tamanho;
    minHeapify(minHeap, 0);
    return temp;
}

// Insere um nó no Min-Heap (Insere)
void insereMinHeap(struct MinHeap* minHeap, struct NoHuffman* minHeapNode) {
    ++minHeap->tamanho;
    int i = minHeap->tamanho - 1;

    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

// Constrói o MinHeap inicial
void constroiMinHeap(struct MinHeap* minHeap) {
    int n = minHeap->tamanho - 1;
    for (int i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

// ==========================================
// 2. CONSTRUÇÃO DA ÁRVORE DE HUFFMAN
// ==========================================
struct NoHuffman* constroiArvoreHuffman(char data[], int freq[], int tamanho) {
    struct NoHuffman *esq, *dir, *topo;
    struct MinHeap* minHeap = criaMinHeap(tamanho);

    for (int i = 0; i < tamanho; ++i)
        minHeap->array[i] = novoNo(data[i], freq[i]);

    minHeap->tamanho = tamanho;
    constroiMinHeap(minHeap);

    // Algoritmo Guloso: Junta os dois menores até sobrar 1
    while (minHeap->tamanho != 1) {
        esq = extraiMin(minHeap);
        dir = extraiMin(minHeap);

        // O nó interno recebe um caractere nulo '$' e a soma das frequências
        topo = novoNo('$', esq->freq + dir->freq);
        topo->esq = esq;
        topo->dir = dir;

        insereMinHeap(minHeap, topo);
    }
    return extraiMin(minHeap); // Retorna a raiz da árvore
}

// ==========================================
// 3. GERAÇÃO DOS CÓDIGOS E COMPACTAÇÃO
// ==========================================
// Percorre a árvore: Esquerda = 0, Direita = 1
void armazenaCodigos(struct NoHuffman* raiz, int arr[], int topo) {
    if (raiz->esq) {
        arr[topo] = 0;
        armazenaCodigos(raiz->esq, arr, topo + 1);
    }
    if (raiz->dir) {
        arr[topo] = 1;
        armazenaCodigos(raiz->dir, arr, topo + 1);
    }
    if (!(raiz->esq) && !(raiz->dir)) {
        char buffer[MAX_TREE_HT];
        for (int i = 0; i < topo; ++i) {
            buffer[i] = arr[i] ? '1' : '0';
        }
        buffer[topo] = '\0';
        strcpy(codigos[(unsigned char)raiz->data], buffer);
    }
}

// ==========================================
// 4. DESCOMPACTAÇÃO
// ==========================================
void descompacta(struct NoHuffman* raiz, char* textoCompactado) {
    struct NoHuffman* atual = raiz;
    for (int i = 0; textoCompactado[i] != '\0'; i++) {
        if (textoCompactado[i] == '0')
            atual = atual->esq;
        else
            atual = atual->dir;

        // Se chegou numa folha, achou o caractere
        if (atual->esq == NULL && atual->dir == NULL) {
            printf("%c", atual->data);
            atual = raiz; // Volta para a raiz para buscar o próximo
        }
    }
    printf("\n");
}

// ==========================================
// 5. MAIN PARA TESTES
// ==========================================
int main() {
    // Texto que simula o conteúdo de um arquivo
    char textoOriginal[] = "estrutura de dados avulsa eh muito legal";
    printf("Texto Original: %s\n", textoOriginal);
    
    // 1. Calcula a frequência de cada caractere
    int frequenciasGlobais[256] = {0};
    for (int i = 0; textoOriginal[i] != '\0'; i++) {
        frequenciasGlobais[(unsigned char)textoOriginal[i]]++;
    }
    
    // Filtra apenas os caracteres que apareceram
    char data[256];
    int freq[256];
    int tamanho = 0;
    for (int i = 0; i < 256; i++) {
        if (frequenciasGlobais[i] > 0) {
            data[tamanho] = (char)i;
            freq[tamanho] = frequenciasGlobais[i];
            tamanho++;
        }
    }

    // 2. Constrói a árvore de Huffman
    struct NoHuffman* raiz = constroiArvoreHuffman(data, freq, tamanho);

    // 3. Gera os códigos para a tabela
    int arr[MAX_TREE_HT], topo = 0;
    armazenaCodigos(raiz, arr, topo);

    // Imprime o dicionário (Opcional, para debug)
    printf("\n--- Dicionario de Huffman ---\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Caractere '%c' | Frequencia %d | Codigo: %s\n", data[i], freq[i], codigos[(unsigned char)data[i]]);
    }

    // 4. Compactador (Transforma o texto em '0's e '1's)
    char textoCompactado[10000] = "";
    for (int i = 0; textoOriginal[i] != '\0'; i++) {
        strcat(textoCompactado, codigos[(unsigned char)textoOriginal[i]]);
    }
    
    printf("\n--- COMPACTACAO ---\n");
    printf("Texto em binario comprimido:\n%s\n", textoCompactado);

    // 5. Descompactador (Lê os '0's e '1's e devolve o texto)
    printf("\n--- DESCOMPACTACAO ---\n");
    printf("Texto restaurado: ");
    descompacta(raiz, textoCompactado);

    return 0;
}