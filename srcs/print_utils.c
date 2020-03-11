/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:52:56 by vserra            #+#    #+#             */
/*   Updated: 2020/03/10 17:36:27 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_flags(t_data *data, int value, int ignored_char, int c)
{
	int	len;

	print_debug("\n********* PRINT_FLAGS *********\n", data, 'S');
	len = value - ignored_char;
	if (len > 0)
		data->nb_char += len;
	while (len >= 8192)
	{
		if (c == ' ')
			write(1, &(data->buff_space), 8192);
		if (c == '0')
			write(1, &(data->buff_zero), 8192);
		len -= 8192;
	}
	if (c == ' ')
		write(1, &(data->buff_space), len);
	if (c == '0')
		write(1, &(data->buff_zero), len);
}

void	print_prefix(t_data *data, long nb, int len, int c)
{
	if (nb < 0 && *data->format != 'p')
		write(1, "-", 1);
	if (*data->format == 'p')
	{
		write(1, "0x", 2);
		data->nb_char += 2;
	}
	if (c == 'P')
		print_flags(data, data->info.p_value, len, '0');
	if (c == 'W')
		print_flags(data, data->info.w_value, len, '0');
	if (nb < 0 && (*data->format == 'd' || *data->format == 'i'))
		write(1, &(data->buff_nb), len - 1);
	else
		write(1, &(data->buff_nb), len);
}
