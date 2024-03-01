/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tallest_sorted_numbers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <eouhrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:18:35 by eouhrich          #+#    #+#             */
/*   Updated: 2024/03/01 14:46:38 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_numbers_range(int *arr_a, int a_size, int i)
{
	int	count;
	int	tmp;
	int	tmp_i;

	tmp = arr_a[i];
	count = 1;
	tmp_i = i - 1;
	while (++tmp_i < a_size)
	{
		if (tmp < arr_a[tmp_i])
		{
			tmp = arr_a[tmp_i];
			count++;
		}
	}
	tmp_i = -1;
	while (++tmp_i < i)
	{
		if (tmp < arr_a[tmp_i])
		{
			tmp = arr_a[tmp_i];
			count++;
		}
	}
	return (count);
}

int	*sorted_arr_filler(int *arr_a, int a_size, int indice, int sorted_size)
{
	int	*sorted_arr;
	int	tmp;
	int	i;

	sorted_arr = (int *)malloc((sorted_size) * sizeof(int));
	sorted_arr[0] = arr_a[indice];
	i = 0;
	tmp = indice;
	while (indice < a_size && i < sorted_size)
	{
		if (arr_a[indice] > sorted_arr[i])
			sorted_arr[++i] = arr_a[indice];
		indice++;
	}
	indice = -1;
	while (++indice < tmp && i < sorted_size)
		if (arr_a[indice] > sorted_arr[i])
			sorted_arr[++i] = arr_a[indice];
	return (sorted_arr);
}

int	*tallest_sorted_numbers(int *arr_a, int a_size, int	*sorted_size)
{
	int	*sorted_arr;
	int	i;
	int	indice;

	i = 0;
	*sorted_size = 0;
	indice = 0;
	while (i < a_size)
	{
		if (sorted_numbers_range(arr_a, a_size, i) >= *sorted_size)
		{
			*sorted_size = sorted_numbers_range(arr_a, a_size, i);
			indice = i;
		}
		i++;
	}
	sorted_arr = sorted_arr_filler(arr_a, a_size, indice, *sorted_size);
	return (sorted_arr);
}
