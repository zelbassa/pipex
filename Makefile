NAME	=	pipex
LIBFT	=	libft/libft.a
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -fsanitize=address
SRC		=	pipex.c utils.c
OBJ		=	$(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	cd libft && make

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -Llibft -lft -o $(NAME)

clean:
	rm -f $(OBJ)
	cd libft && make clean

fclean: clean
	rm -f $(NAME)
	cd libft && make fclean

re: fclean all

.PHONY: all clean fclean re
