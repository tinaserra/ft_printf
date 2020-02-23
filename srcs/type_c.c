/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:17:49 by vserra            #+#    #+#             */
/*   Updated: 2020/02/23 20:20:23 by vserra           ###   ########.fr       */
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
	if(data->info.mask & IS_WIDTH) // if(data->info.mask == (data->info.mask | IS_WIDTH))
	{
		if(data->info.mask & IS_MINUS)
			write(1, &c, 1);
		print_flags(data->info.width_value, 1, ' ');
	}
	else if (data->info.mask ^ IS_MINUS)
		write(1, &c, 1);
	data->format++;
	return (0);
}