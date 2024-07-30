#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 100

struct aluno {
	int matricula;
	char nome[30];
	float n1, n2, n3;
};

struct pilha {
	int qtd;
	struct aluno dados[MAX];
};

typedef struct pilha Pilha;

Pilha* cria_Pilha();
void libera_Pilha(Pilha* pi);
int acessa_topo_Pilha(Pilha* pi, struct aluno *al);
int insere_Pilha(Pilha* pi, struct aluno al);
int remove_Pilha(Pilha* pi);
int tamanho_Pilha(Pilha* pi);
int Pilha_vazia(Pilha* pi);
int Pilha_cheia(Pilha* pi);

int main() {
	setlocale(LC_ALL, "Portuguese");
	Pilha* pi = cria_Pilha();
	struct aluno al;

	printf("Tamanho inicial da pilha: %d\n", tamanho_Pilha(pi));
	printf("A pilha está vazia? %s\n", Pilha_vazia(pi) ? "Sim" : "Não");
	printf("A pilha está cheia? %s\n", Pilha_cheia(pi) ? "Sim" : "Não");

	// Inserindo alunos na pilha usando insere_Pilha
	al.matricula = 1;
	snprintf(al.nome, 30, "Aluno 1");
	al.n1 = 7.5;
	al.n2 = 8.0;
	al.n3 = 6.5;
	if (insere_Pilha(pi, al)) {
		printf("Aluno 1 inserido com sucesso!\n");
	} else {
		printf("Falha ao inserir Aluno 1.\n");
	}

	al.matricula = 2;
	snprintf(al.nome, 30, "Aluno 2");
	al.n1 = 6.0;
	al.n2 = 5.5;
	al.n3 = 7.0;
	if (insere_Pilha(pi, al)) {
		printf("Aluno 2 inserido com sucesso!\n");
	} else {
		printf("Falha ao inserir Aluno 2.\n");
	}

	al.matricula = 3;
	snprintf(al.nome, 30, "Aluno 3");
	al.n1 = 9.0;
	al.n2 = 8.5;
	al.n3 = 9.5;
	if (insere_Pilha(pi, al)) {
		printf("Aluno 3 inserido com sucesso!\n");
	} else {
		printf("Falha ao inserir Aluno 3.\n");
	}

	printf("Tamanho da pilha após inserções: %d\n", tamanho_Pilha(pi));
	printf("A pilha está vazia? %s\n", Pilha_vazia(pi) ? "Sim" : "Não");
	printf("A pilha está cheia? %s\n", Pilha_cheia(pi) ? "Sim" : "Não");

	// Removendo e exibindo alunos da pilha
	while (!Pilha_vazia(pi)) {
		acessa_topo_Pilha(pi, &al);
		printf("Removendo aluno:\n");
		printf("Matricula: %d\n", al.matricula);
		printf("Nome: %s\n", al.nome);
		printf("Notas: %.2f, %.2f, %.2f\n", al.n1, al.n2, al.n3);
		remove_Pilha(pi);
		printf("\n");
	}

	printf("Tamanho da pilha após remoções: %d\n", tamanho_Pilha(pi));
	printf("A pilha está vazia? %s\n", Pilha_vazia(pi) ? "Sim" : "Não");
	printf("A pilha está cheia? %s\n", Pilha_cheia(pi) ? "Sim" : "Não");

	libera_Pilha(pi);
	return 0;
}

Pilha* cria_Pilha() {
	Pilha* pi;
	pi = (Pilha*)malloc(sizeof(struct pilha));
	if (pi != NULL)
		pi->qtd = 0;
	return pi;
}

void libera_Pilha(Pilha* pi) {
	free(pi);
}

int tamanho_Pilha(Pilha *pi) {
	if (pi == NULL)
		return -1;
	else
		return pi->qtd;
}

int Pilha_cheia(Pilha* pi) {
	if (pi == NULL)
		return -1;
	return (pi->qtd == MAX);
}

int Pilha_vazia(Pilha* pi) {
	if (pi == NULL)
		return -1;
	return (pi->qtd == 0);
}

int insere_Pilha(Pilha* pi, struct aluno al) {
	if (pi == NULL)
		return 0;
	if (pi->qtd == MAX)
		return 0;
	pi->dados[pi->qtd] = al;
	pi->qtd++;
	return 1;
}

int remove_Pilha(Pilha* pi) {
	if (pi == NULL || pi->qtd == 0)
		return 0;
	pi->qtd--;
	return 1;
}

int acessa_topo_Pilha(Pilha* pi, struct aluno *al) {
	if (pi == NULL || pi->qtd == 0)
		return 0;
	*al = pi->dados[pi->qtd - 1];
	return 1;
}

