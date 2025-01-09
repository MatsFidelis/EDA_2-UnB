#include <stdio.h>

int media(long long int vetor[], long long int tamanho) {
    long long int soma = 0;
    for(int i = 0; i < tamanho; i++){
        soma += vetor[i];
    }
    return soma / tamanho;
    
}

int compara_maior(long long int vetor[], long long int tamanho, long long int media, long long int maior_media[]) {
    int count = 0;
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] > media) {
            maior_media[count] = vetor[i];
            count++;
        }
    }
    return count;
}

int main() {
    long long int tamanho;
    scanf("%lld", &tamanho);
    long long int vetor[tamanho];

    for (int i = 0; i < tamanho; i++) {
        scanf("%lld", &vetor[i]);
    }

    long long int resultado = media(vetor, tamanho);
    long long int maior_media[tamanho];
    long long int num_maiores = compara_maior(vetor, tamanho, resultado, maior_media);

    if (num_maiores == 0) {
        printf("0\n");
    } else {
        for (int i = 0; i < num_maiores; i++) {
            printf("%lld ", maior_media[i]);
        }
        printf("\n");
    }

    return 0;
}
