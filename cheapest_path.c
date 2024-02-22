/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 23:44:40 by eouhrich          #+#    #+#             */
/*   Updated: 2024/02/21 23:44:49 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cheapest	cheapest_path(int up_up, int up_down, int down_up, int down_down)
{
	t_cheapest	min;

	min.value = up_up;
	min.path = 1;
	if (min.value > up_down)
	{
		min.value = up_down;
		min.path = 2;
	}
	if (min.value > down_up)
	{
		min.value = down_up;
		min.path = 3;
	}
	if (min.value > down_down)
	{
		min.value = down_down;
		min.path = 4;
	}
	return (min);
}
