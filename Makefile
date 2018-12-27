# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgendry <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/20 18:09:46 by sgendry           #+#    #+#              #
#    Updated: 2018/12/27 14:27:32 by sgendry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAG = -Wall -Werror -Wextra
FILES = fillit.c \
		validation.c \
		preparation.c \
		solution.c \
		solution_second.c \
		libft/ft_strlen.c \
		libft/ft_putstr.c \
		libft/ft_putchar.c

OBJECTS = $(FILES:.c=.o)

$(NAME) :
	gcc $(FLAG) -c $(FILES) -o $(OBJECTS)

#$(NAME) :
#	gcc $(FLAG) -o $(NAME) $(FILES)

all : $(NAME)

clean :
	rm -rf $(NAME)

fclean : clean

re : fclean all
