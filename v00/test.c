/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:43:00 by vserra            #+#    #+#             */
/*   Updated: 2020/01/24 15:59:09 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
// #include"ft_printf.h"

// int main()
// {
// 	int i = 0;
// 	char *str = "coucou maman%-012345";

// 	ft_printf(str, 12, 13);

// 	return (0);
// }

int		main()
{
	int		nb;
	char	*str;
	char	c;

	nb = 15;
	str = "Coucou maman !";
	c = 'a';

	// printf("Printf	-> |%d| |%s| |%c|\n", nb, str, c);
	// printf("Printf	-> |%10d| |%10s| |%10c|\n", nb, str, c);
	// printf("Printf	-> |%-10d| |%-10s| |%-10c|\n", nb, str, c);
	// printf("Printf	-> |%020d| |%020s| |%020c|\n", nb, str, c);
	// printf("Printf	-> |%0-20.3d| |%0-20.3s| |%0-20.3c|\n", nb, str, c);
	// printf("Printf	-> |%.3d| |%.3s| |%.3c|\n", nb, str, c);
	// printf("\nWTFF\n");
	// printf("Printf	-> |%020-0d| |%020-0s| |%020-0c|\n", nb, str, c);
	printf("Printf nW	-> |%-----d| |%-----s| |%-----c|\n", nb, str, c);
	printf("Printf 0-	-> |%20d| |%20s| |%20c|\n", nb, str, c);
	printf("Printf 1-	-> |%-20d| |%-20s| |%-20c|\n", nb, str, c);
	printf("Printf 4-	-> |%----20d| |%----20s| |%----20c|\n", nb, str, c);
	printf("Printf 5-	-> |%-----20d| |%-----20s| |%-----20c|\n", nb, str, c);
	// printf("Printf	-> |%%d| |%s%| |%%c| |%%|\n", nb, str, c);
	return (0);
}