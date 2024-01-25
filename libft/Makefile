# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 10:31:55 by amousaid          #+#    #+#              #
#    Updated: 2024/01/25 18:40:13 by amousaid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC= ft_atoi.c\
     ft_strlen.c\
 
OBJ= $(SRC:.c=.o)
CC= cc
CFLAGS= -Wall -Wextra  -Werror 
RM= rm -f
AR= ar -rc

.PHONY: all clean fclean re

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)	

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.SILENT:
