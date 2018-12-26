# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lschambe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/19 15:13:27 by lschambe          #+#    #+#              #
#    Updated: 2018/12/26 17:27:13 by sgendry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAG = -Wall -Werror -Wextra
FILES = fillit.c \
		validation.c \
		preparation.c \
		solution.c \
		libft/ft_strlen.c \
		libft/ft_putstr.c \
		libft/ft_putchar.c

$(NAME) :
	gcc $(FLAG) -o $(NAME) $(FILES)

all : $(NAME)

clean :

fclean : clean
	rm -rf $(NAME)

re : fclean all
