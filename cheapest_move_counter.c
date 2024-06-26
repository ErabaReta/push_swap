/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_move_counter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <eouhrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 23:44:03 by eouhrich          #+#    #+#             */
/*   Updated: 2024/03/09 20:23:10 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cheapest	cheapest_move_counter(int *arr_b, int *arr_a, int b_size,
		int a_size)
{
	t_cheapest	cheapest;
	t_cheapest	tmp;
	int			i;
	int			rank;

	i = 0;
	cheapest.value = a_size + b_size + 1;
	while (i < b_size)
	{
		rank = (rank_calc(arr_a, a_size, arr_b[i])) % a_size;
		tmp = path_counter(i, rank, a_size, b_size);
		if (tmp.value < cheapest.value)
		{
			cheapest = tmp;
			cheapest.indice = i;
			cheapest.rank = rank;
		}
		i++;
	}
	return (cheapest);
}
