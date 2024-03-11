/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_down.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <eouhrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:21:58 by eouhrich          #+#    #+#             */
/*   Updated: 2024/03/09 20:25:59 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	up_down(int *arr_a, int *arr_b, int a_size, int b_size)
{
	t_cheapest	cheapest_move;
	int			i;

	i = 0;
	cheapest_move = cheapest_move_counter(arr_b, arr_a, b_size, a_size);
	while (i < cheapest_move.indice)
	{
		rotate(arr_b, b_size, "rb\n");
		i++;
	}
	i = 0;
	while (a_size - i > cheapest_move.rank)
	{
		reverse_rotate(arr_a, a_size, "rra\n");
		i++;
	}
}
