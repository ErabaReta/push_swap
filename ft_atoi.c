/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <eouhrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 23:48:43 by eouhrich          #+#    #+#             */
/*   Updated: 2024/03/01 14:31:30 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sign_giver(char *str, size_t *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign *= -1;
		*i += 1;
	}
	return (sign);
}

long	ft_atoi(const char *str)
{
	size_t			i;
	size_t			nbr;
	int				sign;
	int				counter;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = sign_giver((char *)str, &i);
	if (str[i] == '+' || str[i] == '-')
		return (2147483648);
	nbr = 0;
	counter = 0;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		nbr = nbr * 10 + str[i++] - 48;
		if ((nbr >= 2147483648 && sign == 1)
			|| (nbr >= 2147483649 && sign == -1))
			return (2147483648);
		counter++;
	}
	if (str[i] == '+' || str[i] == '-' || counter < 1)
		return (2147483648);
	return (nbr * sign);
}
