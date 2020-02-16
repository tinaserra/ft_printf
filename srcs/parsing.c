/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 19:01:06 by vserra            #+#    #+#             */
/*   Updated: 2020/02/16 18:59:29 by vserra           ###   ########.fr       */
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
	// printf("\nreset info\n");
	data->info.mask = 0;
	data->info.width_value = 0;
	data->info.prec_value = 0;
}

#ifdef DEBUG
void	print_debug(char *str, t_data *data, int ctrl)
{
	if (ctrl == 'S')
		printf("%s\n", str);
	if (ctrl == 'F')
		printf("%s |%s|\n", str, data->format);
	if (ctrl == 'W')
		printf("%s %d\n", str, data->info.width_value);
	if (ctrl == 'P')
		printf("%s %d\n", str, data->info.prec_value);
	if (ctrl == 'M')
		printf("%s %d\n", str, data->info.mask);
}
#else
void	print_debug(char *str, t_data *data, int ctrl)
{
	(void)str;
	(void)data;
	(void)ctrl;
	return ;
}
#endif


int		get_format(t_data *data)
{
	print_debug("\n********* GET_FORMAT *********\n", data, 'S');
	print_debug("Format BEFORE", data, 'F');
	// printf("Format BEFOOOOORE	|%s|\n", data->format);
	reset_info(data);
	data->mode = FLAGS;
	g_parse[data->mode][*data->format](data);
	print_debug("AFTER FLAGS", data, 'F');
	// printf("AFTER FLAGS	|%s|\n", data->format);
	data->mode = WIDTH;
	g_parse[data->mode][*data->format](data);
	print_debug("AFTER WIDTH", data, 'F');
	// printf("AFTER WIDTH	|%s|\n", data->format);
	data->mode = PRECISION;
	g_parse[data->mode][*data->format](data);
	print_debug("AFTER PRECISION", data, 'F');
	// printf("AFTER PRECISION	|%s|\n", data->format);
	data->mode = TYPE;
	if(g_parse[data->mode][*data->format](data)) // != 0
	{
		print_debug("ERROR", data, 'F');
		return(-1); // UB -> se casser de print f
	}
	print_debug("\nAFTER TYPE", data, 'F');
	// printf("AFTER TYPE	|%s|\n", data->format);
	return (0);
}

void	parsing(t_data *data)
{
	int i;

	i = 0;
	// Parcourir et afficher str jusqu'a %
	while (data->format[i])
	{
		while(data->format[i] != '%' && data->format[i]) // /!\ si on est sur un '\0'
			i++;
		write(1, data->format, i);
		data->format += i;
		// Decouper et recuperer les infos du format
		if(*data->format == '%') //useless ?
		{
			data->format++;
			get_format(data); // verif si on est sur un '%'
		}
		return ;
		// i++;
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