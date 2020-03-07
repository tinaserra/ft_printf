/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:37:31 by vserra            #+#    #+#             */
/*   Updated: 2020/03/07 04:26:52 by vserra           ###   ########.fr       */
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
		[0 ... 44] = ft_segfault,
		['-'] = is_flag,
		[46 ... 47] = ft_segfault,
		['0'] = is_flag,
		[49 ... 255] = ft_segfault
	},
	[WIDTH] = {
		[0 ... 41] = ft_segfault,
		['*'] = get_width,
		[43 ... 47] = ft_segfault,
		['0' ... '9'] = is_width,
		[58 ... 255] = ft_segfault
	},
	[PRECISION] = {
		[0 ... 45] = ft_segfault,
		['.'] = is_precision,
		[47 ... 255] = ft_segfault
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
		[0 ... 36] = ft_segfault,
		['%'] = type_pourcent,
		[38 ... 87] = ft_segfault,
		['X'] = type_x,
		[89 ... 98] = ft_segfault,
		['c'] = type_c,
		['d'] = type_d,
		[101 ... 104] = ft_segfault,
		['i'] = type_d,
		[106 ... 111] = ft_segfault,
		['p'] = type_p,
		[113 ... 114] = ft_segfault,
		['s'] = type_s,
		[116] = ft_segfault,
		['u'] = type_u,
		[118 ... 119] = ft_segfault,
		['x'] = type_x,
		[121 ... 255] = ft_segfault
	},
};

#endif