NAME	=	philo
SRCS	=	main.c utils.c
OBJS	=	$(SRCS:.c=.o)
HEADER	=	philo.h
CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror #fsanitize=thread -g

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(HEADER)
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o		:	%.c $(HEADER)
			@$(CC) -c $< -o $@
			
clean	:	
			@rm -rf $(OBJS)

fclean	:	clean
			@rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re