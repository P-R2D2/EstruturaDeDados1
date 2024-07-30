#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int compute_score(char *Word);

int main(void)
{
	char Word1[20], Word2[20];
	
    // Get input words from both players
    
    printf("Player 1: ");
    scanf("%s", Word1);
    printf("Player 2: ");
    scanf("%s", Word2);
    

    // Score both words
    int score1 = compute_score(Word1);
    int score2 = compute_score(Word2);

    // TODO: Print the winner
    if(score1 > score2)
      printf("Player 1 ganhou com %d pontos\n", score1);
    else if(score2 > score1)
      printf("Player 2 ganhou com %d pontos\n", score2);
    else
      printf("Empate\n");
}

int compute_score(char *Word)
{
    int i, score = 0 ;
    for(i = 0; i < strlen(Word); i++)
    {
        if(isupper(Word[i]))
          score = score + POINTS[Word[i] - 65];
        if(islower(Word[i]))
          score = score + POINTS[Word[i] - 97];
    }
    return score;
}


