/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 02:13:08 by vserra            #+#    #+#             */
/*   Updated: 2020/03/09 17:21:58 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static void	print_string(t_data *data, char *s, int len)
{
	data->nb_char += len;
	write(1, s, len);
}

static void	cut_string(t_data *data, int len, char *s)
{
	if (data->info.mask & IS_WIDTH)
	{
		if (data->info.mask & IS_MINUS)
			print_string(data, s, len);
		if (data->info.mask & IS_ZERO)
			print_flags(data, data->info.w_value, len, '0');
		else
			print_flags(data, data->info.w_value, len, ' ');
		if (!(data->info.mask & IS_MINUS))
			print_string(data, s, len);
	}
	else
		print_string(data, s, len);
}

int			type_s(t_data *data)
{
	char	*s;
	int		len;

	s = va_arg(data->ap, char*);
	if (s != NULL)
		len = ft_strlen(s);
	if (s == NULL)
	{
		s = "(null)";
		len = 6;
	}
	if (data->info.mask & IS_PRECISION)
	{
		if (len > data->info.p_value)
			cut_string(data, data->info.p_value, s);
		else
			cut_string(data, len, s);
	}
	else if (data->info.mask & IS_WIDTH)
		cut_string(data, len, s);
	else
		print_string(data, s, len);
	data->format++;
	return (0);
}
