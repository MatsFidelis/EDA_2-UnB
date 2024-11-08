#include <stdio.h>
#include <string.h>

void converterParaRomano(int numero, char* romano){

    int valores[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};                         // valores dos algarismos romanos
    char* simbolos[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};     // símbolos dos algarismos romanos

    int i = 0;          // contador
    romano[0] = '\0';   // inicializa a string vazia

    while(numero > 0 ){                     // laço que converte o número em algarismos romanos
        while (numero >= valores[i]){       // laço que verifica se o número é maior ou igual ao valor do algarismo romano
            numero -= valores[i];           
            strcat(romano, simbolos[i]);    // concatena o algarismo romano na string
        }
        i++;
    }
}

int main(){

    int n, i;           // n = quantidade de números a serem convertidos, i = contador
    scanf("%d", &n);    // lê a quantidade de números a serem convertidos

    int numeros[n];     // vetor que armazena os números a serem convertidos

    for(i = 0; i < n; i++){         // laço que lê e armazena os números a serem convertidos
        scanf("%d", &numeros[i]);
    }

    for(i = 0; i < n; i++) {                        // laço que converte e imprime os números em algarismos romanos
        char romano[100];                           // vetor que armazena os algarismos romanos
        converterParaRomano(numeros[i], romano);        
        printf("%s\n", romano);
    }

    return 0;

}