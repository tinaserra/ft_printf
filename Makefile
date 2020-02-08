# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vserra <vserra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/25 22:05:00 by vserra            #+#    #+#              #
#    Updated: 2020/02/07 02:21:35 by vserra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	ft_printf.c\
			parsing.c\
			parsing_utils.c

OBJ		=		$(SRC:%.c=$(PRE_OBJ)%.o) #regle implicite -> peut etre un mauvais vocabulaire
OBJS	=		$(addprefix $(PRE_OBJ), $(OBJ))

SRCS	=		$(addprefix $(PRE_SRC), $(SRC))

DEP		=		$(SRC:%.c=$(PRE_OBJ)%.d)


PRE_SRC	=	./srcs/
PRE_OBJ	=	./objs/

HEAD	=	./includes/

NAME	=	libftprintf.a

AR		=	ar rc

LIB		=	ranlib

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror # -MMD # -> voir pour creer des .d

all : $(NAME) # nom de l'executable

$(PRE_OBJ)%.o: $(PRE_SRC)%.c
	@mkdir -p $(PRE_OBJ)
	$(CC) $(CFLAGS) -I $(HEAD) -c $< -o $@
# -p créer les dossiers s'ils n'existent pas

-include $(DEP)
$(PRE_OBJ)%.d: $(PRE_SRC)%.c
	@mkdir -p $(PRE_OBJ)
	$(CC) -MMD -I $(HEAD) $< -o $@

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)
	$(LIB) $(NAME)

clean :
	rm -rf $(PRE_OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re

# $@	Le nom de la cible / regle
# $<	Le nom de la première dépendance
# $^	La liste des dépendances
# $?	La liste des dépendances plus récentes que la cible
# $*	Le nom du fichier sans suffixe

# %.o: %.c -> regle generique : par exemple construire un .o à partir d'un .c qui se verront appelées par défaut