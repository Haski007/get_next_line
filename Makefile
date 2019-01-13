# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdemian <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/27 15:55:01 by pdemian           #+#    #+#              #
#    Updated: 2019/01/10 23:39:42 by pdemian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	seems_it_works

HEADER		=	get_next_line.h

INCLUDES	=	libft/libft.a

CFLAGS		=	-Wall -Werror -Wextra -I. -c -g

FILES		=	get_next_line.c \
				libft/*.c \
				main.c


OBJ			= $(FILES:%.c=%.o)

TG			=	"\033[32m"
TR			=	"\033[31m"
TU			=	"\033[4m"
EOC			=	"\033[0m"

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror $(FILES) -o $(NAME) -I libft/libft.a
	@echo ${TG}"[✓] "${TU}"$@"${EOC}

clean:
	@rm -f $(OBJ)
	@echo ${TR}"[✗] $(OBJ)"${EOC}

fclean: clean
	@rm -f $(NAME)
	@echo ${TR}"[✗] "${TU}"$(NAME)"${EOC}

re: fclean all

.PHONY: all clean fclean re
