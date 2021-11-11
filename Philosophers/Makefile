NAME			= philo

HEADER			= library.h

SOURCE			= main.c ft_utils.c rft_atoi_l.c threads_var1.c

SRCS			= $(SOURCE)
OBJS			= $(SRCS:.c=.o)

GCC				=	gcc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror

all: $(NAME)

.c.o:
		$(GCC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(HEADER)
		$(GCC) $(CFLAGS) $(OBJS) -o $(NAME)


clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONE:	all clean fclean
