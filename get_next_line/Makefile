CC = cc
CFLAGS = -Wall -Wextra -Werror
CFILES = get_next_line.c get_next_line_utils.c
OFILES = $(CFILES:.c=.o)
BONUS_CFILES = $(CFILES:.c=_bonus.c)
BONUS_OFILES = $(BONUS_CFILES:.c=.o)
AR = ar rcs
RM = rm -Rf
NAME = libft_get_next_line.a

all : $(NAME)

$(NAME) : $(OFILES)

bonus : $(BONUS_OFILES)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
	$(AR) $(NAME) $@

clean :
	$(RM) $(OFILES) $(BONUS_OFILES)

fclean : clean
	$(RM) $(NAME)

re: fclean all

test: re
	@$(RM) $(OFILES)
	@$(CC) $(NAME) .main.c
	@$(RM) $(NAME)
	@echo "===============>( output )<==============="
	@./a.out | cat -e

test_bonus: fclean bonus
	@$(RM) $(BONUS_OFILES)
	@$(CC) $(NAME) .main.c
	@$(RM) $(NAME)
	@echo "===============>( output )<==============="
	@./a.out | cat -e
	

.PHONY: all clean fclean re	bonus
