/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:07:51 by vserra            #+#    #+#             */
/*   Updated: 2020/03/04 18:09:03 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		putnbr(long nb, t_data *data)
{
	long save;
	int len;
	long power;

	save = nb;
	len = 0;
	power = nb >= 0 ? 1 : -1;
	while (nb <= -10 || nb >= 10)
	{
		nb /= 10;
		power *= 10;
	}
	while (power)
	{
		data->buff_nb[len++] = save / power + '0';
		save = save - (save / power) * power;
		power /= 10;
	}
	if (nb < 0)
		len++;
	data->nb_char +=len;
	return (len);
}

int		putnbr_base(unsigned long nbr, char *base, t_data *data)
{
	unsigned long power;
	unsigned long save;
	int len;

	len = 0;
	save = nbr;
	power = 1;
	while (nbr >= 16)
	{
		nbr /= 16;
		power *= 16;
	}
	while (power)
	{
		data->buff_nb[len++] = base[save / power];
		save = save - (save / power) * power;
		power = power / 16;
	}
	if (nbr < 0)
		len++;
	data->nb_char += len;
	return (len);
}

void	specific(t_data *data)
{
	if (*data->format == 'p')
	{
		if(!(data->info.mask & IS_MINUS))
			print_flags(data, data->info.w_value, 0, ' ');
		write(1, "0x", 2);
		data->nb_char += 2;
		if(data->info.mask & IS_MINUS)
			print_flags(data, data->info.w_value, 0, ' ');
	}
	else
		print_flags(data, data->info.w_value, 0, ' ');
}

void	calc_precision(t_data *data, int len, long nb)
{
	print_debug("\n********* CALC_PRECISION *********\n", data, 'S');
	if (nb < 0)
		data->info.p_value++;
	if (nb == 0 && data->info.p_value == 0)
		specific(data);
	else if(data->info.mask & IS_WIDTH)
	{
		if(data->info.mask & IS_MINUS)
			print_prefix(data, nb, len, 'P');
		if (data->info.w_value > data->info.p_value)
		{
			if (data->info.p_value >= len)
				print_flags(data, data->info.w_value, data->info.p_value, ' ');
			else
				print_flags(data, data->info.w_value, len, ' ');
		}
		if (!(data->info.mask & IS_MINUS))
			print_prefix(data, nb, len, 'P');
	}
	else
		print_prefix(data, nb, len, 'P');
}


void	calc_width(t_data *data, size_t len, long nb)
{
	print_debug("\n********* CALC_WIDTH *********\n", data, 'S');
	if(data->info.mask & IS_MINUS)
	{
		print_debug("\nje suis dans minus de width\n", data, 'S');
		print_prefix(data, nb, len, 'N');
		print_flags(data, data->info.w_value, len, ' ');
	}
	else if(data->info.mask & IS_ZERO)
	{
		print_debug("\nje suis dans zero\n", data, 'S');
		print_prefix(data, nb, len, 'W');
	}
	else if(data->info.mask == IS_WIDTH)
	{
		print_debug("\nje suis la gros pd\n", data, 'S');
		print_flags(data, data->info.w_value, len, ' ');
		print_prefix(data, nb, len, 'N');

	}
}