#include <stdio.h>
#include <stdlib.h>

//Prototipagem das funções
int GetTamanhoMatriz();
int** CreateMatriz(int tamanho);
void PreencheMatriz(int** matriz, int tamanho);
int VerificaLinhas(int** matriz, int tamanho);
int VerificaColunas(int** matriz, int tamanho, int soma);
int VerificaDiagonal(int** matriz, int tamanho, int soma);
void ImprimeMatriz(int** matriz, int tamanho);

int main()
{
	int tamanhoMatriz = GetTamanhoMatriz();
	int** matriz = CreateMatriz(tamanhoMatriz);

	PreencheMatriz(matriz, tamanhoMatriz);

	int soma = VerificaLinhas(matriz, tamanhoMatriz);
	if (soma != -1)
		soma = VerificaColunas(matriz, tamanhoMatriz, soma);

	if (soma != -1)
		soma = VerificaDiagonal(matriz, tamanhoMatriz, soma);

	if (soma == -1)
	{
		printf("A matriz nao e um quadrado magico.\nResultado da soma: %d\n", soma);
	}
	else {
		printf("Matriz:\n");
		ImprimeMatriz(matriz, tamanhoMatriz);
		printf("A matriz e um quadrado magico e a soma magica e: %d\n", soma);
	}
	system("pause");

	return 0;
}

int GetTamanhoMatriz() {
	int tamanho;

	while (1)
	{
		printf_s("Digite a ordem do quadrado magico: ");
		scanf_s("%d", &tamanho);

		if (tamanho < 2 || tamanho > 10)
		{
			printf_s("\nA matriz quadrada deve ter o tamanho minimo de 2x2 e maximo de 10x10!\n\n");
		}
		else
		{
			break;
		}
	}

	return tamanho;
}

int** CreateMatriz(int tamanho) {

	int** matriz = (int**)malloc(tamanho * sizeof(int*));

	for (int i = 0; i <= tamanho; i++)
	{
		matriz[i] = (int*)malloc(tamanho * sizeof(int));
	}

	return matriz;
}

void PreencheMatriz(int** matriz, int tamanho)
{
	int elemento = 0;

	printf_s("\nDigite os elementos da matriz: \n");

	for (int i = 0; i < tamanho; i++)
	{
		for (int j = 0; j < tamanho; j++)
		{
			scanf_s("%d", &elemento);

			matriz[i][j] = elemento;
		}
	}
}

int VerificaLinhas(int** matriz, int tamanho)
{
	int soma = 0;

	for (int i = 0; i < tamanho; i++)
	{
		int contador = 0;

		for (int j = 0; j < tamanho; j++)
		{
			contador += matriz[i][j];
		}

		if (soma == 0)
		{
			soma = contador;
		}
		else if (soma == contador)
		{
			continue;
		}
		else
		{
			return -1;
		}
	}

	return soma;
}

int VerificaColunas(int** matriz, int tamanho, int soma)
{
	for (int i = 0; i < tamanho; i++)
	{
		int contador = 0;

		for (int j = 0; j < tamanho; j++)
		{
			contador += matriz[j][i];
		}

		if (soma != contador)
		{
			return -1;
		}

	}
	return soma;
}

int VerificaDiagonal(int** matriz, int tamanho, int soma)
{
	int somaDiagonal = 0;

	for (int i = 0; i < tamanho; i++)
	{
		somaDiagonal += matriz[i][i];
	}

	if (somaDiagonal != soma)
	{
		return -1;
	}

	somaDiagonal = 0;

	for (int i = tamanho - 1; i >= 0; i--)
	{
		somaDiagonal += matriz[i][i];
	}

	if (somaDiagonal != soma)
	{
		return -1;
	}

	return soma;
}

void ImprimeMatriz(int** matriz, int tamanho) {
	for (int i = 0; i < tamanho; i++)
	{
		for (int j = 0; j < tamanho; j++)
		{
			printf_s("%d ", matriz[i][j]);
		}
		printf_s("\n");
	}
}