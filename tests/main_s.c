/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:15:19 by vserra            #+#    #+#             */
/*   Updated: 2020/03/07 04:43:17 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "../includes/ft_printf.h"

int main()
{
	int w = -5;
	int p = 2;
	char *str = "bonjoue yohann";

	// str = NULL;

/* SIMPLE TESTS --------------------------------- */

	printf("\n\n* TYPE S ------------------------- *\n");

	printf("\n* BLOC 1 - Just width *\n");

	printf("\nprintf :	{%s}\n", str);
	ft_printf("ft_printf :	{%s}\n", str);
	printf("\nprintf :	{%*s}\n", w, str);
	ft_printf("ft_printf :	{%*s}\n", w, str);
	printf("\nprintf :	{%-*s}\n", w, str);
	ft_printf("ft_printf :	{%-*s}\n", w, str);
	printf("\nprintf :	{%0*s}\n", w, str);
	ft_printf("ft_printf :	{%0*s}\n", w, str);

	printf("\n\n* BLOC 2 - Width & Precision = 0 *\n");

	printf("\nprintf :	{%.s}\n", str);
	ft_printf("ft_printf :	{%.s}\n", str);
	printf("\nprintf :	{%*.s}\n", w, str);
	ft_printf("ft_printf :	{%*.s}\n", w, str);
	printf("\nprintf :	{%0*.s}\n", w, str);
	ft_printf("ft_printf :	{%0*.s}\n", w, str);
	printf("\nprintf :	{%-*.s}\n", w, str);
	ft_printf("ft_printf :	{%-*.s}\n", w, str);

	printf("\n\n* BLOC 3 - Just precision *\n");

	printf("\nprintf :	{%.*s}\n", p, str);
	ft_printf("ft_printf :	{%.*s}\n", p, str);
	printf("\nprintf :	{%-.*s}\n", p, str);
	ft_printf("ft_printf :	{%-.*s}\n", p, str);
	printf("\nprintf :	{%0.*s}\n", p, str);
	ft_printf("ft_printf :	{%0.*s}\n", p, str);

	printf("\n\n* BLOC 4 - Width & Precision *\n");
	
	printf("\nprintf :	{%*.*s}\n", w, p, str);
	ft_printf("ft_printf :	{%*.*s}\n", w, p, str);
	printf("\nprintf :	{%-*.*s}\n", w, p, str);
	ft_printf("ft_printf :	{%-*.*s}\n", w, p, str);
	printf("\nprintf :	{%0*.*s}\n", w, p, str);
	ft_printf("ft_printf :	{%0*.*s}\n", w, p, str);

	printf("\n😎\n");
	return 0;
}

// INT_MAX 2147483647
// UINT_MAX 4294967295