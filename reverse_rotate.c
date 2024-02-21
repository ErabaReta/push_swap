#include "push_swap.h"

void	reverse_rotate(int *arr, int size, char *msg)
{
	int	tmp;
	int	i;

	i = size - 1;
	tmp = arr[size - 1];
	while (i > 0)
	{
		arr[i] = arr[i - 1];
		i--;
	}
	arr[0] = tmp;
	if (msg[0] != '\0')
		write(1, msg, 4);
}