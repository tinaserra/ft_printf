/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:48:36 by vserra            #+#    #+#             */
/*   Updated: 2020/03/09 17:15:11 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** FLAGS '-' and '0' -> '0' ignored
*/

int			is_flag(t_data *data)
{
	print_debug("\n********* IS_FLAGS *********\n", data, 'S');
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
	if (data->info.mask == (IS_MINUS | IS_ZERO))
		data->info.mask ^= IS_ZERO;
	return (0);
}

static int	bb_atoi(unsigned char **str)
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

/*
** ATTENTION en cas de width > INT_MAX
*/

int			is_width(t_data *data)
{
	print_debug("\n********* IS_WIDTH *********\n", data, 'S');
	if ((data->info.w_value = bb_atoi(&data->format)) > -1)
		data->info.mask |= IS_WIDTH;
	else
		data->info.w_value = 0;
	return (0);
}

int			get_width(t_data *data)
{
	print_debug("\n********* GET_WIDTH *********\n", data, 'S');
	data->info.w_value = va_arg(data->ap, int);
	if (data->info.w_value == -2147483648)
	{
		data->nb_char = -1;
		return (-1);
	}
	if (data->info.w_value < 0)
	{
		data->info.w_value *= -1;
		data->info.mask |= IS_MINUS;
		if (data->info.mask == (IS_MINUS | IS_ZERO))
			data->info.mask ^= IS_ZERO;
	}
	data->info.mask |= IS_WIDTH;
	data->format++;
	return (0);
}

int			is_precision(t_data *data)
{
	print_debug("\n********* IS_PRECISION *********\n", data, 'S');
	data->format++;
	if (*data->format == '*')
	{
		data->info.p_value = va_arg(data->ap, int);
		if (data->info.p_value >= 0)
			data->info.mask |= IS_PRECISION;
		data->format++;
	}
	else if (*data->format >= '0' && *data->format <= '9')
	{
		if ((data->info.p_value = bb_atoi(&data->format)) >= 0)
			data->info.mask |= IS_PRECISION;
		else
			data->info.p_value = 0;
	}
	else
		data->info.mask |= IS_PRECISION;
	return (0);
}
