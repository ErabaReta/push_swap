/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <eouhrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:14:25 by eouhrich          #+#    #+#             */
/*   Updated: 2024/03/01 14:54:34 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(int *arr_a, int a_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < a_size - 1)
	{
		j = i + 1;
		while (j < a_size)
		{
			if (arr_a[i] == arr_a[j])
			{
				write(2, "Error\n", 6);
				free(arr_a);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
