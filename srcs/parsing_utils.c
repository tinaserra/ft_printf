/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:48:36 by vserra            #+#    #+#             */
/*   Updated: 2020/02/21 17:01:39 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	is_flag(t_data *data)
{
	print_debug("\n********* IS_FLAGS *********\n", data, 'S');
	while (*data->format == '-' || *data->format == '0')
	{
		if (*data->format == '-')
		{
			data->info.mask |= IS_MINUS;
			print_debug("mask minus ->", data, 'M');
			data->format++;
		}
		if (*data->format == '0')
		{
			data->info.mask |= IS_ZERO;
			print_debug("mask zero ->", data, 'M');
			data->format++;
		}
	}
	// Si presence de '-' et '0' -> '0' ignoré
	if (data->info.mask == (IS_MINUS | IS_ZERO)) // 3 IS_MINUS | IS_ZERO
		data->info.mask ^= IS_ZERO; // XOR ou exclusif 1 ^ 1 = 0 
	print_debug("mask after is_flags ->", data, 'M');
}

int		ft_atoi_cancer(char **str)
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
		value = -1;
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
}

void	get_width(t_data *data)
{
	print_debug("\n********* GET_WIDTH *********\n", data, 'S');
	print_debug("width_value = 0 ? ->", data, 'W');
	data->info.width_value = va_arg(data->ap, int);
	if (data->info.width_value < 0)
	{
		print_debug("width_value negative ? ->", data, 'W');
		data->info.width_value *= -1;
		data->info.mask |= IS_MINUS;
	}
	data->info.mask |= IS_WIDTH;
	print_debug("width_value ->", data, 'W');
	print_debug("mask ->", data, 'M');
	data->format++;
}

void	is_precision(t_data *data)
{
		print_debug("\n********* IS_PRECISION *********\n",data, 'S');
		data->format++;
		if(*data->format == '*')
		{
			data->info.prec_value = va_arg(data->ap, int);
			if (data->info.prec_value < 1)
			{
				print_debug("prec_value negative ? ->", data, 'P');
				data->info.prec_value = 0; // PRECISION IGNORE
			}
			else
				data->info.mask |= IS_PRECISION;
			print_debug("*prec_value ->", data, 'P');
			print_debug("mask ->", data, 'M');
			data->format++; // (1) a voir si ici ou dans le if
		}
		else if (*data->format >= '0' && *data->format <= '9')
		{
			if ((data->info.prec_value = ft_atoi_cancer(&data->format)) > 0)
				data->info.mask |= IS_PRECISION;
			else // erreur : la width > INT_MAX
				data->info.prec_value = 0;
			print_debug("prec_value ->", data, 'P');
			print_debug("mask ->", data, 'M');
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