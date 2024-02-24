#include "push_swap.h"

int	arr_half_sorted(int *arr, int size)
{
	int	min;

	min = min_indice(arr, size);
	if ((arr[size - 1] < arr[0] && arr_is_sorted(arr, min) && arr_is_sorted(&arr[min], size - min)) || arr_is_sorted(arr, size))
		return (1);
	return (0);
}