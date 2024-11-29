#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;

typedef struct {
celula *tb;
int M;
int N;
} TH;

int checar_duplicadas (TH *h, int ch){
    int id = funcao_hash(h, ch);
    celula *aux = &h->tb[id];
    
    while(aux->prox != NULL){
        if(aux->prox->dado == ch){
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}

int funcao_hash (TH *h, int chave) {
    int M = h->M;
    return chave % M;
}

void THinsere (TH *h, int ch){
    celula *nova = (celula *) malloc(sizeof(celula));
    int id = funcao_hash(h, ch);
    
    if(checar_duplicadas(h, ch) == 1){
        return;
    }

    nova->dado = ch;
    nova->prox = h->tb[id].prox;
    
    h->tb[id].prox = nova;              // O primeiro elemento da lista é o que está na posição da tabela hash
    h->N++;
}

int THremove (TH *h, int ch){
    int id = funcao_hash(h, ch);
    celula *aux = &h->tb[id];            // Esse nó auxiliar é o que vai percorrer a lista
    celula *posterior;                  // Esse nó posterior é o que vai ficar depois do auxiliar  

    while(aux->prox != NULL){           // Enquanto o auxiliar não for o último nó e o dado do auxiliar não for o que queremos remover
        if(aux->prox->dado == ch){
            posterior = aux->prox->prox;
            free(aux->prox);
            aux->prox = posterior;
            h->N--;                     // Diminui o número de elementos da tabela hash
            return 0;
        }
        aux = aux->prox;
    }
    return -1;
}

int THbusca (TH *h, int ch){
    int id = funcao_hash(h, ch);
    celula *aux = &h->tb[id];      // &h->tb[id].prox é o primeiro elemento da lista

    while(aux->prox != NULL){
        if(aux->prox->dado == ch){
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}