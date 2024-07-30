#include <stdio.h>
#include <stdlib.h>
#include <Locale.h>

int verificaOrdemCrescente (int n, int v[])
{
	int ordem = 1;
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(v[j] > v[i])
			  ordem = 1;
			else
			  ordem = 0;
		}
	}
	return ordem;
}

int verificaOrdemDecrescente (int n, int v[])
{
	int ordem = 1;
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(v[j] < v[i])
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
	  printf("%d ", v[i]);
	printf("\n");
}
int main(){
 setlocale(LC_ALL,"Portuguese");
 int Ordem;
 int V1[] = {10, 30, 20, 5, 2, 0, 40, 15, 1, 3};
 int V2[] = {1, 10, 20, 30, 50, 100, 200, 300, 400, 500};
 int V3[] = {500, 400, 300, 200, 100, 50, 30 , 20, 10, 1};
 int V4[] = {222, 555, 111, 333, 444, 555, 666, 888, 777,0};
 int V5[100], V6[100];
 
 printf("V1");
 imprimeVetor(10,V1);
 Ordem = verificaOrdemCrescente (10,V1);
 if (Ordem == 0)
   printf ("\n--> Vetor em ordem crescente!");
 else
   printf ("\n--> Vetor NÂO está em ordem crescente: V1[%i] = %i >= V1[%i] = %i", Ordem-1, V1[Ordem-1], Ordem, V1[Ordem]);
 
 Ordem = verificaOrdemDecrescente (10,V1);
 if (Ordem == 0)
   printf ("\n--> Vetor em ordem decrescente!");
 else
   printf ("\n--> Vetor NÂO está em ordem decrescente! V1[%i] = %i <= V1[%i] = %i\n", Ordem-1, V1[Ordem-1], Ordem, V1[Ordem]);
 
 printf("\nV2");
 imprimeVetor(10,V2);
 Ordem = verificaOrdemCrescente (10,V2);
 if (Ordem == 0)
   printf ("\n--> Vetor em ordem crescente! ");
 else
   printf ("\n--> Vetor NÂO está em ordem crescente: V2[%i] = %i >= V2[%i] = %i\n", Ordem-1, V2[Ordem-1], Ordem, V2[Ordem]);
 
 Ordem = verificaOrdemDecrescente (10,V2);
 if (Ordem == 0)
   printf ("\n--> Vetor em ordem decrescente!");
 else
   printf ("\n--> Vetor NÂO está em ordem decrescente! V2[%i] = %i <= V2[%i] = %i\n", Ordem-1, V2[Ordem-1], Ordem, V2[Ordem]);
 
 printf("\nV3");
 imprimeVetor(10,V3);
 Ordem = verificaOrdemCrescente (10,V3);
 if (Ordem == 0)
   printf ("\n--> Vetor em ordem crescente! ");
 else
   printf ("\n--> Vetor NÂO está em ordem crescente: V3[%i] = %i >= V3[%i] = %i", Ordem-1, V3[Ordem-1], Ordem, V3[Ordem]);
 
 Ordem = verificaOrdemDecrescente (10,V3);
 if (Ordem == 0)
   printf ("\n--> Vetor em ordem decrescente!");
 else
   printf ("\n--> Vetor NÂO está em ordem decrescente! V3[%i] = %i <= V3[%i] = %i\n", Ordem-1, V3[Ordem-1], Ordem, V3[Ordem]);
 
 
 printf("\n\nV4");
 imprimeVetor(10,V3);
 Ordem = verificaOrdemCrescente (10,V4);
 if (Ordem == 0)
   printf ("\n--> Vetor em ordem crescente! ");
 else
   printf ("\n--> Vetor NÂO está em ordem crescente: V4[%i] = %i >= V4[%i] = %i", Ordem-1, V4[Ordem-1], Ordem, V4[Ordem]);
 
 Ordem = verificaOrdemDecrescente (10,V3);
 if (Ordem == 0)
   printf ("\n--> Vetor em ordem decrescente!" );
 else
   printf ("\n--> Vetor NÂO está em ordem decrescente! V4[%i] = %i <= V4[%i] = %i\n", Ordem-1, V4[Ordem-1], Ordem, V4[Ordem]); 
 
 printf("\n\nV5");
 geraVetorCrescente(100, V5);
 imprimeVetor(100,V5);
 Ordem = verificaOrdemCrescente (100,V5);
 if (Ordem == 0)
   printf ("\n--> Vetor em ordem crescente! ");
 else
   printf ("\n--> Vetor NÂO está em ordem crescente: V5[%i] = %i >= V5[%i] = %i", Ordem-1, V5[Ordem-1], Ordem, V5[Ordem]);
 
 Ordem = verificaOrdemDecrescente (100,V5);
 if (Ordem == 0)
   printf ("\n--> Vetor em ordem decrescente!");
 else
   printf ("\n--> Vetor NÂO está em ordem decrescente! V5[%i] = %i <= V5[%i] = %i\n", Ordem-1, V5[Ordem-1], Ordem, V5[Ordem]);
 
 printf("\nV6");
 geraVetorDecrescente(100, V6);
 imprimeVetor(100,V6);
 Ordem = verificaOrdemCrescente (100,V6);
 if (Ordem == 0)
   printf ("\n--> Vetor em ordem crescente! ");
 else
   printf ("\n--> Vetor NÂO está em ordem crescente: V6[%i] = %i >= V6[%i] = %i", Ordem-1, V6[Ordem-1], Ordem, V6[Ordem]);
 
 Ordem = verificaOrdemDecrescente (100,V6);
 if (Ordem == 0)
   printf ("\n--> Vetor em ordem decrescente!");
 else
   printf ("\n--> Vetor NÂO está em ordem decrescente! V6[%i] = %i <= V6[%i] = %i\n", Ordem-1, V5[Ordem-1], Ordem, V6[Ordem]);
}
