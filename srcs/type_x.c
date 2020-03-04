/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:52:55 by vserra            #+#    #+#             */
/*   Updated: 2020/03/04 13:57:58 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// '0' + width -> ajoute des zeros non significatifs jusqu'a atteindre la width
// '-' + width -> alligner resultat a gauche jusqu'a atteindre la width
// '.12' -> ajoute des zeros non significatifs jusqu'a atteindre la precision
// '.' -> on considere que p_value = 0

int		type_x(t_data *data)
{
	unsigned int nbr;
	int len;
	
	nbr = va_arg(data->ap, unsigned int);
	if (*data->format == 'x')
		len = putnbr_base(nbr, "0123456789abcdef", data);
	if (*data->format == 'X')
		len = putnbr_base(nbr, "0123456789ABCDEF", data);
	check_debug(data);
	print_debug("\n********* TYPE_X *********\n", data, 'S');
	print_debug("\nmask ->", data, 'M');
	if (data->info.mask & IS_PRECISION)
	{
		data->info.mask ^= IS_ZERO;
		calc_precision(data, len, nbr);
	}
	else if(data->info.mask & IS_WIDTH)
		calc_width(data, len, nbr);
	else
		write(1, &(data->buff_nb), len);
	data->format++;
	return (0);
}