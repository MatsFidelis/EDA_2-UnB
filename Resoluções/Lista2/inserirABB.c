#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *esq, *dir;
} No;

No *inserir(No *raiz, int ch) {
    if(raiz == NULL) {
        No *novoNo = (No *) malloc(sizeof(No));
        novoNo->esq = NULL;
        novoNo->dir = NULL;
        novoNo->dado = ch;

        return novoNo;
    }

    if(ch < raiz->esq) {
        raiz->esq = inserir(raiz->esq, ch);
    } else {
        raiz->dir = inserir(raiz->dir, ch);
    }

    return raiz;
}