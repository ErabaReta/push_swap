/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <eouhrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:24:13 by eouhrich          #+#    #+#             */
/*   Updated: 2024/03/08 17:46:34 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
	char	*str1;
	char	*str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	while ((str1[i] != '\0' || str2[i] != '\0'))
	{
		if ((unsigned char)str1[i] != (unsigned char)str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

int	check_rotates(int *arr_a, int *arr_b, int **sizes, char *str)
{
	if (ft_strcmp(str, "ra\n") == 0)
		rotate(arr_a, sizes[0][0], "");
	else if (ft_strcmp(str, "rb\n") == 0)
		rotate(arr_b, sizes[1][0], "");
	else if (ft_strcmp(str, "rr\n") == 0)
		silent_rotate_rotate(arr_a, arr_b, sizes[0][0], sizes[1][0]);
	else if (ft_strcmp(str, "rra\n") == 0)
		reverse_rotate(arr_a, sizes[0][0], "");
	else if (ft_strcmp(str, "rrb\n") == 0)
		reverse_rotate(arr_b, sizes[1][0], "");
	else if (ft_strcmp(str, "rrr\n") == 0)
		silent_reverse_rotate_rotate(arr_a, arr_b, sizes[0][0], sizes[1][0]);
	else
		return (1);
	return (0);
}

int	check_instructions(int *arr_a, int **sizes, char *str, int *arr_b)
{
	if (ft_strcmp(str, "pa\n") == 0)
	{
		if (sizes[1][0] != 0)
			push(arr_b, arr_a, sizes[1], sizes[0]);
	}
	else if (ft_strcmp(str, "pb\n") == 0)
	{
		if (sizes[0][0] != 0)
			push(arr_a, arr_b, sizes[0], sizes[1]);
	}
	else if (ft_strcmp(str, "sa\n") == 0)
		swap(arr_a, "");
	else if (ft_strcmp(str, "sb\n") == 0)
		swap(arr_b, "");
	else if (ft_strcmp(str, "ss\n") == 0)
		silent_swap_swap(arr_a, arr_b);
	else if (check_rotates(arr_a, arr_b, sizes, str) == 1)
		return (1);
	return (0);
}

int	handle_instructions(int *arr_a, int a_size, int *b_size)
{
	char	*str;
	int		*arr_b;
	int		*sizes[2];

	*b_size = 0;
	sizes[0] = &a_size;
	sizes[1] = b_size;
	arr_b = (int *)malloc(a_size * sizeof(int));
	if (arr_b == NULL)
		return (1);
	str = get_next_line(0);
	while (str != NULL)
	{
		if (check_instructions(arr_a, sizes, str, arr_b) == 1)
		{
			write(2, "Error\n", 6);
			free(str);
			free(arr_b);
			return (1);
		}
		free(str);
		str = get_next_line(0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		*arr_a;
	char	*str;
	int		a_size;
	int		b_size;

	str = ft_joiner(av, ac);
	if (str == NULL)
		return (1);
	arr_a = arr_extracter(ft_split(str, ' '), count_words(str, ' '));
	a_size = count_words(str, ' ');
	free(str);
	if (arr_a == NULL)
		return (1);
	if (check_duplicate(arr_a, a_size) == 1)
		return (0);
	if (handle_instructions(arr_a, a_size, &b_size) == 0)
	{
		if (arr_is_sorted(arr_a, a_size) == 1 && b_size == 0)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	free(arr_a);
	return (0);
}
