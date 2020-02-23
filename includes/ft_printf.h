/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 17:46:44 by vserra            #+#    #+#             */
/*   Updated: 2020/02/23 19:19:33 by vserra           ###   ########.fr       */
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
	FLAGS = 0,
	WIDTH,
	PRECISION,
	TYPE,
	ERROR
}				t_mode;

//extern int (*g_tab[255])(void); //tableau pointeur sur fonction

typedef struct	s_info {
	char			mask;
	int				width_value;
	int				prec_value;
}				t_info;

typedef struct	s_data {
	unsigned char	*format;
	va_list			ap;
	t_info			info;
	t_mode			mode;
	int				nb_char;
}				t_data;

int		ft_printf(const char *str, ...);
void	parsing(t_data *data);
int		get_format(t_data *data);
void	*ft_memset(void *b, int c, size_t len);
void	print_flags(int value, int nb_char, int c);
void	print_zero_and_nb(t_data *data, int len, int nb);
void	width_and_prec(t_data *data, int len);

// tableau de tableau de pointeur de fonction
void	is_flag(t_data *data);
void	is_width(t_data *data);
void	get_width(t_data *data);
void	is_precision(t_data *data);
int		type_c(t_data *data);
int		type_d(t_data *data);
void	ft_putnbr(int nb);
int		ft_segfault();

// DEBUG
void	print_debug(char *str, t_data *data, int ctrl);
void	check_debug(t_data *data);

#endif
