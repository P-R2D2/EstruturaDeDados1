#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define N 4000
//A função recebe o calculo de frases, palavras e letras e retorna o calculo de indice de coleman-liau
float calculocolemanliau(float frases, float palavras, float letras) {
    float S = (float)letras / palavras * 100;
    float L = (float)frases / palavras * 100;
    return round(0.0588 * L - 0.296 * S - 15.8);
}
//A função recebe a String informada no main e logo em seguida calcula a quantidade de letras na string e retorna a quantidade -1 para não contar um caracter a mais
int numeroletras(char Letras[]) {
    int i;
	float caracteres = 0;
    for (i = 0; i < strlen(Letras); i++) {
        if (isalnum(Letras[i]))
            caracteres++;
    }
    return caracteres;
}

float numeropalavras(char Palavras[]) {
    int i;
	float quantidadepalavras = 0;
     for (i = 0; i < strlen(Palavras); i++) {
        if (isalnum(Palavras[i]))
            quantidadepalavras++;
    }
    return quantidadepalavras;
}

float numerofrases(char Frases[]) {
    int i;
	float frases = 0;
    for (i = 0; i < strlen(Frases); i++) {
        if (Frases[i] == '.' || Frases[i] == ',' || Frases[i] == '?')
            frases++;
    }
    return frases;
}
int verificafinal(char Resumo){
	if (Resumo == '!' || Resumo == '.' || Resumo == '?')
	{
		return 1;
	}
	else
	return 0;
}
int main() {
    char ResumoLivro[N];
    float Frases, Palavras, Letras;
    int Grade, I;
    gets(ResumoLivro);
    Frases = numerofrases(ResumoLivro);
    Palavras = numeropalavras(ResumoLivro);
    Letras = numeroletras(ResumoLivro);
    if(ResumoLivro[I] == '\0' && !verificafinal(ResumoLivro[I-1]) && !verificafinal(ResumoLivro[I-2]))
	{
    	Palavras++;
    	Frases++;
	}else{
		Palavras++;
	}
	
    Grade = calculocolemanliau(Frases, Palavras, Letras);

   if (Grade > 16)
	{
		printf ("Grade 16+");
	}
	else
	{
		if (Grade < 1)
		{
			printf ("Before Grade 1");
		}
		else 
		{
			printf ("Grade %i", Grade);
		}
	}
    return 0;
}

