#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int codigo;
    int reprovados;
} disciplinaciplina;

void ordena(int *codigos, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if (codigos[i] > codigos[j]) {
                int temp = codigos[i];
                codigos[i] = codigos[j];
                codigos[j] = temp;
            }
        }
    }
}

void processa_semestre(int ano, int semestre, int materias) {
    int cod, alunos, aprovados, max_reprovado = -1, count = 0;
    int max_codigo[materias];

    for (int i = 0; i < materias; i++) {
        scanf("%d %d %d", &cod, &alunos, &aprovados);
        int reprovados = alunos - aprovados;

        if (reprovados > max_reprovado) {
            max_reprovado = reprovados;
            count = 0;
            max_codigo[count++] = cod;
        } else if (reprovados == max_reprovado) {
            max_codigo[count++] = cod;
        }
    }

    ordena(max_codigo, count);

    printf("%d/%d\n", ano, semestre);
    for (int i = 0; i < count; i++) {
        printf("%d ", max_codigo[i]);
    }
    printf("\n\n");
}

int main() {
    int disciplina, ano, semestre, materias;

    scanf("%d", &disciplina);
    while (scanf("%d %d %d", &ano, &semestre, &materias) != EOF) {
        processa_semestre(ano, semestre, materias);
    }

    return 0;
}
