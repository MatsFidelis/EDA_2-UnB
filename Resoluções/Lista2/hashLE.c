#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

typedef struct {
    celula *tb;
    int M; /* Tamanho */
    int N; /* Chaves presentes */
} TH;

int hashPosition(int ch, int m) {
    return ch % m;
}

void THinsere(TH *h, int ch) {
    int position = hashPosition(ch, h->M);

    // Verifica se o elemento já está na lista
    celula *aux = h->tb[position].prox;
    while (aux != NULL) {
        if (aux->dado == ch) {
            return; // Não insere duplicados
        }
        aux = aux->prox;
    }

    // Insere no início da lista
    celula *nova = (celula *)malloc(sizeof(celula));
    nova->dado = ch;
    nova->prox = h->tb[position].prox;
    h->tb[position].prox = nova;

    h->N += 1;
}

int THremove(TH *h, int ch) {
    int position = hashPosition(ch, h->M);
    celula *ant = &h->tb[position];
    celula *atual = ant->prox;

    while (atual != NULL) {
        if (atual->dado == ch) {
            ant->prox = atual->prox;
            free(atual);
            h->N -= 1;
            return 0; // Remoção bem-sucedida
        }
        ant = atual;
        atual = atual->prox;
    }

    return -1; // Chave não encontrada
}

int THbusca(TH *h, int ch) {
    int position = hashPosition(ch, h->M);
    celula *aux = h->tb[position].prox;

    while (aux != NULL) {
        if (aux->dado == ch) {
            return 1; // Chave encontrada
        }
        aux = aux->prox;
    }

    return 0; // Chave não encontrada
}
