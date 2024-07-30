#include <stdio.h>
#include <String.h>
#include <ctype.h>
#define T 500
int main (int argc, char *argv[])
{
    char key[T],plaintext[T];
    int i,j, letra;
    //Verfica se possui apenas dois argumentos na chamada do programa
    if (argc != 2)
    {
        printf("Quantidade de argumentos invalida!\n");
        printf("Forma correta: substituicao key");
        return 1;
    }
    //Verifica se o argumento argv[1] são apenas letras do alfabeto
    strcpy(key,argv[1]);
    for(i = 0; i < strlen(key); i++)
    {
        if(!isalpha(key[i]))
        {
         printf("Chave invalida, so letras sao permitidas");
         return 1;
        }
    }
    //Verifica se o argv[1] tem 26 letras para o alfabeto de criptografia
    if (strlen(key) !=  26)
    {
        printf("A chave deve possuir 26 caracteres");
        return 1;
    }
    //Verifica cada letra do alfabeto para que ela não se repita caso contrario o programa fecha
    for (i = 0; i < strlen(key); i++)
    {
        for (j = i + 1; j < strlen(key); j++)
        {
            if (toupper(key[i]) == toupper(key[j]))
            {
                printf("Caracteres repetidos, informe caracteres diferentes");
                return 1;
            }
        }
    }
    printf("Plaintext:");
    gets(plaintext);
    
    //Converto todas as letras em upper para poder comparar
    for (i = 0; i < strlen(key); i++)
    {
        if (islower(key[i]))
        {
            key[i] = key[i] - 32;
        }
    }
    
    //Mostro o texto criptografado
    printf("Ciphertext: ");
    for(i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            letra = plaintext[i] - 65;
            printf("%c", key[letra]);
        }
        else if (islower(plaintext[i]))
        {
            letra = plaintext[i] - 97;
            printf("%c", key[letra] + 32);
        }
        else
          printf("%c", plaintext[i]);
    }
    printf("\n");
    return 0;
}


