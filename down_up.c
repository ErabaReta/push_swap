#include "push_swap.h"

void down_up(int *arr_a, int *arr_b, int a_size, int b_size)
{
	t_cheapest	cheapest_move;
	int			i;

	i = 0;
	cheapest_move = cheapest_move_counter(arr_b, arr_a, b_size, a_size);
	while (i < cheapest_move.rank)
	{
		rotate(arr_a, a_size, "ra\n");
		i++;
	}
	i = 0;
	while (b_size - i > cheapest_move.indice)
	{
		reverse_rotate(arr_b, b_size, "rrb\n");
		i++;
	}
}
