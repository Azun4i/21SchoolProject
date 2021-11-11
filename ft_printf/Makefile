LIBFT 		= ./libft/libft.a

NAME		=	libftprintf.a

HEADER		= ./includes/ft_printf.h

DIR_S		= src

SOURCE		=	ft_printf.c ft_putchar.c\
				ft_pars.c ft_print_wight.c\
				ft_check_strct.c ft_print_smbls.c\
				ft_pars1.c ft_pars2.c ft_pars3.c\

SRCS			= $(addprefix $(DIR_S)/,$(SOURCE))
OBJS			= $(SRCS:.c=.o)


GCC			=	gcc
ARRC		=	ar rcs
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror

%.o:			%.c ${HEADER}
				$(CC) $(CFLAGS) -c -o $@ $<

all:			${NAME}

$(NAME):		$(OBJS) $(HEADER)
				$(MAKE) -C ./libft
				cp libft/libft.a ./$(NAME)
				$(ARRC) $(NAME) $(OBJS)


clean:
				$(MAKE) clean -C ./libft
				$(RM) $(OBJS)

fclean:			clean
				$(MAKE) fclean -C ./libft
				$(RM) $(NAME)

re:				fclean all