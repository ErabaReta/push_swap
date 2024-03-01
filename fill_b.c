/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:27:20 by eouhrich          #+#    #+#             */
/*   Updated: 2024/03/01 14:27:22 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_b(int *arr_a, int *arr_b, int *a_size, int *b_size)
{
	int	sorted_size;
	int	*sorted_arr;

	sorted_arr = tallest_sorted_numbers(arr_a, *a_size, &sorted_size);
	if (sorted_size <= 3)
	{
		while (*a_size != 3)
		{
			write(1, "pb\n", 3);
			push(arr_a, arr_b, a_size, b_size);
		}
		return (free(sorted_arr));
	}
	while (arr_half_sorted(arr_a, *a_size) == 0)
	{
		move_not_sorted(arr_a, *a_size, sorted_arr, sorted_size);
		write(1, "pb\n", 3);
		push(arr_a, arr_b, a_size, b_size);
	}
	free(sorted_arr);
}
