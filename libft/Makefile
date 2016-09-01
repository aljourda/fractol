# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aljourda <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 15:50:12 by aljourda          #+#    #+#              #
#    Updated: 2015/11/30 17:40:15 by aljourda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
SRC=ft_atoi.c ft_lstdelone.c ft_memmove.c ft_sqrt.c ft_strjoin.c ft_strrchr.c \
ft_bzero.c ft_lstiter.c ft_memset.c ft_strcat.c ft_strlcat.c ft_strrev.c \
ft_isalnum.c ft_lstmap.c ft_pow.c ft_strchr.c ft_strlen.c ft_strsplit.c \
ft_isalpha.c ft_lstnew.c ft_putchar.c ft_strclr.c ft_strmap.c ft_strstr.c \
ft_isascii.c ft_memalloc.c ft_putchar_fd.c ft_strcmp.c ft_strmapi.c ft_strsub.c \
ft_isdigit.c ft_memccpy.c ft_putendl.c ft_strcpy.c ft_strncat.c ft_strtrim.c \
ft_isprint.c ft_memchr.c ft_putendl_fd.c ft_strdel.c ft_strncmp.c ft_swap.c \
ft_isspace.c ft_memcmp.c ft_putnbr.c ft_strdup.c ft_strncpy.c ft_tolower.c \
ft_itoa.c ft_memcpy.c ft_putnbr_fd.c ft_strequ.c ft_strnequ.c ft_toupper.c \
ft_lstadd.c ft_memdel.c ft_putstr.c ft_striter.c ft_strnew.c \
ft_lstdel.c ft_memdup.c ft_putstr_fd.c ft_striteri.c ft_strnstr.c

OBJ=$(SRC:.c=.o)
LDFLAGS=-Wall -Wextra -Werror

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	gcc -c $(LDFLAGS) $^ -o $@
