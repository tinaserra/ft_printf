/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:21:11 by vserra            #+#    #+#             */
/*   Updated: 2020/03/09 17:20:24 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** GENERAL RULES FOR %d | %i | %u | %x | %X | %p
**
** width		-> Add ' ' until reaching the width value
** '0' + width	-> Add '0' until reaching the width value
** '-' + width	-> Allign the result to the left then add ' '
** '.num'		-> Add '0' until reaching the precision value
** '.'			-> precison value = 0
*/

/*
** check_debug(data);
** print_debug("\n********* TYPE_D *********\n", data, 'S');
** debug_int("len = ", len);
** print_debug("\nnb_char =", data, 'N');
*/

int			type_d(t_data *data)
{
	int	nb;
	int	len;

	nb = va_arg(data->ap, int);
	len = putnbr(nb, data);
	if (data->info.mask & IS_PRECISION)
	{
		data->info.mask ^= IS_ZERO;
		calc_precision(data, len, nb);
	}
	else if (data->info.mask & IS_WIDTH)
		calc_width(data, len, nb);
	else
	{
		if (nb < 0)
			write(1, "-", 1);
		write(1, &(data->buff_nb), len);
	}
	data->format++;
	return (0);
}
