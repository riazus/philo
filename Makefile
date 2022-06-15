NAME	=	philo
SRCS	=	main.c
OBJS	=	$(SRCS:.c=.o)
HEADER	=	philo.h
CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror -I $(HEADER)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(OBJS) -o $(NAME)

%.o		:	%.c $(HEADER)
			$(CC) -c $< -o $@
			
clean	:	
			rm -rf $(OBJS)

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re