#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASH_SIZE 1048576

typedef struct Node {
    char alimento[21];
    struct Node *next;
} Node;

typedef struct {
    long col_id;
    Node *alimentos;
    struct Formigueiro *next;
} Formigueiro;

Formigueiro *hashTable[HASH_SIZE];

unsigned int hash(long col_id) {
    return col_id % HASH_SIZE;
}

Formigueiro *findColonia(long col_id) {
    unsigned int idx = hash(col_id);
    Formigueiro *colonia = hashTable[idx];
    while (colonia) {
        if (colonia->col_id == col_id) {
            return colonia;
        }
        colonia = colonia->next;
    }
    return NULL;
}

Node *findAlimento(Node *head, const char *alimento) {
    while (head) {
        if (strcmp(head->alimento, alimento) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void addAlimento(long col_id, const char *alimento) {
    unsigned int idx = hash(col_id);
    Formigueiro *colonia = findColonia(col_id);

    if (!colonia) {
        colonia = (Formigueiro *)malloc(sizeof(Formigueiro));
        colonia->col_id = col_id;
        colonia->alimentos = NULL;
        colonia->next = hashTable[idx];
        hashTable[idx] = colonia;
    }

    if (findAlimento(colonia->alimentos, alimento)) {
        printf("%ld\n", col_id);
        return;
    }

    Node *novo = (Node *)malloc(sizeof(Node));
    strcpy(novo->alimento, alimento);
    novo->next = colonia->alimentos;
    colonia->alimentos = novo;
}

void liberarMemoria() {
    for (int i = 0; i < HASH_SIZE; i++) {
        Formigueiro *colonia = hashTable[i];
        while (colonia) {
            Node *atual = colonia->alimentos;
            while (atual) {
                Node *temp = atual;
                atual = atual->next;
                free(temp);
            }
            Formigueiro *tempColonia = colonia;
            colonia = colonia->next;
            free(tempColonia);
        }
    }
}

int main() {
    long col_id;
    char alimento[21];

    while (scanf("%ld %s", &col_id, alimento) != EOF) {
        addAlimento(col_id, alimento);
    }

    liberarMemoria();
    return 0;
}
