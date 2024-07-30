#include <stdio.h>
#include <stdlib.h>
#include <Locale.h>
// Definição da estrutura aluno
struct aluno {
    int matricula;
    float notas[2];
};

// Definição da estrutura do nó da lista
typedef struct elemento* Lista;

struct elemento {
    struct aluno dados;
    struct elemento *prox;
};

// Função para criar uma lista
Lista* cria_lista() {
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL)
        *li = NULL;
    return li;
}

// Função para liberar a lista
void libera_lista(Lista* li) {
    if (li != NULL) {
        struct elemento* no;
        while ((*li) != NULL) {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

// Função para obter o tamanho da lista
int tamanho_lista(Lista* li) {
    if (li == NULL) return 0;
    int cont = 0;
    struct elemento* no = *li;
    while (no != NULL) {
        cont++;
        no = no->prox;
    }
    return cont;
}

// Função para verificar se a lista está cheia
int lista_cheia(Lista* li) {
    return 0; // A lista encadeada nunca está cheia, a menos que a memória acabe
}

// Função para verificar se a lista está vazia
int lista_vazia(Lista* li) {
    if (li == NULL || *li == NULL) return 1;
    return 0;
}

// Função para inserir no início da lista
int insere_lista_inicio(Lista* li, struct aluno al) {
    if (li == NULL) return 0;
    struct elemento* no = (struct elemento*) malloc(sizeof(struct elemento));
    if (no == NULL) return 0;
    no->dados = al;
    no->prox = (*li);
    *li = no;
    return 1;
}

// Função para inserir no final da lista
int insere_lista_final(Lista* li, struct aluno al) {
    if (li == NULL) return 0;
    struct elemento* no = (struct elemento*) malloc(sizeof(struct elemento));
    if (no == NULL) return 0;
    no->dados = al;
    no->prox = NULL;
    if (*li == NULL) { // Lista vazia: insere no início
        *li = no;
    } else {
        struct elemento* aux = *li;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

// Função para inserir de forma ordenada
int insere_lista_ordenada(Lista* li, struct aluno al) {
    if (li == NULL) return 0;
    struct elemento* no = (struct elemento*) malloc(sizeof(struct elemento));
    if (no == NULL) return 0;
    no->dados = al;
    if (lista_vazia(li)) { // Insere no início
        no->prox = (*li);
        *li = no;
        return 1;
    } else {
        struct elemento *ant, *atual = *li;
        while (atual != NULL && atual->dados.matricula < al.matricula) {
            ant = atual;
            atual = atual->prox;
        }
        if (atual == *li) { // Insere no início
            no->prox = (*li);
            *li = no;
        } else {
            no->prox = ant->prox;
            ant->prox = no;
        }
        return 1;
    }
}

// Função para remover do início da lista
int remove_lista_inicio(Lista* li) {
    if (li == NULL || *li == NULL) return 0;
    struct elemento* no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

// Função para remover do final da lista
int remove_lista_final(Lista* li) {
    if (li == NULL || *li == NULL) return 0;
    struct elemento *ant, *no = *li;
    if (no->prox == NULL) { // Remover o primeiro e único
        *li = NULL;
        free(no);
        return 1;
    }
    while (no->prox != NULL) {
        ant = no;
        no = no->prox;
    }
    ant->prox = NULL;
    free(no);
    return 1;
}

// Função para remover um elemento pela matrícula
int remove_lista(Lista* li, int mat) {
    if (li == NULL) return 0;
    struct elemento *ant, *no = *li;
    while (no != NULL && no->dados.matricula != mat) {
        ant = no;
        no = no->prox;
    }
    if (no == NULL) return 0; // Elemento não encontrado
    if (no == *li) // Remove o primeiro
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

// Função para buscar um elemento pela posição
int busca_lista_pos(Lista* li, int pos, struct aluno *al) {
    if (li == NULL || pos <= 0) return 0;
    struct elemento* no = *li;
    int i = 1;
    while (no != NULL && i < pos) {
        no = no->prox;
        i++;
    }
    if (no == NULL) return 0;
    *al = no->dados;
    return 1;
}

// Função para buscar um elemento pela matrícula
int busca_lista_mat(Lista* li, int mat, struct aluno *al) {
    if (li == NULL) return 0;
    struct elemento* no = *li;
    while (no != NULL && no->dados.matricula != mat) {
        no = no->prox;
    }
    if (no == NULL) return 0;
    *al = no->dados;
    return 1;
}

// Função para inicializar a lista com valores predefinidos
void inicializa_lista(Lista* li) {
    int matriculas[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    float notas[][2] = {
        {8.0, 9.0}, {5.0, 6.0}, {8.0, 7.0}, {4.0, 9.0}, {2.0, 6.0},
        {7.5, 6.0}, {3.0, 5.0}, {2.0, 1.0}, {9.0, 8.0}, {8.0, 6.0}
    };

    for (int i = 0; i < 10; i++) {
        struct aluno al;
        al.matricula = matriculas[i];
        al.notas[0] = notas[i][0];
        al.notas[1] = notas[i][1];
        insere_lista_final(li, al);
    }
}

// Função para exibir os elementos da lista com cálculo da média
void exibe_lista(Lista* li) {
    if (li == NULL) return;
    struct elemento* no = *li;
    while (no != NULL) {
        float media = (no->dados.notas[0] * 2 + no->dados.notas[1] * 3) / 5;
        printf("Matrícula: %d\n", no->dados.matricula);
        printf("Notas: %.1f, %.1f\n", no->dados.notas[0], no->dados.notas[1]);
        printf("Média: %.2f\n", media);
        printf("--------------------\n");
        no = no->prox;
    }
}

// Função principal para teste
int main() {
	setlocale(LC_ALL, "Portuguese");
    Lista* li = cria_lista();
    int opcao, mat;
    struct aluno al;

    inicializa_lista(li);

    do {
        printf("\nMenu:\n");
        printf("1. Inserir aluno no início\n");
        printf("2. Inserir aluno no final\n");
        printf("3. Inserir aluno ordenado\n");
        printf("4. Remover aluno do início\n");
        printf("5. Remover aluno do final\n");
        printf("6. Remover aluno por matrícula\n");
        printf("7. Buscar aluno por matrícula\n");
        printf("8. Exibir quantidade de alunos\n");
        printf("9. Exibir todos os alunos\n");
        printf("10. Destruir lista\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a matrícula: ");
                scanf("%d", &al.matricula);
                printf("Digite as notas: ");
                scanf("%f %f", &al.notas[0], &al.notas[1]);
                if (insere_lista_inicio(li, al))
                    printf("Aluno inserido no início com sucesso!\n");
                else
                    printf("Erro ao inserir aluno no início!\n");
                break;

            case 2:
                printf("Digite a matrícula: ");
                scanf("%d", &al.matricula);
                printf("Digite as notas: ");
                scanf("%f %f", &al.notas[0], &al.notas[1]);
                if (insere_lista_final(li, al))
                    printf("Aluno inserido no final com sucesso!\n");
                else
                    printf("Erro ao inserir aluno no final!\n");
                break;

            case 3:
                printf("Digite a matrícula: ");
                scanf("%d", &al.matricula);
                printf("Digite as notas: ");
                scanf("%f %f", &al.notas[0], &al.notas[1]);
                if (insere_lista_ordenada(li, al))
                    printf("Aluno inserido de forma ordenada com sucesso!\n");
                else
                    printf("Erro ao inserir aluno de forma ordenada!\n");
                break;

            case 4:
                if (remove_lista_inicio(li))
                    printf("Aluno removido do início com sucesso!\n");
                else
                    printf("Erro ao remover aluno do início!\n");
                break;

            case 5:
                if (remove_lista_final(li))
                    printf("Aluno removido do final com sucesso!\n");
                else
                    printf("Erro ao remover aluno do final!\n");
                break;

            case 6:
                printf("Digite a matrícula: ");
                scanf("%d", &mat);
                if (remove_lista(li, mat))
                    printf("Aluno removido com sucesso!\n");
                else
                    printf("Erro ao remover aluno!\n");
                break;

            case 7:
                printf("Digite a matrícula: ");
                scanf("%d", &mat);
                if (busca_lista_mat(li, mat, &al)) {
                    printf("Aluno encontrado:\n");
                    printf("Matrícula: %d\n", al.matricula);
                    printf("Notas: %.1f, %.1f\n", al.notas[0], al.notas[1]);
                } else {
                    printf("Aluno não encontrado!\n");
                }
                break;

            case 8:
                printf("Quantidade de alunos na lista: %d\n", tamanho_lista(li));
                break;

            case 9:
                printf("Exibindo todos os alunos:\n");
                exibe_lista(li);
                break;

            case 10:
                libera_lista(li);
                li = cria_lista();
                printf("Lista destruída e recriada!\n");
                break;

            case 0:
                libera_lista(li);
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}

