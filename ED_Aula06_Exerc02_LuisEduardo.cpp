#include <stdio.h>

int get_altura(void)
{
	int Altura;
	do
	{
		printf("Altura:");
		scanf("%i", &Altura);
	}while(Altura <= 0 || Altura > 8);
	return Altura;
}

int main()
{
	int N, i, j, k;
	
	N = get_altura();
	
	i = 0;
	while (i < N)
	{
		k = 0;
		while (k < i)
		{
			printf(" ");
			k++;
		}
		
		j = 0;
		while (j < N - i)
		{
			printf("#");
			j++;
		}
		printf("  ");
		
		j = 0;
		while (j < N - i)
		{
			printf("#");
			j++;
		}
		printf("\n");
		i++;
		
	}
return 0;
}
