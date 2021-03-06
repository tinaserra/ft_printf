/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:41:51 by vserra            #+#    #+#             */
/*   Updated: 2020/03/09 01:20:43 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		type_u(t_data *data)
{
	unsigned int	nb;
	int				len;

	nb = va_arg(data->ap, unsigned int);
	len = putnbr(nb, data);
	check_debug(data);
	print_debug("\n********* TYPE_D *********\n", data, 'S');
	if (data->info.mask & IS_PRECISION)
	{
		data->info.mask ^= IS_ZERO;
		calc_precision(data, len, nb);
	}
	else if (data->info.mask & IS_WIDTH)
		calc_width(data, len, nb);
	else
		write(1, &(data->buff_nb), len);
	data->format++;
	return (0);
}
