/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <eouhrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 03:38:03 by eouhrich          #+#    #+#             */
/*   Updated: 2024/02/24 20:44:13 by eouhrich         ###   ########.fr       */
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

int arr_include_nbr(int *sorted_arr, int sorted_size, int nbr)
{
	int i;
	i = 0 ;
	while (i < sorted_size)
	{
		if (nbr == sorted_arr[i])
			return (1);
		i++;
	}
	return (0);
}

int nearest_target(int *arr_a, int a_size, int *sorted_arr, int sorted_size)
{
	int i;
	int	top;
	int	bottom;
	
	i = 0;
	while (i < a_size)
	{
		if (arr_include_nbr(sorted_arr, sorted_size, arr_a[i]) == 0)
		{
			top = i;
			break ;
		}
		i++;
	}
	i = a_size - 1;
	while (i >= 0)
	{
		if (arr_include_nbr(sorted_arr, sorted_size, arr_a[i]) == 0)
		{
			bottom = i;
			break ;
		}
		i--;
	}
	// if(top < a_size - bottom)
		return (top);
	// return(bottom);
}

void	fill_b(int *arr_a, int *arr_b, int *a_size, int *b_size)
{
	int sorted_size;
	int	*sorted_arr;
	int	i;
	int	nearest;
	
	sorted_arr = tallest_sorted_numbers(arr_a, *a_size, &sorted_size);
	// printf("sorted_size => %d\n", sorted_size);//////
	// 	printf("===================\n");
	// for(int j = 0; j < sorted_size;j++)
	// {
	// 	printf("%d\n", sorted_arr[j]);
	// }
	// 	printf("===================\n");///

	if (sorted_size <= 3)
	{
		while (*a_size != 3)
		{
			write(1, "pb\n", 3);
			push(arr_a, arr_b, a_size, b_size);
		}
		free(sorted_arr);
		return ;
	}
	while (arr_half_sorted(arr_a, *a_size) == 0)
	{
		i = 0;
		// printf("nearest => %d | a_size => %d\n", nearest_target(arr_a, *a_size, sorted_arr, sorted_size), *a_size);////
		nearest = nearest_target(arr_a, *a_size, sorted_arr, sorted_size);
		if ((nearest < (*a_size)/2) /*|| ((*a_size - sorted_size) > 1)*/)
		{
			while (i < nearest)
			{
				rotate(arr_a, *a_size, "ra\n");
				i++;
			}
		}
		else
		{
			while (*a_size > i + nearest)
			{
				// printf("i + nearest_target(arr_a, *a_size, sorted_arr, sorted_size) ==> %d\n", i + nearest_target(arr_a, *a_size, sorted_arr, sorted_size));
				reverse_rotate(arr_a, *a_size, "rra\n");
				i++;
			}
		}
		write(1, "pb\n", 3);
		push(arr_a, arr_b, a_size, b_size);
	}
}

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
		// printf("arr is half sorted (or sorted)\n");///
		fill_a(arr_a, arr_b, a_size, &b_size);
		return (1);
	}
	else if (*a_size == 3)
	{
		// printf("sort three nbrs\n");///
		sort_three_nbrs(arr_a);
	}
	
	else
		fill_b(arr_a, arr_b, a_size, &b_size);
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
		if (tmp > INT_MAX || tmp < INT_MIN)
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
	if(check_duplicate(arr_a, a_size) == 1)
		return (0);
	while (1)
	{
		if (push_swap(arr_a, &a_size) == 1)
			break ;
		// sleep(1);///
	}
	// printf("===================\n");
	// for(int j = 0; j < a_size;j++)
	// 	printf("%d\n", arr_a[j]);
	free(arr_a);
	return (0);
}
