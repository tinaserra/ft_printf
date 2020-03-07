/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pourcent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:15:19 by vserra            #+#    #+#             */
/*   Updated: 2020/03/07 06:02:24 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "../includes/ft_printf.h"

int main()
{
	int w = -5;
	int p = 2;

/* SIMPLE TESTS --------------------------------- */

	printf("\n\n* TYPE %% ------------------------- *\n");

	printf("\n* BLOC 1 - Just width *\n");

	printf("\nprintf :	{%%}\n");
	ft_printf("ft_printf :	{%%}\n");
	printf("\nprintf :	{%*%}\n", w);
	ft_printf("ft_printf :	{%*%}\n", w);
	printf("\nprintf :	{%-*%}\n", w);
	ft_printf("ft_printf :	{%-*%}\n", w);
	printf("\nprintf :	{%0*%}\n", w);
	ft_printf("ft_printf :	{%0*%}\n", w);

	printf("\n\n* BLOC 2 - Width & Precision = 0 *\n");

	printf("\nprintf :	{%.%}\n");
	ft_printf("ft_printf :	{%.%}\n");
	printf("\nprintf :	{%*.%}\n", w);
	ft_printf("ft_printf :	{%*.%}\n", w);
	printf("\nprintf :	{%0*.%}\n", w);
	ft_printf("ft_printf :	{%0*.%}\n", w);
	printf("\nprintf :	{%-*.%}\n", w);
	ft_printf("ft_printf :	{%-*.%}\n", w);

	printf("\n\n* BLOC 3 - Just precision *\n");

	printf("\nprintf :	{%.*%}\n", p);
	ft_printf("ft_printf :	{%.*%}\n", p);
	printf("\nprintf :	{%-.*%}\n", p);
	ft_printf("ft_printf :	{%-.*%}\n", p);
	printf("\nprintf :	{%0.*%}\n", p);
	ft_printf("ft_printf :	{%0.*%}\n", p);

	printf("\n\n* BLOC 4 - Width & Precision *\n");
	
	printf("\nprintf :	{%*.*%}\n", w, p);
	ft_printf("ft_printf :	{%*.*%}\n", w, p);
	printf("\nprintf :	{%-*.*%}\n", w, p);
	ft_printf("ft_printf :	{%-*.*%}\n", w, p);
	printf("\nprintf :	{%0*.*%}\n", w, p);
	ft_printf("ft_printf :	{%0*.*%}\n", w, p);

	printf("\n😎\n");
	return 0;
}

// INT_MAX 2147483647
// UINT_MAX 4294967295