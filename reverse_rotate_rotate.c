/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:19:06 by eouhrich          #+#    #+#             */
/*   Updated: 2024/02/22 00:19:29 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_rotate(int *arr_a, int *arr_b, int a_size, int b_size)
{
	reverse_rotate(arr_a, a_size, "");
	reverse_rotate(arr_b, b_size, "");
	write(1, "rrr\n", 4);
}
