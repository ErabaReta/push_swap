/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eouhrich <eouhrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 03:38:54 by eouhrich          #+#    #+#             */
/*   Updated: 2024/02/24 20:43:23 by eouhrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
#include <stdio.h>
typedef struct s_cheapest
{
	int		value;
	int		indice;
	int		rank;
	char	path;
}	t_cheapest;

int				arr_is_sorted(int *arr, int size);
t_cheapest		cheapest_move_counter(int *arr_b, int *arr_a, int b_size,
					int a_size);
t_cheapest		cheapest_path(int up_up, int up_down, int down_up,
					int down_down);
void			down_down(int *arr_a, int *arr_b, int a_size, int b_size);
void			down_up(int *arr_a, int *arr_b, int a_size, int b_size);
size_t			ft_abs(long long value);
long			ft_atoi(const char *str);
void			*ft_memmove(void *dst, const void *src, size_t len);
size_t			indexer(char const *s, char c, size_t i, size_t *end_index);
size_t			count_words(char const *s, char c);
void			*free_all(char **ptr, int i);
char			**ft_split(char const *s, char c);
char			*ft_strdup(const char *s1);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char *s1, char const *s2);
int				ft_strlen(const char *s);
int				min_indice(int *arr, int size);
void			move_cheapest(int *arr_b, int *arr_a, int b_size, int a_size);
t_cheapest		path_counter(int i, int rank, int a_size, int b_size);
int				push_swap(int *arr_a, int *a_size);
int				ft_is_digit(int c);
int				*arr_extracter(char **av, int ac, int initial);
void			push(int *arr_src, int *arr_dst, int *src_size, int *dst_size);
int				rank_calc(int *arr, int arr_size, int nbr);
void			reverse_rotate_rotate(int *arr_a, int *arr_b, int a_size,
					int b_size);
void			reverse_rotate(int *arr, int size, char *msg);
void			rotate_rotate(int *arr_a, int *arr_b, int a_size, int b_size);
void			rotate(int *arr, int size, char *msg);
void			sort_three_nbrs(int *arr_a);
void			swap(int *arr, char *msg);
void			up_down(int *arr_a, int *arr_b, int a_size, int b_size);
void			up_up(int *arr_a, int *arr_b, int a_size, int b_size);
int				check_duplicate(int *arr_a, int a_size);
int				*tallest_sorted_numbers(int *arr_a, int a_size, int	*sorted_size);
int				sorted_numbers_range(int *arr_a, int a_size, int i);
int	arr_half_sorted(int *arr_a, int a_size);
#endif
