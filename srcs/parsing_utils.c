/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:48:36 by vserra            #+#    #+#             */
/*   Updated: 2020/02/06 22:53:31 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_printf.h"

void	is_flag(char **format, t_info *info)
{
	while (**format == '-' || **format == '0')
	{
		if (**format == '-')
		{
			info->mask = (info->mask | IS_MINUS);
			*format++;
		}
		if (**format == '0')
		{
			info->mask = (info->mask | IS_ZERO);
			*format++;
		}
	}
	// return (i);
}

// anciennement "atoi cancer" ---->

// void	is_width(char **format, t_info *info) //get width
// {
// 	int			len;
// 	long long	width_value;

// 	len = 0;
// 	width_value = 0;
// 	while ((*format)[len] >= '0' && (*format)[len] <= '9' && len < 11)
// 	{
// 		width_value = width_value * 10 + (*format)[len] - '0';
// 		len++;
// 	}
// 	*format += len;
// 	info->mask = (info->mask | IS_WIDTH); // est-ce un doublon d'information ?
// 	if (width_value > INT_MAX)
// 		*format -= len - 1;
// 	else
// 		info->width_value = width_value;
// 		*format++;
// }

int		ft_atoi_cancer(char **str) //get width
{
	int			len;
	long long	value;

	len = 0;
	value = 0;
	while ((*str)[len] >= '0' && (*str)[len] <= '9' && len < 11)
	{
		value = value * 10 + (*str)[len] - '0';
		len++;
	}
	*str += len;
	if (value > INT_MAX)
		// *str -= len - 1;
		value = -1;
	// else
		// *str++;
	return (value);
}

void	is_width(char **format, t_info *info)
{
	if ((info->width_value = ft_atoi_cancer(format) > -1)
		info->mask = (info->mask | IS_WIDTH);
	else // erreur : la width > INT_MAX
		info->width_value = 0;
	*format++; // (1) a voir si ici ou dans le if
}

void	get_width(char **format, t_info *info) // possibilite de faire une ft get_arg
{
	char *temp;

	temp = va_arg(ap, temp);
	if ((info->width_value = ft_atoi_cancer(temp)) > -1) //a voir si atoi arrangé
		info->mask = (info->mask | IS_WIDTH);
	*format++; //(1) a voir si ici ou dans le if
}

void	get_width(char **format, t_info *info)

// (1) ->	veut-on continuer a get_format si une width ou autre n'est pas correcte?
//			est-ce qu'on continue printf, gere-ton les autres formats ?

void	is_precision(char **format, t_info *info)
{
	char *temp;

	if(**format == '.') // deja check ulterieurement
	{
		*format++;
		if(**format == '*')
		{
			// get_arg -> mettre la valeur dans info->prec_value
			temp = va_arg(ap, temp);
			if ((info->prec_value = ft_atoi_cancer(temp)) > -1) //a voir si atoi arrangé
				info->mask = (info->mask | IS_PRECISION);
			*format++; // (1) a voir si ici ou dans le if
		}
		else if (**format >= '0' && **format <= '9')
		{
			//get_num /!\ le chiffre qui suit ne peut pas etre negatif (warning)
			if ((info->prec_value = ft_atoi_cancer(format) > -1)
				info->mask = (info->mask | IS_PRECISION); // info->mask |= IS_PRECISION
			else // erreur : la width > INT_MAX
				info->width_value = 0;
			*format++; // (1) a voir si ici ou dans le if
		}
		else
			info->mask = (info->mask | IS_POINT);
	}
}