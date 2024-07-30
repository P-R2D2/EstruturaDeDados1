#include <stdlib.h>
#include <stdio.h>
#define MAX 100
//Define a estrutura de aluno
struct aluno
{
	int matricula;
	char nome[30];
	float n1,n2,n3;
};
//Define a estrutura da fila
struct fila
{
	int inicio, final, qtd;
	struct aluno dados[MAX];
};
typedef struct fila Fila;

Fila* cria_Fila();
void libera_Fila(Fila* fi);
int consulta_Fila(Fila* fi, struct aluno *al);
int insere_Fila(Fila* fi, struct aluno al);
int remove_Fila(Fila* fi);
int tamanho_Fila(Fila* fi);
int Fila_vazia(Fila* fi);
int Fila_cheia(Fila* fi);

int main()
{
	
}
//Aloca um espaço de memória onde a fila será usada
Fila* cria_Fila()
{
	Fila *fi;
	fi = (Fila*)malloc(sizeof(struct fila));
	if(fi != NULL)
	{
		fi->inicio = 0;
		fi->final = 0;
		fi->qtd = 0;
	}
	return fi;
	
}
//libera a memoria alocada para a fila
void libera_Fila(Fila* fi)
{
	free(fi);
}
//retorna o Tamanho da fila
int tamanho-Fila(Fila* fi)
{
	if(fi == NULL)
		return -1;
	return fi->qtd;
}
//Verifica se a fila está cheia ou inválida
int Fila_cheia(Fila* fi){
	if(fi == NULL)
		return -1;
	if(fi->qtd == MAX)
		return 1;
	else
		return 0;
}
//Verifica se a fila está vazia ou inválida
int Fila_vazia(Fila* fi)
{
	if(fi == NULL)
		return -1;
	if(fi->qtd == 0)
		return 1;
	else
		return 0;
}
//Insere um elemento na fila
int insere_Fila(Fila* fi, struct aluno al)
{
	if(fi == NULL)
		return 0;
	if(fi->qtd == MAX)
		return 0;
	fi->dados[fi->final] = al;
	fi->final = (fi->final+1)%MAX;
	fi->qtd++;
	return 1;
}
