#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

struct fila {
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
};

typedef struct elemento Elem;
typedef struct fila Fila;

Fila* cria_Fila();
void libera_Fila(Fila* fi);
int consulta_Fila(Fila* fi, struct aluno *al);
int insere_Fila(Fila* fi, struct aluno al);
int remove_Fila(Fila* fi);
int tamanho_Fila(Fila* fi);
int Fila_vazia(Fila* fi);
int Fila_cheia(Fila* fi);

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    Fila* fi = cria_Fila();
    
    struct aluno al1 = {123, "Aluno 1", 7.5, 8.0, 6.5};
    struct aluno al2 = {456, "Aluno 2", 9.0, 8.5, 7.0};
    struct aluno al3 = {789, "Aluno 3", 6.5, 7.5, 8.0};
    
    insere_Fila(fi, al1);
    insere_Fila(fi, al2);
    insere_Fila(fi, al3);
    
    printf("Tamanho da fila: %d\n", tamanho_Fila(fi));
    
    remove_Fila(fi);
    remove_Fila(fi);
    
    if (consulta_Fila(fi, &al1)) {
        printf("\nDados do próximo aluno na fila:\n");
        printf("Matrícula: %d\n", al1.matricula);
        printf("Nome: %s\n", al1.nome);
        printf("Nota 1: %.2f\n", al1.n1);
        printf("Nota 2: %.2f\n", al1.n2);
        printf("Nota 3: %.2f\n", al1.n3);
    }
    
    printf("\nTamanho da fila após remoções: %d\n", tamanho_Fila(fi));
    
    libera_Fila(fi);
    
    return 0;
}

Fila* cria_Fila() {
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if (fi != NULL) {
        fi->inicio = NULL;
        fi->final = NULL;
        fi->qtd = 0;
    }
    return fi;
}

void libera_Fila(Fila* fi) {
    if (fi != NULL) {
        Elem* no;
        while (fi->inicio != NULL) {
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

int tamanho_Fila(Fila* fi) {
    if (fi == NULL)
        return 0;
    return fi->qtd;
}

int Fila_cheia(Fila* fi) {
    return 0;
}

int Fila_vazia(Fila* fi) {
    if (fi == NULL)
        return -1;
    if (fi->inicio == NULL)
        return 1;
    return 0;
}

int insere_Fila(Fila* fi, struct aluno al) {
    if (fi == NULL)
        return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if (fi->final == NULL) // Fila vazia
        fi->inicio = no;
    else
        fi->final->prox = no;
    fi->final = no;
    fi->qtd++;
    return 1;
}

int remove_Fila(Fila* fi) {
    if (fi == NULL)
        return 0;
    if (fi->inicio == NULL) // Fila vazia
        return 0;
    Elem* no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    free(no);
    if (fi->inicio == NULL) // Fila ficou vazia
        fi->final = NULL;
    fi->qtd--;
    return 1;
}

int consulta_Fila(Fila* fi, struct aluno *al) {
    if (fi == NULL)
        return 0;
    if (fi->inicio == NULL)
        return 0;
    *al = fi->inicio->dados;
    return 1;
}

