#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#define T 100

int main (int argc, char *argv[]){
	int k,i;
	char Plaintext[T];
	k = atoi(argv[1]);
	printf("Plaintext:");
	//Verifica se a quantidade de argumentos e diferente de dois
	//informa ao usuário que a chave é invalida em caso verdadeiro
	if(argc !=  2)
	{
		printf("Quantidade de argumentos invalida!");
		return 1;
	}
	//Verifica caracter a caracter, em argv para conferir se é um numero
	//se nenhum deles for um numero de 0 a 9 ele fecha o programa
	for(i = 0; i < strlen(argv[1]); i++)
	{

		if(!isdigit(argv[1][i]) && argv[1][i] > 0 && argv[1][i] <= 26)
		{
			printf("Nenhum numero para criptografar ou ele e invalido");
			return 1;
		}
	}
	
	gets(Plaintext);
	printf("Ciphertext:");
	
	for(i = 0; i < strlen(Plaintext); i++)
	{
		if(isupper(Plaintext[i]))
		{
				printf("%c", (Plaintext[i] - 65 + k) % 26 + 65);
		}
	    else if(islower(Plaintext[i]))
		{
	    		printf("%c", (Plaintext[i] - 97 + k) % 26 + 97);
		}
		else
		{
			printf("%c", Plaintext[i]);
		}
	
	}
	printf("\n");
	return 0;
}


