#include "push_swap.h"

int	min_indice(int *arr, int size)
{
	int	i;
	int	min;
	int	indice;

	i = 1;
	min = arr[0];
	indice = 0;
	while (i < size)
	{
		if (min > arr[i])
		{
			min = arr[i];
			indice = i;
		}
		i++;
	}
	return (indice);
}