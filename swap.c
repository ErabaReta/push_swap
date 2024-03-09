/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <eouhrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:21:30 by eouhrich          #+#    #+#             */
/*   Updated: 2024/03/09 13:20:13 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *arr, int size, char *msg)
{
	int	tmp;

	if (size <= 1)
		return ;
	tmp = arr[0];
	arr[0] = arr[1];
	arr[1] = tmp;
	if (msg[0] != '\0')
		write(1, msg, 3);
}
