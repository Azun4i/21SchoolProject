PUSH_SWAP	= push_swap

CHECKER = checker

HEADER		= ft_push_swap.h

SOURCE		= ft_algoritm.c ft_algoritm_for_small.c ft_cheker.c ft_func_for_list.c ft_mark.c ft_push_swap.c ft_rules.c\
				ft_rules_r.c ft_utils.c ft_utils_for_algoritm.c ft_wat_sort_need.c ft_if_space.c

CH_SRCS  	= ft_checker.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
			ft_algoritm.c ft_algoritm_for_small.c ft_cheker.c ft_func_for_list.c ft_mark.c ft_rules.c\
                			ft_rules_r.c ft_utils.c ft_utils_for_algoritm.c ft_wat_sort_need.c ft_if_space.c

SRCS		= $(SOURCE)
OBJS		= $(SRCS:.c=.o)
SRCS1		= $(CH_SRCS)
OBJS1		= $(CH_SRCS:.c=.o)

GCC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror

all: $(PUSH_SWAP)

.c.o:
		$(GCC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(PUSH_SWAP): $(OBJS)
		$(MAKE) -C ./libft
		$(GCC) $(OBJS) $(CFLAGS) libft/libft.a -o $(PUSH_SWAP)

$(CHECKER): $(OBJS1)
		$(GCC) $(OBJS1) $(CFLAGS) libft/libft.a -o $(CHECKER)


bonus:	$(PUSH_SWAP) $(CHECKER)

clean:
				$(MAKE) clean -C ./libft
				$(RM) $(OBJS)
				$(RM) $(OBJS1)

fclean:			clean
				$(MAKE) fclean -C ./libft
				$(RM) $(PUSH_SWAP)
				$(RM) $(CHECKER)

re:				fclean all
