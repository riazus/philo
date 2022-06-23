NAME	=	philo
SRCS	=	main.c utils.c init_philos.c \
			threads.c routine.c actions.c
			
OBJS	=	$(SRCS:.c=.o)
HEADER	=	philo.h
CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror #fsanitize=thread -g

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(HEADER)
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			@echo Built!

%.o		:	%.c $(HEADER)
			@$(CC) -c $< -o $@
			
clean	:	
			@rm -rf $(OBJS)
			@echo Clened!

fclean	:	clean
			@rm -rf $(NAME)
			@echo Full cleaned!

re		:	fclean all

.PHONY	:	all clean fclean re
