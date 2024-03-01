/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_not_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:21:32 by eouhrich          #+#    #+#             */
/*   Updated: 2024/03/01 14:21:33 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_not_sorted(int *arr_a, int a_size, int *sorted_arr,
		int sorted_size)
{
	int	i;
	int	nearest;

	i = 0;
	nearest = nearest_target(arr_a, a_size, sorted_arr, sorted_size);
	if (nearest < (a_size / 2))
	{
		while (i < nearest)
		{
			rotate(arr_a, a_size, "ra\n");
			i++;
		}
	}
	else
	{
		while (a_size > i + nearest)
		{
			reverse_rotate(arr_a, a_size, "rra\n");
			i++;
		}
	}
}
