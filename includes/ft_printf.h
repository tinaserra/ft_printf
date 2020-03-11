/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 17:46:44 by vserra            #+#    #+#             */
/*   Updated: 2020/03/10 21:58:09 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** # define IS_MINUS		1 << 0 -> 1
** # define IS_ZERO			1 << 1 -> 2
** # define IS_WIDTH		1 << 2 -> 4
** # define IS_PRECISION	1 << 3 -> 8
** # define IS_POINT		1 << 4 -> 16
*/

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>

# define IS_MINUS		1
# define IS_ZERO		2
# define IS_WIDTH		4
# define IS_PRECISION	8
# define IS_POINT		16

typedef enum	e_mode{
	FLAGS,
	WIDTH,
	PRECISION,
	TYPE,
	ERROR
}				t_mode;

typedef struct	s_info {
	char			mask;
	int				w_value;
	int				p_value;
}				t_info;

typedef struct	s_data {
	unsigned char	*format;
	va_list			ap;
	t_info			info;
	t_mode			mode;
	int				nb_char;
	char			buff_nb[16];
	char			buff_space[8192];
	char			buff_zero[8192];
}				t_data;

/*
** GENERAL
*/

int				ft_printf(const char *str, ...);
void			parsing(t_data *data);
int				get_format(t_data *data);

/*
** TAB PARSING
*/

int				is_flag(t_data *data);
int				is_width(t_data *data);
int				get_width(t_data *data);
int				is_precision(t_data *data);
int				type_c(t_data *data);
int				type_d(t_data *data);
int				type_u(t_data *data);
int				type_x(t_data *data);
int				type_p(t_data *data);
int				type_s(t_data *data);
int				type_pourcent(t_data *data);
int				error();

/*
** UTILS
*/

int				putnbr(long nb, t_data *data);
int				putnbr_base(unsigned long nbr, char *base, t_data *data);
void			print_flags(t_data *data, int value, int ignored_char, int c);
void			print_prefix(t_data *data, long nb, int len, int c);
void			calc_precision(t_data *data, int len, long nb);
void			calc_width(t_data *data, size_t len, long nb);

/*
** DEBUG
*/

void			print_debug(char *str, t_data *data, int ctrl);
void			check_debug(t_data *data);
void			debug_int(char *str, int nb);

#endif
