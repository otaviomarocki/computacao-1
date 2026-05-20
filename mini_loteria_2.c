#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int contagem_de_acertos(int n1, int n2, int n3, int n4,
                        int aposta1, int aposta2, int aposta3, int aposta4)
{
	int numero_de_acertos = 0;

	if (n1 == aposta1 || n1 == aposta2 || n1 == aposta3 || n1 == aposta4)
		numero_de_acertos++;

	if (n2 == aposta1 || n2 == aposta2 || n2 == aposta3 || n2 == aposta4)
		numero_de_acertos++;

	if (n3 == aposta1 || n3 == aposta2 || n3 == aposta3 || n3 == aposta4)
		numero_de_acertos++;

	if (n4 == aposta1 || n4 == aposta2 || n4 == aposta3 || n4 == aposta4)
		numero_de_acertos++;

	return numero_de_acertos;
}

void sorteia_numeros(int *n1, int *n2, int *n3, int *n4)
{
	*n1 = rand() % 15 + 1;

	*n2 = rand() % 15 + 1;
	while (*n2 == *n1)
		*n2 = rand() % 15 + 1;

	*n3 = rand() % 15 + 1;
	while (*n3 == *n1 || *n3 == *n2)
		*n3 = rand() % 15 + 1;

	*n4 = rand() % 15 + 1;
	while (*n4 == *n1 || *n4 == *n2 || *n4 == *n3)
		*n4 = rand() % 15 + 1;
}

int main()
{
	int n1, n2, n3, n4;
	int aposta1, aposta2, aposta3, aposta4;
	int numero_de_acertos;
	int tentativas;
	int historico[100];
	int rodada = 0;
    int total_tentativas = 0;
	setlocale(LC_ALL, "Portuguese");
	srand(time(0));

	while (1)
	{
		tentativas = 0;

		sorteia_numeros(&n1, &n2, &n3, &n4);

		printf("Sorteio: %d %d %d %d\n", n1, n2, n3, n4);

		do
		{
			tentativas++;

			printf("Digite quatro números entre 1 e 15 (tentativa %d): ",
			       tentativas);

			scanf("%d %d %d %d",
			      &aposta1, &aposta2, &aposta3, &aposta4);

			numero_de_acertos = contagem_de_acertos(
			                        n1, n2, n3, n4,
			                        aposta1, aposta2, aposta3, aposta4);

			printf("Você acertou %d números na sua aposta!\n",
			       numero_de_acertos);

		} while (numero_de_acertos != 4);

		historico[rodada] = tentativas;
		rodada++;

		printf("Você conseguiu em %d tentativa(s) e gastou %d reais\n",
		       tentativas, tentativas * 6);

		if (tentativas <= 10)
		{
			printf("Você é ÓTIMO!\n");
		}
		else if (tentativas <= 15)
		{
			printf("Você é BOM!\n");
		}
		else if (tentativas <= 25)
		{
			printf("Você é FRACO!\n");
		}
		else
		{
			printf("Você é PÉSSIMO!\n");
		}

		while (getchar() != '\n');
        total_tentativas = total_tentativas + tentativas;
		char c;
		if (tentativas >= 0)
			printf("\nHistórico de rodadas:\n");

		for (int i = 0; i < rodada; i++)
		{
			printf("Rodada %d: %d tentativa(s)\n",
			       i + 1, historico[i]);
	        printf("Dinheiro gasto: %d\n", total_tentativas * 6);
       
		}
		printf("Deseja continuar? (S/N): ");
		scanf("%c", &c);

		if (c != 'S' && c != 's')
		{
			break;
		}
	}

	return 0;
}
