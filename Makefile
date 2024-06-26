CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
CFILES = nearest_target.c move_not_sorted.c ft_joiner.c ft_is_digit.c fill_b.c fill_a.c arr_include_nbr.c arr_extracter.c arr_is_sorted.c cheapest_move_counter.c cheapest_path.c down_down.c down_up.c ft_abs.c ft_atoi.c ft_memmove.c ft_split.c ft_strdup.c ft_strjoin.c ft_strlen.c min_indice.c move_cheapest.c path_counter.c push_swap.c push.c rank_calc.c reverse_rotate_rotate.c reverse_rotate.c rotate.c rotate_rotate.c sort_three_nbrs.c swap.c up_down.c up_up.c check_duplicate.c tallest_sorted_numbers.c arr_half_sorted.c
OFILES = $(CFILES:.c=.o)
BONUS_CFILES = checker_bonus.c ft_atoi.c ft_strjoin.c ft_strlen.c ft_strdup.c ft_is_digit.c ft_memmove.c  get_next_line/get_next_line.c get_next_line/get_next_line_utils.c push.c swap.c rotate.c reverse_rotate.c  rotate_rotate.c reverse_rotate_rotate.c swap_swap.c arr_extracter.c check_duplicate.c ft_split.c arr_is_sorted.c ft_joiner.c 
BONUS_OFILES = $(BONUS_CFILES:.c=.o)
NAME = push_swap
BONUS_NAME = checker

all : $(NAME)

bonus : $(BONUS_NAME)

$(NAME) : $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o $(NAME)

$(BONUS_NAME) : $(BONUS_OFILES)
	$(CC) $(CFLAGS) $(BONUS_OFILES) -o $(BONUS_NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OFILES) $(BONUS_OFILES) $(BONUS_OFILES)

fclean : clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re	bonus