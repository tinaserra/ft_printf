/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 20:10:25 by vserra            #+#    #+#             */
/*   Updated: 2019/12/14 06:03:32 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

// toutes les fonctions de tab doivent avoir le meme prototype

// découper
// traiter et aficher
// reset info

void	get_arg(const char *str, va_list ap)
{
	int i;

	i = 0;
	while(str[i])
	{

		while (str[i] != '%')
			i++;
		write(1, str, i);

			while(str[i] != 'c' || str[i] != 's' || str[i] != 'p' || str[i] != 'd'
					|| str[i] != 'i' || str[i] != 'u' || str[i] != 'x'
					|| str[i] != 'X' || str[i] != '%')
			{
				if (str[i] == '-')
					info.mask = IS_MINUS;
				if (str[i] == '0')
				if (str[i] >= '0' && str[i] <= '9') // is_num
				if (str[i] == '*')
				if (str[i] == '.')
				// if (str[i] == '-')
				// if (str[i] == '-')
			}
		i++;
	}

}

void	parsing(const char *str, va_list ap)
{
	int i;
	t_info info;

	i = 0;
	// Parcourir et afficher str jusqu'a %

}