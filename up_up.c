#include "push_swap.h"

void up_up(int *arr_a, int *arr_b, int a_size, int b_size)
{
	int i;
	t_cheapest	cheapest_move;

	i = 0;
	cheapest_move = cheapest_move_counter(arr_b, arr_a, b_size, a_size);
	if (cheapest_move.indice > cheapest_move.rank)
	{
		while (i < cheapest_move.rank)
		{
			rotate_rotate(arr_a, arr_b, a_size, b_size);
			i++;
		}
		while (i++ < cheapest_move.indice)
			rotate(arr_b, b_size, "rb\n");
	}
	else
	{
		while (i < cheapest_move.indice)
		{
			rotate_rotate(arr_a, arr_b, a_size, b_size);
			i++;
		}
		while (i++ < cheapest_move.rank)
			rotate(arr_a, a_size, "ra\n");
	}
}
