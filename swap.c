#include "push_swap.h"


void	swap(int *arr, char *msg)
{
	int	tmp;

	tmp = arr[0];
	arr[0] = arr[1];
	arr[1] = tmp;
	write(1, msg, 3);
}
