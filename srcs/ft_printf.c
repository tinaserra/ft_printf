/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:42:50 by vserra            #+#    #+#             */
/*   Updated: 2020/02/18 15:30:19 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	int i;
	t_data data;

	i = 0;
	data.format = (unsigned char *)str;

	// int nb; // nombre de char ecrit par printf

	va_start(data.ap, str);
	// nb = 0;
	/*nb = */parsing(&data);
	va_end(data.ap);
	// return (nb);
	return (0);
}