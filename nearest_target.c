/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearest_target.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:35:16 by eouhrich          #+#    #+#             */
/*   Updated: 2024/03/01 14:35:17 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nearest_target(int *arr_a, int a_size, int *sorted_arr, int sorted_size)
{
	int	i;
	int	top;

	i = 0;
	top = 0;
	while (i < a_size)
	{
		if (arr_include_nbr(sorted_arr, sorted_size, arr_a[i]) == 0)
		{
			top = i;
			break ;
		}
		i++;
	}
	return (top);
}
