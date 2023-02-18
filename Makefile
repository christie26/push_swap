
SRCDIR		= ./src
SRC			= 	main.c \
				parse.c \
				parse_utils.c \
				cmd_push.c \
				cmd_swap.c \
				cmd_rotate.c \
				cmd_reverse.c \
				cmd_utils.c \
				quick_sort.c \
				biggest.c \
				move_to_b.c \
				back_to_a.c 

SRC			:= $(addprefix $(SRCDIR)/, $(SRC))
OBJ			= ${SRC:.c=.o}

NAME		= ./push_swap
LIBFT		= ./libft/libft.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
LDFLAGS		= -fsanitize=address
RM			= rm -f

all:		${NAME}

%.o: 		%.c
			$(CC) $(CFLAGS) -Ilibft -c $< -o $@

$(NAME): 	$(OBJ) $(LIBFT)
			$(CC) $(OBJ) -L./libft -lft -o $(NAME) 

$(LIBFT):
			make -j3 -C ./libft all
clean:
			${RM} ${OBJ}
			@make -C ./libft clean

fclean:		clean
			${RM} ${NAME}
			@make -C ./libft fclean

re:			fclean all

.PHONY:		all clean fclean re
