#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define N 500

int calculocolemanliau(int frases, int palavras, int letras) {
    if (palavras == 0) return 0; // Verifica se o denominador é zero
    float S = (float)letras / palavras * 100;
    float L = (float)frases / palavras * 100;
    return round(0.0588 * L - 0.296 * S - 15.8);
}

int numeroletras(char Letras[]) {
    int i;
    float caracteres = 0;
    for (i = 0; i < strlen(Letras); i++) {
        if (isalpha(Letras[i]) != 0)
            caracteres++;
    }
    return caracteres;
}

int numeropalavras(char Palavras[]) {
    int i = 0, quantidadepalavras = 0;
    while (Palavras[i] != '\n' && Palavras[i] != '\0') {
        while (Palavras[i] == ' ')
            i++;
        if (Palavras[i] != '\0') // Verifica se não é o final da string
            quantidadepalavras++;
        while (Palavras[i] != ' ' && Palavras[i] != '\n' && Palavras[i] != '\0')
            i++;
    }
    return quantidadepalavras;
}

int numerofrases(char Frases[]) {
    int i;
    float frases = 0;
    for (i = 0; i < strlen(Frases); i++) {
        if (Frases[i] == '.' || Frases[i] == ',' || Frases[i] == '?')
            frases++;
    }
    return frases;
}

int main() {
    char ResumoLivro[N] = "As the average number of letters and words per sentence increases, the Coleman-Liau index gives the text a higher reading level. If you were to take this paragraph, for instance, which has longer words and sentences than either of the prior two examples, the formula would give the text an eleventh grade reading level.";
    int Frases, Palavras, Letras;
    int Grade;
    printf("Texto fornecido:\n%s\n\n", ResumoLivro);
    Frases = numerofrases(ResumoLivro);
    Palavras = numeropalavras(ResumoLivro);
    Letras = numeroletras(ResumoLivro);
    Grade = calculocolemanliau(Frases, Palavras, Letras);

    if (Grade < 1)
        printf("Before grade 1\n");
    else if (Grade > 16)
        printf("Grade 16+\n");
    else
        printf("Grade %d\n", Grade);

    return 0;
}

