/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 19:01:06 by vserra            #+#    #+#             */
/*   Updated: 2020/02/26 17:53:44 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "parsing.h"

// toutes les fonctions de tab doivent avoir le meme prototype

// découper
// traiter et aficher
// reset info

int		ft_segfault()
{
	return(-1);
}

void reset_info(t_data *data) //memset ou bzero
{
	print_debug("\n********* RESET INFOS *********\n", data, 'S');
	data->info.mask = 0;
	data->info.w_value = 0;
	data->info.p_value = 0;
}

int		get_format(t_data *data)
{
	reset_info(data);
	print_debug("\n********* GET_FORMAT *********\n", data, 'S');
	print_debug("Format BEFORE", data, 'F');
	data->mode = FLAGS;
	g_parse[data->mode][*data->format](data);
	print_debug("AFTER FLAGS", data, 'F');
	data->mode = WIDTH;
	g_parse[data->mode][*data->format](data);
	print_debug("AFTER WIDTH", data, 'F');
	data->mode = PRECISION;
	g_parse[data->mode][*data->format](data);
	print_debug("AFTER PRECISION", data, 'F');
	data->mode = TYPE;
	if(g_parse[data->mode][*data->format](data)) // != 0
	{
		print_debug("ERROR", data, 'F');
		return(-1); // UB -> se casser de print f
	}
	print_debug("\nAFTER TYPE", data, 'F');
	return (0);
}

void	parsing(t_data *data)
{
	int i;

	// Parcourir et afficher str jusqu'a %
	data->nb_char = 0;
	while (*(data->format))
	{
		i = 0;
		while(data->format[i] != '%' && data->format[i])
			i++;
		data->nb_char += i;
		// printf("%d")
		write(1, data->format, i);
		data->format += i;
		print_debug("\nnb_char =", data, 'N');
		// Decouper et recuperer les infos du format
		if(*data->format == '%') //useless ?
		{
			data->format++;
			get_format(data); // verif si on est sur un '%'
		}
		// return ;
	}
	/* TEST */
	// return (i);
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