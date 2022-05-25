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
					srcs/radix_bit_sort.c \

FLAGS			=	-Wall -Wextra -Werror
OBJS			=	$(SRCS:.c=.o)

ARG5			=	7 9 1 3 5 
ARG6			=	4 2 -8 12 15 1
ARG9			=	-50 -150 -250 -200 -300 -350 -400 -500 -600
ARG30			=	14 20 11 12 16 19 24 18 8 7 6 3 4 5 9 0 -14 -20 -10 -12 -16 -22 -24 -18 -8 -7 -6 -3 -4 -5 
ARG40			=	-12 -54 -51 -15 21 0 15 24 -45 30 39 -30 33 45 36 42 51 18 54 3 6 57 -3 48 -9 -6 -18 -24 9 -27 -33 12 -36 -39 -42 60 -48 -21 -60 -57 27

all		: 	$(NAME)

%.o	: %.c
			$(CC) -I ./includes/ -c $(CFLAGS) -o $@ $<

$(NAME)	:	$(OBJS)
			$(CC) ${OBJS} $(FLAGS) -o $(NAME)
			@echo $(NAME) has been made!

run		:	all
			./$(NAME) $(ARG40)

show	:	all
			python3 ./push_swap_visualizer/pyviz.py $(ARG40)
			
checker	:	all
			./$(NAME) $(ARG40) | ./checker_Mac $(ARG40)

clean	:
	    	$(RM) $(OBJS)

fclean	: 	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	clean fclean re all run test1