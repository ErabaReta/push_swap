/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_indice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <eouhrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 23:52:36 by eouhrich          #+#    #+#             */
/*   Updated: 2024/03/09 20:24:56 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_indice(int *arr, int size)
{
	int	i;
	int	min;
	int	indice;

	i = 1;
	min = arr[0];
	indice = 0;
	while (i < size)
	{
		if (min > arr[i])
		{
			min = arr[i];
			indice = i;
		}
		i++;
	}
	return (indice);
}
