/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:17:49 by vserra            #+#    #+#             */
/*   Updated: 2020/02/25 18:54:15 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//'0' -> Undefined behaviour
// '.12' -> Undefined behaviour
// '.' -> Nothing to do
// '-' -> alligner resultat a gauche

int		type_c(t_data *data)
{
	char c;
	
	c = va_arg(data->ap, char);
	print_debug("\n********* TYPE_C *********\n", data, 'S');
	check_debug(data);
	print_debug("\nmask ->", data, 'M');
	if(data->info.mask & IS_WIDTH)
	{
		if(data->info.mask & IS_MINUS)
		{
			data->nb_char += 1;
			write(1, &c, 1);
		}
		print_flags(data, data->info.w_value, 1, ' ');
	}
	if (!(data->info.mask & IS_MINUS))
	{
		data->nb_char += 1;
		write(1, &c, 1);
	}
	data->format++;
	return (0);
}