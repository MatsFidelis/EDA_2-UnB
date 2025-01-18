#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORD_LEN 16
#define HASH_SIZE 65536

typedef struct Node {
    char palavra[MAX_WORD_LEN + 1];
    int count;
    struct Node *next;
} Node;

Node *hashTable[HASH_SIZE];

unsigned int hash(const char *str) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash * 31) + (unsigned char)(*str++);
    }
    return hash % HASH_SIZE;
}

Node *findNode(const char *palavra) {
    unsigned int idx = hash(palavra);
    Node *current = hashTable[idx];
    while (current) {
        if (strcmp(current->palavra, palavra) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void insertOrIncrement(const char *palavra) {
    unsigned int idx = hash(palavra);
    Node *node = findNode(palavra);

    if (node) {
        node->count++;
    } else {
        Node *newNode = (Node *)malloc(sizeof(Node));
        strcpy(newNode->palavra, palavra);
        newNode->count = 1;
        newNode->next = hashTable[idx];
        hashTable[idx] = newNode;
    }
}

int getCount(const char *palavra) {
    Node *node = findNode(palavra);
    return node ? node->count : 0;
}

void resetCount(const char *palavra) {
    Node *node = findNode(palavra);
    if (node) {
        node->count = 0;
    }
}

void freeHashTable() {
    for (int i = 0; i < HASH_SIZE; i++) {
        Node *current = hashTable[i];
        while (current) {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
        hashTable[i] = NULL;
    }
}

int main() {
    int comando;
    char palavra[MAX_WORD_LEN + 1];

    while (scanf("%d %s", &comando, palavra) != EOF) {
        if (comando == 1) {
            insertOrIncrement(palavra);
        } else if (comando == 2) {
            printf("%d\n", getCount(palavra));
        } else if (comando == 3) {
            resetCount(palavra);
        }
    }

    freeHashTable();
    return 0;
}
