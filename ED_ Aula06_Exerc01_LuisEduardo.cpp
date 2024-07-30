#include <stdio.h>
#include <stdlib.h>

int get_Numero(int N)
{
	printf("Informe um numero maior que 0: ");
	
	do{
		scanf("%d", &N);
	}while(N <= 0);
	return N;
}

int convertIntToBinItera(int N)
{
	for (int i = 0; i < N; i++)
	{
		while (N >= 0)
		{
			if (N == 0)
			{
				printf("0");
				break;
			}
			else
			{
				printf("%i", N%2);
				N = N/2;
			}
		}
	}
	return N;
}

void convertIntToBinRec(int N)
{
	if(N == 0)
	{
		printf("0");
		return;
	}
	convertIntToBinRec(N/2);
	printf("%i", N%2);
}

int calcFatorialRec(int N)
{
	if(N == 1 || N == 0)
		return 1;
	else
		return N*calcFatorialRec(N-1);
}

int calcFatorialItera(int N)
{
	int resposta = 1;
	for(int i = N; i > 1; i--)
	   resposta *= i;
	   
	return resposta;
}
int main () {
 int N = get_Numero(N);
 printf ("\nNão recursivo - %i em binário:", N);
 convertIntToBinItera (N);
 printf ("\nRecursivo - %i em binário:",N);
 for(int i = 0; i < N; i++)
 	convertIntToBinRec (N);
 printf ("\n\nNão recursivo - fatorial de %i: %i", N, calcFatorialItera (N));
 printf ("\nRecursivo - fatorial de %i: %i", N, calcFatorialRec (N));
}
