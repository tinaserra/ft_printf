/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:21:11 by vserra            #+#    #+#             */
/*   Updated: 2020/02/29 17:39:40 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// '0' + width -> ajoute des zeros non significatifs jusqu'a atteindre la width
// '-' + width -> alligner resultat a gauche jusqu'a atteindre la width
// '.12' -> ajoute des zeros non significatifs jusqu'a atteindre la precision
// '.' -> on considere que p_value = 0

int			type_d(t_data *data)
{
	int nb;
	int len;
	
	nb = va_arg(data->ap, int);
	len = nb_len(nb);
	check_debug(data);
	print_debug("\n********* TYPE_D *********\n", data, 'S');
	print_debug("\nmask ->", data, 'M');
	if (data->info.mask & IS_PRECISION)
	{
		data->info.mask ^= IS_ZERO;
		calc_precision(data, len, nb);
	}
	else if(data->info.mask & IS_WIDTH)
		calc_width(data, len, nb);
	else
	{
		if (nb < 0)
			write(1, "-", 1);
		write_nbr(nb, data);
	}
	data->format++;
	return (0);
}
