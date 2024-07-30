#include <stdio.h>
#include <stdlib.h>
#include <Locale.h>
#define N 8

void ordenaInsercao (int n, int v[])
{
	for (int i = 1; i < n; ++i)
	{
		int x = v[i];
		int j;
		for (j = i-1; j >= 0 && v[j] > x ; --j)
			v[j+1] = v[j];
		v[j+1] = x;
	}
}
 
void ordenaSelecao (int n, int v[])
{
	for (int i = 0; i < n-1; ++i)
	{
 		int min = i;
 		for (int j = i+1; j < n; ++j)
			if (v[j] < v[min])
				min = j;
 		int x = v[i];
 		v[i] = v[min];
 		v[min] = x;
}

}
void ordenaBolha (int n, int v[])
{
	int Aux;
	for (int i = 0; i < n ; i++)
	{
		for (int j = 0; j < n-i-1 ; ++j)
			if (v[j] > v[j+1])
			{
				Aux = v[j];
				v[j] = v[j+1];
				v[j+1] = Aux;
 			}
	}	

}
int verificaOrdemCrescente(int n, int v[])
{
	int ordem = 1;
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(v[i] > v[j])
			  ordem = 1;
			else
			  ordem = 0;
		}
	}
	return ordem;
}
void imprimeVetor (int n, int v[])
{
	for(int i = 0; i < n; i++)
	  printf("%d ",v[i]);
	printf("\n");
}
int main(){
 setlocale(LC_ALL,"Portuguese");
 int V1[N]= {25, 57, 48, 37, 12, 92, 86, 33}, V2[N] = {25, 57, 48, 37, 12, 92, 86, 33}, V3[N] = {25, 57, 48, 37, 12, 92, 86, 33};
 printf ("\nOrdenação por inserção:"); 
 printf("\nV\n");
 imprimeVetor(8,V1);
 ordenaInsercao(N,V1);
 imprimeVetor(N,V1);
 if (verificaOrdemCrescente (N,V1) == 0)
    printf ("\n--> Vetor em ordem crescente! ");
 else
    printf ("\n--> Erro de ordenação! ");
 
 printf ("\n\nOrdenação por seleção:");
 printf("\nV\n");
 imprimeVetor(N,V2);
 ordenaSelecao(N,V2);
 imprimeVetor(N,V2);
 if (verificaOrdemCrescente (N,V2) == 0)
    printf ("\n--> Vetor em ordem crescente! ");
 else
    printf ("\n--> Erro de ordenação! ");

 printf ("\n\nOrdenação por bolha:");
 printf("\nV\n");
 imprimeVetor(N,V3);
 ordenaBolha(N,V3);
 imprimeVetor(N,V3);
 if (verificaOrdemCrescente (N,V3) == 0)
    printf ("\n--> Vetor em ordem crescente! ");
 else
    printf ("\n--> Erro de ordenação! ");
}
