#include "push_swap.h"


void down_down(int *arr_a, int *arr_b, int a_size, int b_size)
{
		t_cheapest	cheapest_move;
	int			i;

	i = 0;
	cheapest_move = cheapest_move_counter(arr_b, arr_a, b_size, a_size);
	if (b_size - cheapest_move.indice > a_size - cheapest_move.rank)
	{
		while (cheapest_move.rank < a_size - i)
		{
			reverse_rotate_rotate(arr_a, arr_b, a_size, b_size);
			i++;
		}
		while (cheapest_move.indice < b_size - i++)
			reverse_rotate(arr_b, b_size, "rrb\n");
	}
	else
	{
		while (cheapest_move.indice < b_size - i)
		{
			reverse_rotate_rotate(arr_a, arr_b, a_size, b_size);
			i++;
		}
		while (cheapest_move.rank < a_size - i++)
			reverse_rotate(arr_a, a_size, "rra\n");
	}
}
