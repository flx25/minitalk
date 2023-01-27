# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 09:41:14 by fvon-nag          #+#    #+#              #
#    Updated: 2023/01/27 12:06:36 by fvon-nag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = minitalk
SEVER = server
CLIENT = client

SERVER_DIR = ./src/server
CLIENT_DIR = ./src/client
OBJ_DIR = ./obj

PRINTF_DIR = ./ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SERVER_FILES :=

CLIENT_FILES :=

IFLAGS = -I./libft -I./ft_printf
LFLAGS = -L./libft -L./ft_printf -lftprintf -lft

SERVER_OBJECTS = $(addprefix $(OBJ_DIR)/, $(SERVER_FILES:.c=.o))
CLIENT_OBJECTS = $(addprefix $(OBJ_DIR)/, $(CLIENT_FILES:.c=.o))

CFLAGS += -Wall -Wextra -Werror -03

all: ${NAME}

$(NAME) : $(LIBFT) $(PRINTF) $(OBJ_DIR) $(SERVER) $(CLIENT)

$(OBJ_DIR)
	mkdir -p $(OBJ_DIR)

$(SERVER): $(SERVER_OBJECTS)
	$(CC) $(SERVER_OBJECTS) -o $(SERVER) $(LFLAGS)

$(CLIENT): $(CLIENT_OBJECTS)
	$(CC) $(CLIENT_OBJECTS) -o $(CLIENT) $(LFLAGS)
clean :
	make -C ft_printf clean
	make -C libft clean
	rm -f $(OBJECTS)
fclean : clean
	make -C ft_printf fclean
	make -C libft fclean
	rm -f $(NAME)
re : fclean all

