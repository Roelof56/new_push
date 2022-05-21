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

FLAGS			=	-Wall -Wextra -Werror #-g -fsanitize=address
OBJS			=	$(SRCS:.c=.o)

ARG9			=	-50 -150 -250 -200 -300 -350 -400 -500 -600
ARG31			=	14 20 11 12 16 19 24 18 8 7 6 3 4 5 9 0 -14 -20 -10 -12 -16 -21 -24 -18 -8 -7 -6 -3 -4 -5 -9 


all		: 	$(NAME)

%.o	: %.c
			$(CC) -I ./includes/ -c $(CFLAGS) -o $@ $<

$(NAME)	:	$(OBJS)
			$(CC) ${OBJS} $(FLAGS) -o $(NAME)
			@echo $(NAME) has been made!

run		:	all
			./$(NAME) 4 2 -8 12 2147483647

run6	:	all
			./$(NAME) 4 2 -8 12 15 1

run9	:	all
			./$(NAME) $(ARG9)

show	:	all
			python3 ./push_swap_visualizer/pyviz.py $(ARG31)
			
checker	:	all
			./$(NAME) $(ARG31) | ./checker_Mac $(ARG31)

clean	:
	    	$(RM) $(OBJS)

fclean	: 	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	clean fclean re all run test1