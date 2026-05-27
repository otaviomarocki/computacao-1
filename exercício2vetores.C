/******************************************************************************

Implemente um programa em C que preenche com valores aleatórios um vetor de N posições, onde N é uma constante
pré-deﬁnida. Dada uma posição do vetor (informada pelo usuário), o programa deve remover o elemento desta posição,
“puxando” todos os elementos das posições posteriores uma posição para “trás”. Por exemplo, se o vetor contém os
números 1, 3, 6, 2 e 10 e o usuário digita 2, o programa deve remover o elemento na posição número 2 do vetor - o
6 (lembre-se que a contagem inicia em 0) - ﬁcando com os números 1, 3, 2 e 10. Após a remoção, o programa deve
mostrar o “novo” vetor na tela. Atenção, a solução deve declarar apenas o vetor original (não utilize mais de um vetor
para resolver o problema)


*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int numeros[5];

    for (int i = 0; i < 5; i++) {
        numeros[i] = (rand() % 9) + 1;
    }

    for (int i = 0; i < 5; i++) {
        printf("numeros[%d] = %d\n", i + 1, numeros[i]);
    }

    int posicao;

    printf("\nEscolha uma posicao de 1 a 5: ");
    scanf("%d", &posicao);

    if (posicao >= 1 && posicao <= 5) {

        int i;

        for (i = posicao - 1; i < 4; i++) {
            numeros[i] = numeros[i + 1];
        }

        numeros[4] = 0;

        printf("\nVetor depois da remocao:\n");

        for (int i = 0; i < 5; i++) {
            printf("numeros[%d] = %d\n", i + 1, numeros[i]);
        }

    } else {
        printf("Posicao invalida!\n");
    }

    return 0;
}
