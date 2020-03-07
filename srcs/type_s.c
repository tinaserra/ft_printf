/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 02:13:08 by vserra            #+#    #+#             */
/*   Updated: 2020/03/07 05:47:57 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return(len);
}

void	cut_string(t_data *data, int len, char *s)
{
	print_debug("\n********* CUT_STRING *********\n", data, 'S');
	if (data->info.mask & IS_WIDTH)
	{
		if(data->info.mask & IS_MINUS)
		{
			data->nb_char += len;
			write(1, s, len);
		}
		if (data->info.mask & IS_ZERO)
			print_flags(data, data->info.w_value, len, '0');
		else
			print_flags(data, data->info.w_value, len, ' ');
		if (!(data->info.mask & IS_MINUS))
		{
			data->nb_char += len;
			write(1, s, len);
		}
	}
	else
	{
		data->nb_char += len;
		write(1, s, len);
	}
}

// printf("\nstr = %s\n", s);
// printf("len = %d\n", len);
// data->info.mask ^= IS_ZERO;
int		type_s(t_data *data)
{
	char	*s;
	int		len;
	
	s = va_arg(data->ap, char*);
	if (s != NULL)
		len = ft_strlen(s);
	check_debug(data);
	print_debug("\n********* TYPE_S *********\n", data, 'S');
	if (s == NULL)
	{
		s = "(null)";
		len = 6;
	}
	if (data->info.mask & IS_ZERO && (data->info.p_value > 1 || data->info.w_value > 1))
		data->info.mask ^= IS_ZERO;
	if (data->info.mask & IS_PRECISION)
	{
		print_debug("Je suis dans precision", data, 'S');
		if (len > data->info.p_value)
			cut_string(data, data->info.p_value, s);
		else
			cut_string(data, len, s);
	}
	else if(data->info.mask & IS_WIDTH)
	{
		print_debug("Je suis dans width", data, 'S');
		cut_string(data, len, s);
	}
	else
	{
		print_debug("Pas de width ou de precision", data, 'S');
		data->nb_char += len;
		write(1, s, len);
	}
	data->format++;
	return (0);
}