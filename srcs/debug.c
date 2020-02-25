/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:22:41 by vserra            #+#    #+#             */
/*   Updated: 2020/02/24 17:06:25 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#ifdef DEBUG
void	 check_debug(t_data *data)
{
	printf("\n********* CHECK_DEBUG *********\n");
	if(data->info.mask & IS_ZERO)
		printf("Flag ZERO\n");
	if(data->info.mask & IS_MINUS)
		printf("Flag MINUS\n");
	if(data->info.mask & IS_WIDTH)
		printf("width\n");
	if(data->info.mask & IS_POINT)
		printf(".point\n");
	if(data->info.mask & IS_PRECISION)
		printf(".Precision\n");
}
#else
void	 check_debug(t_data *data)
{
	(void)data;
	return ;
}
#endif

#ifdef DEBUG
void	print_debug(char *str, t_data *data, int ctrl)
{
	if (ctrl == 'S')
		printf("%s\n", str);
	if (ctrl == 'F')
		printf("%s |%s|\n", str, data->format);
	if (ctrl == 'W')
		printf("%s %d\n", str, data->info.width_value);
	if (ctrl == 'P')
		printf("%s %d\n", str, data->info.prec_value);
	if (ctrl == 'M')
		printf("%s %d\n", str, data->info.mask);
}
#else
void	print_debug(char *str, t_data *data, int ctrl)
{
	(void)str;
	(void)data;
	(void)ctrl;
	return ;
}
#endif