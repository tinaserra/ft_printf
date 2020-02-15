/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:17:49 by vserra            #+#    #+#             */
/*   Updated: 2020/02/15 17:27:32 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		type_c(t_data *data)
{
	char c;

	// char buff[data->info.width_value - 1];
	c = va_arg(data->ap, char);

	printf("\n********* TYPE_C *********\n");

	printf("\nmask -> %d\n", data->info.mask);
	//'0' -> Undefined behaviour
	if(data->info.mask & IS_ZERO)
		printf("Flag 0 -> Undefine Behaviour\n");
	if(data->info.mask & IS_MINUS)
		printf("Flag minus\n");
	// '.12' -> Undefined behaviour
	if(data->info.mask & IS_PRECISION) // if(data->info.mask == data->info.mask | IS_PRECISION)
		printf(".Precision -> Undefine Behaviour\n");
	// '.' -> Nothing to do
	if(data->info.mask & IS_POINT) // if(data->info.mask == data->info.mask | IS_POINT)
		printf(".point -> RAS\n");
	if(data->info.mask & IS_WIDTH) // if(data->info.mask == data->info.mask | IS_WIDTH)
	{
		// printf("width -> %d\n", data->info.width_value);
		if(data->info.mask & IS_MINUS) // if(data->info.mask == data->info.mask | IS_MINUS)
		{
			// '-' -> alligner resultat a gauche
			// printf("Flag minus -> alligner a gauche le res\n");
			write(1, &c, 1);
			while (data->info.width_value - 1)
			{
				write(1, " ", 1);
				data->info.width_value -= 1;

			}
		}
		else
		{
			while(data->info.width_value - 1)
			{
				write(1, " ", 1);
				data->info.width_value -= 1;
			}
			write(1, &c, 1);
		}
		// printf("width_value : %d\n", data->info.width_value);
	}
	else
		write(1, &c, 1);
	return (0);
}