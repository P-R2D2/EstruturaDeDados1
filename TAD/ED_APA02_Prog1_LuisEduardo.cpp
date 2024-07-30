#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Tamanho máximo da lista estática

// Estrutura do aluno
struct aluno {
    int matricula;
    float notas[2]; // Notas de cada aluno (duas notas)
};

// Estrutura da lista estática
typedef struct {
    struct aluno dados[MAX];
    int qtd;
} Lista;

// Função para criar uma lista
Lista* cria_lista() {
    Lista *li;
    li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL) {
        li->qtd = 0;

        // Inicializa com os valores padrão de matrícula e notas
        int matriculas[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        float notas[][2] = {{8.0, 9.0}, {5.0, 6.0}, {8.0, 7.0}, {4.0, 9.0}, {2.0, 6.0},
                            {7.5, 6.0}, {3.0, 5.0}, {2.0, 1.0}, {9.0, 8.0}, {8.0, 6.0}};
        
        for (int i = 0; i < MAX; i++) {
            li->dados[i].matricula = matriculas[i];
            li->dados[i].notas[0] = notas[i][0];
            li->dados[i].notas[1] = notas[i][1];
            li->qtd++;
        }
    }
    return li;
}

// Função para liberar a lista da memória
void libera_lista(Lista* li) {
    free(li);
}

// Função para retornar o tamanho da lista
int tamanho_lista(Lista* li) {
    if (li == NULL)
        return -1; // Erro
    else
        return li->qtd;
}

// Função para verificar se a lista está cheia
int lista_cheia(Lista* li) {
    if (li == NULL)
        return -1; // Erro
    return (li->qtd == MAX);
}

// Função para verificar se a lista está vazia
int lista_vazia(Lista* li) {
    if (li == NULL)
        return -1; // Erro
    return (li->qtd == 0);
}

// Função para inserir um elemento no início da lista
int insere_lista_inicio(Lista* li, struct aluno al) {
    if (li == NULL || lista_cheia(li))
        return 0; // Falha na inserção

    // Desloca os elementos para frente
    for (int i = li->qtd - 1; i >= 0; i--)
        li->dados[i + 1] = li->dados[i];
    
    // Insere o novo elemento no início
    li->dados[0] = al;
    li->qtd++;
    return 1; // Inserção com sucesso
}

// Função para inserir um elemento no final da lista
int insere_lista_final(Lista* li, struct aluno al) {
    if (li == NULL || lista_cheia(li))
        return 0; // Falha na inserção
    
    // Insere o novo elemento no final
    li->dados[li->qtd] = al;
    li->qtd++;
    return 1; // Inserção com sucesso
}

// Função para inserir um elemento de forma ordenada na lista
int insere_lista_ordenada(Lista* li, struct aluno al) {
    if (li == NULL || lista_cheia(li))
        return 0; // Falha na inserção
    
    int pos = 0;
    while (pos < li->qtd && li->dados[pos].matricula < al.matricula)
        pos++;

    // Desloca os elementos para frente
    for (int i = li->qtd - 1; i >= pos; i--)
        li->dados[i + 1] = li->dados[i];
    
    // Insere o novo elemento na posição encontrada
    li->dados[pos] = al;
    li->qtd++;
    return 1; // Inserção com sucesso
}

// Função para remover um elemento do início da lista
int remove_lista_inicio(Lista* li) {
    if (li == NULL || lista_vazia(li))
        return 0; // Falha na remoção
    
    // Desloca os elementos para trás
    for (int i = 0; i < li->qtd - 1; i++)
        li->dados[i] = li->dados[i + 1];
    
    li->qtd--;
    return 1; // Remoção com sucesso
}

// Função para remover um elemento do final da lista
int remove_lista_final(Lista* li) {
    if (li == NULL || lista_vazia(li))
        return 0; // Falha na remoção
    
    li->qtd--;
    return 1; // Remoção com sucesso
}

// Função para remover um elemento específico da lista pela matrícula
int remove_lista(Lista* li, int mat) {
    if (li == NULL || lista_vazia(li))
        return 0; // Falha na remoção
    
    int pos = 0;
    while (pos < li->qtd && li->dados[pos].matricula != mat)
        pos++;
    
    if (pos == li->qtd) // Elemento não encontrado
        return 0;

    // Desloca os elementos para trás
    for (int i = pos; i < li->qtd - 1; i++)
        li->dados[i] = li->dados[i + 1];
    
    li->qtd--;
    return 1; // Remoção com sucesso
}

// Função para buscar um elemento pela posição na lista
int busca_lista_pos(Lista* li, int pos, struct aluno *al) {
    if (li == NULL || pos <= 0 || pos > li->qtd)
        return 0; // Posição inválida
    
    *al = li->dados[pos - 1];
    return 1; // Busca com sucesso
}

// Função para buscar um elemento pela matrícula na lista
int busca_lista_mat(Lista* li, int mat, struct aluno *al) {
    if (li == NULL || lista_vazia(li))
        return 0; // Lista vazia ou inválida
    
    int pos = 0;
    while (pos < li->qtd && li->dados[pos].matricula != mat)
        pos++;
    
    if (pos == li->qtd) // Elemento não encontrado
        return 0;
    
    *al = li->dados[pos];
    return 1; // Busca com sucesso
}

// Função para imprimir a lista de alunos com suas notas e média
void imprime_lista(Lista* li) {
    if (li == NULL || lista_vazia(li)) {
        printf("Lista vazia.\n");
        return;
    }

    printf("\nMatrícula\tNota 1\t\tNota 2\t\tMédia\n");
    printf("----------------------------------------------\n");
    for (int i = 0; i < li->qtd; i++) {
        struct aluno al = li->dados[i];
        float media = (al.notas[0] * 2 + al.notas[1] * 3) / 5.0;
        printf("%d\t\t%.1f\t\t%.1f\t\t%.2f\n", al.matricula, al.notas[0], al.notas[1], media);
    }
}

// Função principal para interação com o usuário
int main() {
    Lista* li = cria_lista();
    struct aluno al;
    int opcao, matricula, posicao;

    do {
        printf("\n1 - Inserir no início");
        printf("\n2 - Inserir no final");
        printf("\n3 - Inserir ordenado");
        printf("\n4 - Remover do início");
        printf("\n5 - Remover do final");
        printf("\n6 - Remover por matrícula");
        printf("\n7 - Buscar por posição");
        printf("\n8 - Buscar por matrícula");
        printf("\n9 - Imprimir lista");
        printf("\n0 - Sair");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite a matrícula: ");
                scanf("%d", &al.matricula);
                printf("Digite a primeira nota: ");
                scanf("%f", &al.notas[0]);
                printf("Digite a segunda nota: ");
                scanf("%f", &al.notas[1]);
                if (insere_lista_inicio(li, al))
                    printf("Aluno inserido com sucesso!\n");
                else
                    printf("Falha ao inserir aluno.\n");
                break;
            case 2:
                printf("Digite a matrícula: ");
                scanf("%d", &al.matricula);
                printf("Digite a primeira nota: ");
                scanf("%f", &al.notas[0]);
                printf("Digite a segunda nota: ");
                scanf("%f", &al.notas[1]);
                if (insere_lista_final(li, al))
                    printf("Aluno inserido com sucesso!\n");
                else
                    printf("Falha ao inserir aluno.\n");
                break;
            case 3:
                printf("Digite a matrícula: ");
                scanf("%d", &al.matricula);
                printf("Digite a primeira nota: ");
                scanf("%f", &al.notas[0]);
                printf("Digite a segunda nota: ");
                scanf("%f", &al.notas[1]);
                if (insere_lista_ordenada(li, al))
                    printf("Aluno inserido com sucesso!\n");
                else
                    printf("Falha ao inserir aluno.\n");
                break;
            case 4:
                if (remove_lista_inicio(li))
                    printf("Aluno removido do início com sucesso!\n");
                else
                    printf("Falha ao remover aluno do início.\n");
                break;
            case 5:
                if (remove_lista_final(li))
                    printf("Aluno removido do final com sucesso!\n");
                else
                    printf("Falha ao remover aluno do final.\n");
                break;
            case 6:
                printf("Digite a matrícula a ser removida: ");
                scanf("%d", &matricula);
                if (remove_lista(li, matricula))
                    printf("Aluno removido por matrícula com sucesso!\n");
                else
                    printf("Aluno não encontrado ou falha ao remover.\n");
                break;
            case 7:
                printf("Digite a posição a ser buscada: ");
                scanf("%d", &posicao);
                if (busca_lista_pos(li, posicao, &al))
                    printf("Aluno encontrado: Matrícula: %d, Nota 1: %.2f, Nota 2: %.2f\n", al.matricula, al.notas[0], al.notas[1]);
                else
                    printf("Posição inválida ou aluno não encontrado.\n");
                break;
            case 8:
                printf("Digite a matrícula a ser buscada: ");
                scanf("%d", &matricula);
                if (busca_lista_mat(li, matricula, &al))
                    printf("Aluno encontrado: Matrícula: %d, Nota 1: %.2f, Nota 2: %.2f\n", al.matricula, al.notas[0], al.notas[1]);
                else
                    printf("Aluno não encontrado.\n");
                break;
            case 9:
                imprime_lista(li);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    libera_lista(li);

    return 0;
}

