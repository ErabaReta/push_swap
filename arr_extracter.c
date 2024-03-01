/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_extracter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:40:19 by eouhrich          #+#    #+#             */
/*   Updated: 2024/02/29 22:40:56 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*arr_extracter(char **av, int ac)
{
	int		*arr_a;
	int		j;
	int		i;
	long	tmp;

	arr_a = (int *)malloc((ac) * sizeof(int));
	if (arr_a == NULL)
		return (free_all(av, ac, arr_a, 0));
	i = 0;
	while (i < ac)
	{
		j = -1;
		while (av[i][++j] != '\0')
			if (ft_is_digit(av[i][j]) != 1 && av[i][j] != '-'
					&& av[i][j] != '-')
				return (free_all(av, ac, arr_a, 1));
		tmp = ft_atoi(av[i]);
		if (tmp > INT_MAX)
			return (free_all(av, ac, arr_a, 1));
		arr_a[i] = tmp;
		i++;
	}
	free_all(av, ac, NULL, 0);
	return (arr_a);
}
