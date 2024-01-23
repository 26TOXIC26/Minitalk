# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 17:35:08 by amousaid          #+#    #+#              #
#    Updated: 2024/01/23 18:54:46 by amousaid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN=$(shell tput setaf 2)
RED=$(shell tput setaf 1)
RESET := $(shell tput sgr0)
NAME = server client
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/libftprintf.a
RM = rm -rf

SERVER_SRCS = server.c
CLIENT_SRCS = client.c

all: $(NAME)

$(LIBFT):
		$(MAKE) --no-print-directory -C ./libft
		
$(FT_PRINTF):
		$(MAKE) --no-print-directory -C ./ft_printf
		
$(NAME): $(LIBFT) $(FT_PRINTF) client.c server.c
	$(CC) $(CFLAGS) $(SERVER_SRCS) $(LIBFT) $(FT_PRINTF) -o server
	
	$(CC) $(CFLAGS) $(CLIENT_SRCS) $(LIBFT) $(FT_PRINTF) -o client
	@echo "$(GREEN)        		--------[DONE]--------"
	@echo "$(GREEN)			|[LIBFT] $(RESET)is ready    $(GREEN)|"
	@echo "$(GREEN)			|[FT_PRINTF] $(RESET)is ready$(GREEN)|"
	@echo "$(GREEN)			|[SERVER] $(RESET)is ready.  $(GREEN)|"
	@echo "$(GREEN)			|[CLIENT] $(RESET)is ready.  $(GREEN)|"
	@echo "$(GREEN)        		--------[DONE]--------"
clean:
	$(MAKE) clean --no-print-directory -C ./libft
	$(MAKE) clean --no-print-directory -C ./ft_printf
	@echo "$(RED)			-----------[DONE]-----------"
	@echo "$(RED)			|[LIBFT OBJ] $(RESET)is clean.     $(RED)|"
	@echo "$(RED)			|[FT_PRINTF OBJ] $(RESET)is clean. $(RED)|"
	@echo "$(RED)			|[MINITALK OBJ] $(RESET)is clean.  $(RED)|"
	@echo "$(RED)			-----------[DONE]-----------"
fclean: clean
	$(MAKE) fclean --no-print-directory -C ./libft
	$(MAKE) fclean --no-print-directory -C ./ft_printf
	$(RM) $(NAME)
	@echo "$(RED)			|[ALL MINITALK] $(RESET)is clean.  $(RED)|"
	@echo "$(RED)			-----------[DONE]-----------"
re: fclean all

.SILENT:
	