#include "push_swap.h"

int	check_duplicate(int *arr_a, int a_size)
{
	int	i;
	int	j;

	i = 0;
	while(i < a_size - 1)
	{
		j = i + 1;
		while(j < a_size)
		{
			if (arr_a[i] == arr_a[j])
			{
				write(1, "Error\n", 6);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}