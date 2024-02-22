/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <eouhrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:17:46 by eouhrich          #+#    #+#             */
/*   Updated: 2024/02/22 22:08:32 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rank_calc(int *arr, int arr_size, int nbr)
{
	int				i;
	int				rank;
	size_t	shortest_dist;

	shortest_dist = ft_abs((long long)nbr - arr[0]);
	i = 1;
	rank = 0;
		// printf(" ranking.. : nbr => %d | indice => %d | arr_size => %d | dist => %lu\n", nbr, 0, arr_size, shortest_dist);
	while (i < arr_size)
	{
		// printf("ranking.. : nbr => %d | indice => %d | arr_size => %d | dist => %lu\n", nbr, i, arr_size, shortest_dist);
		if (shortest_dist > ft_abs((long long)nbr - arr[i]))
		{
			shortest_dist = ft_abs((long long)nbr - arr[i]);
			rank = i;
		}
		i++;
	}
	if (nbr > arr[rank])
		rank += 1;
	return (rank);
}
