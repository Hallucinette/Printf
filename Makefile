NAME = libftprintf.a

SRCS =	ft_printf.c \
		ft_width.c \
		type_c_s.c \
		type_xX.c \
		type_p.c \
		type_d.c \
		type_u.c

OBJS	:= ${SRCS:.c=.o}

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -I.
RM		= rm -f

all:	${NAME}

%.o: %.c
		${CC} ${CFLAGS} -c $< -o $@

%.o: libft/%.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}:${OBJS}
		make -C libft 
		ar rc ${NAME} libft/*.o ${OBJS}

debug:
		$(CC) $(CFLAGS) -g $(SRCS) main.c ft_printf.h libft/ft_*.c -I libft

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME} libft/*.o *.o

re:		fclean all
.PHONY: all clean fclean re