#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

no *encontrarMaior(no *r) {
    while (r->dir != NULL) {
        r = r->dir;
    }
    return r;
}

no *remover(no *r, int x) {
    if (r == NULL) {
        return NULL; // Chave não encontrada
    }

    if (x < r->chave) {
        r->esq = remover(r->esq, x); // Procura na subárvore esquerda
    } else if (x > r->chave) {
        r->dir = remover(r->dir, x); // Procura na subárvore direita
    } else {
        // Caso 1: Nó folha
        if (r->esq == NULL && r->dir == NULL) {
            free(r);
            return NULL;
        }
        // Caso 2: Um filho
        if (r->esq == NULL) {
            no *temp = r->dir;
            free(r);
            return temp;
        } else if (r->dir == NULL) {
            no *temp = r->esq;
            free(r);
            return temp;
        }
        // Caso 3: Dois filhos
        no *antecessor = encontrarMaior(r->esq);
        r->chave = antecessor->chave;
        r->esq = remover(r->esq, antecessor->chave);
    }
    return r;
}
