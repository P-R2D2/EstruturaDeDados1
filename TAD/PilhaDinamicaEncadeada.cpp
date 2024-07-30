#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

struct elemento {
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;
typedef struct elemento* Pilha;

// Declaração das funções da Pilha
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

    struct aluno a1 = {1, "Aluno 1", 7.5, 8.0, 9.0};
    struct aluno a2 = {2, "Aluno 2", 6.5, 7.0, 8.5};
    
    insere_Pilha(pi, a1);
    insere_Pilha(pi, a2);

    printf("Tamanho da pilha: %d\n", tamanho_Pilha(pi));

    if (acessa_topo_Pilha(pi, &a1)) {
        printf("Topo da pilha\nMatricula: %d Nome: %s Nota1: %.2f Nota2: %.2f Nota3: %.2f\n", a1.matricula, a1.nome, a1.n1, a1.n2, a1.n3);
    }

    remove_Pilha(pi);
    printf("Tamanho da pilha após remoção: %d\n", tamanho_Pilha(pi));

    if (acessa_topo_Pilha(pi, &a2)) {
        printf("Topo da pilha após remoção: %d %s %.2f %.2f %.2f\n", a2.matricula, a2.nome, a2.n1, a2.n2, a2.n3);
    }

    libera_Pilha(pi);

    return 0;
}

Pilha* cria_Pilha() {
    Pilha* pi = (Pilha*)malloc(sizeof(Pilha));
    if (pi != NULL)
        *pi = NULL;
    return pi;
}

void libera_Pilha(Pilha* pi) {
    if (pi != NULL) {
        Elem* no;
        while ((*pi) != NULL) {
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
        free(pi);
    }
}

int tamanho_Pilha(Pilha* pi) {
    if (pi == NULL)
        return 0;
    int cont = 0;
    Elem* no = *pi;
    while (no != NULL) {
        cont++;
        no = no->prox;
    }
    return cont;
}

int Pilha_cheia(Pilha* pi) {
    return 0; // A pilha com encadeamento dinâmico nunca está cheia
}

int Pilha_vazia(Pilha* pi) {
    if (pi == NULL)
        return 1;
    if (*pi == NULL)
        return 1;
    return 0;
}

int insere_Pilha(Pilha* pi, struct aluno al) {
    if (pi == NULL)
        return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*pi);
    *pi = no;
    return 1;
}

int remove_Pilha(Pilha* pi) {
    if (pi == NULL)
        return 0;
    if ((*pi) == NULL)
        return 0;
    Elem* no = *pi;
    *pi = no->prox;
    free(no);
    return 1;
}

int acessa_topo_Pilha(Pilha* pi, struct aluno *al) {
    if (pi == NULL)
        return 0;
    if ((*pi) == NULL)
        return 0;
    *al = (*pi)->dados;
    return 1;
}



