# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gleger <gleger@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/16 17:27:47 by gleger            #+#    #+#              #
#    Updated: 2014/04/29 10:03:14 by gleger           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

SOURCES = main.c \
			ft_tool.c \
			init_list.c \
			clean_list.c \
			exit.c move.c \
			del_arg.c \
			write_list.c \
			loop.c \
			signals.c

OBJECTS = $(SOURCES:.c=.o)

HEADERS = ./includes/ft_select.h

FLAGS = -Wall -Werror -Wextra -O3 -I ./includes

LFLAGS = -ltermcap

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "\033[1;35;m[Linking] \t\t\033[0m: " | tr -d '\n'
	$(CC) $(FLAGS) $(LFLAGS) -o $@ $^ 
	@echo "\033[1;32;m[Success] \t\t\t\033[0m"

%.o: %.c $(HEADERS)
	@echo "\033[1;36;m[Compiling $<] \t\033[0m: " | tr -d '\n'
	$(CC) $(FLAGS) -c $<

clean:
	@echo "\033[0;33;m[Cleaning] \t\t\033[0m: " | tr -d '\n'
	rm -f $(OBJECTS)

fclean: clean
	@echo "\033[0;31;m[Deleting $(NAME)] \t\033[0m: " | tr -d '\n'
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re