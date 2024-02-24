/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <eouhrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:15:36 by eouhrich          #+#    #+#             */
/*   Updated: 2024/02/24 20:44:34 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(int *arr_src, int *arr_dst, int *src_size, int *dst_size)
{
	int	pushed;
	int	i;

	pushed = arr_src[0];
	i = 0;
	while (i < *src_size - 1)
	{
		arr_src[i] = arr_src[i + 1];
		i++;
	}
	i = *dst_size;
	while (i > 0)
	{
		arr_dst[i] = arr_dst[i - 1];
		i--;
	}
	arr_dst[0] = pushed;
	*dst_size += 1;
	*src_size -= 1;
}
