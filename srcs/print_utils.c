/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:52:56 by vserra            #+#    #+#             */
/*   Updated: 2020/03/03 14:47:49 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*temp;

	i = 0;
	temp = (unsigned char *)b;
	while (i < len)
	{
		temp[i] = (unsigned char)c;
		i++;
	}
	b = (void *)temp;
	return (b);
}

void		print_flags(t_data *data, int value, int ignored_char, int c)
{
	int len;
	char buff[8192];

	len = value - ignored_char;
	ft_memset(buff, c, 8192);
	while (len > 8192)
	{
		write(1, &buff, 8192);
		len -= 8192;
	}
	data->nb_char +=len;
	write(1, &buff, len);
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
	write(1, &(data->buff_nb), len);
}
