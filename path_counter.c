/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_counter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:14:23 by eouhrich          #+#    #+#             */
/*   Updated: 2024/02/22 00:15:15 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cheapest	path_counter(int i, int rank, int a_size, int b_size)
{
	if (i > rank)
	{
		if (b_size - i > a_size - rank)
			return (cheapest_path(i, i + (a_size - rank), (b_size - i) + rank,
					b_size - i));
		else
			return (cheapest_path(i, i + (a_size - rank), (b_size - i) + rank,
					a_size - rank));
	}
	else
	{
		if (b_size - i > a_size - rank)
			return (cheapest_path(rank, i + (a_size - rank), (b_size - i)
					+ rank, b_size - i));
		else
			return (cheapest_path(rank, i + (a_size - rank), (b_size - i)
					+ rank, a_size - rank));
	}
}