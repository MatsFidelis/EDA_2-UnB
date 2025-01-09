#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int profMax;
char str[1000];

int max(int a, int b) {
    return a > b ? a : b;
}

int altura(int posL, int prof) {
    int posR, retVal;

    profMax = max(profMax, prof);
    if(str[posL] == 'l') {
        return posL + 1;
    }

    posR = altura(posL + 1, prof + 1);
    retVal = altura(posR, prof + 1);

    return retVal;
}
