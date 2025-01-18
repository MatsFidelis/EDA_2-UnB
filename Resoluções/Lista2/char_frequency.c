#include <stdio.h>
#include <string.h>

#define MAX_ASCII 256

void calcularFrequencia(char *linha) {
    int frequencia[MAX_ASCII] = {0};

    // Conta a frequência de cada caractere
    for (int i = 0; linha[i] != '\0'; i++) {
        frequencia[(unsigned char)linha[i]]++;
    }

    // Imprime os caracteres e suas frequências em ordem crescente de frequência
    for (int freq = 1; freq <= 1000; freq++) {
        for (int i = 0; i < MAX_ASCII; i++) {
            if (frequencia[i] == freq) {
                printf("%d %d\n", i, frequencia[i]);
            }
        }
    }
    printf("\n");
}

int main() {
    char linha[1001];

    while (fgets(linha, sizeof(linha), stdin) != NULL) {
        linha[strcspn(linha, "\n")] = '\0'; // Remove o caractere de nova linha
        calcularFrequencia(linha);
    }

    return 0;
}
