# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vserra <vserra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/25 22:05:00 by vserra            #+#    #+#              #
#    Updated: 2020/03/04 14:15:18 by vserra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	ft_printf.c\
			parsing.c\
			parsing_utils.c\
			print_utils.c\
			int_utils.c\
			type_c.c\
			type_d.c\
			type_u.c\
			type_x.c\
			type_p.c\
			type_s.c\
			debug.c

OBJ		=		$(SRC:%.c=$(PRE_OBJ)%.o)

DEP		=		$(SRC:%.c=$(PRE_OBJ)%.d)

PRE_SRC	=	srcs/

PRE_OBJ	=	objs/

HEAD	=	includes/

NAME	=	libftprintf.a

AR		=	ar rc

LIB		=	ranlib

CC		=	gcc

override CFLAGS	+=	-Wall -Wextra -MMD # -Werror # -MMD -> creer des .d
# override -> permet de reecrire la suite de la variable

opti:
	make -j all
# -j = jobs (separe les taches de compile)

all: $(NAME) # nom de l'executable

$(PRE_OBJ)%.o: $(PRE_SRC)%.c
	mkdir -p $(PRE_OBJ)
	$(CC) $(CFLAGS) -I $(HEAD) -c $< -o $@
# -p créer les dossiers s'ils n'existent pas

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)
	$(LIB) $(NAME)
	@echo Le temps est bon, le ciel est bleu !

debug : fclean
	make opti CFLAGS:="-DDEBUG -g"

clean :
	rm -rf $(PRE_OBJ)

fclean : clean
	rm -f $(NAME)

re :
	@make fclean
	@make opti

.PHONY : all clean fclean re opti

-include $(DEP)

# $@	Le nom de la cible / regle
# $<	Le nom de la première dépendance
# $^	La liste des dépendances
# $?	La liste des dépendances plus récentes que la cible
# $*	Le nom du fichier sans suffixe
# @		Met en silence la ligne executée

# %.o: %.c -> regle generique : par exemple construire un .o à partir d'un .c qui se verront appelées par défaut