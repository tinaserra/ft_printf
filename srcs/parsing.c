/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 19:01:06 by vserra            #+#    #+#             */
/*   Updated: 2020/03/09 00:43:03 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "parsing.h"

int			error(void)
{
	return (-1);
}

static void	reset_info(t_data *data)
{
	print_debug("\n********* RESET INFOS *********\n", data, 'S');
	data->info.mask = 0;
	data->info.w_value = 0;
	data->info.p_value = 0;
}

int			get_format(t_data *data)
{
	reset_info(data);
	print_debug("\n********* GET_FORMAT *********\n", data, 'S');
	print_debug("Format BEFORE", data, 'F');
	data->mode = FLAGS;
	g_parse[data->mode][*data->format](data);
	print_debug("AFTER FLAGS", data, 'F');
	data->mode = WIDTH;
	g_parse[data->mode][*data->format](data);
	print_debug("AFTER WIDTH", data, 'F');
	data->mode = PRECISION;
	g_parse[data->mode][*data->format](data);
	print_debug("AFTER PRECISION", data, 'F');
	data->mode = TYPE;
	if (g_parse[data->mode][*data->format](data))
	{
		print_debug("ERROR", data, 'F');
		data->nb_char = -1;
		return (-1);
	}
	print_debug("\nAFTER TYPE", data, 'F');
	return (0);
}

void		parsing(t_data *data)
{
	int i;

	data->nb_char = 0;
	while (*(data->format))
	{
		i = 0;
		while (data->format[i] != '%' && data->format[i])
			i++;
		data->nb_char += i;
		write(1, data->format, i);
		data->format += i;
		print_debug("\nnb_char =", data, 'N');
		if (*data->format == '%')
		{
			data->format++;
			if (get_format(data) == -1)
				return ;
		}
	}
}
