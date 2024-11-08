#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
} Celula;

//Procedimento para inserir no INICIO da LE
void insere_le(Celula **lista, int num){
    Celula *novo = malloc(sizeof(Celula));

    if(novo){                                               //Se *novo foi devidamente alocado na memoria
        novo->dado = num;                                   //Coloco o valor desejado na minha celula 'novo'
        novo->prox = *lista;                                //Indico o ponteiro para aonde deve ser alocado meu valor
        *lista = novo;                                      //O inicio da LE recebe o valor alocado na celula 'novo
        printf("Inserido %d\n", num);
    }
    else{
        printf("Erro ao alocar memoria! \n");
    }
}

//Procedimento para inserir um elemento no MEIO da LE
void insere_meio(Celula **lista, int num, int ant){
    Celula *aux, *novo = malloc(sizeof(Celula));            //Crio uma celula auxiliar, que pode ser usado para alterações, sem afetar o ponteiro inicial da *lista

    if(novo){
        novo->dado = num;

        if(*lista == NULL){                                 //Faco primeiro a verificacao se minha LE esta vazia
            novo->prox = NULL;                              //Se ela estiver, ja direciono meu prox para NULL
            *lista = novo;                                  //E realizo a alocacao do meu valor na LE
        }
        else{
            aux = *lista;                                   //Indico para minha celula auxiliar, qual endereco ela ira utilizar
            while (aux->dado != ant && aux->prox){          //Percorro os valores enquanto eu nao achar o dado anterior, e nem alcancar o fim da LE
                aux = aux->prox;
            }
            novo->prox = aux->prox;                         //Realizo a devida alocacao dos ponteiros, onde meu 'novo' recebe os valores q estavam na celula auxiliar
            aux->prox = novo;                               //E por fim, realizo a alocacao do valor no seu lugar devido
            printf("Inserido %d\n", num);
        }
    }
    else{
        printf("Erro ao alocar memoria! \n");
    }
}

//Procedimento para inserir no FIM da LE
void insere_fim(Celula **lista, int num){                   //'**lista' ponteiro de ponteiro, estou indicando o endereco da minha variavel *lista na main
    Celula *aux, *novo = malloc(sizeof(Celula));

    if(novo){
        novo->dado = num;
        novo->prox = NULL;

        if(*lista == NULL){
            *lista = novo;
        }
        else{
            aux = *lista;
            while(aux->prox){                               //Percorro minha LE enquanto eu nao alcancar o fim dela
                aux = aux->prox;
            }
            aux->prox = novo;
            printf("Inserido %d\n", num);
        }
    }
    else{
        printf("Erro ao alocar memoria! \n");
    }
}

//Procedimento para inserir de forma ordenada na LE ~ta quebrado~
void insere_ordenado(Celula **lista, int num){
    Celula *aux, *novo = malloc(sizeof(Celula));

    if(novo){
        novo->dado = num;

        if(*lista == NULL){
            novo->prox = NULL;
            *lista = novo;
            printf("Inserido %d\n", num);
        }
        else if(novo->dado < (*lista)->dado){
            novo->prox = *lista;
            *lista = novo;
            printf("Inserido %d\n", num);
        }
        else{
            aux = *lista;
            while(aux->prox && aux->dado > aux->prox->dado){
                aux = aux->prox; 
            }
            novo->prox = aux->prox;
            aux->prox = novo;
            printf("Inserido %d\n", num);
        }
    }
    else{
        printf("Erro ao alocar memoria! \n");
    }
}

// Função para imprimir a lista
void imprime_lista(Celula *lista) {
    Celula *atual = lista;

    if(atual == NULL){
        printf("NULL\n");
        return;
    }

    printf("Estado atual da lista: ");
    while (atual) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}

int main(){
    Celula *lista = NULL;

    // Insere alguns elementos
    insere_le(&lista, 10);
    imprime_lista(lista);

    insere_le(&lista, 20);
    imprime_lista(lista);

    insere_le(&lista, 30);
    imprime_lista(lista);


    insere_le(&lista, 40);
    imprime_lista(lista);

    insere_fim(&lista, 5);
    imprime_lista(lista);

    insere_fim(&lista, 1);
    imprime_lista(lista);

    insere_meio(&lista, 15, 20);
    imprime_lista(lista);

    insere_ordenado(&lista, 42);
    imprime_lista(lista);

    return 0;
}