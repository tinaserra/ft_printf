/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:43:00 by vserra            #+#    #+#             */
/*   Updated: 2020/01/25 21:56:30 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
// #include <stdint.h>
#include <limits.h>

// int		is_flag(char *format, int i)
// {
// 	int minus = 0;
// 	int zero = 0;
// 	// int i = 0;

// 	while (format[i] == '-' || format[i] == '0')
// 	{
// 		printf("TOUR ------------- %d\n", i);
// 		if (format[i] == '-')
// 		{
// 			// info->mask = (info->mask | IS_MINUS);
// 			minus = 1;
// 			printf("minus	= %d\n", minus);
// 			i++;
// 		}
// 		if (format[i] == '0')
// 		{
// 			// info->mask = (info->mask | IS_ZERO)
// 			zero = 1;
// 			printf("zero	= %d\n", zero);
// 			i++;
// 		}
// 	}
// 	return (i);
// }

void	is_flag(char **format)
{
	int minus = 0;
	int zero = 0;

	while (**format == '-' || **format == '0')
	{
		if (**format == '-')
		{
			// info->mask = (info->mask | IS_MINUS);
			minus = 1;
			printf("minus	= %d\n", minus);
			++(*format);
		}
		if (**format == '0')
		{
			// info->mask = (info->mask | IS_ZERO);
			zero = 1;
			printf("zero	= %d\n", zero);
			++(*format);
		}
	}
}

void	is_width(char **format)
{
	int len;
	long long width_value;
	int is_width = 0;
	int width = 0;

	width_value = 0;
	len = 0;

	// info->mask = (info->mask | IS_WIDTH);
	while ((*format)[len] >= '0' && (*format)[len] <= '9' && len < 11)
	{
		width_value = width_value * 10 + (*format)[len] - '0';
		len++;
	}
	*format += len;
	is_width = 1;
	if (width_value > INT_MAX)
		*format -= len - 1;
	else
		width = width_value;
	printf("width_value	= %lld\n", width_value);
	printf("width		= %d\n", width);
	printf("is_width	= %d\n", is_width);
	printf("len		= %d\n", len);
}

int		main()
{
	char	*format;
	int		i;

	i = 0;

	format = "--0-214007483648";

	while (format[i])
	{
		is_flag(&format);
		is_width(&format);
		i++;
	}
	printf("i	= %d\n", i);
	return (0);
}