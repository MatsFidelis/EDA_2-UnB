#include <stdio.h>
#include <string.h>

void construirPosfixo(char *prefixo, char *infixo, int n, char *posfixo, int *indice) {
    if (n <= 0) {
        return;
    }

    char raiz = prefixo[0];
    int posRaiz = strchr(infixo, raiz) - infixo;

    construirPosfixo(prefixo + 1, infixo, posRaiz, posfixo, indice);
    construirPosfixo(prefixo + 1 + posRaiz, infixo + posRaiz + 1, n - posRaiz - 1, posfixo, indice);

    posfixo[(*indice)++] = raiz;
}

int main() {
    int casos;
    scanf("%d", &casos);

    while (casos--) {
        int n;
        char prefixo[53], infixo[53], posfixo[53];
        int indice = 0;

        scanf("%d %s %s", &n, prefixo, infixo);
        construirPosfixo(prefixo, infixo, n, posfixo, &indice);

        posfixo[indice] = '\0';
        printf("%s\n", posfixo);
    }

    return 0;
}
