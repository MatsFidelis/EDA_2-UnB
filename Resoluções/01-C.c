#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validaSigla(char nome[], char sigla[]){

    int lenNome = strlen(nome);
    int lenSigla = strlen(sigla);
    int i = 0, j = 0;       // contadores : i para o nome e j para a sigla

    if(sigla[2] == 'X'){     // Se meu terceiro digito for 'X', desconsidero o terceiro caractere
        lenSigla = 2;
    }

    while(i < lenNome && j < lenSigla){     // condição para percorrer todo o tamanho da string
        if (toupper(nome[i]) == sigla[j]){  // Se o caractere do nome for igual ao caractere da sigla, toupper para transformar em maiúsculo
            j++;                            // incremento o contador da sigla
        }
        i++;                                // incremento o contador do nome
    }

    return j == lenSigla;                   // Se o contador da sigla for igual ao tamanho da sigla, retorna 1, senão retorna 0

}

int main(){

    char nome[100001];     // vetor que armazena o nome
    char sigla [4];     // vetor que armazena a sigla

    scanf("%s", nome);
    scanf("%s", sigla);

    if (validaSigla(nome, sigla)){
        printf("Sim\n");
    }
    else{
        printf("Nao\n");
    }

    return 0;
}
