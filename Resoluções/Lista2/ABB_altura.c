#include <stdio.h>

typedef struct no {
    int chave;
    struct no *esq, *dir;
} no ;

no *altura (no *r){
    
    if(r != NULL){
        int altura_esq = altura(r->esq);
        int altura_dir = altura(r->dir);

        if(altura_esq > altura_dir){
            return altura_esq + 1;
        }else{
            return altura_dir + 1;
        }

        return 0;
   }
   
}