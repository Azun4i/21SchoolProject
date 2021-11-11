NAME	= fdf

HEADER		= ft_fdf.h

SOURCE		=  get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
				ft_fdf.c ft_utils.c ft_utils_1.c ft_read_file_and_fill_matrix.c ft_algo_brethenhema.c\
				ft_rotete_xyz.c ft_do_algo_brethenheme.c

SRCS		= $(SOURCE)
OBJS		= $(SRCS:.c=.o)


GCC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror

all: $(NAME)

.c.o:
		$(GCC) $(CFLAGS)  -Imlx -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(HEADER)
		$(MAKE) -C ./libft
		$(GCC) $(OBJS) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit libft/libft.a -o $(NAME)


bonus:	$(all)

clean:
				$(MAKE) clean -C ./libft
				$(RM) $(OBJS)
				$(RM) $(OBJS1)

fclean:			clean
				$(MAKE) fclean -C ./libft
				$(RM) $(NAME)

re:				fclean all

.PHONE:	all clean fclean
