NAME	= minishell

SRCS	= 	main.c\
			parse/signals.c parse/free.c parse/exit.c\
			parse/readline_change/readline_change.c parse/readline_change/copy_dollar.c parse/readline_change/readline_utils.c\
			parse/env/env_to_array.c parse/env/unset.c parse/env/env_creation.c parse/env/env_export_print.c\
			parse/env/env_change.c parse/env/env_change_utils.c parse/double_redir_read.c\
			parse/list_maker/lstnew_redir_pipe.c parse/list_maker/lstnew_cmd.c parse/list_maker/parse_main_cycle.c\
			parse/list_maker/lstnew_args.c parse/list_maker/lstnew_flags.c\
			chell/ft_chel.c chell/ft_utils_chell.c  chell/ft_redir.c chell/ft_utils_0.c chell/ft_utils.c\
			chell/ft_utils_for_redir_0.c chell/ft_utils_for_redir_1.c\
            builtins/rft_pwd.c builtins/rft_echo.c builtins/rft_cd.c\
            pipe/ft_utils_bonus.c pipe/ft_pipex_bonus.c  pipe/ft_process_bonus.c chell/ft_utils_do_path_direct.c\
            chell/ft_utils_for_redir_2.c


OBJS	= ${SRCS:.c=.o}

CFLAGS	= -Wall -Wextra -Werror 

LIBFT_DIR = libft

READLINE =  -L/Users/$(USER)/.brew/Cellar/readline/8.1/lib/ -lreadline

%.o: %.c minishell.h
	gcc -c ${CFLAGS} -I . $< -o ${<:.c=.o}

${NAME}: ${OBJS} minishell.h
	ar rc libminishell.a ${OBJS}
	ranlib libminishell.a
	make -C ${LIBFT_DIR}
	make bonus -C ${LIBFT_DIR}
	cd ..
	gcc ${CFLAGS} ${LIBFT_DIR}/libft.a ${OBJS} ${READLINE} -L. -lminishell -o ${NAME}

all:	${NAME}

clean:
	rm -f ${OBJS}
	make -C ${LIBFT_DIR} clean
	cd ..

fclean:	clean
	rm -f ${NAME} libminishell.a ${LIBFT_DIR}/libft.a

re: fclean all

.PHONY:	all fclean clean re








