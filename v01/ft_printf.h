/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 17:46:44 by vserra            #+#    #+#             */
/*   Updated: 2020/01/25 18:17:53 by vserra           ###   ########.fr       */
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
# include 

# define IS_MINUS		1
# define IS_ZERO		2
# define IS_WIDTH		4
# define IS_PRECISION	8
// # define IS_POINT	16
// # define IS_STAR		32


//extern int (*g_tab[255])(void); //tableau pointeur sur fonction

typedef struct	s_info {
	char	mask;
	int		width_value;
	int		prec_value;
}				t_info;

int		ft_printf(const char *format, ...);
void	parsing(const char *format, va_list ap);
void	get_format(char *format, va_list ap, t_info *info);

#endif
