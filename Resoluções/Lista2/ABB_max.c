#include <stdio.h>

typedef struct no {
    int chave;
    struct no *esq, *dir;
} no ;

no *maximo (no *r){
    no *aux = malloc(sizeof(no));
    
    if(r == NULL){
        return NULL;
    }
    while (r->dir != NULL){
        r = r->dir;
        aux = r;    
    }
    return aux;
}