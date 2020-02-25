/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d_2.c                                         :+:      :+:    :+:   */
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

void	ft_putnbr(int nb)
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
// 	ft_putnbr(nb);
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
// 		ft_putnbr(nb);
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
// 		ft_putnbr(nb);
// 	data->format++;
// 	return (0);
// }

// void	print_zero_and_nb(t_data *data, int len, int nb)
// {
// 	print_flags(data->info.w_value, len, '0');
// 	ft_putnbr(nb);
// }

////// cas 2

void	print_prec(t_data *data, int len, int nb)
{
	print_debug("\n********* PRINT_PREC *********\n", data, 'S');
	if(data->info.mask & IS_WIDTH)
	{
		print_debug("\nje suis dans width\n", data, 'S');
		if(data->info.mask & IS_MINUS)
		{
			print_debug("\nje suis dans minus\n", data, 'S');
			print_flags(data->info.p_value, len, '0');
			ft_putnbr(nb);
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
			ft_putnbr(nb);
		}
	}
	else
	{
		print_debug("\nje suis dans autre yoloooo\n", data, 'S');
		print_flags(data->info.p_value, len, '0');
		ft_putnbr(nb);
	}
}

void	print_width(t_data *data, int len, int nb)
{
	print_debug("\n********* PRINT_WIDTH *********\n", data, 'S');
	if(data->info.mask & IS_MINUS)
	{
		print_debug("\nje suis dans minus de width\n", data, 'S');
		ft_putnbr(nb);
		print_flags(data->info.w_value, len, ' ');
	}
	else if(data->info.mask & IS_ZERO)
	{
		print_debug("\nje suis dans zero\n", data, 'S');
		if (data->info.mask & IS_POINT)
			print_flags(data->info.w_value, len, ' ');
		else if (data->info.mask ^ IS_POINT)
			print_flags(data->info.w_value, len, '0');
		ft_putnbr(nb);
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
		ft_putnbr(nb);
	if(data->info.mask == IS_WIDTH)
	{
		print_flags(data->info.w_value, len, ' ');
		ft_putnbr(nb);
	}
	// if (data->info.mask == IS_PRECISION)
	// {
	// 	print_flags(data->info.p_value, len, '0');
	// 	ft_putnbr(nb);
	// }
	if (data->info.mask & IS_PRECISION)
		print_prec(data, len, nb);
	else if(data->info.mask & IS_WIDTH)
		print_width(data, len, nb);
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
// 		print_prec(data, len, nb);
// 	else if (data->info.mask  == (IS_WIDTH | IS_MINUS))
// 	{
// 		ft_putnbr(nb);
// 		print_flags(data->info.w_value, len, ' ');
// 	}
// 	else if (data->info.mask == (IS_WIDTH | IS_ZERO))
// 	{
// 		print_flags(data->info.w_value, len, '0');
// 		ft_putnbr(nb);
// 	}
// 	else if (data->info.mask == IS_WIDTH || data->info.mask == 22)
// 	{
// 		print_flags(data->info.w_value, len, ' ');
// 		ft_putnbr(nb);
// 	}
// 	if (data->info.mask == 0)
// 		ft_putnbr(nb);
// 	data->format++;
// 	return (0);
// }