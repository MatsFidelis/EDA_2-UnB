#include <stdio.h>
#include <stdlib.h>

typedef struct {
int *tb;
int M;
int N;
} TH;

int aumentaTamanho (int M);

int funcao_hash (TH *h, int chave) {
    int M = h->M;
    return chave % M;
}

int checar_duplicadas (TH *h, int ch){
    int id = funcao_hash(h, ch);

    for(int i = 0; i <= h->M - 1; i++){                             // Percorre toda a lista (M) e ve se tem itens com o msm valor da minha chave
        if(h->tb[id] == ch){
            return 1;
        }
    }
    return 0;
}

void inicializaNovaTabela(TH *h) {
    for(int i = 0; i <= h->M; i++) {                                // Posso utilizar o M ao inves do M - 1, por ser uma variavel, o valor de M é o total de posicoes da tabela
        if(h->tb[i] == 0) {
            h->tb[i] = -1;
        }
    }
}

void THinsere (TH *h, int ch){
    int id = funcao_hash(h, ch);

    if(checar_duplicadas(h, ch) == 1){
        return;
    }

    if(h->N > h->M / 2){                                            // Se a tabela estive com a ocupacao limite, ela vai aumentar o tamanho, e realocar tudo
        h->M = aumentaTamanho(h->M);                                // Atualiza o tamanho da tabela hash (M) a partir da funcao aumentaTamanho
        h->tb = (int *) realloc(h->tb, h->M * sizeof(int));         // Realoca a tabela hash com o novo tamanho de M (gerado pela funcao aumentaTamanho)

        inicializaNovaTabela(h);                                    // Depois do realloc, aonde tiver 0, muda para -1 (simbolo de vazio)

        for(int i = 0; i <= h->M; i++){                             // Retirando as chaves, e inserindo novamente
            if(h->tb[i] != -1){
                int realloc_hash = h->tb[i];                        // Guardo o valor da chave
                THremove (h,h->tb[i]);                              // Retiro a chave
                THinsere (h, realloc_hash);                         // Insiro a chave novamente
            }
        }
        THinsere(h, ch);
        return;
    }
    
    while(h->tb[id] != -1){
        id = (id + 1) % h->M;
    }
    h->tb[id] = ch;
    h->N++;
}

int THremove (TH *h, int ch){
    int id = funcao_hash(h, ch);

    if(h->tb[id] == -1){                                            // Ja deletado || Nao alocado
        return -1;
    }
    
    while(h->tb[id] != -1){                                         // No indice tem um valor, mas nao é o que eu quero, e ainda nao cheguei a um elemento vazio (-1)
        if(h->tb[id] == ch){                                        // Encontrei minha chave na posicao certa
            h->tb[id] = -1;
            h->N--;                                                 // Reduzo o valor de N (numero de chaves na lista)
            
            for(int i = 0; i <= h->M; i++){                         // Retirar chaves e realoc
                int realloc_hash = h->tb[i];
                h->tb[i] = -1;
                h->N--;
                THinsere (h, realloc_hash);
            }
            return 0;
        }
        id = (id + 1) % h->M;                                       // Aumento o id, para ir para o proximo elemento
    }
    return -1;
}

int THbusca (TH *h, int ch){
    int id = funcao_hash(h, ch);

    if(h->tb[id] == ch){                                            // Pesquisei e minha chave esta na posicao certa
        return 1;
    }

    while(h->tb[id] != -1){                                         // No indice tem um valor, mas nao é o que eu quero, e ainda nao cheguei a um elemento vazio (-1)
        if(h->tb[id] == ch){
            return 1;
        }
        id = (id + 1) % h->M;
    }
    return 0;
}
