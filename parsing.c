/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 20:10:25 by vserra            #+#    #+#             */
/*   Updated: 2020/01/10 20:20:40 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// toutes les fonctions de tab doivent avoir le meme prototype

// découper
// traiter et aficher
// reset info

void	get_arg(const char *str, va_list ap, t_info *info)
{
	int i;
	int nb_char;
	// char *temp;
	// t_info info;

	i = 0;
	nb_char = 0;

	// est-ce utile tout ca ?
	info->mask = 0;
	info->width_value = 0;
	info->prec_value = 0;
	while(str[i])
	{

		while (str[i] != '%') // compter le nombre de carateres affichés
		{
			write(1, str, i);
			i++;
			nb_char++;
		}

		while(str[i] != 'c' || str[i] != 's' || str[i] != 'p' || str[i] != 'd'
				|| str[i] != 'i' || str[i] != 'u' || str[i] != 'x'
				|| str[i] != 'X' || str[i] != '%')
		{
			i = ft_is_minus(str, i, &info);

			i = ft_is_zero(str, i, &info);

			// /!\ a bien differencier le flag 0 d'un 0 dans un nombre !

			i = ft_get_width(str, i, &info);

			i = ft_get_star_value(str, i, ap, &info);

			i = ft_is_precision(str, i, ap, info);
		}
		// i++;
	}

}

void	parsing(const char *str, va_list ap)
{
	int i;
	t_info info;

	// info = NULL;

	i = 0;
	// Parcourir et afficher str jusqu'a %
	get_arg(str, ap, &info);

	/* TEST */
	// return (i);

}
