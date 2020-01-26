/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 17:46:44 by vserra            #+#    #+#             */
/*   Updated: 2020/01/23 03:58:28 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** # define IS_MINUS		1 << 0 -> 1
** # define IS_ZERO			1 << 1 -> 2
** # define IS_WIDTH		1 << 2 -> 4
** # define IS_PRECISION	1 << 3 -> 8
** # define IS_POINT		1 << 4 -> 16
** # define IS_STAR			1 << 5 -> 32
*/

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>

# define IS_MINUS		1
# define IS_ZERO		2
# define IS_WIDTH		4
# define IS_PRECISION	8
// # define IS_POINT	16
// # define IS_STAR		32


extern int (*g_tab[255])(void); //tableau pointeur sur fonction

typedef struct	s_info {
	char	mask;
	int		width_value;
	int		prec_value;
}				t_info;

int				ft_printf(const char *str, ...);
void			parsing(const char *str, va_list ap);
void			get_arg(const char *str, va_list ap, t_info *info);
int				ft_n_atoi(const char *str, int i);
int		ft_is_minus(char *str, int i, t_info *info);
int		ft_is_zero(char *str, int i, t_info *info);
int		ft_get_width(char *str, int i, t_info *info);
int		ft_get_star_value(char *str, int i, va_list ap, t_info *info);
int		ft_is_precision(char *str, int i, va_list ap, t_info *info);

#endif
