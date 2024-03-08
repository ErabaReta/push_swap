/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <eouhrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:19:43 by eouhrich          #+#    #+#             */
/*   Updated: 2024/03/08 12:29:16 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(int *arr, int size, char *msg)
{
	int	tmp;
	int	i;

	tmp = arr[0];
	i = 0;
	while (i < size - 1)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[size - 1] = tmp;
	if (msg[0] != '\0')
		write(1, msg, 3);
}
