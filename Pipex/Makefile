NAME			= pipex

BONUS			= pipex_bonus

HEADER			= ft_pipex.h
HEADER_B		= ft_pipex_bonus.h

SOURCE			= ft_pipex.c ft_utils.c
SOURCE_BONUS	= srs_bonus/ft_pipex_bonus.c srs_bonus/ft_utils_bonus.c srs_bonus/ft_process_bonus.c

SRCS			= $(SOURCE)
OBJS			= $(SRCS:.c=.o)

SRCS_bonus		= $(SOURCE_BONUS)
OBJS_bonus		= $(SRCS_bonus:.c=.o)


GCC				=	gcc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror

all: $(NAME)

.c.o:
		$(GCC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(HEADER)
		$(MAKE) -C ./libft
		$(GCC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

$(BONUS): $(OBJS_bonus)
		$(MAKE) -C ./libft
		$(GCC) $(CFLAGS) $(OBJS_bonus) libft/libft.a -o $(BONUS)


bonus:	$(BONUS)

clean:
				$(MAKE) clean -C ./libft
				$(RM) $(OBJS)
				$(RM) $(OBJS_bonus)

fclean:			clean
				$(MAKE) fclean -C ./libft
				$(RM) $(NAME)
				$(RM) $(BONUS)

re:				fclean all

.PHONE:	all clean fclean
