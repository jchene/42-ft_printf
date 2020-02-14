NAME		=	libftprintf.a

HEADER		=	headers/

SRCS		=	srcs/ft_printf.c\
				srcs/check.c\
				srcs/handle.c\
				srcs/convert_csp.c\
				srcs/convert_diuxX%.c\
				lib/numbers.c\
				lib/strings.c\

BONUSSRCS	=	

CC			=	gcc

CFLAGS		=	-Werror -Wextra -Wall

DEL			=	rm -f

OBJS		=	${SRCS:.c=.o}

BONUSOBJS	=	${BONUSSRCS:.c=.o}

$(NAME):		${OBJS}
				${CC} ${CFLAGS} -c -I ${HEADER} ${SRCS}
				ar rc ${NAME} ${OBJS}

all:			${NAME}

bonus:			${BONUSBJS} fclean
				${CC} ${CFLAGS} -c -I ${HEADER} ${SRCS} ${BONUSSRCS}
				ar rc ${NAME} ${OBJS} ${BONUSOBJS}

clean:
				${DEL} ${OBJS} ${BONUSOBJS}

fclean:			clean
				${DEL} ${NAME}

re:				fclean all

.PHONY: 		all clean fclean re bonus
