/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:32:55 by eouhrich          #+#    #+#             */
/*   Updated: 2024/03/01 14:32:56 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <eouhrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 23:53:22 by eouhrich          #+#    #+#             */
/*   Updated: 2024/02/22 22:09:44 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_cheapest(int *arr_b, int *arr_a, int b_size, int a_size)
{
	t_cheapest	cheapest_move;

	cheapest_move = cheapest_move_counter(arr_b, arr_a, b_size, a_size);
	if (cheapest_move.path == 1)
	{
		up_up(arr_a, arr_b, a_size, b_size);
	}
	else if (cheapest_move.path == 2)
	{
		up_down(arr_a, arr_b, a_size, b_size);
	}
	else if (cheapest_move.path == 3)
	{
		down_up(arr_a, arr_b, a_size, b_size);
	}
	else if (cheapest_move.path == 4)
	{
		down_down(arr_a, arr_b, a_size, b_size);
	}
}
