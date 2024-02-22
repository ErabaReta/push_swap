/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <eouhrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 03:38:03 by eouhrich          #+#    #+#             */
/*   Updated: 2024/02/22 22:09:57 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_a(int *arr_a, int *arr_b, int *a_size, int *b_size)
{
	while (*b_size != 0)
	{
		move_cheapest(arr_b, arr_a, *b_size, *a_size);
		push(arr_b, arr_a, b_size, a_size);
		write(1, "pa\n", 3);
	}
	while (min_indice(arr_a, *a_size) != 0)
	{
		if (min_indice(arr_a, *a_size) <= (*a_size / 2))
			rotate(arr_a, *a_size, "ra\n");
		else
			reverse_rotate(arr_a, *a_size, "rra\n");
	}
}

int	push_swap(int *arr_a, int *a_size)
{
	static int	*arr_b;
	static int	b_size;
	int			cheapest_move;

	if (arr_b == NULL)
	{
		arr_b = (int *)malloc(*a_size * sizeof(int));
		if (arr_b == NULL)
			return (1);
	}
	if (arr_is_sorted(arr_a, *a_size))
	{
		fill_a(arr_a, arr_b, a_size, &b_size);
		return (1);
	}
	else if (*a_size == 3)
		sort_three_nbrs(arr_a);
	else
	{
		push(arr_a, arr_b, a_size, &b_size);
		write(1, "pb\n", 3);
	}
	return (0);
}

int	ft_is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	*arr_extracter(char **av, int ac, int initial)
{
	int		*arr_a;
	int		j;
	int		i;
	long	tmp;

	arr_a = (int *)malloc((ac - initial) * sizeof(int));
	if (arr_a == NULL)
		return (NULL);
	i = initial;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (ft_is_digit(av[i][j]) != 1 && av[i][j] != '-')
			{
				write(1, "Error\n", 6);
				return (NULL);
			}
			j++;
		}
		tmp = ft_atoi(av[i]);
		if (tmp > INT_MAX)
		{
			write(1, "Error\n", 6);
			free(arr_a);
			return (NULL);
		}
		arr_a[i] = tmp;
		i++;
	}
	return (arr_a);
}

int	main(int ac, char **av)
{
	int *arr_a;
	int i;
	char *str;
	int a_size;

	str = ft_strdup(" ");
	if (ac <= 1)
		return (0);
	i = 1;
	while (i < ac)
	{
		str = ft_strjoin(str, " ");
		str = ft_strjoin(str, av[i]);
		i++;
	}
	arr_a = arr_extracter(ft_split(str, ' '), count_words(str, ' '), 0);
	if (arr_a == NULL)
		return (0);
	a_size = count_words(str, ' ');
	free(str);
	while (1)
	{
		if (push_swap(arr_a, &a_size) == 1)
			break ;
	}
	// printf("===================\n");
	// for(int j = 0; j < a_size;j++)
	// 	printf("%d\n", arr_a[j]);
	free(arr_a);
	return (0);
}
