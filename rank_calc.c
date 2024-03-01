/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <eouhrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:17:46 by eouhrich          #+#    #+#             */
/*   Updated: 2024/03/01 14:43:00 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rank_calc(int *arr, int arr_size, int nbr)
{
	int				i;
	int				rank;
	size_t			shortest_dist;

	shortest_dist = ft_abs((long long)nbr - arr[0]);
	i = 1;
	rank = 0;
	while (i < arr_size)
	{
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
