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

ARG1			= 2 1 3 6 5 -8 +4 -100 23456

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
			./$(NAME) 4 2 -8 12 15 1 -2 -1 30 

show	:	all
			python3 ./psv/pyviz.py $(ARG1)

clean	:
	    	$(RM) $(OBJS)

fclean	: 	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	clean fclean re all run test1