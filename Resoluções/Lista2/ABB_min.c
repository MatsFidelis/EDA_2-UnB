#include <stdio.h>

typedef struct no {
    int chave;
    struct no *esq, *dir;
} no ;

no *minimo (no *r){
    no *aux = malloc(sizeof(no));
    
    if(r == NULL){
        return NULL;
    }
    while (r->esq != NULL){
        r = r->esq;
        aux = r;    
    }
    return aux;
}