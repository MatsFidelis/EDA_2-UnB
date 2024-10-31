#include <stdio.h>

int main() {
    int tamanho;

    // Leitura do tamanho do array
    scanf("%d", &tamanho);
    
    // Definição do array e leitura dos valores
    int vetor[tamanho];
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }

    // Cálculo da soma e da média
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += vetor[i];
    }
    int media = soma / tamanho;  // Média dos valores do vetor

    // Encontrar valores maiores que a média
    int maior_media[tamanho];  // Array para armazenar valores maiores que a média
    int contador = 0;  // Contador para saber quantos valores são maiores que a média

    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] > media) {
            maior_media[contador] = vetor[i];  // Armazenar valores maiores que a média
            contador++;  // Incrementa o contador
        }
    }

    // Impressão dos valores maiores que a média
    for (int i = 0; i < contador; i++) {
        printf("%lld ", maior_media[i]);
    }
    
    printf("\n");  // Nova linha ao final da saída
    return 0;
}
