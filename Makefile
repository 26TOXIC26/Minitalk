# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 17:35:08 by amousaid          #+#    #+#              #
#    Updated: 2024/01/27 01:18:54 by amousaid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server client server_bonus client_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/libftprintf.a
RM = rm -rf

SERVER_SRCS = server.c
CLIENT_SRCS = client.c
SERVER_BONUS_SRCS = server_bonus.c
CLIENT_BONUS_SRCS = client_bonus.c

all: $(NAME)

$(LIBFT):
		$(MAKE) --no-print-directory -C ./libft
		
$(FT_PRINTF):
		$(MAKE) --no-print-directory -C ./ft_printf
		
$(NAME): $(LIBFT) $(FT_PRINTF) $(SERVER_SRCS) $(SERVER_BONUS_SRCS) $(CLIENT_SRCS) $(CLIENT_BONUS_SRCS)
	$(CC) $(CFLAGS) $(SERVER_SRCS) $(LIBFT) $(FT_PRINTF) -o server
	$(CC) $(CFLAGS) $(SERVER_BONUS_SRCS) $(LIBFT) $(FT_PRINTF) -o server_bonus
	$(CC) $(CFLAGS) $(CLIENT_SRCS) $(LIBFT) $(FT_PRINTF) -o client
	$(CC) $(CFLAGS) $(CLIENT_BONUS_SRCS) $(LIBFT) $(FT_PRINTF) -o client_bonus
	@echo "-----------[DONE]-----------"
	@echo "[LIBFT] is ready           |"
	@echo "[FT_PRINTF] is ready       |"
	@echo "[SERVER] is ready.         |"
	@echo "[CLIENT] is ready.         |"
	@echo "-----------[DONE]-----------"
clean:
	$(MAKE) clean --no-print-directory -C ./libft
	$(MAKE) clean --no-print-directory -C ./ft_printf
	@echo "-----------[DONE]-----------"
	@echo "[LIBFT OBJ] is clean.	   |"
	@echo "[FT_PRINTF OBJ] is clean.  |"
	@echo "[MINITALK OBJ] is clean.   |"
fclean: clean
	$(MAKE) fclean --no-print-directory -C ./libft
	$(MAKE) fclean --no-print-directory -C ./ft_printf
	$(RM) $(NAME)
	@echo "[ALL MINITALK] is clean.   |"
re: fclean all

.SILENT:
	