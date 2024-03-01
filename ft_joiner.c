/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joiner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:31:52 by eouhrich          #+#    #+#             */
/*   Updated: 2024/03/01 14:31:53 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_joiner(char **av, int ac)
{
	char	*str;
	int		i;

	str = ft_strdup(" ");
	if (str == NULL || ac <= 1)
		return (NULL);
	i = 1;
	while (i < ac)
	{
		str = ft_strjoin(str, " ");
		str = ft_strjoin(str, av[i]);
		i++;
	}
	if (str == NULL)
		return (NULL);
	return (str);
}
