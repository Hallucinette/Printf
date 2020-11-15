# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amepocch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/09 12:53:22 by amepocch          #+#    #+#              #
#    Updated: 2019/12/13 07:52:18 by amepocch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFTDIR = /Users/amepocch/42cursus/libft

SRCDIR = ./
SRCS    = ft_strlen.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_atoi.c \
		ft_strnstr.c \
		ft_strdup.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_isprint.c \
		ft_isascii.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memcmp.c \
		ft_memchr.c \
		ft_bzero.c \
		ft_memset.c \
		ft_strjoin.c \
		ft_calloc.c \
		ft_substr.c \
		ft_strmapi.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_itoa.c \
		ft_strtrim.c \
		ft_split.c \
		ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c \

BON 	= 	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS    = ${SRCS:.c=.o}

CC      = gcc

CFLAGS  = -Wall -Wextra -Werror

BONU 	= 	${BON:.c=.o}

NAME    = libft.a

.c.o :       ${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}		:	${OBJS}
				ar rc ${NAME} ${OBJS}
				ranlib ${NAME}

all 		:   ${NAME}

bonus	 	: 	${BONU} ${OBJS}
				ar rc ${NAME} ${BONU} ${OBJS}
				ranlib ${NAME}
clean 		:
				rm -f ${OBJS} ${BONU}

fclean 		:	clean
				rm -f ${NAME}

re 			:   fclean all

.PHONY		:	all clean fclean re
