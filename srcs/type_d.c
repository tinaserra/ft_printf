/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:21:11 by vserra            #+#    #+#             */
/*   Updated: 2020/02/25 18:26:12 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// '0' + width -> ajoute des zeros non significatifs jusqu'a atteindre la width
// '-' + width -> alligner resultat a gauche jusqu'a atteindre la width
// '.12' -> 
// '.' -> 

void	ft_putnbr(int nb, t_data *data)
{
	char buffer[11];
	int i;
	int save;
	int power;

	i = 0;
	save = nb;
	power = nb >= 0 ? 1 : -1;
	if (nb < 0)
		buffer[i++] = '-';
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

static int	nb_len(nb)
{
	size_t len;

	len = 1;
	if (nb < 0)
	{
		nb = -nb;
		len = 2;
	}
	while(nb >= 10)
	{
		nb /= 10;
		len++;
	}
	if (nb == -2147483648)
		len = 11;
	return (len);
}

void	print_prec(t_data *data, int len, int nb)
{
	print_debug("\n********* PRINT_PREC *********\n", data, 'S');
	if(data->info.mask & IS_WIDTH)
	{
		print_debug("\nje suis dans width\n", data, 'S');
		if(data->info.mask & IS_MINUS)
		{
			print_debug("\nje suis dans minus\n", data, 'S');
			print_flags(data, data->info.p_value, len, '0');
			ft_putnbr(nb, data);
		}
		if (data->info.w_value > data->info.p_value)
		{
			print_debug("\nwidth est superieure a prec\n", data, 'S');
			if (data->info.p_value > len)
				print_flags(data, data->info.w_value, data->info.p_value, ' ');
			else if (data->info.p_value < len)
				print_flags(data, data->info.w_value, len, ' ');
		}
		if (!(data->info.mask & IS_MINUS))
		{
			print_debug("\nje suis dans !(minus)\n", data, 'S');
			print_flags(data, data->info.p_value, len, '0');
			ft_putnbr(nb, data);
		}
	}
	else
	{
		print_debug("\nje suis dans autre yoloooo\n", data, 'S');
		print_flags(data, data->info.p_value, len, '0');
		ft_putnbr(nb, data);
	}
}

void	print_width(t_data *data, int len, int nb)
{
	print_debug("\n********* PRINT_WIDTH *********\n", data, 'S');
	if(nb == 0 && data->info.mask & IS_POINT)
		print_flags(data, data->info.w_value, 0, ' ');
	else if(data->info.mask & IS_MINUS)
	{
		print_debug("\nje suis dans minus de width\n", data, 'S');
		ft_putnbr(nb, data);
		print_flags(data, data->info.w_value, len, ' ');
	}
	else if(data->info.mask & IS_ZERO)
	{
		print_debug("\nje suis dans zero\n", data, 'S');
		if (data->info.mask & IS_POINT)
			print_flags(data, data->info.w_value, len, ' ');
		else if (data->info.mask ^ IS_POINT)
			print_flags(data, data->info.w_value, len, '0');
		ft_putnbr(nb, data);
	}
}

int			type_d(t_data *data)
{
	int nb;
	int len;
	
	nb = va_arg(data->ap, int);
	len = nb_len(nb);
	check_debug(data);
	print_debug("\n********* TYPE_D *********\n", data, 'S');
	print_debug("\nmask ->", data, 'M');
	if(data->info.mask == IS_WIDTH)
	{
		print_flags(data, data->info.w_value, len, ' ');
		ft_putnbr(nb, data);
	}
	else if (data->info.mask & IS_PRECISION)
		print_prec(data, len, nb);
	else if(data->info.mask & IS_WIDTH)
		print_width(data, len, nb);
	else if(data->info.mask == IS_POINT && nb == 0)
	{
		data->format++;
		return(0);
	}
	else // si pas width et pas precision et pas (point et nb == 0)
		ft_putnbr(nb, data);
	data->format++;
	return (0);
}
