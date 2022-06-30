# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rhol <rhol@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/06/02 15:00:07 by rhol          #+#    #+#                  #
#    Updated: 2022/06/30 13:01:47 by rhol          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SHELL			:=	/bin/bash

NAME			=	push_swap
SRCS			=	srcs/main.c \
					srcs/utils.c \
					srcs/utils_list.c \
					srcs/op_push.c \
					srcs/op_reverse.c \
					srcs/op_rotate.c \
					srcs/op_swap.c \
					srcs/parse_input.c \
					srcs/handle_less.c \
					srcs/radix_bit_sort.c

FLAGS			=	-Wall -Wextra -Werror
OBJS			=	$(SRCS:.c=.o)

ARG				=	`seq -1000 -500 | sort -R | tr "\n" " "`
ARG6			=	42 12 11 60 9 26
ARG7			=	7 4 1 2 -3 -6 0

all		: 	$(NAME)

%.o	: %.c
			$(CC) -I ./includes/ -c $(CFLAGS) -o $@ $<

$(NAME)	:	$(OBJS)
			$(CC) ${OBJS} $(FLAGS) -o $(NAME)
			@echo $(NAME) has been made!

run		:	all
			./$(NAME) $(ARG6)

show	:	all
			python3 ./push_swap_visualizer/pyviz.py $(ARG40)

leak	:	all
			valgrind --leak-check=full ./push_swap $(ARG40)

checker	:	all
			./$(NAME) $(< list.txt) | ./checker_Mac $(list.txt)

output	:	all
			@echo $(ARG) >> list.txt

clean	:
	    	$(RM) $(OBJS)

fclean	: 	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	clean fclean re all run

# make output 
# ./push_swap $(< list.txt) | ./checker_Mac $(< list.txt); 
# ./push_swap $(< list.txt) | wc -l;