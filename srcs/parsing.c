/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 19:01:06 by vserra            #+#    #+#             */
/*   Updated: 2020/02/10 19:54:29 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
# include "parsing.h"


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

// void	get_format(t_data *data)
// {
// 	reset_info(data->info); // OK?
// 	if (*data->format == '0' || *data->format == '-')
// 		is_flag(data);
// 	if (*data->format >= '0' && *data->format <= '9')
// 		is_width(data); //Ne rien afficher en cas de width > int max
// 	else if (*data->format == '*') // pas correct si les deux
// 		get_width(data);
// 	if (*data->format == '.') // si oui -> check si un nombre ou une etoile apres .
// 		is_precision(data);
// 	// if (*data->format == 'c' || *data->format == 's' || *data->format == 'p'
// 	// 	|| *data->format == 'd' || *data->format == 'i' || *data->format == 'u'
// 	// 	|| *data->format == 'x' || *data->format == 'X' || *data->format == '%') // type cspdiuxX%
// 	// 	get_type(data);
// }
int		ft_segfault()
{
	return(-1);
}

int		get_format(t_data *data)
{
	data->mode = FLAGS;
	g_parse[data->mode][*data->format](data);
	data->mode = WIDTH;
	g_parse[data->mode][*data->format](data);
	data->mode = PRECISION;
	g_parse[data->mode][*data->format](data);
	data->mode = TYPE;
	if(g_parse[data->mode][*data->format](data)) // != 0
		return(-1); // UB -> se casser de print f
	return (0);
}

void	parsing(t_data *data)
{
	int i;
	// t_info info;

	i = 0;
	// Parcourir et afficher str jusqu'a %
	while (data->format[i])
	{
		while (data->format[i] != '%' && data->format[i]) // /!\ si on est sur un '\0'
			i++;
		write(1, data->format, i);
		i++;
		data->format += i;
		// Decouper et recuperer les infos du format
		if(data->format[i]) //useless ?
			get_format(data); // verif si on est sur un '%'
		// i++;
	}
	/* TEST */
	// return (i);
}
