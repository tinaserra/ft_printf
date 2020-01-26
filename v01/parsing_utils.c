/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:48:36 by vserra            #+#    #+#             */
/*   Updated: 2020/01/26 01:52:20 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_printf.h"

void	is_flag(char **format, t_info *info)
{
	while (**format == '-' || **format == '0')
	{
		if (**format == '-')
		{
			info->mask = (info->mask | IS_MINUS);
			*format++;
		}
		if (**format == '0')
		{
			info->mask = (info->mask | IS_ZERO);
			*format++;
		}
	}
	// return (i);
}

void	is_width(char **format, t_info *info) //get width
{
	int			len;
	long long	width_value;

	len = 0;
	width_value = 0;
	while ((*format)[len] >= '0' && (*format)[len] <= '9' && len < 11)
	{
		width_value = width_value * 10 + (*format)[len] - '0';
		len++;
	}
	*format += len;
	info->mask = (info->mask | IS_WIDTH); // est-ce un doublon d'information ?
	if (width_value > INT_MAX)
		*format -= len - 1;
	else
		info->width_value = width_value;
}

void	get_width(char **format, t_info *info) // possibilite de faire une ft get_arg
{
	char *temp;
	if (**format == '*' && (**format) - 1 != '.')
	{
		temp = va_arg(ap, temp)
		ft_atoi(temp);
		info->mask = (info->mask | IS_WIDTH);
	}
	if (**format == '*' && (**format) - 1 == '.')
	{
		temp = va_arg(ap, temp)
		ft_atoi(temp);
		info->mask = (info->mask | IS_PRECISION);
	}
}