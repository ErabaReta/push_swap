/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <eouhrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:40:15 by eouhrich          #+#    #+#             */
/*   Updated: 2024/03/09 13:20:57 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	silent_swap_swap(int *arr_a, int *arr_b, int a_size, int b_size)
{
	swap(arr_a, a_size, "");
	swap(arr_b, b_size, "");
}
