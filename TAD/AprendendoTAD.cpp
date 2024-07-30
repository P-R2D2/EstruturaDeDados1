#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ponto Ponto;
//cria um novo ponto
Ponto* Ponto_cria(float x, float y);
//Libera um ponto
void Ponto_libera(Ponto* p);
//Acessa os valores "x" e "y" de um ponto
int Ponto_acessa(Ponto* p, float* x, float* y);
//Atribui os valores "x" e "y" a um ponto
int Ponto_atribui(Ponto* p, float x, float y);
//Calcula a distancia entre dois pontos
float Ponto_distancia(Ponto* p1, Ponto* p2);
struct ponto //Definição dos tipos de dados
{
	float x;
	float y;
};

//Criando um ponto
Ponto* Ponto_cria(float x, float y)
{
	Ponto* p = (Ponto*) malloc(sizeof(Ponto));
	if(p != NULL)
	{
		p->x = x;
		p->y = y;
	}
	return p;
}
//Destruindo o ponto alocado no TAD
void Ponto_libera(Ponto* p)
{
	free(p);
}
//Acessando as coordenadas do ponto por ref
int Ponto_Acessa (Ponto* p, float* x, float* y)
{
	if(p == NULL)
		return 0;
	*x = p->x;
	*y = p->y;
	return 1;
}
//Atribuindo um valor a um ponto
int Ponto_atribui(Ponto* p, float x, float y)
{
	if(p == NULL)
		return 0;
	p->x = x;
	p->y = y;
	return 1;
}
//Calculando a distancia entre dois pontos
float Ponto_distancia(Ponto* p1, Ponto* p2)
{
	if(p1 == NULL || p2 == NULL)
		return -1;
	float dx = p1->x - p2->x;
	float dy = p1->y - p2->y;
	return sqrt(dx * dx + dy * dy);
}

int main()
{
	float d;
	Ponto *p, *q;
	p = Ponto_cria(10.0,21.0);
	q = Ponto_cria(7.0,25.0);
	d = Ponto_distancia(p,q);
	printf("Distancia entre dois pontos: %f\n", d);
	Ponto_libera(q);
	Ponto_libera(p);
	system("pause");
	return 0;
}
