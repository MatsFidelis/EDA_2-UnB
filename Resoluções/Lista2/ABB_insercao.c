#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

no *inserir(no *r, int x) {
    if (r == NULL) { // Se a árvore estiver vazia, cria o nó
        no *novo = (no *)malloc(sizeof(no));
        novo->chave = x;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo; // Retorna o novo nó como a raiz
    }

    // Verifica duplicatas e segue para a subárvore apropriada
    if (x < r->chave) {
        r->esq = inserir(r->esq, x);
    } else if (x > r->chave) {
        r->dir = inserir(r->dir, x);
    }
    // Se x == r->chave, não faz nada (não insere duplicatas)

    return r; // Retorna a raiz da árvore
}
