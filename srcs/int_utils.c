/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:07:51 by vserra            #+#    #+#             */
/*   Updated: 2020/02/29 18:22:47 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nb_len(long nb)
{
	int len;

	len = 1;
	if (nb < 0)
		len = 2;
	while(nb <= -10 || nb >= 10)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

void	write_nbr(long nb, t_data *data)
{
	char buffer[11];
	long save;
	int i;
	int power;

	i = 0;
	save = nb;
	power = nb >= 0 ? 1 : -1;
	while (nb <= -10 || nb >= 10)
	{
		nb /= 10;
		power *= 10;
	}
	while (power)
	{
		buffer[i++] = save / power + '0';
		save = save - (save / power) * power;
		power /= 10;
	}
	data->nb_char +=i;
	write(1, &buffer, i);
}

void	print_prec(t_data *data, long nb, int len, int c)
{
	if (nb < 0)
		write(1, "-", 1);
	if (c = '0')
		print_flags(data, data->info.p_value, len, '0');
	write_nbr(nb, data);
}

void	calc_precision(t_data *data, int len, long nb)
{
	print_debug("\n********* CALC_PRECISION *********\n", data, 'S');
	if (nb < 0)
		data->info.p_value++;
	if (nb == 0) //&& data->info.p_value != 0)
		print_flags(data, data->info.w_value, 0, ' ');
	else if(data->info.mask & IS_WIDTH)
	{
		if(data->info.mask & IS_MINUS)
			print_prec(data, nb, len, '0');
		if (data->info.w_value > data->info.p_value)
		{
			if (data->info.p_value > len)
				print_flags(data, data->info.w_value, data->info.p_value, ' ');
			else if (data->info.p_value < len)
				print_flags(data, data->info.w_value, len, ' ');
		}
		if (!(data->info.mask & IS_MINUS))
			print_prec(data, nb, len, '0');
	}
	else if (nb != 0)
		print_prec(data, nb, len, '0');
}

void	calc_width(t_data *data, size_t len, long nb)
{
	print_debug("\n********* CALC_WIDTH *********\n", data, 'S');
	if(data->info.mask & IS_MINUS)
	{
		print_debug("\nje suis dans minus de width\n", data, 'S');
		if (nb < 0)
			write(1, "-", 1);
		write_nbr(nb, data);
		print_flags(data, data->info.w_value, len, ' ');
	}
	else if(data->info.mask & IS_ZERO)
	{
		print_debug("\nje suis dans zero\n", data, 'S');
		if (nb < 0)
			write(1, "-", 1);
		print_flags(data, data->info.w_value, len, '0');
		write_nbr(nb, data);
	}
	else if(data->info.mask == IS_WIDTH)
	{
		print_flags(data, data->info.w_value, len, ' ');
		if (nb < 0)
			write(1, "-", 1);
		write_nbr(nb, data);
	}
}