/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:15:19 by vserra            #+#    #+#             */
/*   Updated: 2020/03/04 18:16:04 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
	int w = 18;
	int p = 12;
	char *str = "Hola que tal";
	void *ptr;

	ptr = -462354;
	// str = NULL;

/* SIMPLE TESTS --------------------------------- */

	printf("\n\n* TYPE P ------------------------- *\n");

	printf("\n* BLOC 1 *\n");
// pour une w = 16 et la len du nombre = 9
// on print 0x puis w - (len  + 2)(len de 0x) espaces
// ou w - len - 2 = (w - 2) - len

	printf("\nprintf :	{%p}\n", str);
	ft_printf("ft_printf :	{%p}\n", str);
	printf("\nprintf :	{%*p}\n", w, str);
	ft_printf("ft_printf :	{%*p}\n", w, str);
	printf("\nprintf :	{%-*p}\n", w, str);
	ft_printf("ft_printf :	{%-*p}\n", w, str);
	printf("\nprintf :	{%0*p}\n", w, str);
	ft_printf("ft_printf :	{%0*p}\n", w, str);

	printf("\n\n* BLOC 2 *\n");
// pour une w = 18 et p = 0 la len du nombre = 9
// on print w - (len  + 2)(len de 0x) espaces
// ou w - len - 2 = (w - 2) - len

	printf("\nprintf :	{%*.p}\n", w, str);
	ft_printf("ft_printf :	{%*.p}\n", w, str);
	printf("\nprintf :	{%0*.p}\n", w, str);
	ft_printf("ft_printf :	{%0*.p}\n", w, str);
	printf("\nprintf :	{%-*.p}\n", w, str);
	ft_printf("ft_printf :	{%-*.p}\n", w, str);

	printf("\n\n* BLOC 3 *\n");
// pour une p = 12 la len du nombre = 9
// on print '0x' puis p - len zeros

	printf("\nprintf :	{%.*p}\n", p, str);
	ft_printf("ft_printf :	{%.*p}\n", p, str);
	printf("\nprintf :	{%-.*p}\n", p, str);
	ft_printf("ft_printf :	{%-.*p}\n", p, str);
	printf("\nprintf :	{%0.*p}\n", p, str);
	ft_printf("ft_printf :	{%0.*p}\n", p, str);

	printf("\n\n* BLOC 4 *\n");
// pour une w = 18 et p = 12 la len du nombre = 9
// on print w - (p + 2)(0x) espaces, puis'0x' , puis p - len zeros puis nb
// ou w - 2 - p = nb espaces 

	printf("\nprintf :	{%*.*p}\n", w, p, str);
	ft_printf("ft_printf :	{%*.*p}\n", w, p, str);
	printf("\nprintf :	{%-*.*p}\n", w, p, str);
	ft_printf("ft_printf :	{%-*.*p}\n", w, p, str);
	printf("\nprintf :	{%0*.*p}\n", w, p, str);
	ft_printf("ft_printf :	{%0*.*p}\n", w, p, str);

	printf("\n😎\n");
	return 0;
}

// INT_MAX 2147483647
// UINT_MAX 4294967295