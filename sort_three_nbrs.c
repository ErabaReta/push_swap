/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_nbrs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <eouhrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:20:53 by eouhrich          #+#    #+#             */
/*   Updated: 2024/03/09 17:34:31 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_nbrs(int *arr_a)
{
	if (min_indice(arr_a, 3) == 0)
	{
		swap(arr_a, 3, "sa\n");
		rotate(arr_a, 3, "ra\n");
	}
	else if (min_indice(arr_a, 3) == 1)
	{
		if (arr_a[0] > arr_a[2])
			rotate(arr_a, 3, "ra\n");
		else if (arr_a[0] < arr_a[2])
			swap(arr_a, 3, "sa\n");
	}
	else if (min_indice(arr_a, 3) == 2)
	{
		if (arr_a[0] < arr_a[1])
			reverse_rotate(arr_a, 3, "rra\n");
		else if (arr_a[0] > arr_a[2])
		{
			swap(arr_a, 3, "sa\n");
			reverse_rotate(arr_a, 3, "rra\n");
		}
	}
}
