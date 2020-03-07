/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_pourcent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 04:08:07 by vserra            #+#    #+#             */
/*   Updated: 2020/03/07 06:11:51 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pourcent(t_data *data)
{
	print_debug("\n********* print_pourcent *********\n", data, 'S');
	if (data->info.mask & IS_WIDTH)
	{
		if(data->info.mask & IS_MINUS)
		{
			data->nb_char += 1;
			write(1, "%", 1);
		}
		if (data->info.mask & IS_ZERO)
		// {
		// 	if (data->info.p_value == 0)
		// 		data->info.mask ^= IS_ZERO;
		// }
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

int		type_pourcent(t_data *data)
{
	check_debug(data);
	print_debug("\n********* TYPE_S *********\n", data, 'S');
	// if (data->info.mask & IS_ZERO && (data->info.p_value > 1 || data->info.w_value > 1))
	// 	data->info.mask ^= IS_ZERO;
	// printf("width = %d\n", data->info.w_value);
	if (data->info.mask & IS_PRECISION)
	{
		print_debug("Je suis dans precision", data, 'S');
		print_pourcent(data);
	}
	else if(data->info.mask & IS_WIDTH)
	{
		print_debug("Je suis dans width", data, 'S');
		print_pourcent(data);
	}
	else
	{
		print_debug("Pas de width ou de precision", data, 'S');
		data->nb_char += 1;
		write(1, "%", 1);
	}
	data->format++;
	return (0);
}