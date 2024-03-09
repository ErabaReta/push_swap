/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <eouhrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:40:56 by eouhrich          #+#    #+#             */
/*   Updated: 2024/03/09 13:19:36 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "push_swap.h"
# include "get_next_line/get_next_line.h"

void	silent_reverse_rotate_rotate(int *arr_a, int *arr_b, int a_size,
			int b_size);
void	silent_rotate_rotate(int *arr_a, int *arr_b, int a_size, int b_size);
void	silent_swap_swap(int *arr_a, int *arr_b, int a_size, int b_size);
int		ft_strcmp(const char *s1, const char *s2);
#endif