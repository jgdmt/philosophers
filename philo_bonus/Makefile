SRCS		:=	main_bonus.c

OBJS		:=	${SRCS:.c=.o}

CC			:= gcc
CFLAGS		:= -Werror -Wextra -Wall -I.
RM			:= rm -f

NAME		:= philo_bonus

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:		
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re