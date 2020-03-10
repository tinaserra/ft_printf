/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lover.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:20:52 by vserra            #+#    #+#             */
/*   Updated: 2020/03/10 15:11:07 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
	int ret1 = 0;
	int ret2 = 0;
	int c;
	// int p;
	char *str;

	str = NULL;

	// p = 0;
	c = 'y';

	ret1 = printf("-->|%-4.|<--\n", c);
	ret2 = ft_printf("-->|%-4.|<--\n", c);
	printf("--> %d | %d\n\n", ret1, ret2);

// printf("\n* TYPE C ************************\n\n");

	// ret1 = printf("-->|%-4.c|<--\n", c);
	// ret2 = ft_printf("-->|%-4.c|<--\n", c);
	// printf("--> %d | %d\n\n", ret1, ret2);

// 	ret1 = printf("-->|%-4c|<--\n", c);
// 	ret2 = ft_printf("-->|%-4c|<--\n", c);
// 	printf("--> %d | %d\n\n", ret1, ret2);

// 	ret1 = printf("-->|%-3.c|<--\n", c);
// 	ret2 = ft_printf("-->|%-3.c|<--\n", c);
// 	printf("--> %d | %d\n\n", ret1, ret2);

// 	ret1 = printf("-->|%-3c|<--\n", c);
// 	ret2 = ft_printf("-->|%-3c|<--\n", c);
// 	printf("--> %d | %d\n\n", ret1, ret2);

// 	ret1 = printf("-->|%-2.c|<--\n", c);
// 	ret2 = ft_printf("-->|%-2.c|<--\n", c);
// 	printf("--> %d | %d\n\n", ret1, ret2);

// printf("\n* TYPE P ************************\n\n");

// 	ret1 = printf("-->|%-14p|<--\n", str);
// 	ret2 = ft_printf("-->|%-14p|<--\n", str);
// 	printf("--> %d | %d\n\n", ret1, ret2);

// 	ret1 = printf("-->|%-15.p|<--\n", str);
// 	ret2 = ft_printf("-->|%-15.p|<--\n", str);
// 	printf("--> %d | %d\n\n", ret1, ret2);

// 	ret1 = printf("-->|%-15p|<--\n", str);
// 	ret2 = ft_printf("-->|%-15p|<--\n", str);
// 	printf("--> %d | %d\n\n", ret1, ret2);

// 	ret1 = printf("-->|%-16.p|<--\n", str);
// 	ret2 = ft_printf("-->|%-16.p|<--\n", str);
// 	printf("--> %d | %d\n\n", ret1, ret2);

// 	ret1 = printf("-->|%-16p|<--\n", str);
// 	ret2 = ft_printf("-->|%-16p|<--\n", str);
// 	printf("--> %d | %d\n\n", ret1, ret2);

	printf("\n😎\n");
	return (0);
}