#include "push_swap.h"

typedef struct s_cheapest
{
    int value;
    int indice;
    int rank;
    char path;
} t_cheapest;

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
    if(msg[0] != '\0')
        write(1, msg, 3);
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
    if (msg[0] != '\0')
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
        if(shortest_dist > ft_abs(nbr - arr[i]))
        {
            shortest_dist = ft_abs(nbr - arr[i]);
            rank = i;
        }
		i++;
	}
    if (nbr > arr[rank])
        rank += 1;
	return (rank);
}

t_cheapest cheapest_path(int up_up, int up_down, int down_up, int down_down)
{
    t_cheapest min;

    min.value = up_up;
    min.path = 1;
    if (min.value > up_down)
    {
        min.value = up_down;
        min.path = 2;
    }
    if (min.value > down_up)
    {
        min.value = down_up;
        min.path = 3;
    }
    if (min.value > down_down)
    {
        min.value = down_down;
        min.path = 4;
    }
    return (min);
}

t_cheapest	cheapest_move_counter(int *arr_b, int *arr_a, int b_size, int a_size)// returns the indice of the number with the cheapest moves
{
	t_cheapest	cheapest;
	t_cheapest tmp;
	int	i;
    int rank;

	i = 0;
	cheapest.value = a_size + b_size + 1; // setting the max (it decreases anyway)
    //     ///////////////////////////////////////////////////
    // printf("======= stack A =====\n");//

    // for(int j = 0;j < a_size; j++ )//
    //     printf("%d, ", arr_a[j]);//
    // printf("\n=====================\n");//
    // ///////////////////////////////////////////////////
    //     ///////////////////////////////////////////////////
    // printf("======= stack B =====\n");//

    // for(int j = 0;j < b_size; j++ )//
    //     printf("%d, ", arr_b[j]);//
    // printf("\n=====================\n");//
    // ///////////////////////////////////////////////////
	while (i < b_size)
	{
		rank = (rank_calc(arr_a, a_size, arr_b[i])) % a_size; // store the indice of our number if it was in the other array
        if (i > rank)
        {
            if (b_size - i > a_size - rank)
                tmp = cheapest_path(i, i + (a_size - rank), (b_size - i) + rank, b_size - i);
            else
                tmp = cheapest_path(i, i + (a_size - rank), (b_size - i) + rank, a_size - rank);
        }
        else
        {
            if (b_size - i > a_size - rank)
                tmp = cheapest_path(rank, i + (a_size - rank), (b_size - i) + rank, b_size - i);
            else
                tmp = cheapest_path(rank, i + (a_size - rank), (b_size - i) + rank, a_size - rank);
        }
        // printf("calculating...  indice => %d  | rank => %d | path => %d | moves => %d \n", i, rank, tmp.path, tmp.value);///////////////////////
		if (tmp.value < cheapest.value)
		{
            cheapest = tmp;
            cheapest.indice = i;
            cheapest.rank = rank;
        }
        i++;
	}
	return (cheapest);
}

void    push_cheapest(int *arr_b, int *arr_a, int b_size, int a_size)
{
    t_cheapest cheapest_move;
    int i = 0;

    cheapest_move = cheapest_move_counter(arr_b, arr_a, b_size, a_size);
    // printf("moves => %d | path ==> %d | indice ==> %d | rank ==> %d \n",cheapest_move.value, cheapest_move.path, cheapest_move.indice, cheapest_move.rank);////////////////////////////////////
    if (cheapest_move.path == 1)
    {
        if (cheapest_move.indice > cheapest_move.rank)
        {
            while (i < cheapest_move.rank)
            {
                rotate(arr_a, a_size, "");
                rotate(arr_b, b_size, "");
                write(1, "rr\n", 3);
                i++;
            }
            while(i < cheapest_move.indice)
            {
                rotate(arr_b, b_size, "rb\n");
                i++;
            }
        } 
        else
        {
            while (i < cheapest_move.indice)
            {
                rotate(arr_a, a_size, "");
                rotate(arr_b, b_size, "");
                write(1, "rr\n", 3);
                i++;
            }
            while(i < cheapest_move.rank)
            {
                rotate(arr_a, a_size, "ra\n");
                i++;
            }
        }
    }
    else if (cheapest_move.path == 2)
    {
        while(i < cheapest_move.indice)
        {
            rotate(arr_b, b_size, "rb\n");
            i++;
        }
        i = 0;
        while(a_size - i > cheapest_move.rank)
        {
            reverse_rotate(arr_a, a_size, "rra\n");
            i++;
        }
    }
    else if (cheapest_move.path == 3)
    {
        while(i < cheapest_move.rank)
        {
            rotate(arr_a, a_size, "ra\n");
            i++;
        }
        i = 0;
        while(b_size - i > cheapest_move.indice)
        {
            reverse_rotate(arr_b, b_size, "rrb\n");
            i++;
        }
    }
    else if (cheapest_move.path == 4)
    {
        // printf("path 4 down down followed\n");
        // printf("b_size => %d | cheapest_move.indice => %d | a_size => %d | cheapest_move.rank => %d\n", b_size, cheapest_move.indice, a_size, cheapest_move.rank);
        if (b_size - cheapest_move.indice > a_size - cheapest_move.rank)
        {
            while (cheapest_move.rank < a_size - i)
            {
                reverse_rotate(arr_a, a_size, "");
                reverse_rotate(arr_b, b_size, "");
                write(1, "rrr\n", 4);
                i++;
            }
            while(cheapest_move.indice < b_size - i)
            {
                reverse_rotate(arr_b, b_size, "rrb\n");
                i++;
            }
        }
        else
        {
            while (cheapest_move.indice < b_size - i)
            {
                reverse_rotate(arr_a, a_size, "");
                reverse_rotate(arr_b, b_size, "");
                write(1, "rrr\n", 4);
                i++;
            }
            while(cheapest_move.rank < a_size - i)
            {
                reverse_rotate(arr_a, a_size, "rra\n");
                i++;
            }
        }
    }
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
    if(arr_is_sorted(arr_a, *a_size))
    {
        // printf("arr a sorted\n");///////////////////////////////////
        while (b_size != 0)
        {
            push_cheapest(arr_b, arr_a, b_size, *a_size);
            push(arr_b, arr_a, &b_size, a_size, "pa\n");
        }
        // printf("array b is emty\n");///////////////////////////
        ///////////////////////////////////////////////////
        // for(int j = 0;j < *a_size; j++ )//           ///
        //     printf("%d ", arr_a[j]);//               ///
        // printf("\n======================\n");//      ///
        ///////////////////////////////////////////////////
        while (min_indice(arr_a, *a_size) != 0)
        {
            // printf("indice of minimum => %d\n", min_indice(arr_a, *a_size));////////////////////////
            if (min_indice(arr_a, *a_size) <= (*a_size/2))
                rotate(arr_a, *a_size, "ra\n");
            else
                reverse_rotate(arr_a, *a_size, "rra\n");
        }
        return 1;
    }
    else if (*a_size == 3)
    {
        // printf("there is only 3 numbers in stack A\n");
        sort_three_nbrs(arr_a);
    }
    else
    {
        push(arr_a, arr_b, a_size, &b_size, "pb\n");
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
        arr_a[i] = tmp;
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
    // int k =0;
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