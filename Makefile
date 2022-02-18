HEADER	= push_swap.h
NAME	= push_swap
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
SRCS	= rules.c utils.c push_swap.c ft_atoi.c \
			utils2.c rules2.c rules3.c algo.c valid.c \
			ft_split.c algo2.c algo3.c algo4.c algo5.c \
			valid2.c algo6.c optimization.c

OBJ		= $(SRCS:%.c=%.o)

$(NAME)	:	$(OBJ) $(HEADER)
			$(CC) $(CFLAGS) -g $(OBJ) -o $(NAME)

all		:	$(NAME)

clean	:
	rm -rf $(OBJ)

fclean	: clean
	rm -rf $(NAME)

re		: fclean $(NAME)

.PHONY	: all clean fclean re
