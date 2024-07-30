#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAX 100

struct aluno 
{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

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
	setlocale(LC_ALL,"Portuguese");
    // Exemplo de uso das funções
    Fila *fi = cria_Fila();

    struct aluno al1 = {1, "Aluno 1", 7.5, 8.0, 6.5};
    struct aluno al2 = {2, "Aluno 2", 9.0, 7.5, 8.5};
    struct aluno al3 = {3, "Aluno 3", 6.0, 7.0, 8.0};
    struct aluno al4 = {4, "Aluno 4", 8.5, 9.0, 7.5};
    struct aluno al5 = {5, "Aluno 5", 7.0, 6.5, 8.5};

    insere_Fila(fi, al1);
    insere_Fila(fi, al2);
    insere_Fila(fi, al3);
    insere_Fila(fi, al4);
    insere_Fila(fi, al5);

    printf("Tamanho da fila: %d\n", tamanho_Fila(fi));

    struct aluno al;
    if (consulta_Fila(fi, &al)) {
        printf("Aluno no início da fila: %s\n", al.nome);
    }

    remove_Fila(fi);

    if (consulta_Fila(fi, &al)) {
        printf("Aluno no início da fila após remoção: %s\n", al.nome);
    }

    remove_Fila(fi);

    if (consulta_Fila(fi, &al)) {
        printf("Aluno no início da fila após segunda remoção: %s\n", al.nome);
    }

    libera_Fila(fi);

    return 0;
}

Fila* cria_Fila() 
{
    Fila* fi;
    fi = (Fila*) malloc(sizeof(struct fila));
    if (fi != NULL) {
        fi->inicio = 0;
        fi->final = 0;
        fi->qtd = 0;
    }
    return fi;
}

void libera_Fila(Fila* fi) 
{
    free(fi);
}

int tamanho_Fila(Fila* fi) 
{
    if (fi == NULL)
        return -1;
    return fi->qtd;
}

int Fila_cheia(Fila* fi) 
{
    if (fi == NULL)
        return -1;
    if (fi->qtd == MAX)
        return 1;
    else
        return 0;
}

int Fila_vazia(Fila* fi) 
{
    if (fi == NULL)
        return -1;
    if (fi->qtd == 0)
        return 1;
    else
        return 0;
}

int insere_Fila(Fila* fi, struct aluno al) 
{
    if (fi == NULL)
        return 0;
    if (fi->qtd == MAX)
        return 0;
    fi->dados[fi->final] = al;
    fi->final = (fi->final + 1) % MAX;
    fi->qtd++;
    return 1;
}

int remove_Fila(Fila* fi) 
{
    if (fi == NULL || fi->qtd == 0)
        return 0;
    fi->inicio = (fi->inicio + 1) % MAX;
    fi->qtd--;
    return 1;
}

int consulta_Fila(Fila* fi, struct aluno *al) 
{
    if (fi == NULL || Fila_vazia(fi))
        return 0;
    *al = fi->dados[fi->inicio];
    return 1;
}

