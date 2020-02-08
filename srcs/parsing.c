/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 19:01:06 by vserra            #+#    #+#             */
/*   Updated: 2020/02/06 22:59:44 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// toutes les fonctions de tab doivent avoir le meme prototype

// découper
// traiter et aficher
// reset info

//renommer get_arg (pas de sens)

// faire une fonction pour initialiser ma structure a 0
	// info->mask = 0;
	// info->width_value = 0;
	// info->prec_value = 0;

void reset_info(t_info *info) //memset ou bzero
{
	if (info != NULL)
	{
		info->mask = 0;
		info->width_value = 0;
		info->prec_value = 0;
	}
	// return (info);
}

void	get_format(char **format, va_list ap, t_info *info)
{
	reset_info(info); // OK?
	if (**format == '0' || **format == '-')
		is_flags(format, info);
	if (**format >= '0' && **format <= '9')
		is_width(format, info); //Ne rien afficher en cas de width > int max
	if (**format == '*')
		get_width(format, info);
	if (**format == '.') // si oui -> check si un nombre ou une etoile apres .
		is_precision(format, info);
	if (**format == 'c' || **format == 's' || **format == 'p'
		|| **format == 'd' || **format == 'i' || **format == 'u'
		|| **format == 'x' || **format == 'X' || **format == '%') // type cspdiuxX%
		get_type(format, info);
}

void	parsing(char **format, va_list ap)
{
	int i;
	t_info info;

	i = 0;
	// Parcourir et afficher str jusqu'a %
	while (*format[i])
	{
		while (*format[i] != '%' && *format[i]) // /!\ si on est sur un '\0'
			i++;
		write(1, *format, i);
		i++;
		*format += i;
		// Decouper et recuperer les infos du format
		if(*format[i]) //useless ?
			get_format(format, ap, &info); // verif si on est sur un '%'
		// i++;
	}
	/* TEST */
	// return (i);
}
