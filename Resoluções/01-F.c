#include <stdio.h>

int main(){

    int D, A, N, i, valorDiaria, valorTotal;
    scanf("%d", &D);
    scanf("%d", &A);
    scanf("%d", &N);

    i = (31 - N) + 1;
    valorDiaria = D + ((N-1) * A);
    valorTotal = valorDiaria * i;

    printf("%d", valorTotal);

    return 0;
}