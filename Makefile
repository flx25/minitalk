# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 09:41:14 by fvon-nag          #+#    #+#              #
#    Updated: 2023/02/01 16:50:42 by fvon-nag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = minitalk
SERVER = server
CLIENT = client

SERVER_DIR = ./sources/server
CLIENT_DIR = ./sources/client
OBJ_DIR = ./obj

PRINTF_DIR = ./ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SERVER_FILES := server.c

CLIENT_FILES := client.c

IFLAGS = -I./libft -I./ft_printf
LFLAGS = -L./libft -L./ft_printf -lftprintf -lft

SERVER_OBJECTS = $(addprefix $(OBJ_DIR)/, $(SERVER_FILES:.c=.o))
CLIENT_OBJECTS = $(addprefix $(OBJ_DIR)/, $(CLIENT_FILES:.c=.o))

CFLAGS += -Wall -Wextra -Werror -g

all: ${NAME}

$(NAME) : $(LIBFT) $(PRINTF) $(OBJ_DIR) $(SERVER) $(CLIENT)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(SERVER): $(SERVER_OBJECTS)
	$(CC) $(CFLAGS) $(SERVER_OBJECTS) -o $(SERVER) $(LFLAGS)

$(CLIENT): $(CLIENT_OBJECTS)
	$(CC) $(CFLAGS) $(CLIENT_OBJECTS) -o $(CLIENT) $(LFLAGS)

$(OBJ_DIR)/%.o: $(SERVER_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(CLIENT_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(PRINTF):
	make -C $(PRINTF_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	$(RM) $(SERVER_OBJECTS) $(CLIENT_OBJECTS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean
	$(RM) $(SERVER)
	$(RM) $(CLIENT)

re : fclean all

