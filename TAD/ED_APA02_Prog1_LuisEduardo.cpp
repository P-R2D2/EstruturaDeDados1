#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Tamanho m�ximo da lista est�tica

// Estrutura do aluno
struct aluno {
    int matricula;
    float notas[2]; // Notas de cada aluno (duas notas)
};

// Estrutura da lista est�tica
typedef struct {
    struct aluno dados[MAX];
    int qtd;
} Lista;

// Fun��o para criar uma lista
Lista* cria_lista() {
    Lista *li;
    li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL) {
        li->qtd = 0;

        // Inicializa com os valores padr�o de matr�cula e notas
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

// Fun��o para liberar a lista da mem�ria
void libera_lista(Lista* li) {
    free(li);
}

// Fun��o para retornar o tamanho da lista
int tamanho_lista(Lista* li) {
    if (li == NULL)
        return -1; // Erro
    else
        return li->qtd;
}

// Fun��o para verificar se a lista est� cheia
int lista_cheia(Lista* li) {
    if (li == NULL)
        return -1; // Erro
    return (li->qtd == MAX);
}

// Fun��o para verificar se a lista est� vazia
int lista_vazia(Lista* li) {
    if (li == NULL)
        return -1; // Erro
    return (li->qtd == 0);
}

// Fun��o para inserir um elemento no in�cio da lista
int insere_lista_inicio(Lista* li, struct aluno al) {
    if (li == NULL || lista_cheia(li))
        return 0; // Falha na inser��o

    // Desloca os elementos para frente
    for (int i = li->qtd - 1; i >= 0; i--)
        li->dados[i + 1] = li->dados[i];
    
    // Insere o novo elemento no in�cio
    li->dados[0] = al;
    li->qtd++;
    return 1; // Inser��o com sucesso
}

// Fun��o para inserir um elemento no final da lista
int insere_lista_final(Lista* li, struct aluno al) {
    if (li == NULL || lista_cheia(li))
        return 0; // Falha na inser��o
    
    // Insere o novo elemento no final
    li->dados[li->qtd] = al;
    li->qtd++;
    return 1; // Inser��o com sucesso
}

// Fun��o para inserir um elemento de forma ordenada na lista
int insere_lista_ordenada(Lista* li, struct aluno al) {
    if (li == NULL || lista_cheia(li))
        return 0; // Falha na inser��o
    
    int pos = 0;
    while (pos < li->qtd && li->dados[pos].matricula < al.matricula)
        pos++;

    // Desloca os elementos para frente
    for (int i = li->qtd - 1; i >= pos; i--)
        li->dados[i + 1] = li->dados[i];
    
    // Insere o novo elemento na posi��o encontrada
    li->dados[pos] = al;
    li->qtd++;
    return 1; // Inser��o com sucesso
}

// Fun��o para remover um elemento do in�cio da lista
int remove_lista_inicio(Lista* li) {
    if (li == NULL || lista_vazia(li))
        return 0; // Falha na remo��o
    
    // Desloca os elementos para tr�s
    for (int i = 0; i < li->qtd - 1; i++)
        li->dados[i] = li->dados[i + 1];
    
    li->qtd--;
    return 1; // Remo��o com sucesso
}

// Fun��o para remover um elemento do final da lista
int remove_lista_final(Lista* li) {
    if (li == NULL || lista_vazia(li))
        return 0; // Falha na remo��o
    
    li->qtd--;
    return 1; // Remo��o com sucesso
}

// Fun��o para remover um elemento espec�fico da lista pela matr�cula
int remove_lista(Lista* li, int mat) {
    if (li == NULL || lista_vazia(li))
        return 0; // Falha na remo��o
    
    int pos = 0;
    while (pos < li->qtd && li->dados[pos].matricula != mat)
        pos++;
    
    if (pos == li->qtd) // Elemento n�o encontrado
        return 0;

    // Desloca os elementos para tr�s
    for (int i = pos; i < li->qtd - 1; i++)
        li->dados[i] = li->dados[i + 1];
    
    li->qtd--;
    return 1; // Remo��o com sucesso
}

// Fun��o para buscar um elemento pela posi��o na lista
int busca_lista_pos(Lista* li, int pos, struct aluno *al) {
    if (li == NULL || pos <= 0 || pos > li->qtd)
        return 0; // Posi��o inv�lida
    
    *al = li->dados[pos - 1];
    return 1; // Busca com sucesso
}

// Fun��o para buscar um elemento pela matr�cula na lista
int busca_lista_mat(Lista* li, int mat, struct aluno *al) {
    if (li == NULL || lista_vazia(li))
        return 0; // Lista vazia ou inv�lida
    
    int pos = 0;
    while (pos < li->qtd && li->dados[pos].matricula != mat)
        pos++;
    
    if (pos == li->qtd) // Elemento n�o encontrado
        return 0;
    
    *al = li->dados[pos];
    return 1; // Busca com sucesso
}

// Fun��o para imprimir a lista de alunos com suas notas e m�dia
void imprime_lista(Lista* li) {
    if (li == NULL || lista_vazia(li)) {
        printf("Lista vazia.\n");
        return;
    }

    printf("\nMatr�cula\tNota 1\t\tNota 2\t\tM�dia\n");
    printf("----------------------------------------------\n");
    for (int i = 0; i < li->qtd; i++) {
        struct aluno al = li->dados[i];
        float media = (al.notas[0] * 2 + al.notas[1] * 3) / 5.0;
        printf("%d\t\t%.1f\t\t%.1f\t\t%.2f\n", al.matricula, al.notas[0], al.notas[1], media);
    }
}

// Fun��o principal para intera��o com o usu�rio
int main() {
    Lista* li = cria_lista();
    struct aluno al;
    int opcao, matricula, posicao;

    do {
        printf("\n1 - Inserir no in�cio");
        printf("\n2 - Inserir no final");
        printf("\n3 - Inserir ordenado");
        printf("\n4 - Remover do in�cio");
        printf("\n5 - Remover do final");
        printf("\n6 - Remover por matr�cula");
        printf("\n7 - Buscar por posi��o");
        printf("\n8 - Buscar por matr�cula");
        printf("\n9 - Imprimir lista");
        printf("\n0 - Sair");
        printf("\nEscolha uma op��o: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite a matr�cula: ");
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
                printf("Digite a matr�cula: ");
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
                printf("Digite a matr�cula: ");
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
                    printf("Aluno removido do in�cio com sucesso!\n");
                else
                    printf("Falha ao remover aluno do in�cio.\n");
                break;
            case 5:
                if (remove_lista_final(li))
                    printf("Aluno removido do final com sucesso!\n");
                else
                    printf("Falha ao remover aluno do final.\n");
                break;
            case 6:
                printf("Digite a matr�cula a ser removida: ");
                scanf("%d", &matricula);
                if (remove_lista(li, matricula))
                    printf("Aluno removido por matr�cula com sucesso!\n");
                else
                    printf("Aluno n�o encontrado ou falha ao remover.\n");
                break;
            case 7:
                printf("Digite a posi��o a ser buscada: ");
                scanf("%d", &posicao);
                if (busca_lista_pos(li, posicao, &al))
                    printf("Aluno encontrado: Matr�cula: %d, Nota 1: %.2f, Nota 2: %.2f\n", al.matricula, al.notas[0], al.notas[1]);
                else
                    printf("Posi��o inv�lida ou aluno n�o encontrado.\n");
                break;
            case 8:
                printf("Digite a matr�cula a ser buscada: ");
                scanf("%d", &matricula);
                if (busca_lista_mat(li, matricula, &al))
                    printf("Aluno encontrado: Matr�cula: %d, Nota 1: %.2f, Nota 2: %.2f\n", al.matricula, al.notas[0], al.notas[1]);
                else
                    printf("Aluno n�o encontrado.\n");
                break;
            case 9:
                imprime_lista(li);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Op��o inv�lida.\n");
        }
    } while (opcao != 0);

    libera_lista(li);

    return 0;
}

