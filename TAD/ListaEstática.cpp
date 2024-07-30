#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct lista Lista;

struct lista {
    int qtd;
    struct aluno dados[MAX];
};

Lista* cria_lista();
void libera_lista(Lista* li);
int tamanho_lista(Lista* li);
int lista_cheia(Lista* li);
int lista_vazia(Lista* li);
int insere_lista_inicio(Lista* li, struct aluno al);
int insere_lista_final(Lista* li, struct aluno al);
int insere_lista_ordenada(Lista* li, struct aluno al);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int remove_lista(Lista* li, int mat);
int remove_lista_otimizado(Lista* li, int mat);
int busca_lista_pos(Lista* li, int pos, struct aluno *al);
int busca_lista_mat(Lista* li, int mat, struct aluno *al);

int main() {
    Lista *li;
    struct aluno al;
    int pos, mat, op;

    li = cria_lista();

    // Inicializa a lista com alguns valores padrão
    al.matricula = 1;
    strcpy(al.nome, "Alice");
    al.n1 = 7.5;
    al.n2 = 8.5;
    al.n3 = 9.0;
    insere_lista_final(li, al);

    al.matricula = 2;
    strcpy(al.nome, "Bob");
    al.n1 = 6.0;
    al.n2 = 7.0;
    al.n3 = 8.0;
    insere_lista_final(li, al);

    al.matricula = 3;
    strcpy(al.nome, "Charlie");
    al.n1 = 9.0;
    al.n2 = 9.5;
    al.n3 = 10.0;
    insere_lista_final(li, al);

    do {
        printf("\nMenu:\n");
        printf("1. Inserir no inicio\n");
        printf("2. Inserir no final\n");
        printf("3. Inserir ordenado\n");
        printf("4. Remover do inicio\n");
        printf("5. Remover do final\n");
        printf("6. Remover por matricula\n");
        printf("7. Remover otimizado por matricula\n");
        printf("8. Buscar por posicao\n");
        printf("9. Buscar por matricula\n");
        printf("10. Tamanho da lista\n");
        printf("11. Lista cheia\n");
        printf("12. Lista vazia\n");
        printf("13. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                printf("Digite a matricula, nome e notas do aluno: ");
                scanf("%d%s%f%f%f", &al.matricula, al.nome, &al.n1, &al.n2, &al.n3);
                if(insere_lista_inicio(li, al))
                    printf("Inserido com sucesso!\n");
                else
                    printf("Erro ao inserir.\n");
                break;
            case 2:
                printf("Digite a matricula, nome e notas do aluno: ");
                scanf("%d%s%f%f%f", &al.matricula, al.nome, &al.n1, &al.n2, &al.n3);
                if(insere_lista_final(li, al))
                    printf("Inserido com sucesso!\n");
                else
                    printf("Erro ao inserir.\n");
                break;
            case 3:
                printf("Digite a matricula, nome e notas do aluno: ");
                scanf("%d%s%f%f%f", &al.matricula, al.nome, &al.n1, &al.n2, &al.n3);
                if(insere_lista_ordenada(li, al))
                    printf("Inserido com sucesso!\n");
                else
                    printf("Erro ao inserir.\n");
                break;
            case 4:
                if(remove_lista_inicio(li))
                    printf("Removido com sucesso!\n");
                else
                    printf("Erro ao remover.\n");
                break;
            case 5:
                if(remove_lista_final(li))
                    printf("Removido com sucesso!\n");
                else
                    printf("Erro ao remover.\n");
                break;
            case 6:
                printf("Digite a matricula do aluno a ser removido: ");
                scanf("%d", &mat);
                if(remove_lista(li, mat))
                    printf("Removido com sucesso!\n");
                else
                    printf("Erro ao remover.\n");
                break;
            case 7:
                printf("Digite a matricula do aluno a ser removido: ");
                scanf("%d", &mat);
                if(remove_lista_otimizado(li, mat))
                    printf("Removido com sucesso!\n");
                else
                    printf("Erro ao remover.\n");
                break;
            case 8:
                printf("Digite a posicao do aluno: ");
                scanf("%d", &pos);
                if(busca_lista_pos(li, pos, &al))
                    printf("Aluno encontrado: %d %s %.2f %.2f %.2f\n", al.matricula, al.nome, al.n1, al.n2, al.n3);
                else
                    printf("Aluno nao encontrado.\n");
                break;
            case 9:
                printf("Digite a matricula do aluno: ");
                scanf("%d", &mat);
                if(busca_lista_mat(li, mat, &al))
                    printf("Aluno encontrado: %d %s %.2f %.2f %.2f\n", al.matricula, al.nome, al.n1, al.n2, al.n3);
                else
                    printf("Aluno nao encontrado.\n");
                break;
            case 10:
                printf("Tamanho da lista: %d\n", tamanho_lista(li));
                break;
            case 11:
                if(lista_cheia(li))
                    printf("Lista cheia.\n");
                else
                    printf("Lista nao cheia.\n");
                break;
            case 12:
                if(lista_vazia(li))
                    printf("Lista vazia.\n");
                else
                    printf("Lista nao vazia.\n");
                break;
            case 13:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(op != 13);

    libera_lista(li);
    return 0;
}

Lista* cria_lista() {
    Lista* li;
    li = (Lista*) malloc(sizeof(struct lista));
    if (li != NULL) {
        li->qtd = 0;
    }
    return li;
}

void libera_lista(Lista* li) {
    free(li);
}

int tamanho_lista(Lista* li) {
    if (li == NULL)
        return -1;
    return li->qtd;
}

int lista_cheia(Lista* li) {
    if (li == NULL)
        return -1;
    return (li->qtd == MAX);
}

int lista_vazia(Lista* li) {
    if (li == NULL)
        return -1;
    return (li->qtd == 0);
}

int insere_lista_inicio(Lista* li, struct aluno al) {
    if (li == NULL)
        return 0;
    if (li->qtd == MAX) // lista cheia
        return 0;
    int i;
    for (i = li->qtd-1; i >= 0; i--)
        li->dados[i+1] = li->dados[i];
    li->dados[0] = al;
    li->qtd++;
    return 1;
}

int insere_lista_final(Lista* li, struct aluno al) {
    if (li == NULL)
        return 0;
    if (li->qtd == MAX) // lista cheia
        return 0;
    li->dados[li->qtd] = al;
    li->qtd++;
    return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno al) {
    if (li == NULL)
        return 0;
    if (li->qtd == MAX) // lista cheia
        return 0;
    int k, i = 0;
    while (i < li->qtd && li->dados[i].matricula < al.matricula)
        i++;
    for (k = li->qtd-1; k >= i; k--)
        li->dados[k+1] = li->dados[k];
    li->dados[i] = al;
    li->qtd++;
    return 1;
}

int remove_lista_inicio(Lista* li) {
    if (li == NULL)
        return 0;
    if (li->qtd == 0)
        return 0;
    int k;
    for (k = 0; k < li->qtd-1; k++)
        li->dados[k] = li->dados[k+1];
    li->qtd--;
    return 1;
}

int remove_lista_final(Lista* li) {
    if (li == NULL)
        return 0;
    if (li->qtd == 0)
        return 0;
    li->qtd--;
    return 1;
}

int remove_lista(Lista* li, int mat) {
    if (li == NULL)
        return 0;
    if (li->qtd == 0)
        return 0;
    int k, i = 0;
    while (i < li->qtd && li->dados[i].matricula != mat)
        i++;
    if (i == li->qtd)
        return 0;
    for (k = i; k < li->qtd-1; k++)
        li->dados[k] = li->dados[k+1];
    li->qtd--;
    return 1;
}

int remove_lista_otimizado(Lista* li, int mat) {
    if (li == NULL)
        return 0;
    if (li->qtd == 0)
        return 0;
    int i = 0;
    while (i < li->qtd && li->dados[i].matricula != mat)
        i++;
    if (i == li->qtd)
        return 0;
    li->qtd--;
    li->dados[i] = li->dados[li->qtd];
    return 1;
}

int busca_lista_pos(Lista* li, int pos, struct aluno *al) {
    if (li == NULL || pos <= 0 || pos > li->qtd)
        return 0;
    *al = li->dados[pos-1];
    return 1;
}

int busca_lista_mat(Lista* li, int mat, struct aluno *al) {
    if (li == NULL)
        return 0;
    int i = 0;
    while (i < li->qtd && li->dados[i].matricula != mat)
        i++;
    if (i == li->qtd)
        return 0;
    *al = li->dados[i];
    return 1;
}

