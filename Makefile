# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aljourda <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/16 14:36:09 by aljourda          #+#    #+#              #
#    Updated: 2016/08/16 14:39:54 by aljourda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fractol
SRC= srcs/fractal.c \
	 srcs/mouse.c \
	 srcs/fractol.c

CC=clang
CFLAGS=-I libft/includes -I minilibx_macos/ -I get_next_line/ -I includes/ -Wall -Wextra -Werror
OBJ=$(SRC:.c=.o)
LDFLAGS=-L libft/ -L minilibx_macos/
LIBS=-lft -lm -lmlx -framework OpenGL -framework AppKit

$(NAME): $(OBJ)
	make -C libft/
	make -C minilibx_macos/
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LIBS)

all: $(NAME)

clean:
	make clean -C libft/
	make clean -C minilibx_macos/
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	$(CC) -c $(CFLAGS) $^ -o $@
