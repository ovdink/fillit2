# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lschambe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/19 15:13:27 by lschambe          #+#    #+#              #
#    Updated: 2018/12/25 20:54:12 by sgendry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAG = -Wall -Werror -Wextra -c
FILES = fillit.c \
		validation.c

OBJECTS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C ./libft
	$(CC) $(OBJECTS) libft/libft.a -I ./includes -o $(NAME)

%.o: %.c
	$(CC) $(CFLAG) $(FILES) -I ./includes -c $< -o $@

clean :
	make clean -C ./libft
	rm -rf $(OBJECTS)

fclean : clean
	make fclean -C ./libft
	rm -rf $(NAME)

re : fclean all
