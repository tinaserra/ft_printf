/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:17:49 by vserra            #+#    #+#             */
/*   Updated: 2020/03/09 17:18:40 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Flag ZERO and precision -> Undifined behaviour
*/

/*
**	check_debug(data);
**	print_debug("\n********* TYPE_C *********\n", data, 'S');
**	print_debug("\nnb_char =", data, 'N');
*/

int		type_c(t_data *data)
{
	char	c;

	c = (char)va_arg(data->ap, int);
	if (data->info.mask < IS_WIDTH)
		data->info.mask = 0;
	if (data->info.mask & IS_WIDTH)
	{
		if (data->info.mask & IS_MINUS)
		{
			data->nb_char += 1;
			write(1, &c, 1);
		}
		if (data->info.mask & IS_ZERO)
			print_flags(data, data->info.w_value, 1, '0');
		else
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
