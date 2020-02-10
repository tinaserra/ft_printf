/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:42:50 by vserra            #+#    #+#             */
/*   Updated: 2020/02/10 17:58:23 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// toutes les fonctions de tab doivent avoir le meme prototype
// extern dans ft_printf.h
// extern -> pour rendre la globale accessible dans tous les fichiers

// int (*g_tab[256])(void) =
// {
// 	[0 ... '$']		=	ft_error,\
// 	'%'				=	ft_hvbhfbv,\
// 	['&' ... 'W']	=	ft_error,\
// 	'X'				=	ft_hvbhfbv,\
// 	['Y' ... 'b']	=	ft_error,\
// 	'c'				=	ft_hvbhfbv,\
// 	'd'				=	ft_njnjn,\
// 	['e' ... 'h']	=	ft_error,\
// 	'i'				=	ft_hvbhfbv,\
// 	['j' ... 'o']	=	ft_error,\
// 	'p'				=	ft_hvbhfbv,\
// 	['q' ... 'r']	=	ft_error,\
// 	's'				=	ft_hvbhfbv,\
// 	't'				=	ft_error,\
// 	'u'				=	ft_hvbhfbv,\
// 	['v' ... 'w']	=	ft_error,\
// 	'x'				=	ft_hvbhfbv,\
// 	['y' ... 127]	=	ft_error
// };

int		ft_printf(const char *str, ...)
{
	t_data data;

	data.format = (unsigned char *)str;

	// int nb; // nombre de char ecrit par printf

	va_start(data.ap, str);
	// nb = 0;
	/*nb = */parsing(&data);
	va_end(data.ap);
	// return (nb);
}