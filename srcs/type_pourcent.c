/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_pourcent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 04:08:07 by vserra            #+#    #+#             */
/*   Updated: 2020/03/09 01:21:14 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_pourcent(t_data *data)
{
	print_debug("\n********* print_pourcent *********\n", data, 'S');
	if (data->info.mask & IS_WIDTH)
	{
		if (data->info.mask & IS_MINUS)
		{
			data->nb_char += 1;
			write(1, "%", 1);
		}
		if (data->info.mask & IS_ZERO)
			print_flags(data, data->info.w_value, 1, '0');
		else
			print_flags(data, data->info.w_value, 1, ' ');
		if (!(data->info.mask & IS_MINUS))
		{
			data->nb_char += 1;
			write(1, "%", 1);
		}
	}
	else
	{
		data->nb_char += 1;
		write(1, "%", 1);
	}
}

int			type_pourcent(t_data *data)
{
	check_debug(data);
	print_debug("\n********* TYPE_S *********\n", data, 'S');
	if (data->info.mask & IS_PRECISION)
		print_pourcent(data);
	else if (data->info.mask & IS_WIDTH)
		print_pourcent(data);
	else
	{
		data->nb_char += 1;
		write(1, "%", 1);
	}
	data->format++;
	return (0);
}
