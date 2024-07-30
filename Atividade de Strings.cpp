#include <stdio.h>
#include <ctype.h>


//Recebe uma string e retorna o número de caracteres da string (sem contar o '\0').
int strlen (char *s)
{    
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}
//Recebe uma string e verifica se a string está nula retorna 1 para sim e 0 para não
int isnull(char *s)
{
  return (s[0] == '\0');
}
//Recebe uma string da origem e copia para a string destino
//Ao final retorna o ponteiro para o vetor de destino
char *strcpy (char *dest, char *orig)
{
    int i;
    for (i=0 ; orig[i]!='\0' ; i++)
        dest[i] = orig[i];
    dest[i] = '\0';
    return dest;
}

//Recebe duas strings (origem e destino) e concatena o conteudo no fim da destino
//Retorna o ponteiro para a String de destino
char *strcat (char *dest, char *orig)
{
    int i, len;
    for (i = 0, len = strlen (dest) ; orig[i] != '\0' ; i++, len++)
        dest[len] = orig[i];
    dest[len]='\0';
    return dest;
}

//A função recebe uma string e um caracter
//E retorna quantas vezes o caracter aparece na string
int strcountc (char *s, char ch)
{
    int i, conta;
    for (i = conta = 0 ; s[i] != '\0' ; i++)
        if (s[i] == ch)
            conta++;
    return conta;
}
//A função recebe uma string
//E retorna quantas vezes dígitos numéricos aparecem nela
int strcountd(char *s)
{
    int i, conta;
    for (i = conta = 0 ; s[i] != '\0'; i++)
        if (isdigit (s[i]))
            conta++;
    return conta;
}
//A função recebe uma string e um caracter
//E retorna o indice onde o caracter aparece pela primeira vez na string
int indchr(char *s,char ch)
{
    int i;
    for (i = 0 ; s[i] != '\0' ; i++)
        if (s[i] == ch)
            return i;
    return -1;
}
//A função recebe a string e verifica se é um palíndromo ou seja
// Se ele é lida da mesma forma mesmo invertida de tras para frente e vice versa
// Em caso de ser um palindromo devolve 1 se não devolve 0
int strpal(char *s)
{
    int i,j;
    for (i = 0, j = strlen(s)-1 ; i < j ; i++, j--)
        if (s[i]!=s[j])
            return 0;
    return 1;
}
//A função recebe a string e a inverte
//E retorna o ponteiro para a da string invertida
char * strrev(char *s)
{
    int i,len;
    char aux;
    for (i = 0,len = strlen (s)-1 ; i < len ; i++, len--)
    {
        aux=s[i];
        s[i] = s[len];
        s[len]= aux;
    }
    return s;
}
//A função recebe duas strings e as compara alfabeticamente
//Se a s1 > s2 seu Retorno é > 
//Se a s1 < s2 seu Retorno é <
//Se si = s2 seu Retorno é =
int strcmp(char *s1 ,char *s2)
{
    int i=0;
    while (s1[i]==s2[i] && s1[i]!='\0')
        i++;
    return (s1[i] - s2[i]);
}
//A funçaõ recebe a string e coloca um espaço em branco entre cada caracter
//E depois retorna o ponteiro para a string com espaços
char * strpad(char *s)
{
    int i = strlen(s);
    s[2*i] = s[i]; /* Colocar o delimitador na nova posição */
    for (i-- ; i >= 0 ; i--)
    {
        s[2*i] = s[i];
        s[2*i+1] = ' ';
    }
    return s;
}
//Recebe uma string e um caracter
//Logo após apaga as aparições do caracter escolhido
//E depois retorna para a string com os caracteres apagados
char * strdelc(char *s , char ch)
{
    int i,j;
    for (i = j = 0 ; s[i] != '\0' ; i++)
        if (s[i] != ch)
            s[j++] = s[i];
    s[j] = '\0';
    return s;
}
//A função recebve uma variável de string e lê uma string que sera digitada
//Retorna o ponteiro para a string inserida 
char *mygets(char *s)
{
    int i = 0, ch;
    while ((ch=getchar())!='\n')
        s[i++]=ch;
    s[i] = '\0';
    return s;
}
//A função recebe uma string e um caracter
//Coloca em todas as posições da string o caracter escolhido
//E depois retorna o ponteiro para a string alterada
char *strset(char *s , char ch)
{
    int i;
    for (i=0 ; s[i] != '\0' ; i++)
        s[i] = ch;
    return s;
}
//A função recebe a string e coloca todos os caracteres em maiusculo
//Retorna o ponteiro para a string alterada.
char *strupr(char *s)
{
    int i;
    for (i = 0 ; s[i] != '\0' ; i++)
        s[i] = toupper (s[i]);
    return s;
}
main()
{
    char Nome[100];
    char Sobrenome[100];
    
   //printf("Informe o nome:");
    gets (Nome);
    //printf("Informe o sobrenome:");
    gets (Sobrenome);
    
    if (isnull(Sobrenome))
    {
        printf("O sobrenome está nulo!\n");
        printf("Foi atribuído o nome: %s para o sobrenome: %s.\n", Nome, strcpy(Sobrenome, Nome));
    }
    printf ("O nome \"%s\" contém %i caracteres.\n",Nome, strlen(Nome));
    printf ("O Nome \"%s\" contém %i dígito(s).\n", Nome, strcountd(Nome));
    printf ("O Nome \"%s\" contém %i caractere(s) \'%c\'. A primeira ocorrência é na posição %i.\n", Nome, strcountc(Nome, 'a'), 'a', indchr(Nome,'a')+1);
    printf ("Referência: \"%s, %s\"\n",strupr(Sobrenome), Nome);
    printf ("Concatenando sobrenome e nome: %s.\n", strcat(Sobrenome, Nome));
    if (strpal(Nome))
        printf("O Nome \"%s\" é palíndromo. Ou seja, pode ser lido da direita para a esquerda: \"%s\".\n", Nome, strrev(Nome));    
    else 
    {
        printf("O Nome \"%s\" não é palíndromo. ", Nome);
        printf("Ou seja, não pode ser lido da direita para a esquerda: \"%s\".\n",strrev(Nome));    
    }
}

