/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:17:49 by vserra            #+#    #+#             */
/*   Updated: 2020/02/16 18:58:15 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#ifdef DEBUG
void	 check_debug(t_data *data)
{
	if(data->info.mask & IS_ZERO)
		printf("Flag ZERO -> Undefine Behaviour\n");
	if(data->info.mask & IS_MINUS)
		printf("Flag MINUS\n");
	if(data->info.mask & IS_WIDTH)
		printf("Présence width\n");
	if(data->info.mask & IS_POINT)
		printf(".point -> Nothing to do\n");
	if(data->info.mask & IS_PRECISION)
		printf(".Precision -> Undefine Behaviour\n");
}
#else
void	 check_debug(t_data *data)
{
	(void)data;
	return ;
}
#endif

//'0' -> Undefined behaviour
// '.12' -> Undefined behaviour
// '.' -> Nothing to do
int		type_c(t_data *data)
{
	char c;

	// char buff[data->info.width_value - 1];
	c = va_arg(data->ap, char);

	print_debug("\n********* TYPE_C *********\n", data, 'S');
	check_debug(data);
	print_debug("\nmask ->", data, 'M');
	if(data->info.mask & IS_WIDTH) // if(data->info.mask == data->info.mask | IS_WIDTH)
	{
		if(data->info.mask & IS_MINUS) // if(data->info.mask == data->info.mask | IS_MINUS)
		{
			// '-' -> alligner resultat a gauche
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
	}
	else
		write(1, &c, 1);
	// incrementer format
	return (0);
}