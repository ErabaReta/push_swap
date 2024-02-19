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

int min_indice(int *arr, int size)
{
    int i;
    int min;
    int indice;

    i = 1;
    min = arr[0];
    indice = 0;
    while (i < size)
    {
        if (min > arr[i])
        {
            min = arr[i];
            indice = i;
        }
        i++;
    }
    return (indice);
}

void    rotate(int *arr, int size, char *msg)
{
    int tmp;
    int i;

    tmp = arr[0];
    i = 0;
    while (i < size - 1)
    {
        arr[i] = arr[i + 1];
        i++;
    }
    arr[size - 1] = tmp;
    write(1, msg, 4);
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
    if(msg[0] != '\0')
	    write(1, msg, 4);
}

void    sort_three_nbrs(int *arr_a)
{
    if(min_indice(arr_a, 3) == 0)
    {
        //sa ra
        swap(arr_a, "sa\n");
        rotate(arr_a, 3, "ra\n");
    }
    else if (min_indice(arr_a, 3) == 1)
    {
        if(arr_a[0] > arr_a[2])
        {
            //ra
            rotate(arr_a, 3, "ra\n");
        }
        else if(arr_a[0] < arr_a[2])
        {
            //sa
            swap(arr_a, "sa\n");
        }
    }
    else if(min_indice(arr_a, 3) == 2)
    {
        if (arr_a[0] < arr_a[1])
        {
            //rra
            reverse_rotate(arr_a, 3, "rra\n");
        }
        else if (arr_a[0] > arr_a[2])
        {
            //sa rra
            swap(arr_a, "sa\n");
            reverse_rotate(arr_a, 3, "rra\n");
        }
    }
}

unsigned int ft_abs(int value)
{
    return (((value > 0) - (value < 0)) * value);
}

int	rank_calc(int *arr, int arr_size, int nbr)
{
	int	i;
	int	rank;
    unsigned int shortest_dist;

    shortest_dist = ft_abs(nbr - arr[0]);
	i = 1;
	rank = 0;
	while (i < arr_size)
	{
        if(shortest_dist < ft_abs(nbr - arr[i]))
        {
            shortest_dist = ft_abs(nbr - arr[0]);
            rank = i;
        }
		i++;
	}
    if (nbr > arr[rank])
        rank += 1;
	return (rank);
}

int cheapest_path(int up_up, int up_down, int down_up, int down_down)
{
    int min;

    min = up_up;
    if (min < up_down)
        min = up_down;
    if (min < down_up)
        min = up_down;
    if (min < down_down)
        min = down_down;
    return (min);
}

int	cheapest_move_counter(int *arr_a, int *arr_b, int a_size, int b_size)// returns the indice of the number with the cheapest moves
{
	int	indice;
	int	count;
	int tmp;
	int	i;

	i = 0;
	count = a_size + b_size + 1; // setting the max (it decreases anyway)
	while (i < a_size)
	{
		tmp = rank_calc(arr_b, b_size, arr_a[i]); // store the indice of our number if it was in the other array
        if (i > tmp)
            if (a_size - i > b_size - tmp)
                tmp = cheapest_path(i, i + (b_size - tmp), (a_size - i) + tmp, a_size - i);
            else
                tmp = cheapest_path(i, i + (b_size - tmp), (a_size - i) + tmp, b_size - tmp);
        else
            if (a_size - i > b_size - tmp)
                tmp = cheapest_path(tmp, i + (b_size - tmp), (a_size - i) + tmp, a_size - i);
            else
                tmp = cheapest_path(tmp, i + (b_size - tmp), (a_size - i) + tmp, b_size - tmp);
		if (tmp < count)  // !!!!! Dont forget tmp after this loses its meaning , the variable will be used next to store how many moves !!!!!!!!!! 
		{
			count = tmp;
			indice = i;
		}
	}
	return (indice);
}

void    push_cheapest(int *arr_a, int *arr_b, int a_size, int b_size)
{
    int cheapest_move;
    int rank;

    cheapest_move = cheapest_move_counter(arr_a, arr_b, a_size, b_size);
    rank = rank_calc(arr_b, b_size, arr_a[cheapest_move]);

}

int push_swap(int *arr_a, int *a_size)
{
    static int *arr_b;
    static int b_size;
    int	cheapest_move;

    if(arr_b == NULL)
    {
        arr_b = (int *)malloc(*a_size * sizeof(int));
        if(arr_b == NULL)
            return (1);
    }
	cheapest_move = cheapest_move_counter(arr_a, arr_b, *a_size, b_size);
    if(arr_is_sorted(arr_a, *a_size))
    {
        while (b_size != 0)
        {
            cheapest_move = cheapest_move_counter(arr_b, arr_a, b_size, *a_size);
            // push(arr_b, arr_a, &b_size, a_size, "pa\n");
        }
        return 1;
    }
    else if (*a_size == 3)
    {
        sort_three_nbrs(arr_a);
    }
    else
    {
        push_cheapest(arr_a, arr_b, *a_size, b_size);
    }
    // else if (arr_a[0] > arr_a[1])
    // {
    //     swap(arr_a, "sa\n");
    // }
    // else if (min_indice(arr_a, *a_size) == 0)
    // {
    //     push(arr_a, arr_b, a_size, &b_size, "pb\n");
    // }
	// else
	// {
	// 	reverse_rotate(arr_a, *a_size, "rra\n");
	// }
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
    long tmp;
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
        tmp = atoi(av[i]);///////////////////////////////
        if (tmp > INT_MAX)
        {
            printf("Error");//////////////////
            free(arr_a);
            return (NULL);
        }
        i++;
    }
	return (arr_a);
}

int main(int ac, char **av)
{
    int *arr_a;
    int i;
    char *str;
	int a_size;

    str = ft_strdup(" ");
    if (ac <= 1)
        return 0;
    i = 1;
    while(i < ac)
    {
        str = ft_strjoin(str, " ");
        str = ft_strjoin(str, av[i]);
        i++;
    }
    int k =0;
    // while (str[k] != '\0')
    //     {
    //         if (str[k] != ' ')
    //             break;
    //         k++;
    //     }
    // if (k == ft_strlen(str))
    // {
    //         printf("Error");//////////////////
    //         return 0;
    // }
	arr_a = arr_extracter(ft_split(str, ' '), count_words(str, ' '), 0);
	if (arr_a == NULL)
	    return (0);
	a_size = count_words(str, ' ');
    
    // ///////////////////////////////////////////////////
    // for(int j = 0;j < a_size; j++ )//
    //     printf("%d\n", arr_a[j]);//
    // printf("======================\n");//
    // ///////////////////////////////////////////////////

    while(1)
    {
        if (push_swap(arr_a, &a_size) == 1)
            break ;
    }
    // /////////////////////////////////////////////
    // printf("======================\n");//
    // for(int j = 0;j < a_size; j++ )//
    //     printf("%d\n", arr_a[j]);//
    // //////////////////////////////////////////////
    return (0);
}