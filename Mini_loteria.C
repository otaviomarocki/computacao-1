#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));

    int numero_1 = rand() % 20 + 1;

    int numero_2 = rand() % 20 + 1;
    while (numero_2 == numero_1) {
        numero_2 = rand() % 20 + 1;
    }

    int numero_3 = rand() % 20 + 1;
    while (numero_3 == numero_1 ||
           numero_3 == numero_2) {
        numero_3 = rand() % 20 + 1;
    }

    //printf("Numeros: %d %d %d\n",
    //       numero_1,
    //       numero_2,
    //       numero_3);

    int tentativa_1;
    int tentativa_2;
    int tentativa_3;

    int dinheiro_gasto = 0;

    printf("Tente ganhar a loteria!\n");

    while (1) {

        printf("\nDigite 3 numeros: ");

        scanf("%d %d %d",
              &tentativa_1,
              &tentativa_2,
              &tentativa_3);

        dinheiro_gasto++;

        if (tentativa_1 == numero_1 &&
            tentativa_2 == numero_2 &&
            tentativa_3 == numero_3) {

            printf("\nVoce ganhou!\n");
            break;
        }
        else {
            printf("Nao ganhou nada!\n");
        }
    }

    printf("\nOs numeros eram: %d %d %d\n",
           numero_1,
           numero_2,
           numero_3);

    printf("Dinheiro gasto: %d\n",
           dinheiro_gasto);

    if (dinheiro_gasto <= 30) {
        printf("Otimo\n");
    }
    else if (dinheiro_gasto <= 60) {
        printf("Bom\n");
    }
    else if (dinheiro_gasto <= 100) {
        printf("Fraco\n");
    }
    else {
        printf("Pessimo\n");
    }

    return 0;
}
