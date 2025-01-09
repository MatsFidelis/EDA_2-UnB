#include <stdio.h>

int main() {
    float D;
    float notas[7];
    scanf("%f", &D);

    for (int i = 0; i < 7; i++) {
        scanf("%f", &notas[i]);
    }

    float maior = notas[0], menor = notas[0];
    float soma = 0.0;

    for (int i = 0; i < 7; i++) {
        if (notas[i] > maior) maior = notas[i];
        if (notas[i] < menor) menor = notas[i];
        soma += notas[i];
    }

    soma -= (maior + menor); // remove a maior e menor nota
    float media = soma / 5.0; // media das outras
    float nota_final = media * D;
    printf("%.1f\n", nota_final);
    return 0;
}
