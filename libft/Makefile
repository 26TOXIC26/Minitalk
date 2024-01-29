# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 10:31:55 by amousaid          #+#    #+#              #
#    Updated: 2024/01/29 00:55:30 by amousaid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC= ft_atoi.c\
     ft_strlen.c\
	 ft_isdigit.c\
 
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
