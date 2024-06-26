/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_include_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <eouhrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:42:26 by eouhrich          #+#    #+#             */
/*   Updated: 2024/03/09 20:22:57 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arr_include_nbr(int *sorted_arr, int sorted_size, int nbr)
{
	int	i;

	i = 0;
	while (i < sorted_size)
	{
		if (nbr == sorted_arr[i])
			return (1);
		i++;
	}
	return (0);
}
