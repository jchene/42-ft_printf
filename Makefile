
NAME		=	libftprintf.a

HEADER		=	headers/

SRCS		=	srcs/ft_printf.c\
				srcs/convert_int.c\
				lib/numbers.c\
				lib/strings.c\

BONUSSRCS	=	ft_lstadd_back_bonus.c\
				ft_lstadd_front_bonus.c\
				ft_lstclear_bonus.c\
				ft_lstdelone_bonus.c\
				ft_lstiter_bonus.c\
				ft_lstlast_bonus.c\
				ft_lstmap_bonus.c\
				ft_lstnew_bonus.c\
				ft_lstsize_bonus.c\

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
