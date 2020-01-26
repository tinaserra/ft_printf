# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vserra <vserra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/25 22:05:00 by vserra            #+#    #+#              #
#    Updated: 2020/01/25 22:23:30 by vserra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	ft_printf.c\
			parsing.c\
			parsing_utils.c

OBJ		=		${SRC:.c=.o}
OBJS	=		${addprefix ${PRE_OBJ}, ${OBJ}}

SRCS	=		${addprefix ${PRE_SRC}, ${SRC}}


PRE_SRC	=	./srcs/
PRE_OBJ	=	./objs/

HEAD	=	./includes/

NAME	=	libftprintf.a

AR		=	ar rc

LIB		=	ranlib

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror # -MMD -> voir pour creer des .d

all : ${NAME}

# %.o: %.c ${CC} ${CFLAGS} -I ${HEAD} -c $< -o $@
${PRE_OBJ}%.o: ${PRE_SRC}%.c ${HEAD}ft_printf.h
	@mkdir -p ${PRE_OBJ}
	${CC} ${CFLAGS} -I ${HEAD} -c $< -o $@

${NAME} : ${OBJS}
	${AR} ${NAME} ${OBJS}
	${LIB} ${NAME}

clean :
	rm -rf ${PRE_OBJ}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re
