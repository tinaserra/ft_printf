/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:17:49 by vserra            #+#    #+#             */
/*   Updated: 2020/02/12 17:58:29 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	type_c(t_data *data)
{
	char c;

	char buff[data->info.width_value - 1];

	c = va_arg(data->ap, char);
	// '0' -> Undefined behaviour
	if(data->info.mask == data->info.mask | IS_ZERO)
		printf("Flag 0 -> Undefine Behaviour");
	// '.12' -> Undefined behaviour
	if(data->info.mask == data->info.mask | IS_PRECISION)
		printf(".Precision -> Undefine Behaviour");
	// '.' -> Nothing to do
	if(data->info.mask == data->info.mask | IS_POINT)
		printf(".point -> RAS");
	if(data->info.mask == data->info.mask | IS_WIDTH)
	{
		if(data->info.mask == data->info.mask | IS_MINUS)
		{
			// '-' -> alligner resultat a gauche
			write(1, &c, 1);
			while(data->info.width_value - 1)
			{
				write(1, " ", 1);
			}
		}
		while(data->info.width_value - 1)
		{
			write(1, " ", 1);
		}
		write(1, &c, 1);
	}
	else
		write(1, &c, 1);
}