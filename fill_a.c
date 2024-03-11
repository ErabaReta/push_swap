/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <eouhrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:25:04 by eouhrich          #+#    #+#             */
/*   Updated: 2024/03/09 20:24:18 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_a(int *arr_a, int *arr_b, int *a_size, int *b_size)
{
	while (*b_size != 0)
	{
		move_cheapest(arr_b, arr_a, *b_size, *a_size);
		push(arr_b, arr_a, b_size, a_size);
		write(1, "pa\n", 3);
	}
	while (min_indice(arr_a, *a_size) != 0)
	{
		if (min_indice(arr_a, *a_size) <= (*a_size / 2))
			rotate(arr_a, *a_size, "ra\n");
		else
			reverse_rotate(arr_a, *a_size, "rra\n");
	}
}
