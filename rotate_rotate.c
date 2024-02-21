#include "push_swap.h"

void rotate_rotate(int *arr_a, int *arr_b, int a_size, int b_size)
{
	rotate(arr_a, a_size, "");
	rotate(arr_b, b_size, "");
	write(1, "rr\n", 3);
}
