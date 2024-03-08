/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <eouhrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:19:06 by eouhrich          #+#    #+#             */
/*   Updated: 2024/03/06 19:00:04 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	silent_reverse_rotate_rotate(int *arr_a, int *arr_b, int a_size,
			int b_size)
{
	reverse_rotate(arr_a, a_size, "");
	reverse_rotate(arr_b, b_size, "");
}

void	reverse_rotate_rotate(int *arr_a, int *arr_b, int a_size, int b_size)
{
	reverse_rotate(arr_a, a_size, "");
	reverse_rotate(arr_b, b_size, "");
	write(1, "rrr\n", 4);
}
