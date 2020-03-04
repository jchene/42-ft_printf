NAME		=	libftprintf.a

HEADER		=	headers/

SRCS		=	srcs/ft_printf.c\
				srcs/ft_printf_utils.c\
				srcs/check.c\
				srcs/handle.c\
				srcs/apply_convert_csp.c\
				srcs/apply_convert_diux.c\
				srcs/apply_prec.c\
				srcs/apply_width.c\
				srcs/apply_flag.c\
				lib/numbers.c\
				lib/strings.c\
				lib/mem_disp.c\
				lib/lenghts.c\

CC			=	gcc

CFLAGS		=	-Werror -Wextra -Wall

DEL			=	rm -f

OBJS		=	${SRCS:.c=.o}

$(NAME):		${OBJS}
				${CC} ${CFLAGS} -c -I ${HEADER} ${SRCS}
				ar rc ${NAME} ${OBJS}

all:			${NAME}

clean:
				${DEL} ${OBJS} *.o

fclean:			clean
				${DEL} ${NAME}

re:				fclean all

.PHONY: 		all clean fclean re
