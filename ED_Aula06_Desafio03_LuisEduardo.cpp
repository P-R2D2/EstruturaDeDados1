#include <stdio.h>
#define ESPACO ' '
#define DIM 3

/* Define os espaços do tabuleiro */
void inicia_espacos(char s[][DIM])
{    
    int i, j;
    for (i = 0; i < DIM; i++)
        for (j = 0; j < DIM; j++)
            s[i][j] = ESPACO;
}

/* Desenha o tabuleiro na tela */
void desenha_tabuleiro(char s[DIM][DIM])
{ 
    int i, j;
    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
            printf("%c %c", s[i][j], j == DIM - 1 ? ' ' : '|');
        if (i != DIM - 1) 
            printf("\n--------");
        putchar('\n');
    }
}

/* Verifica se alguma linha, coluna ou diagonal está preenchida com o caractere ch */
int Ganhou(char g[DIM][DIM], char ch)
{
    int i;

    // Verifica linhas
    for (i = 0; i < DIM; i++) {
        if (g[i][0] == ch && g[i][1] == ch && g[i][2] == ch)
            return 1;
    }

    // Verifica colunas
    for (i = 0; i < DIM; i++) {
        if (g[0][i] == ch && g[1][i] == ch && g[2][i] == ch)
            return 1;
    }

    // Verifica diagonal principal
    if (g[0][0] == ch && g[1][1] == ch && g[2][2] == ch)
        return 1;

    // Verifica diagonal secundária
    if (g[0][2] == ch && g[1][1] == ch && g[2][0] == ch)
        return 1;

    return 0; // Não ganhou o jogo
}

int main()
{
    char Jogo_da_Velha[DIM][DIM];
    int posx, posy;
    char ch = '0'; // Caractere a Jogar
    int n_jogadas = 0;
    inicia_espacos(Jogo_da_Velha);

    while (1) // Laço Infinito
    { 
        desenha_tabuleiro(Jogo_da_Velha);
        printf("\nIntroduza a Posição de Jogo Linha Coluna: ");
        scanf("%d %d", &posx, &posy);

        if (posx > DIM || posy > DIM)
        {
            printf("\n\n**** Valores Inválidos ****\n\n");
            continue; // Próxima iteração
        }

        posx--;
        posy--; // Os índices do vetor começam em ZERO
        
        if (Jogo_da_Velha[posx][posy] == ESPACO) // Casa Livre para jogadas
        { 
            Jogo_da_Velha[posx][posy] = ch = (ch == '0') ? 'X' : '0';
            n_jogadas++;

            if (Ganhou(Jogo_da_Velha, ch)) // Basta verificar o jogador corrente
            {
                printf("\n\n**** Ganhou o Jogador %c ****\n\n", ch);
                break;
            }
        }
        else
            printf("Posição já ocupada\nJogue Novamente!!!\n");

        if (n_jogadas == DIM * DIM)
        { 
            printf("\n\n**** EMPATE TÉCNICO ****\n\n");
            break; // Encerrar o Laço
        }
    }

    desenha_tabuleiro(Jogo_da_Velha);
    return 0;
}

