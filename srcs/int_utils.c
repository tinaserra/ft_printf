/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:07:51 by vserra            #+#    #+#             */
/*   Updated: 2020/03/09 17:12:23 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			putnbr(long nb, t_data *data)
{
	int		len;
	long	save;
	long	power;

	len = 0;
	save = nb;
	power = nb >= 0 ? 1 : -1;
	print_debug("\n********* PUTNBR *********\n", data, 'S');
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
	data->nb_char += len;
	return (len);
}

int			putnbr_base(unsigned long nbr, char *base, t_data *data)
{
	int				len;
	unsigned long	power;
	unsigned long	save;

	len = 0;
	save = nbr;
	power = 1;
	print_debug("\n********* PUTNBR_BASE *********\n", data, 'S');
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

static void	specific(t_data *data)
{
	print_debug("\n********* SPECIFIC *********\n", data, 'S');
	if (*data->format == 'p')
	{
		if (!(data->info.mask & IS_MINUS))
			print_flags(data, data->info.w_value, 0, ' ');
		write(1, "0x", 2);
		data->nb_char += 2;
		if (data->info.mask & IS_MINUS)
			print_flags(data, data->info.w_value, 0, ' ');
	}
	else
		print_flags(data, data->info.w_value, 0, ' ');
	data->nb_char -= 1;
}

void		calc_precision(t_data *data, int len, long nb)
{
	print_debug("\n********* CALC_PRECISION *********\n", data, 'S');
	debug_int("len = ", len);
	print_debug("\nnb_char =", data, 'N');
	if (nb < 0)
		data->info.p_value++;
	if (nb == 0 && data->info.p_value == 0)
		specific(data);
	else if (data->info.mask & IS_WIDTH)
	{
		if (data->info.mask & IS_MINUS)
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

void		calc_width(t_data *data, size_t len, long nb)
{
	print_debug("\n********* CALC_WIDTH *********\n", data, 'S');
	if (data->info.mask & IS_MINUS)
	{
		print_prefix(data, nb, len, 'N');
		print_flags(data, data->info.w_value, len, ' ');
	}
	else if (data->info.mask & IS_ZERO)
		print_prefix(data, nb, len, 'W');
	else if (data->info.mask == IS_WIDTH)
	{
		print_flags(data, data->info.w_value, len, ' ');
		print_prefix(data, nb, len, 'N');
	}
}
