# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvon-nag <fvon-nag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 09:41:14 by fvon-nag          #+#    #+#              #
#    Updated: 2023/01/27 12:51:37 by fvon-nag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = minitalk
SEVER = server
CLIENT = client

SERVER_DIR = ./sources/server
CLIENT_DIR = ./sources/client
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

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(SERVER): $(SERVER_OBJECTS)
	$(CC) $(SERVER_OBJECTS) -o $(SERVER) $(LFLAGS)

$(CLIENT): $(CLIENT_OBJECTS)
	$(CC) $(CLIENT_OBJECTS) -o $(CLIENT) $(LFLAGS)

$(OBJ_DIR)/%.o: $(SERVER_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(CLIENT_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(PRINTF):
	make -C $(PRINTF_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(SERVER)
	$(RM) $(CLIENT)

re : fclean all

