#include "push_swap.h"

void reverse_rotate_rotate(int *arr_a, int *arr_b, int a_size, int b_size)
{
	reverse_rotate(arr_a, a_size, "");
	reverse_rotate(arr_b, b_size, "");
	write(1, "rrr\n", 4);
}
