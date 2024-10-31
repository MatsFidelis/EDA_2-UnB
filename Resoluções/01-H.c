#include <stdio.h>

int main(){

    float D, notas[7];
    scanf("%f", &D);

    for (int i = 0; i < 7; i++){
        scanf("%f", &notas[i]);
    }

    float maiorNota = notas[0], menorNota = notas[0];
    float soma = 0.0;

    for(int i = 0; i < 7; i++){
        if(notas[i] > maiorNota)
            maiorNota = notas[i];
        if(notas[i] < menorNota)
            menorNota = notas[i];
        soma += notas[i];
    }

    soma -= (maiorNota + menorNota);
    soma = (soma/5) * D;
    printf("%.1f\n", soma);

    return 0;
}