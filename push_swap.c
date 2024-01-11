#include "push_swap.h"
int    arr_is_sorted(int *arr, int size)
{
    int i;

    i = 0;
    while (i < size - 1)
    {
        if (arr[i] > arr[i + 1])
            return (0);
        i++;
    }
    return (1);
}
void    push(int *arr_src, int *arr_dst, int *src_size, int *dst_size, char *msg)
{
    int tmp;
    int pushed;
    int i;

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
void    swap(int *arr, char *msg)
{
    int tmp;

    tmp = arr[0];
    arr[0] = arr[1];
    arr[1] = tmp;
    write(1, msg, 3);
}

int top_is_min(int *arr, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (arr[0] > arr[i])
            return (0);
        i++;
    }
    return (1);
}

void	reverse_rotate(int *arr, int size, char *msg)
{
	int tmp;
	int i;

	i = size - 1;
	tmp = arr[size - 1];
	while (i > 0)
	{
		arr[i] = arr[i - 1];
		i--;
	}
	arr[0] = tmp;
	write(1, msg, 4);
}

int push_swap(int *arr_a, int *a_size)
{
    static int *arr_b;
    static int b_size;
    
    if(arr_b == NULL)
    {
        arr_b = (int *)malloc(*a_size * sizeof(int));
        if(arr_b == NULL)
            return (1);
    }
    if(arr_is_sorted(arr_a, *a_size))
    {
        while (b_size != 0)
            push(arr_b, arr_a, &b_size, a_size, "pa\n");
        return 1;
    }
    else if (arr_a[0] > arr_a[1])
    {
        swap(arr_a, "sa\n");
    }
    else if (top_is_min(arr_a, *a_size) == 1)
    {
        push(arr_a, arr_b, a_size, &b_size, "pb\n");
    }
	else
	{
		reverse_rotate(arr_a, *a_size, "rra\n");
	}
    return 0;
}

int is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int *arr_extracter(char **av, int ac, int initial)
{
	int *arr_a;
	int	j;
	int i;

    arr_a = (int *)malloc((ac - initial) * sizeof(int));
    if (arr_a == NULL)
        return (NULL);
    i = initial;
    while(i < ac)
    {
        j = 0;
        while (av[i][j] != '\0')
        {
            if (is_digit(av[i][j]) != 1)
            {
                printf("Error");//////////////////
                return (NULL);
            }
            j++;
        }
        arr_a[i - initial] = atoi(av[i]);///////////////////////////////
        i++;
    }
	return (arr_a);
}

int main(int ac, char **av)
{
    int *arr_a;
    int i;
    int j;
	int a_size;

    if (ac <= 1)
        return 0;
	if (ac == 2)
	{
		arr_a = arr_extracter(ft_split(av[1], ' '), count_words(av[1], ' '), 0);
		a_size = count_words(av[1], ' ');
	}
	if (ac > 2)
	{
		arr_a = arr_extracter(av, ac, 1);
		a_size = ac -1;
	}
	if (arr_a == NULL)
		return (0);
	//////
	////
	// for(i = 0; i > ac - 1; i++)
	// {
	// 	printf("%d\n", arr_a[i]);
	// }
	// return 0;
	////
    while(1)
    {
        if (push_swap(arr_a, &a_size) == 1)
            break ;
    }
    return (0);
}