#include <stdio.h>

// Função para imprimir o estado atual do vetor
void imprimeVetor(int *V, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");
}

// Função para trocar dois elementos
void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particiona (int *V, int e, int d){

    int i, pivo = V[e], pos = d+1;

    for(i = d; i >= e; i--){
        if(V[i] >=pivo)
        troca(&V[i], &V[--pos]);
    }
    return pos;
}

void quicksort (int *V, int e, int d, int tamanho){
    if(e <= d){
        int p = particiona (V,e,d);

        // Exibe o vetor após particionar
        printf("Particionado com pivô %d: ", V[p]);
        imprimeVetor(V, tamanho);

        quicksort(V,e,p-1, tamanho);
        quicksort(V,p+1,d, tamanho);
    }
}

int main() {
    // int V[] = {9, 3, 7, 5, 6, 4, 8, 2};
    int V[] = {13, 19, 9, 5, 12};
    int tamanho = sizeof(V) / sizeof(V[0]);

    printf("Vetor original:\n");
    imprimeVetor(V, tamanho);

    quicksort(V, 0, tamanho - 1, tamanho);

    printf("Vetor ordenado:\n");
    imprimeVetor(V, tamanho);

    return 0;
}