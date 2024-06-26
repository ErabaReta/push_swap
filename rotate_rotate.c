/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <eouhrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:20:15 by eouhrich          #+#    #+#             */
/*   Updated: 2024/03/06 19:00:41 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	silent_rotate_rotate(int *arr_a, int *arr_b, int a_size, int b_size)
{
	rotate(arr_a, a_size, "");
	rotate(arr_b, b_size, "");
}

void	rotate_rotate(int *arr_a, int *arr_b, int a_size, int b_size)
{
	rotate(arr_a, a_size, "");
	rotate(arr_b, b_size, "");
	write(1, "rr\n", 3);
}
