/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:37:31 by vserra            #+#    #+#             */
/*   Updated: 2020/02/19 17:03:57 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

// toutes les fonctions de tab doivent avoir le meme prototype
// extern dans ft_printf.h
// extern -> pour rendre la globale accessible dans tous les fichiers

int (*g_parse[ERROR][256])() =
{
	[FLAGS] = {
		[0 ... 255] = ft_segfault,
		['0'] = is_flag,
		['-'] = is_flag
	},
	[WIDTH] = {
		[0 ... 255] = ft_segfault,
		['0' ... '9'] = is_width,
		['*'] = get_width
	},
	[PRECISION] = {
		[0 ... 255] = ft_segfault,
		['.'] = is_precision
	},
	// [TYPE] = {
		// [0 ... 255] = ft_segfault,
		// ['X'] = type_X,
		// ['c'] = type_c,
		// ['d'] = type_d,
		// ['i'] = type_d,
		// ['p'] = type_p,
		// ['s'] = type_s,
		// ['u'] = type_u,
		// ['x'] = type_x,
		// ['%'] = type_pourcent
	// }
	[TYPE] = {
		[0 ... 255] = ft_segfault,
		['c'] = type_c,
		['d'] = type_d
	},
};

#endif