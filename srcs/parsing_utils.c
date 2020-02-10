/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:48:36 by vserra            #+#    #+#             */
/*   Updated: 2020/02/10 18:28:10 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdint.h>
#include "ft_printf.h"

// data->info.mask |= IS_PRECISION; data->info.mask = (data->info.mask | IS_PRECISION);

void	is_flag(t_data *data)
{
	while (*data->format == '-' || *data->format == '0')
	{
		if (*data->format == '-')
		{
			data->info.mask |= IS_MINUS;
			data->format++;
		}
		if (*data->format == '0')
		{
			data->info.mask |= IS_ZERO;
			data->format++;
		}
	}
	// return (i);
}

int		ft_atoi_cancer(char **str) //get width
{
	int			len;
	long long	value;

	len = 0;
	value = 0;
	while ((*str)[len] >= '0' && (*str)[len] <= '9' && len < 11)
	{
		value = value * 10 + (*str)[len] - '0';
		len++;
	}
	*str += len;
	if (value > INT_MAX)
		// *str -= len - 1;
		value = -1;
	// else
		// *str++;
	return (value);
}

void	is_width(t_data *data)
{
	if ((data->info.width_value = ft_atoi_cancer(&data->format)) > -1)
	{
		data->info.mask |= IS_WIDTH;
		data->format++; // (1) a voir si ici ou dans le if
	}
	else // erreur : la width > INT_MAX
		data->info.width_value = 0;
}

void	get_width(t_data *data) // possibilite de faire une ft get_arg
{
	data->info.width_value = va_arg(data->ap, int);
	data->info.mask |= IS_WIDTH;
	data->format++; //(1) a voir si ici ou dans le if
}

// void	get_width(char **format, t_info *info)

// (1) ->	veut-on continuer a get_format si une width ou autre n'est pas correcte?
//			est-ce qu'on continue printf, gere-ton les autres formats ?

void	is_precision(t_data *data)
{
		data->format++;
		if(*data->format == '*')
		{
			// get_arg -> mettre la valeur dans data->info.prec_value
			data->info.width_value = va_arg(data->ap, int);
			data->info.mask |= IS_PRECISION;
			data->format++; // (1) a voir si ici ou dans le if
		}
		else if (*data->format >= '0' && *data->format <= '9')
		{
			//get_num /!\ le chiffre qui suit ne peut pas etre negatif (warning)
			if ((data->info.prec_value = ft_atoi_cancer(&data->format)) > -1)
				data->info.mask |= IS_PRECISION;
			else // erreur : la width > INT_MAX
				data->info.width_value = 0;
			data->format++; // (1) a voir si ici ou dans le if
		}
		else
			data->info.mask |= IS_POINT;
}

// anciennement "atoi cancer" ---->

// void	is_width(char **format, t_info *info) //get width
// {
// 	int			len;
// 	long long	width_value;

// 	len = 0;
// 	width_value = 0;
// 	while ((*format)[len] >= '0' && (*format)[len] <= '9' && len < 11)
// 	{
// 		width_value = width_value * 10 + (*format)[len] - '0';
// 		len++;
// 	}
// 	*format += len;
// 	data->info.mask = (data->info.mask | IS_WIDTH); // est-ce un doublon d'information ?
// 	if (width_value > INT_MAX)
// 		*format -= len - 1;
// 	else
// 		data->info.width_value = width_value;
// 		*format++;
// }