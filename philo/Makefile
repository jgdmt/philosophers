SRCS		:=	main.c \
				init.c \
				ft_atoi.c \
				utils.c

OBJS		:=	${SRCS:.c=.o}

CC			:= gcc
CFLAGS		:= -Werror -Wextra -Wall -I. #-fsanitize=address
RM			:= rm -f

NAME		:= philo

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:		
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re