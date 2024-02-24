#include "push_swap.h"

int	sorted_numbers_range(int *arr_a, int a_size, int i)
{
	int	count;
	int tmp;
	int	tmp_i;


	tmp = arr_a[i];
	count = 1;
	tmp_i = i;
	while (tmp_i < a_size)
	{
		if (tmp < arr_a[tmp_i])
		{
			tmp = arr_a[tmp_i];
			count++;
		}
		tmp_i++;////
	}
	tmp_i = 0;
	while (tmp_i < i)
	{
		if (tmp < arr_a[tmp_i])
		{
			tmp = arr_a[tmp_i];
			count++;
		}
		tmp_i++;////
	}
	return (count);
}

int *tallest_sorted_numbers(int *arr_a, int a_size, int	*sorted_size)
{
	int	*sorted_arr;
	int i;
	int indice;
	int	tmp;

	i = 0;
	*sorted_size = 0;
	indice = 0;
	
	while(i < a_size)
	{		
		if (sorted_numbers_range(arr_a, a_size, i) >= *sorted_size)
		{
			*sorted_size = sorted_numbers_range(arr_a, a_size, i);
			indice = i;
		}
		i++;
	}
	sorted_arr = (int *)malloc((*sorted_size) * sizeof(int));
	sorted_arr[0] = arr_a[indice];
	i = 0;
	tmp = indice;
	while (indice < a_size && i < *sorted_size)
	{
		if (arr_a[indice] > sorted_arr[i])
		{
			i++;
			sorted_arr[i] = arr_a[indice];
		}
		indice++;
	}
	indice = 0;

	while (indice < tmp && i < *sorted_size)
	{
		if (arr_a[indice] > sorted_arr[i])
		{
			i++;
			sorted_arr[i] = arr_a[indice];
		}
		indice++;
	}
	return (sorted_arr);
}
