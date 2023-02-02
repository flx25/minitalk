# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 09:41:14 by fvon-nag          #+#    #+#              #
#    Updated: 2023/02/02 13:38:59 by fvon-nag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

NAME = minitalk
CC = cc
CFLAGS = -Wall -Wextra -Werror

$(NAME) : all

all: server client

server: server.o libft printf
	$(CC) $(CFLAGS) -o $@ $< -Llibft -lft -Lft_printf -lftprintf

client: client.o libft printf
	$(CC) $(CFLAGS) -o $@ $< -Llibft -lft -Lft_printf -lftprintf

%.o: %.c
	$(CC) -c $(CFLAGS) $?

libft:
	make -C libft
printf:
	make -C ft_printf

clean:
	rm -f $(OBJECTS)
	make -C libft clean
	make -C ft_printf clean

fclean: clean
	rm -f server client libft/libft.a ft_printf/libftprintf.a

re: fclean all

.PHONY: all bonus libft clean fclean re
