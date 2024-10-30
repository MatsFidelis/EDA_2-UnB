#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void imprime (celula *le);
void imprime_rec (celula *le);

void imprime (celula *le){
    if (le->prox == NULL){
        printf("NULL\n");
        return;
    }

    celula *atual = le->prox;

    while (atual != NULL) {
        printf("%d", atual->dado);
        if (atual->prox != NULL) {
            printf(" -> ");
        }
        atual = atual->prox;
    }

    printf(" -> NULL\n");

}

void imprime_rec(celula *le) {
    if (le == NULL) {
        printf("NULL\n");
        return;
    }

    if (le->prox == NULL) {
        printf("NULL\n");
        return;
    }

    printf("%d -> ", le->prox->dado);
    imprime_rec(le->prox);
}
