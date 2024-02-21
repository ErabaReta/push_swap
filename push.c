#include "push_swap.h"

void	push(int *arr_src, int *arr_dst, int *src_size, int *dst_size,
		char *msg)
{
	int	tmp;
	int	pushed;
	int	i;

	pushed = arr_src[0];
	i = 0;
	while (i < *src_size - 1)
	{
		arr_src[i] = arr_src[i + 1];
		i++;
	}
	i = *dst_size;
	while (i > 0)
	{
		arr_dst[i] = arr_dst[i - 1];
		i--;
	}
	arr_dst[0] = pushed;
	*dst_size += 1;
	*src_size -= 1;
	write(1, msg, 3);
}