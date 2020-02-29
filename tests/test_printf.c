/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:50:27 by vserra            #+#    #+#             */
/*   Updated: 2020/02/25 17:14:38 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main()
{
	int				nb;
	unsigned int	unb;
	int				hexa;
	char			*str;
	char			c;

	nb = 1456;
	unb = 46531;
	hexa = 255;
	str = "Coucou maman !";
	c = 'a';

	/* TYPES */
	// printf("Printf	-> |%c| |%s| |%p| |%d| |%i| |%u| |%x| |%X| |%%|\n", c, str, str, nb, nb, unb, hexa, hexa);
	// printf("Printf	-> |%*c| |%*s| |%*p| |%*d| |%*i| |%*u| |%*x| |%*X| |%*%|\n", 12, c, 12, str, 12, str, 12, nb, 12, nb, 12, unb, 12, hexa, 12, hexa);
	// printf("Printf	-> |%.*c| |%.*s| |%.*p| |%.*d| |%.*i| |%.*u| |%.*x| |%.*X| |%.*%|\n", -5, c, -5, str, -5, str, -5, nb, -5, nb, -5, unb, -5, hexa, -5, hexa);

	/* ZERO */
	// printf("Printf	-> |%0c| |%0s| |%0p| |%0d| |%0i| |%0u| |%0x| |%0X| |%0%|\n", c, str, str, nb, nb, unb, hexa, hexa);

	/* MINUS */
	// printf("Printf	-> |%-c| |%-s| |%-p| |%-d| |%-i| |%-u| |%-x| |%-X| |%-%|\n", c, str, str, nb, nb, unb, hexa, hexa);

	/* WIDTH */
	// printf("Printf	-> |%1c| |%1s| |%1p| |%1d| |%1i| |%1u| |%1x| |%1X| |%1%|\n", c, str, str, nb, nb, unb, hexa, hexa);
	// printf("Printf	-> |%10c| |%10s| |%10p| |%10d| |%10i| |%10u| |%10x| |%10X| |%10%|\n", c, str, str, nb, nb, unb, hexa, hexa);
	// printf("Printf	-> |%25c| |%25s| |%25p| |%25d| |%25i| |%25u| |%25x| |%25X| |%25%|\n", c, str, str, nb, nb, unb, hexa, hexa);

	/* PRECISION */
	printf("Printf	-> |%.c| |%.s| |%.p| |%.d| |%.i| |%.u| |%.x| |%.X| |%.%|\n", c, str, str, nb, nb, unb, hexa, hexa);
	// printf("Printf	-> |%.0c| |%.0s| |%.0p| |%.0d| |%.0i| |%.0u| |%.0x| |%.0X| |%.0%|\n", c, str, str, nb, nb, unb, hexa, hexa);
	// printf("Printf	-> |%.1c| |%1.s| |%.1p| |%.1d| |%.1i| |%.1u| |%.1x| |%.1X| |%.1%|\n", c, str, str, nb, nb, unb, hexa, hexa);
	// printf("Printf	-> |%.3c| |%3.s| |%.3p| |%.3d| |%.3i| |%.3u| |%.3x| |%.3X| |%.3%|\n", c, str, str, nb, nb, unb, hexa, hexa);

	/* A TRIER */
	// printf("Printf	-> |%020d| |%020s| |%020c|\n", nb, str, c);

	// printf("Printf	-> |%-10d| |%-10s| |%-10c|\n", nb, str, c);

	// printf("Printf	-> |%0-20.3d| |%0-20.3s| |%0-20.3c|\n", nb, str, c);

	// printf("Printf	-> |%.3d| |%.3s| |%.3c|\n", nb, str, c);

	// printf("\nWTFF\n");

	// printf("Printf	-> |%020-0d| |%020-0s| |%020-0c|\n", nb, str, c);

	// printf("Printf nW	-> |%-----d| |%-----s| |%-----c|\n", nb, str, c);

	// printf("Printf 0-	-> |%20d| |%20s| |%20c|\n", nb, str, c);

	// printf("Printf 1-	-> |%-20d| |%-20s| |%-20c|\n", nb, str, c);

	// printf("Printf 4-	-> |%----20d| |%----20s| |%----20c|\n", nb, str, c);

	// printf("Printf 0-	-> |%-015d| |%-015s| |%-015c|\n", nb, str, c);

	// printf("Printf 5-	-> |%-----20d| |%-----20s| |%-----20c|\n", nb, str, c);

	// printf("Printf	-> |%%d| |%s%| |%%c| |%%|\n", nb, str, c);

	return (0);
}