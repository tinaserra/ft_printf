/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:50:27 by vserra            #+#    #+#             */
/*   Updated: 2020/02/05 18:22:10 by vserra           ###   ########.fr       */
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

	printf("Printf	-> |%0c| |%0s| |%0p| |%0d| |%0i| |%0u| |%0x| |%0X| |%0%|\n", c, str, str, nb, nb, unb, hexa, hexa);
	// printf("Printf	-> |%.0c| |%.0s| |%.0p| |%.0d| |%.0i| |%.0u| |%.0x| |%.0X| |%.0%|\n", c, str, str, nb, nb, unb, hexa, hexa);
	// printf("Printf	-> |%10d| |%10s| |%10c|\n", nb, str, c);
	// printf("Printf	-> |%-10d| |%-10s| |%-10c|\n", nb, str, c);
	// printf("Printf	-> |%020d| |%020s| |%020c|\n", nb, str, c);
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