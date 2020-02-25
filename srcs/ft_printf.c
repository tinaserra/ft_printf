/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:42:50 by vserra            #+#    #+#             */
/*   Updated: 2020/02/25 18:03:18 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	int i;
	t_data data;

	i = 0;
	data.format = (unsigned char *)str;
	va_start(data.ap, str);
	parsing(&data);
	va_end(data.ap);
	print_debug("\nnb_char =", &data, 'N');
	return (data.nb_char);
}