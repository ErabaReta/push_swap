/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <eouhrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:24:13 by eouhrich          #+#    #+#             */
/*   Updated: 2024/03/01 14:50:53 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		return (0);
	if (check_duplicate(arr_a, a_size) == 1)
		return (0);
	
	free(arr_a);
	return (0);
}
