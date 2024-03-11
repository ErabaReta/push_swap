/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joiner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <eouhrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:31:52 by eouhrich          #+#    #+#             */
/*   Updated: 2024/03/11 13:21:12 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_only_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

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
		if (ft_strlen(av[i]) == 0 || is_only_spaces(av[i]))
		{
			free(str);
			write(2, "Error\n", 6);
			return (NULL);
		}
		str = ft_strjoin(str, " ");
		str = ft_strjoin(str, av[i]);
		i++;
	}
	if (str == NULL)
		return (NULL);
	return (str);
}
