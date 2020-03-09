/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:52:31 by vserra            #+#    #+#             */
/*   Updated: 2020/03/09 01:00:21 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		type_p(t_data *data)
{
	long	addr;
	int		len;

	addr = (long)va_arg(data->ap, void*);
	len = putnbr_base(addr, "0123456789abcdef", data);
	data->info.w_value -= 2;
	check_debug(data);
	print_debug("\n********* TYPE_P *********\n", data, 'S');
	if (data->info.mask & IS_PRECISION)
	{
		data->info.mask ^= IS_ZERO;
		calc_precision(data, len, addr);
	}
	else if (data->info.mask & IS_WIDTH)
		calc_width(data, len, addr);
	else
	{
		write(1, "0x", 2);
		data->nb_char += 2;
		write(1, &(data->buff_nb), len);
	}
	data->format++;
	return (0);
}
