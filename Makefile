# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 09:41:14 by fvon-nag          #+#    #+#              #
#    Updated: 2023/02/06 15:47:32 by fvon-nag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = server.c client.c
BSOURCES = server_bonus.c client_bonus.c
OBJECTS = $(SOURCES:.c=.o)
BOBJECTS = $(BSOURCES:.c=.o)
NAME = minitalk
CC = cc
CFLAGS = -Wall -Wextra -Werror

$(NAME) : all

bonus : server_bonus client_bonus

all: server client

server: server.o libft printf
	$(CC) $(CFLAGS) -o $@ $< -Llibft -lft -Lft_printf -lftprintf

client: client.o libft printf
	$(CC) $(CFLAGS) -o $@ $< -Llibft -lft -Lft_printf -lftprintf

server_bonus: server_bonus.o libft printf
	$(CC) $(CFLAGS) -o $@ $< -Llibft -lft -Lft_printf -lftprintf

client_bonus: client_bonus.o libft printf
	$(CC) $(CFLAGS) -o $@ $< -Llibft -lft -Lft_printf -lftprintf

%.o: %.c
	$(CC) -c $(CFLAGS) $?

libft:
	make -C libft
printf:
	make -C ft_printf

clean:
	rm -f $(OBJECTS) $(BOBJECTS)
	make -C libft clean
	make -C ft_printf clean

fclean: clean
	rm -f server client server_bonus client_bonus libft/libft.a ft_printf/libftprintf.a

re: fclean all

.PHONY: all bonus libft clean fclean re
