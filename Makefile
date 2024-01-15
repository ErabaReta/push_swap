CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
CFILES = push_swap.c push_swap_utils.c
OFILES = $(CFILES:.c=.o)
NAME = push_swap

all : $(NAME)

$(NAME) : $(OFILES)
	$(CC) $(OFILES) -o $(NAME)

# $(OFILES) : $(CFILES)
# 	$(CC) -c $(CFILES)

.c.o:
	$(CC) -c $< -o $@
# $(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OFILES) $(BONUS_OFILES)

fclean : clean
	$(RM) $(NAME)

re: fclean all
