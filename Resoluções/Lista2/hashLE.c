#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

typedef struct {
    celula *tb;
    int M; /* Tamanho */
    int N; /* Chabes presentes */
} TH;

int hashPosition(int ch, int m) {
    return ch % m;
}


void THinsere (TH *h, int ch) {
    int position = hashPosition(ch, h->M);
    celula *nova = (celula*) malloc(sizeof(celula));
    nova->dado = ch;
    
    if (h->tb[position].prox == NULL) {
        nova->prox = NULL;
        h->tb[position].prox = nova;
    } else {
        nova->prox = h->tb[position].prox;
        h->tb[position].prox = nova;
    }

    h->N = h->N + 1;
}

int THremove (TH *h, int ch) {
    celula *pAnt, *pPost;

    int position = hashPosition(ch, h->M);

    pAnt = h->tb[position].prox;

    int i = 0;
    while(i <= h->N) {
        if(pAnt->prox->dado == ch) {
            pPost = pAnt->prox->prox;
            free(pAnt->prox);
            pAnt->prox = pPost;
            h->N = h->N - 1;

            return 0;
        }
        pAnt = pAnt->prox;
        i++;
    }

    return -1;
}

int THbusca (TH *h, int ch) {
    int position = hashPosition(ch, h->M);

    celula *aux = &h->tb[position];

    for(int i = 0; i <= h->N; i++) {
        if(aux->prox->dado == ch) {
            return 1;
        }
        aux = aux->prox;
    }

    return 0;
}