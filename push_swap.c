/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <eouhrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 03:38:03 by eouhrich          #+#    #+#             */
/*   Updated: 2024/03/10 20:54:51 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int *arr_a, int *a_size)
{
	static int	*arr_b;
	static int	b_size;

	if (arr_b == NULL)
	{
		arr_b = (int *)malloc(*a_size * sizeof(int));
		if (arr_b == NULL)
			return (1);
	}
	if (arr_half_sorted(arr_a, *a_size) == 1)
	{
		fill_a(arr_a, arr_b, a_size, &b_size);
		free(arr_b);
		return (1);
	}
	else if (*a_size == 3)
		sort_three_nbrs(arr_a);
	else if (*a_size == 2)
	{
		if (arr_a[0] > arr_a[0])
			swap(arr_a, *a_size, "sa\n");
	}
	else
		fill_b(arr_a, arr_b, a_size, &b_size);
	return (0);
}

int	main(int ac, char **av)
{
	int		*arr_a;
	char	*str;
	int		a_size;

	str = ft_joiner(av, ac);
	if (str == NULL)
		return (1);
	arr_a = arr_extracter(ft_split(str, ' '), count_words(str, ' '));
	a_size = count_words(str, ' ');
	free(str);
	if (a_size <= 1 || arr_a == NULL)
		return (1);
	if (check_duplicate(arr_a, a_size) == 1)
		return (1);
	while (1)
	{
		if (push_swap(arr_a, &a_size) == 1)
			break ;
	}
	free(arr_a);
	return (0);
}
