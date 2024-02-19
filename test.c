#include<stdio.h>

typedef struct s_cheapest
{
    int value;
    int indice;
    char path;
} t_cheapest;


int main ()
{
	t_cheapest a;
	a.value = 1;
	a.indice = 1;
	a.path = 1;
	t_cheapest b;
	b.value = 2;
	b.indice = 2;
	b.path = 2;

	b = a;

	printf("%d %d %d", b.value, b.indice, b.path);
}