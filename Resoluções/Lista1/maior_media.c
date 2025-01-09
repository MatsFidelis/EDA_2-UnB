#include <stdio.h>
#include <string.h>

int media (int vetor[], int tamanho) {
    int media;
    int soma = 0;
    int i;

    for(i = 0; i < tamanho; i++){
        soma += vetor[i];
    }
    media = soma/tamanho;
    return media;
}

int compara_maior (int vetor[], int tamanho, int media) {
    int maior_media[tamanho];
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i]>media) {
            maior_media[vetor[i]];
        }
    }
    return *maior_media;
}


int main(){
    int tamanho;
    scanf("%d", &tamanho);
    int vetor[tamanho];
    int resultado;
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }
    resultado = media(vetor, tamanho);
    //printf("%d\n", resultado);
    int maiores[] = compara_maior(vetor, tamanho, resultado);
    printf("%ls\n", maiores);
}