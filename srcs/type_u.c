/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:41:51 by vserra            #+#    #+#             */
/*   Updated: 2020/02/29 16:36:30 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			type_u(t_data *data)
{
	unsigned int nb;
	int len;
	
	nb = va_arg(data->ap, unsigned int);
	len = nb_len(nb);
	check_debug(data);
	print_debug("\n********* TYPE_D *********\n", data, 'S');
	print_debug("\nmask ->", data, 'M');
	// if(data->info.mask == IS_WIDTH)
	// {
	// 	print_flags(data, data->info.w_value, len, ' ');
	// 	write_nbr(nb, data);
	// }
	if (data->info.mask & IS_PRECISION) // Utile ?
		data->info.mask ^= IS_ZERO;
	if (data->info.mask & IS_PRECISION)
		calc_precision(data, len, nb);
	else if(data->info.mask & IS_WIDTH)
		calc_width(data, len, nb);
	// else if (data->info.mask == IS_POINT && nb == 0) //|| (data->info.p_value == 0 && nb == 0))
	// {
	// 	data->format++;
	// 	return(0);
	// }
	else // si pas width et pas precision et pas (point et nb == 0)
		write_nbr(nb, data);
	data->format++;
	return (0);
}