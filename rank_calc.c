#include "push_swap.h"

int	rank_calc(int *arr, int arr_size, int nbr)
{
	int				i;
	int				rank;
	unsigned int	shortest_dist;

	shortest_dist = ft_abs(nbr - arr[0]);
	i = 1;
	rank = 0;
	while (i < arr_size)
	{
		if (shortest_dist > ft_abs(nbr - arr[i]))
		{
			shortest_dist = ft_abs(nbr - arr[i]);
			rank = i;
		}
		i++;
	}
	if (nbr > arr[rank])
		rank += 1;
	return (rank);
}
