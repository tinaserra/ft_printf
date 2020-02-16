/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:48:36 by vserra            #+#    #+#             */
/*   Updated: 2020/02/15 17:39:43 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdint.h>
#include "ft_printf.h"

// data->info.mask |= IS_PRECISION; data->info.mask = (data->info.mask | IS_PRECISION);

void	is_flag(t_data *data)
{
	print_debug("\n********* IS_FLAGS *********\n", data, 'S');
	while (*data->format == '-' || *data->format == '0')
	{
		if (*data->format == '-')
		{
			data->info.mask |= IS_MINUS;
			print_debug("mask minus ->", data, 'M');
			// printf("mask minus -> %d\n", data->info.mask);
			data->format++;
		}
		if (*data->format == '0')
		{
			data->info.mask |= IS_ZERO;
			print_debug("mask zero ->", data, 'M');
			// printf("mask zero -> %d\n", data->info.mask);
			data->format++;
		}
	}
	// Si presence de '-' et '0' -> '0' ignoré
	if (data->info.mask == (IS_MINUS | IS_ZERO)) // 3 IS_MINUS | IS_ZERO
		data->info.mask ^= IS_ZERO; // XOR ou exclusif 1 ^ 1 = 0 
	print_debug("mask after is_flags ->", data, 'M');
	// printf("mask after is_flags -> %d\n", data->info.mask);
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
	print_debug("\n********* IS_WIDTH *********\n", data, 'S');
	if ((data->info.width_value = ft_atoi_cancer(&data->format)) > -1)
		data->info.mask |= IS_WIDTH;
	else // erreur : la width > INT_MAX
		data->info.width_value = 0;
	print_debug("width_value ->", data, 'W');
	print_debug("mask ->", data, 'M');
	// printf("width_value -> %d\n", data->info.width_value);
	// printf("mask -> %d\n", data->info.mask);
}

void	get_width(t_data *data) // possibilite de faire une ft get_arg
{
	print_debug("\n********* GET_WIDTH *********\n", data, 'S');
	data->info.width_value = va_arg(data->ap, int);
	data->info.mask |= IS_WIDTH;
	print_debug("width_value ->", data, 'W');
	print_debug("mask ->", data, 'M');
	data->format++; //(1) a voir si ici ou dans le if
}

// (1) ->	veut-on continuer a get_format si une width ou autre n'est pas correcte?
//			est-ce qu'on continue printf, gere-ton les autres formats ?

void	is_precision(t_data *data)
{
		print_debug("\n********* IS_PRECISION *********\n",data, 'S');
		data->format++;
		if(*data->format == '*')
		{
			// get_arg -> mettre la valeur dans data->info.prec_value
			data->info.prec_value = va_arg(data->ap, int);
			data->info.mask |= IS_PRECISION;
			print_debug("*prec_value ->", data, 'P');
			print_debug("mask ->", data, 'M');
			// printf("*prec_value -> %d\n", data->info.prec_value);
			// printf("mask -> %d\n", data->info.mask);
			data->format++; // (1) a voir si ici ou dans le if
		}
		else if (*data->format >= '0' && *data->format <= '9')
		{
			//get_num /!\ le chiffre qui suit ne peut pas etre negatif (warning)
			if ((data->info.prec_value = ft_atoi_cancer(&data->format)) > -1)
				data->info.mask |= IS_PRECISION;
			else // erreur : la width > INT_MAX
				data->info.prec_value = 0;
			print_debug("prec_value ->", data, 'P');
			print_debug("mask ->", data, 'M');
			// data->format++; // (1) a voir si ici ou dans le if
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