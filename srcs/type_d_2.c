/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:21:11 by vserra            #+#    #+#             */
/*   Updated: 2020/02/29 16:36:30 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// '0' + width -> ajoute des zeros non significatifs jusqu'a atteindre la width
// '-' + width -> alligner resultat a gauche jusqu'a atteindre la width
// '.12' -> 
// '.' -> 

void	write_nbr(int nb)
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
	return (len);
}

////// cas 1

// void	print_zero_and_nb(t_data *data, int len, int nb)
// {
// 	print_flags(data->info.p_value, len, '0');
// 	write_nbr(nb);
// }

// void	width_and_prec(t_data *data, int len)
// {
// 	if (data->info.p_value > len)
// 		print_flags(data->info.w_value, data->info.p_value, ' ');
// 	else
// 		print_flags(data->info.w_value, len, ' ');
// }

// int			type_d(t_data *data)
// {
// 	int nb;
// 	int len;
	
// 	nb = va_arg(data->ap, int);
// 	len = nb_len(nb);
// 	check_debug(data);
// 	print_debug("\n********* TYPE_D *********\n", data, 'S');
// 	print_debug("\nmask ->", data, 'M');
// 	if(data->info.mask == IS_WIDTH) // == 4
// 		print_flags(data->info.w_value, len, ' ');
// 	if(data->info.mask == 5) // width + minus
// 	{
// 		write_nbr(nb);
// 		print_flags(data->info.w_value, len, ' ');
// 	}
// 	if(data->info.mask == 6 || data->info.mask == 8) // width + zero ou precision seul
// 		print_zero_and_nb(data, len, nb);
// 	if(data->info.mask == 12) // width + precision
// 	{
// 		width_and_prec(data, len);
// 		print_zero_and_nb(data, len, nb);
// 	}
// 	if(data->info.mask == 13) // width + precision + minus
// 	{
// 		print_zero_and_nb(data, len, nb);
// 		width_and_prec(data, len);
// 	}
// 	if(data->info.mask == 0 || data->info.mask == 4)
// 		write_nbr(nb);
// 	data->format++;
// 	return (0);
// }

// void	print_zero_and_nb(t_data *data, int len, int nb)
// {
// 	print_flags(data->info.w_value, len, '0');
// 	write_nbr(nb);
// }

////// cas 2

void	calc_precision(t_data *data, int len, int nb)
{
	print_debug("\n********* calc_precision *********\n", data, 'S');
	if(data->info.mask & IS_WIDTH)
	{
		print_debug("\nje suis dans width\n", data, 'S');
		if(data->info.mask & IS_MINUS)
		{
			print_debug("\nje suis dans minus\n", data, 'S');
			print_flags(data->info.p_value, len, '0');
			write_nbr(nb);
		}
		if (data->info.w_value > data->info.p_value)
		{
			print_debug("\nwidth est superieure a prec\n", data, 'S');
			if (data->info.p_value < len)
				print_flags(data->info.w_value, data->info.p_value, ' ');
			else if (data->info.p_value > len)
				print_flags(data->info.w_value, len, ' ');
		}
		if (!(data->info.mask & IS_MINUS))
		{
			print_debug("\nje suis dans !(minus)\n", data, 'S');
			print_flags(data->info.p_value, len, '0');
			write_nbr(nb);
		}
	}
	else
	{
		print_debug("\nje suis dans autre yoloooo\n", data, 'S');
		print_flags(data->info.p_value, len, '0');
		write_nbr(nb);
	}
}

void	calc_width(t_data *data, int len, int nb)
{
	print_debug("\n********* calc_width *********\n", data, 'S');
	if(data->info.mask & IS_MINUS)
	{
		print_debug("\nje suis dans minus de width\n", data, 'S');
		write_nbr(nb);
		print_flags(data->info.w_value, len, ' ');
	}
	else if(data->info.mask & IS_ZERO)
	{
		print_debug("\nje suis dans zero\n", data, 'S');
		if (data->info.mask & IS_POINT)
			print_flags(data->info.w_value, len, ' ');
		else if (data->info.mask ^ IS_POINT)
			print_flags(data->info.w_value, len, '0');
		write_nbr(nb);
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
	if(data->info.mask == 0)
		write_nbr(nb);
	if(data->info.mask == IS_WIDTH)
	{
		print_flags(data->info.w_value, len, ' ');
		write_nbr(nb);
	}
	// if (data->info.mask == IS_PRECISION)
	// {
	// 	print_flags(data->info.p_value, len, '0');
	// 	write_nbr(nb);
	// }
	if (data->info.mask & IS_PRECISION)
		calc_precision(data, len, nb);
	else if(data->info.mask & IS_WIDTH)
		calc_width(data, len, nb);
	data->format++;
	return (0);
}

////// cas 3

// int			type_d(t_data *data)
// {
// 	int nb;
// 	int len;
	
// 	nb = va_arg(data->ap, int);
// 	len = nb_len(nb);
// 	check_debug(data);
// 	print_debug("\n********* TYPE_D *********\n", data, 'S');
// 	print_debug("\nmask ->", data, 'M');
// 	if (data->info.mask & IS_PRECISION) // PRECISION ONLY
// 		calc_precision(data, len, nb);
// 	else if (data->info.mask  == (IS_WIDTH | IS_MINUS))
// 	{
// 		write_nbr(nb);
// 		print_flags(data->info.w_value, len, ' ');
// 	}
// 	else if (data->info.mask == (IS_WIDTH | IS_ZERO))
// 	{
// 		print_flags(data->info.w_value, len, '0');
// 		write_nbr(nb);
// 	}
// 	else if (data->info.mask == IS_WIDTH || data->info.mask == 22)
// 	{
// 		print_flags(data->info.w_value, len, ' ');
// 		write_nbr(nb);
// 	}
// 	if (data->info.mask == 0)
// 		write_nbr(nb);
// 	data->format++;
// 	return (0);
// }