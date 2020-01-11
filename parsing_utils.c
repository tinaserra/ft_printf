/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:14:33 by vserra            #+#    #+#             */
/*   Updated: 2020/01/10 20:15:03 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_n_atoi(const char *str, int i)
{
	int		sign;
	int		nbr;

	sign = 1;
	nbr = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10);
		nbr = nbr + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}

inline int ft_is_minus(char *str, int i, t_info *info)
{
	if (str[i] == '-') // || str[i + 1] == '-'
		info->mask = (info->mask | IS_MINUS);
	return(i);
}

inline int ft_is_zero(char *str, int i, t_info *info)
{
	if (str[i] == '0' && !info->width_value) // /!\ peut etre avant ou apres le zero
		info->mask = (info->mask | IS_ZERO);
	return(i);
}

inline int ft_get_width(char *str, int i, t_info *info)
{

	if (str[i] >= '0' && str[i] <= '9')
	{
		info->mask = (info->mask | IS_WIDTH);
		info->width_value = ft_n_atoi(str, i);
	}
	return(i);
}

inline int ft_get_star_value(char *str, int i, va_list ap, t_info *info)
{
	char *temp;
	
	if (str[i] == '*')
	//prendre la valeur et le stocker dans info->width_value : atoi
	temp = va_arg(ap, char *);
	info->width_value = ft_n_atoi(temp, i);
	return(i);
}

inline int ft_is_precision(char *str, int i, va_list ap, t_info *info)
{
	char *temp;
	if (str[i] == '.')
	{
		info->mask = (info->mask | IS_PRECISION);
		if (str[i + 1] == '*')
		{
			temp = va_arg(ap, char *);
			// ft_atoi && stocker le resultat dans info->prec_value
			info->prec_value = ft_n_atoi(temp, i);
		}
	}
	return (i);
}