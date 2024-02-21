#include "push_swap.h"

void	rotate(int *arr, int size, char *msg)
{
	int	tmp;
	int	i;

	tmp = arr[0];
	i = 0;
	while (i < size - 1)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[size - 1] = tmp;
	if (msg[0] != '\0')
		write(1, msg, 3);
}
