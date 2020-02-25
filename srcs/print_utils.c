/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:52:56 by vserra            #+#    #+#             */
/*   Updated: 2020/02/25 18:58:27 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *b, int c, size_t len)
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

// write(1, &buff_minus, data->info.w_value - 1);

void	print_flags(t_data *data, int value, int ignored_char, int c)
{
	// int count = 0;
	int len;
	char buff[8192];

	len = value - ignored_char;
	ft_memset(buff, c, 8192);
	while (len > 8192)
	{
		write(1, &buff, 8192);
		len -= 8192;
		// count += 8192;
	}
	data->nb_char +=len;
	write(1, &buff, len);
	// count += len;
	// printf("len = %d\n", count);
}