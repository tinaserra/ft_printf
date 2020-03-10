/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 03:52:56 by vserra            #+#    #+#             */
/*   Updated: 2020/03/10 19:22:11 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int		main()
{
	int ret1 = 0;
	int ret2 = 0;
	unsigned int unb;
	unsigned int hexa;
	int nb;
	int w;
	int p;

	// ".1 {%s}  .2 {%-s}  .3 {%0s}\n",
	// ".4 {%*s}  .5 {%-*s}  .6 {%0*s}\n"
	// ".7 {%.s}  8. {%*.s}  9. {%0*.s}  .10 {%-*.s}\n"
	// ".11 {%.*s}  .12 {%-.*s}  .13 {%0.*s}\n"
	// ".14 {%*.*s}  .15 {%0*.*s}  .16 {%-*.*s}\n"

	// printf("\nTEST nb = 12 | width = 4\n");
	// printf("-----\n");
	// printf("printf\n);
	// ret1 = printf(".1 {%s}  .2 {%-s}  .3 {%0s}  .4 {%*s}  .5 {%-*s}  .6 {%0*s}\n", str, str, str, w, str, w, str, w, str);
	// printf("ft_printf\n);
	// ret2 = ft_printf(".1 {%s}  .2 {%-s}  .3 {%0s}  .4 {%*s}  .5 {%-*s}  .6 {%0*s}\n", str, str, str, w, str, w, str, w, str);

printf("\n\n\n\n******************************************* int --> %% d *******************************************\n\n");
		// printf("\n  ////////////////////////////////////////\n // Met un int en 1er argument ta race //\n////////////////////////////////////////\n");
		nb = 12;
		printf("\nTEST nb = 12 | width = 4\n");
		printf("-----\n");
		printf("printf\n|%d| |%.d| |%0d| |%-d| |%4d| |%04d| |%-04d| |%0-4d| |%04.d| |%-04.d| |%0-4.d|\n", nb, nb, nb, nb, nb, nb, nb, nb, nb, nb, nb);
		ft_printf("ft_printf\n|%d| |%.d| |%0d| |%-d| |%4d| |%04d| |%-04d| |%0-4d| |%04.d| |%-04.d| |%0-4.d|\n", nb, nb, nb, nb, nb, nb, nb, nb, nb, nb, nb);

		nb = 12345;
		printf("\n\nTEST nb = 12345 | width = 20 | precision = 9\n");
		printf("-----\n");
		printf("printf\n|%d| |%.d| |%0d| |%-d| |%020d| |%-020d| |%0-20d| |%020.9d| |%-020.9d| |%0-20.9d|\n", nb, nb, nb, nb, nb, nb, nb, nb, nb, nb);
		ft_printf("ft_printf\n|%d| |%.d| |%0d| |%-d| |%020d| |%-020d| |%0-20d| |%020.9d| |%-020.9d| |%0-20.9d|\n", nb, nb, nb, nb, nb, nb, nb, nb, nb, nb);

		nb = 0;
		printf("\n\nTEST nb = 0 | width = 4 | precision = 0\n");
		printf("-----\n");
		printf("printf\n|%d| |%.d| |%0d| |%-d| |%04d| |%-04d| |%0-4d| |%04.d| |%-04.d| |%0-4.d|\n", nb, nb, nb, nb, nb, nb, nb, nb, nb, nb);
		ft_printf("ft_printf\n|%d| |%.d| |%0d| |%-d| |%04d| |%-04d| |%0-4d| |%04.d| |%-04.d| |%0-4.d|\n", nb, nb, nb, nb, nb, nb, nb, nb, nb, nb);
		printf("printf\n|%.0d| |%04.0d| |%-04.0d| |%0-4.0d|\n", nb, nb, nb, nb);
		ft_printf("ft_printf\n|%.0d| |%04.0d| |%-04.0d| |%0-4.0d|\n", nb, nb, nb, nb);

		nb = INT_MAX;
		printf("\n\nTEST nb = int max | width = 20 | precision = 0\n");
		printf("-----\n");
		printf("printf\n|%d| |%.d| |%0d| |%-d| |%020d| |%-020d| |%0-20d| |%020.d| |%-020.d| |%0-20.d|\n", nb, nb, nb, nb, nb, nb, nb, nb, nb, nb);
		ft_printf("ft_printf\n|%d| |%.d| |%0d| |%-d| |%020d| |%-020d| |%0-20d| |%020.d| |%-020.d| |%0-20.d|\n", nb, nb, nb, nb, nb, nb, nb, nb, nb, nb);
		printf("printf\n|%.0d| |%020.0d| |%-20.0d| |%0-20.0d|\n", nb, nb, nb, nb);
		ft_printf("ft_printf\n|%.0d| |%020.0d| |%-20.0d| |%0-20.0d|\n", nb, nb, nb, nb);

		nb = INT_MIN;
		printf("\n\nTEST nb = int min | width = 20\n");
		printf("------\n");
		printf("printf\n|%d| |%.d| |%0d| |%-d| |%020d| |%-020d| |%0-20d| |%020.d| |%-020.d| |%0-20.d|\n", nb, nb, nb, nb, nb, nb, nb, nb, nb, nb);
		ft_printf("ft_printf\n|%d| |%.d| |%0d| |%-d| |%020d| |%-020d| |%0-20d| |%020.d| |%-020.d| |%0-20.d|\n", nb, nb, nb, nb, nb, nb, nb, nb, nb, nb);

		printf("\n😎");

printf("\n\n\n\n******************************************* unsigned int --> %% u *******************************************\n\n");
		// printf("\n  ////////////////////////////////////////\n // Met un int en 1er argument ta race //\n////////////////////////////////////////\n");
		unb = 12;
		printf("\nTEST nb = 12 | width = 4\n");
		printf("-----\n");
		printf("printf\n|%u| |%.u| |%0u| |%-u| |%04u| |%-04u| |%0-4u| |%04.u| |%-04.u| |%0-4.u|\n", unb, unb, unb, unb, unb, unb, unb, unb, unb, unb);
		ft_printf("ft_printf\n|%u| |%.u| |%0u| |%-u| |%04u| |%-04u| |%0-4u| |%04.u| |%-04.u| |%0-4.u|\n", unb, unb, unb, unb, unb, unb, unb, unb, unb, unb);

		unb = 12345;
		printf("\n\nTEST nb = 12345 | width = 20 | precision = 9\n");
		printf("-----\n");
		printf("printf\n|%u| |%.u| |%0u| |%-u| |%020u| |%-020u| |%0-20u| |%020.9u| |%-020.9u| |%0-20.9u|\n", unb, unb, unb, unb, unb, unb, unb, unb, unb, unb);
		ft_printf("ft_printf\n|%u| |%.u| |%0u| |%-u| |%020u| |%-020u| |%0-20u| |%020.9u| |%-020.9u| |%0-20.9u|\n", unb, unb, unb, unb, unb, unb, unb, unb, unb, unb);

		unb = 0;
		printf("\n\nTEST nb = 0 | width = 4\n");
		printf("-----\n");
		printf("printf\n|%u| |%.u| |%0u| |%-u| |%04u| |%-04u| |%0-4u| |%04.u| |%-04.u| |%0-4.u|\n", unb, unb, unb, unb, unb, unb, unb, unb, unb, unb);
		ft_printf("ft_printf\n|%u| |%.u| |%0u| |%-u| |%04u| |%-04u| |%0-4u| |%04.u| |%-04.u| |%0-4.u|\n", unb, unb, unb, unb, unb, unb, unb, unb, unb, unb);

		unb = UINT_MAX;
		printf("\n\nTEST nb = unsigned int max | width = 20\n");
		printf("-----\n");
		printf("printf\n|%u| |%.u| |%0u| |%-u| |%020u| |%-020u| |%0-20u| |%020.u| |%-020.u| |%0-20.u|\n", unb, unb, unb, unb, unb, unb, unb, unb, unb, unb);
		ft_printf("ft_printf\n|%u| |%.u| |%0u| |%-u| |%020u| |%-020u| |%0-20u| |%020.u| |%-020.u| |%0-20.u|\n", unb, unb, unb, unb, unb, unb, unb, unb, unb, unb);

		unb = 123456789;
		printf("\n\nTEST nb = 123456789 | width = 20 | precision = -15\n");
		printf("-----\n");
		printf("printf\n|%u| |%.u| |%0u| |%-u| |%020u| |%-020u| |%0-20u| |%020.*u| |%-020.*u| |%0-20.*u|\n", unb, unb, unb, unb, unb, unb, unb, -15, unb, -15, unb, -15, unb);
		ft_printf("ft_printf\n|%u| |%.u| |%0u| |%-u| |%020u| |%-020u| |%0-20u| |%020.*u| |%-020.*u| |%0-20.*u|\n", unb, unb, unb, unb, unb, unb, unb, -15, unb, -15, unb, -15, unb);

		printf("\n😎");

printf("\n\n\n\n******************************************* hexadecimal (unsigned int) --> %% x *******************************************\n\n");
		hexa = 255; w = 15; p = 10;
		printf("\nTEST hexa = 255 | width = 15 | precision = 10\n");
		printf("-----\n");
		printf("printf :	.1 {%x}  .2 {%*x}  .3 {%-*x}  .4 {%0*x}  .5 {%0*.x}  .6 {%-*.x}  .7 {%*.x}  .8 {%.*x}  .9 {%-.*x}  .10 {%0.*x}  .11 {%*.*x}  .12 {%0*.*d}  .13 {%-*.*x}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);
		ft_printf("ft_printf :	.1 {%x}  .2 {%*x}  .3 {%-*x}  .4 {%0*x}  .5 {%0*.x}  .6 {%-*.x}  .7 {%*.x}  .8 {%.*x}  .9 {%-.*x}  .10 {%0.*x}  .11 {%*.*x}  .12 {%0*.*d}  .13 {%-*.*x}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);

		hexa = 255; w = -15; p = -10;
		printf("\n\nTEST hexa = 255 | width = -15 | precision = -10\n");
		printf("-----\n");
		printf("printf :	.1 {%x}  .2 {%*x}  .3 {%-*x}  .4 {%0*x}  .5 {%0*.x}  .6 {%-*.x}  .7 {%*.x}  .8 {%.*x}  .9 {%-.*x}  .10 {%0.*x}  .11 {%*.*x}  .12 {%0*.*d}  .13 {%-*.*x}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);
		ft_printf("ft_printf :	.1 {%x}  .2 {%*x}  .3 {%-*x}  .4 {%0*x}  .5 {%0*.x}  .6 {%-*.x}  .7 {%*.x}  .8 {%.*x}  .9 {%-.*x}  .10 {%0.*x}  .11 {%*.*x}  .12 {%0*.*d}  .13 {%-*.*x}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);

		hexa = 0; w = 0; p = 0;
		printf("\n\nTEST hexa = 0 | width = 0 | precision = 0\n");
		printf("-----\n");
		printf("printf :	.1 {%x}  .2 {%*x}  .3 {%-*x}  .4 {%0*x}  .5 {%0*.x}  .6 {%-*.x}  .7 {%*.x}  .8 {%.*x}  .9 {%-.*x}  .10 {%0.*x}  .11 {%*.*x}  .12 {%0*.*d}  .13 {%-*.*x}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);
		ft_printf("ft_printf :	.1 {%x}  .2 {%*x}  .3 {%-*x}  .4 {%0*x}  .5 {%0*.x}  .6 {%-*.x}  .7 {%*.x}  .8 {%.*x}  .9 {%-.*x}  .10 {%0.*x}  .11 {%*.*x}  .12 {%0*.*d}  .13 {%-*.*x}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);

		hexa = 1; w = 5; p = 3;
		printf("\n\nTEST hexa = 1 | width = 5 | precision = 3\n");
		printf("-----\n");
		printf("printf :	.1 {%x}  .2 {%*x}  .3 {%-*x}  .4 {%0*x}  .5 {%0*.x}  .6 {%-*.x}  .7 {%*.x}  .8 {%.*x}  .9 {%-.*x}  .10 {%0.*x}  .11 {%*.*x}  .12 {%0*.*d}  .13 {%-*.*x}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);
		ft_printf("ft_printf :	.1 {%x}  .2 {%*x}  .3 {%-*x}  .4 {%0*x}  .5 {%0*.x}  .6 {%-*.x}  .7 {%*.x}  .8 {%.*x}  .9 {%-.*x}  .10 {%0.*x}  .11 {%*.*x}  .12 {%0*.*d}  .13 {%-*.*x}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);

		hexa = 1; w = 1; p = 1;
		printf("\n\nTEST hexa = 1 | width = 1 | precision = 1\n");
		printf("-----\n");
		printf("printf :	.1 {%x}  .2 {%*x}  .3 {%-*x}  .4 {%0*x}  .5 {%0*.x}  .6 {%-*.x}  .7 {%*.x}  .8 {%.*x}  .9 {%-.*x}  .10 {%0.*x}  .11 {%*.*x}  .12 {%0*.*d}  .13 {%-*.*x}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);
		ft_printf("ft_printf :	.1 {%x}  .2 {%*x}  .3 {%-*x}  .4 {%0*x}  .5 {%0*.x}  .6 {%-*.x}  .7 {%*.x}  .8 {%.*x}  .9 {%-.*x}  .10 {%0.*x}  .11 {%*.*x}  .12 {%0*.*d}  .13 {%-*.*x}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);

		hexa = 1; w = 3; p = 7;
		printf("\n\nTEST hexa = 1 | width = 3 | precision = 7\n");
		printf("-----\n");
		printf("printf :	.1 {%x}  .2 {%*x}  .3 {%-*x}  .4 {%0*x}  .5 {%0*.x}  .6 {%-*.x}  .7 {%*.x}  .8 {%.*x}  .9 {%-.*x}  .10 {%0.*x}  .11 {%*.*x}  .12 {%0*.*d}  .13 {%-*.*x}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);
		ft_printf("ft_printf :	.1 {%x}  .2 {%*x}  .3 {%-*x}  .4 {%0*x}  .5 {%0*.x}  .6 {%-*.x}  .7 {%*.x}  .8 {%.*x}  .9 {%-.*x}  .10 {%0.*x}  .11 {%*.*x}  .12 {%0*.*d}  .13 {%-*.*x}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);

		hexa = 254; w = 10; p = 5;
		printf("\n\nTEST hexa = 254 | width = 10 | precision = 5\n");
		printf("-----\n");
		printf("printf :	.1 {%x}  .2 {%*x}  .3 {%-*x}  .4 {%0*x}  .5 {%0*.x}  .6 {%-*.x}  .7 {%*.x}  .8 {%.*x}  .9 {%-.*x}  .10 {%0.*x}  .11 {%*.*x}  .12 {%0*.*d}  .13 {%-*.*x}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);
		ft_printf("ft_printf :	.1 {%x}  .2 {%*x}  .3 {%-*x}  .4 {%0*x}  .5 {%0*.x}  .6 {%-*.x}  .7 {%*.x}  .8 {%.*x}  .9 {%-.*x}  .10 {%0.*x}  .11 {%*.*x}  .12 {%0*.*d}  .13 {%-*.*x}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);

		hexa = 201; w = 7; p = 4;
		printf("\n\nTEST hexa = 201 | width = 7 | precision = 4\n");
		printf("-----\n");
		printf("printf :	.1 {%x}  .2 {%*x}  .3 {%-*x}  .4 {%0*x}  .5 {%0*.x}  .6 {%-*.x}  .7 {%*.x}  .8 {%.*x}  .9 {%-.*x}  .10 {%0.*x}  .11 {%*.*x}  .12 {%0*.*d}  .13 {%-*.*x}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);
		ft_printf("ft_printf :	.1 {%x}  .2 {%*x}  .3 {%-*x}  .4 {%0*x}  .5 {%0*.x}  .6 {%-*.x}  .7 {%*.x}  .8 {%.*x}  .9 {%-.*x}  .10 {%0.*x}  .11 {%*.*x}  .12 {%0*.*d}  .13 {%-*.*x}\n", hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, w, hexa, p, hexa, p, hexa, p, hexa, w, p, hexa, w, p, hexa, w, p, hexa);

		hexa = 33;
		printf("\n\nTEST hexa = 33 | width = 7 ou 1 | precision = 5 ou 1\n");
		printf("-----\n");
		printf("printf :	1 {%x} 2 {%7x} 3 {%1x} 4 {%-7x} 5 {%07x} 6 {%.x} 7 {%-.x} 8 {%07.5x} 9 {%-7.5x} 10 {%07.x} 11 {%-7.1x} 12 {%07.1x} 13 {%07.x}\n", hexa, hexa, hexa, hexa, hexa, hexa, hexa, hexa, hexa, hexa, hexa, hexa, 0);
		ft_printf("ft_printf :	1 {%x} 2 {%7x} 3 {%1x} 4 {%-7x} 5 {%07x} 6 {%.x} 7 {%-.x} 8 {%07.5x} 9 {%-7.5x} 10 {%07.x} 11 {%-7.1x} 12 {%07.1x} 13 {%07.x}\n", hexa, hexa, hexa, hexa, hexa, hexa, hexa, hexa, hexa, hexa, hexa, hexa, 0);

		printf("\n😎");

// printf("\n\n\n******************************************* string --> %% s *******************************************\n\n");
// 		str = "Hello world";
// 		printf("\nTEST str = Hello word | width = 20 | precision = 5\n");
// 		printf("-----\n");
// 		printf("printf\n|%s| |%0s| |%-s| |%20s| |%020s| |%-20s| |%0-20s|\n", str, str, str, str, str, str, str);
// 		// ft_printf("ft_printf\n|%s| |%0s| |%-s| |%20s| |%020s| |%-20s| |%0-20s|\n", str, str, str, str, str, str, str);
// 		printf("printf\n|%.5s| |%0.5s| |%-.5s| |%0-.5s| |%020.5s| |%-020.5s| |%-20.5s|\n", str, str, str, str, str, str, str);
// 		// ft_printf("ft_printf\n|%.5s| |%0.5s| |%-.5s| |%0-.5s| |%020.5s| |%-020.5s| |%-20.5s|\n", str, str, str, str, str, str, str);

// 		printf("\nTEST str = Hello word | width = 20 | precision = 0\n");
// 		printf("-----\n");
// 		printf("printf\n|%20s| |%020s| |%-20s| |%0-20s|\n", str, str, str, str);
// 		// ft_printf("ft_printf|%20s| |%020s| |%-20s| |%0-20s|\n", str, str, str, str);
// 		printf("printf\n|%.0s| |%0.0s| |%-.0s| |%0-.0s| |%020.0s| |%-020.0s| |%-20.0s|\n", str, str, str, str, str, str, str);
// 		// ft_printf("ft_printf\n|%.0s| |%0.0s| |%-.0s| |%0-.0s| |%020.0s| |%-020.0s| |%-20.0s|\n", str, str, str, str, str, str, str);

// 		printf("\nTEST str = Hello word | width = 4 | precision = 0\n");
// 		printf("-----\n");
// 		printf("printf\n|%4s| |%04s| |%-4s| |%0-4s|\n", str, str, str, str);
// 		// ft_printf("ft_printf\n|%4s| |%04s| |%-4s| |%0-4s|\n", str, str, str, str);
// 		printf("printf\n|%4s| |%04.0s| |%-04.0s| |%-4.0s|\n", str, str, str, str);
// 		// ft_printf("ft_printf\n|%4s| |%04.0s| |%-04.0s| |%-4.0s|\n", str, str, str, str);

// 		printf("\nTEST str = Hello word | width = 15 | precision = -12\n");
// 		printf("-----\n");
// 		printf("printf\n|%15s| |%015s| |%-15s| |%0-15s|\n", str, str, str, str);
// 		// ft_printf("ft_printf\n|%15s| |%015s| |%-15s| |%0-15s|\n", -12, str, -12, str, -12, str, -12, str);
// 		printf("printf\n|%.*s| |%0.*s| |%-.*s| |%0-.*s| |%015.*s| |%-015.*s| |%-15.*s|\n", -12, str, -12, str, -12, str, -12, str, -12, str, -12, str, -12, str);
// 		// ft_printf("ft_printf\n|%.*s| |%0.*s| |%-.*s| |%0-.*s| |%015.*s| |%-015.*s| |%-15.*s|\n", -12, str, -12, str, -12, str, -12, str, -12, str, -12, str, -12, str);

// 		printf("\nTEST str = Hello word | width = 10 | precision = 1\n");
// 		printf("-----\n");
// 		printf("printf\n|%10s| |%010s| |%-10s| |%0-10s|\n", str, str, str, str);
// 		// ft_printf("ft_printf\n|%10s| |%010s| |%-10s| |%0-10s|\n", str, str, str, str);
// 		printf("printf\n|%.1s| |%0.1s| |%-.1s| |%0-.1s| |%020.1s| |%-020.1s| |%-20.1s|\n", str, str, str, str, str, str, str);
// 		// ft_printf("ft_printf\n|%.1s| |%0.1s| |%-.1s| |%0-.1s| |%020.1s| |%-020.1s| |%-20.1s|\n", str, str, str, str, str, str, str);

// 		printf("\nTEST only IS_POINT | width = 20 \n");
// 		printf("-----\n");
// 		printf("printf\n|%.s| |%0.s| |%-.s| |%020.s| |%-20.s| |%0-20.s|\n", str, str, str, str, str, str);
// 		// ft_printf("ft_printf\n|%.s| |%0.s| |%-.s| |%020.s| |%-20.s| |%0-20.s|\n", str, str, str, str, str, str);

// 		str = "UnE pHrAsE uN pEu LoNgUe PoUr Un TeSt NuLlE a ChIeR";
// 		printf("\nTEST str = phrase longue | width = 75 | precision = 15\n");
// 		printf("-----\n");
// 		printf("printf\n|%s| |%0s| |%-s| | 75s| |% 75s| |% 75s| |%0 75s|\n", str, str, str, str, str, str, str);
// 		// ft_printf("ft_printf\n|%s| |%0s| |%-s| | 75s| |% 75s| |% 75s| |%0 75s|\n", str, str, str, str, str, str, str);
// 		printf("printf\n|%.15s| |%0.15s| |%-.15s| |%0-.15s| |% 75.15s| |%- 75.15s| |% 75.15s|\n", str, str, str, str, str, str, str);
// 		// ft_printf("ft_printf\n|%.15s| |%0.15s| |%-.15s| |%0-.15s| |% 75.15s| |%- 75.15s| |% 75.15s|\n", str, str, str, str, str, str, str);

// 		printf("\nTEST str = Hello word | width = 20 | precision = 0\n");
// 		printf("-----\n");
// 		printf("printf\n|%20s| |%020s| |%-20s| |%0-20s|\n", str, str, str, str);
// 		// ft_printf("ft_printf|%20s| |%020s| |%-20s| |%0-20s|\n", str, str, str, str);
// 		printf("printf\n|%.0s| |%0.0s| |%-.0s| |%0-.0s| |%020.0s| |%-020.0s| |%-20.0s|\n", str, str, str, str, str, str, str);
// 		// ft_printf("ft_printf\n|%.0s| |%0.0s| |%-.0s| |%0-.0s| |%020.0s| |%-020.0s| |%-20.0s|\n", str, str, str, str, str, str, str);

// 		printf("\nTEST str = Hello word | width = 4 | precision = 0\n");
// 		printf("-----\n");
// 		printf("printf\n|%4s| |%04s| |%-4s| |%0-4s|\n", str, str, str, str);
// 		// ft_printf("ft_printf\n|%4s| |%04s| |%-4s| |%0-4s|\n", str, str, str, str);
// 		printf("printf\n|%4s| |%04.0s| |%-04.0s| |%-4.0s|\n", str, str, str, str);
// 		// ft_printf("ft_printf\n|%4s| |%04.0s| |%-04.0s| |%-4.0s|\n", str, str, str, str);

// 		printf("\nTEST str = Hello word | width = 15 | precision = -12\n");
// 		printf("-----\n");
// 		printf("printf\n|%15s| |%015s| |%-15s| |%0-15s|\n", str, str, str, str);
// 		// ft_printf("ft_printf\n|%15s| |%015s| |%-15s| |%0-15s|\n", -12, str, -12, str, -12, str, -12, str);
// 		printf("printf\n|%.*s| |%0.*s| |%-.*s| |%0-.*s| |%015.*s| |%-015.*s| |%-15.*s|\n", -12, str, -12, str, -12, str, -12, str, -12, str, -12, str, -12, str);
// 		// ft_printf("ft_printf\n|%.*s| |%0.*s| |%-.*s| |%0-.*s| |%015.*s| |%-015.*s| |%-15.*s|\n", -12, str, -12, str, -12, str, -12, str, -12, str, -12, str, -12, str);

// 		printf("\nTEST str = Hello word | width = 10 | precision = 1\n");
// 		printf("-----\n");
// 		printf("printf\n|%10s| |%010s| |%-10s| |%0-10s|\n", str, str, str, str);
// 		// ft_printf("ft_printf\n|%10s| |%010s| |%-10s| |%0-10s|\n", str, str, str, str);
// 		printf("printf\n|%.1s| |%0.1s| |%-.1s| |%0-.1s| |%020.1s| |%-020.1s| |%-20.1s|\n", str, str, str, str, str, str, str);
// 		// ft_printf("ft_printf\n|%.1s| |%0.1s| |%-.1s| |%0-.1s| |%020.1s| |%-020.1s| |%-20.1s|\n", str, str, str, str, str, str, str);

// 		printf("\nTEST only IS_POINT | width = 20 \n");
// 		printf("-----\n");
// 		printf("printf\n|%.s| |%0.s| |%-.s| |%020.s| |%-20.s| |%0-20.s|\n", str, str, str, str, str, str);
// 		// ft_printf("ft_printf\n|%.s| |%0.s| |%-.s| |%020.s| |%-20.s| |%0-20.s|\n", str, str, str, str, str, str);

// 		str = "A";
// 		printf("\nTEST str = Hello word | width = 20 | precision = 5\n");
// 		printf("-----\n");
// 		printf("printf\n|%s| |%0s| |%-s| |%20s| |%020s| |%-20s| |%0-20s|\n", str, str, str, str, str, str, str);
// 		// ft_printf("ft_printf\n|%s| |%0s| |%-s| |%20s| |%020s| |%-20s| |%0-20s|\n", str, str, str, str, str, str, str);
// 		printf("printf\n|%.5s| |%0.5s| |%-.5s| |%0-.5s| |%020.5s| |%-020.5s| |%-20.5s|\n", str, str, str, str, str, str, str);
// 		// ft_printf("ft_printf\n|%.5s| |%0.5s| |%-.5s| |%0-.5s| |%020.5s| |%-020.5s| |%-20.5s|\n", str, str, str, str, str, str, str);

// 		printf("\nTEST str = Hello word | width = 20 | precision = 0\n");
// 		printf("-----\n");
// 		printf("printf\n|%20s| |%020s| |%-20s| |%0-20s|\n", str, str, str, str);
// 		// ft_printf("ft_printf|%20s| |%020s| |%-20s| |%0-20s|\n", str, str, str, str);
// 		printf("printf\n|%.0s| |%0.0s| |%-.0s| |%0-.0s| |%020.0s| |%-020.0s| |%-20.0s|\n", str, str, str, str, str, str, str);
// 		// ft_printf("ft_printf\n|%.0s| |%0.0s| |%-.0s| |%0-.0s| |%020.0s| |%-020.0s| |%-20.0s|\n", str, str, str, str, str, str, str);

// 		printf("\nTEST str = Hello word | width = 4 | precision = 0\n");
// 		printf("-----\n");
// 		printf("printf\n|%4s| |%04s| |%-4s| |%0-4s|\n", str, str, str, str);
// 		// ft_printf("ft_printf\n|%4s| |%04s| |%-4s| |%0-4s|\n", str, str, str, str);
// 		printf("printf\n|%4s| |%04.0s| |%-04.0s| |%-4.0s|\n", str, str, str, str);
// 		// ft_printf("ft_printf\n|%4s| |%04.0s| |%-04.0s| |%-4.0s|\n", str, str, str, str);

// 		printf("\nTEST str = Hello word | width = 15 | precision = -12\n");
// 		printf("-----\n");
// 		printf("printf\n|%15s| |%015s| |%-15s| |%0-15s|\n", str, str, str, str);
// 		// ft_printf("ft_printf\n|%15s| |%015s| |%-15s| |%0-15s|\n", -12, str, -12, str, -12, str, -12, str);
// 		printf("printf\n|%.*s| |%0.*s| |%-.*s| |%0-.*s| |%015.*s| |%-015.*s| |%-15.*s|\n", -12, str, -12, str, -12, str, -12, str, -12, str, -12, str, -12, str);
// 		// ft_printf("ft_printf\n|%.*s| |%0.*s| |%-.*s| |%0-.*s| |%015.*s| |%-015.*s| |%-15.*s|\n", -12, str, -12, str, -12, str, -12, str, -12, str, -12, str, -12, str);

// 		printf("\nTEST str = Hello word | width = 10 | precision = 1\n");
// 		printf("-----\n");
// 		printf("printf\n|%10s| |%010s| |%-10s| |%0-10s|\n", str, str, str, str);
// 		// ft_printf("ft_printf\n|%10s| |%010s| |%-10s| |%0-10s|\n", str, str, str, str);
// 		printf("printf\n|%.1s| |%0.1s| |%-.1s| |%0-.1s| |%020.1s| |%-020.1s| |%-20.1s|\n", str, str, str, str, str, str, str);
// 		// ft_printf("ft_printf\n|%.1s| |%0.1s| |%-.1s| |%0-.1s| |%020.1s| |%-020.1s| |%-20.1s|\n", str, str, str, str, str, str, str);

// 		printf("\nTEST only IS_POINT | width = 20 \n");
// 		printf("-----\n");
// 		printf("printf\n|%.s| |%0.s| |%-.s| |%020.s| |%-20.s| |%0-20.s|\n", str, str, str, str, str, str);
// 		// ft_printf("ft_printf\n|%.s| |%0.s| |%-.s| |%020.s| |%-20.s| |%0-20.s|\n", str, str, str, str, str, str);

// 		str = "";
// 		printf("\nTEST str = Hello word | width = 20 | precision = 5\n");
// 		printf("-----\n");
// 		printf("printf\n|%s| |%0s| |%-s| |%20s| |%020s| |%-20s| |%0-20s|\n", str, str, str, str, str, str, str);
// 		// ft_printf("ft_printf\n|%s| |%0s| |%-s| |%20s| |%020s| |%-20s| |%0-20s|\n", str, str, str, str, str, str, str);
// 		printf("printf\n|%.5s| |%0.5s| |%-.5s| |%0-.5s| |%020.5s| |%-020.5s| |%-20.5s|\n", str, str, str, str, str, str, str);
// 		// ft_printf("ft_printf\n|%.5s| |%0.5s| |%-.5s| |%0-.5s| |%020.5s| |%-020.5s| |%-20.5s|\n", str, str, str, str, str, str, str);

// 		printf("\nTEST str = Hello word | width = 20 | precision = 0\n");
// 		printf("-----\n");
// 		printf("printf\n|%20s| |%020s| |%-20s| |%0-20s|\n", str, str, str, str);
// 		// ft_printf("ft_printf|%20s| |%020s| |%-20s| |%0-20s|\n", str, str, str, str);
// 		printf("printf\n|%.0s| |%0.0s| |%-.0s| |%0-.0s| |%020.0s| |%-020.0s| |%-20.0s|\n", str, str, str, str, str, str, str);
// 		// ft_printf("ft_printf\n|%.0s| |%0.0s| |%-.0s| |%0-.0s| |%020.0s| |%-020.0s| |%-20.0s|\n", str, str, str, str, str, str, str);

// 		printf("\nTEST str = Hello word | width = 4 | precision = 0\n");
// 		printf("-----\n");
// 		printf("printf\n|%4s| |%04s| |%-4s| |%0-4s|\n", str, str, str, str);
// 		// ft_printf("ft_printf\n|%4s| |%04s| |%-4s| |%0-4s|\n", str, str, str, str);
// 		printf("printf\n|%4s| |%04.0s| |%-04.0s| |%-4.0s|\n", str, str, str, str);
// 		// ft_printf("ft_printf\n|%4s| |%04.0s| |%-04.0s| |%-4.0s|\n", str, str, str, str);

// 		printf("\nTEST str = Hello word | width = 15 | precision = -12\n");
// 		printf("-----\n");
// 		printf("printf\n|%15s| |%015s| |%-15s| |%0-15s|\n", str, str, str, str);
// 		// ft_printf("ft_printf\n|%15s| |%015s| |%-15s| |%0-15s|\n", -12, str, -12, str, -12, str, -12, str);
// 		printf("printf\n|%.*s| |%0.*s| |%-.*s| |%0-.*s| |%015.*s| |%-015.*s| |%-15.*s|\n", -12, str, -12, str, -12, str, -12, str, -12, str, -12, str, -12, str);
// 		// ft_printf("ft_printf\n|%.*s| |%0.*s| |%-.*s| |%0-.*s| |%015.*s| |%-015.*s| |%-15.*s|\n", -12, str, -12, str, -12, str, -12, str, -12, str, -12, str, -12, str);

// 		printf("\nTEST str = Hello word | width = 10 | precision = 1\n");
// 		printf("-----\n");
// 		printf("printf\n|%10s| |%010s| |%-10s| |%0-10s|\n", str, str, str, str);
// 		// ft_printf("ft_printf\n|%10s| |%010s| |%-10s| |%0-10s|\n", str, str, str, str);
// 		printf("printf\n|%.1s| |%0.1s| |%-.1s| |%0-.1s| |%020.1s| |%-020.1s| |%-20.1s|\n", str, str, str, str, str, str, str);
// 		// ft_printf("ft_printf\n|%.1s| |%0.1s| |%-.1s| |%0-.1s| |%020.1s| |%-020.1s| |%-20.1s|\n", str, str, str, str, str, str, str);

// 		printf("\nTEST only IS_POINT | width = 20 \n");
// 		printf("-----\n");
// 		printf("printf\n|%.s| |%0.s| |%-.s| |%020.s| |%-20.s| |%0-20.s|\n", str, str, str, str, str, str);
// 		// ft_printf("ft_printf\n|%.s| |%0.s| |%-.s| |%020.s| |%-20.s| |%0-20.s|\n", str, str, str, str, str, str);

// 		str = NULL;
// 		printf("\nTEST str = Hello word | width = 20 | precision = 5\n");
// 		printf("-----\n");
// 		printf("printf\n|%s| |%0s| |%-s| |%20s| |%020s| |%-20s| |%0-20s|\n", str, str, str, str, str, str, str);
// 		// ft_printf("ft_printf\n|%s| |%0s| |%-s| |%20s| |%020s| |%-20s| |%0-20s|\n", str, str, str, str, str, str, str);
// 		printf("printf\n|%.5s| |%0.5s| |%-.5s| |%0-.5s| |%020.5s| |%-020.5s| |%-20.5s|\n", str, str, str, str, str, str, str);
// 		// ft_printf("ft_printf\n|%.5s| |%0.5s| |%-.5s| |%0-.5s| |%020.5s| |%-020.5s| |%-20.5s|\n", str, str, str, str, str, str, str);

// 		printf("\nTEST str = Hello word | width = 20 | precision = 0\n");
// 		printf("-----\n");
// 		printf("printf\n|%20s| |%020s| |%-20s| |%0-20s|\n", str, str, str, str);
// 		// ft_printf("ft_printf|%20s| |%020s| |%-20s| |%0-20s|\n", str, str, str, str);
// 		printf("printf\n|%.0s| |%0.0s| |%-.0s| |%0-.0s| |%020.0s| |%-020.0s| |%-20.0s|\n", str, str, str, str, str, str, str);
// 		// ft_printf("ft_printf\n|%.0s| |%0.0s| |%-.0s| |%0-.0s| |%020.0s| |%-020.0s| |%-20.0s|\n", str, str, str, str, str, str, str);

// 		printf("\nTEST str = Hello word | width = 4 | precision = 0\n");
// 		printf("-----\n");
// 		printf("printf\n|%4s| |%04s| |%-4s| |%0-4s|\n", str, str, str, str);
// 		// ft_printf("ft_printf\n|%4s| |%04s| |%-4s| |%0-4s|\n", str, str, str, str);
// 		printf("printf\n|%4s| |%04.0s| |%-04.0s| |%-4.0s|\n", str, str, str, str);
// 		// ft_printf("ft_printf\n|%4s| |%04.0s| |%-04.0s| |%-4.0s|\n", str, str, str, str);

// 		printf("\nTEST str = Hello word | width = 15 | precision = -12\n");
// 		printf("-----\n");
// 		printf("printf\n|%15s| |%015s| |%-15s| |%0-15s|\n", str, str, str, str);
// 		// ft_printf("ft_printf\n|%15s| |%015s| |%-15s| |%0-15s|\n", -12, str, -12, str, -12, str, -12, str);
// 		printf("printf\n|%.*s| |%0.*s| |%-.*s| |%0-.*s| |%015.*s| |%-015.*s| |%-15.*s|\n", -12, str, -12, str, -12, str, -12, str, -12, str, -12, str, -12, str);
// 		// ft_printf("ft_printf\n|%.*s| |%0.*s| |%-.*s| |%0-.*s| |%015.*s| |%-015.*s| |%-15.*s|\n", -12, str, -12, str, -12, str, -12, str, -12, str, -12, str, -12, str);

// 		printf("\nTEST str = Hello word | width = 10 | precision = 1\n");
// 		printf("-----\n");
// 		printf("printf\n|%10s| |%010s| |%-10s| |%0-10s|\n", str, str, str, str);
// 		// ft_printf("ft_printf\n|%10s| |%010s| |%-10s| |%0-10s|\n", str, str, str, str);
// 		printf("printf\n|%.1s| |%0.1s| |%-.1s| |%0-.1s| |%020.1s| |%-020.1s| |%-20.1s|\n", str, str, str, str, str, str, str);
// 		// ft_printf("ft_printf\n|%.1s| |%0.1s| |%-.1s| |%0-.1s| |%020.1s| |%-020.1s| |%-20.1s|\n", str, str, str, str, str, str, str);

// 		printf("\nTEST only IS_POINT | width = 20 \n");
// 		printf("-----\n");
// 		printf("printf\n|%.s| |%0.s| |%-.s| |%020.s| |%-20.s| |%0-20.s|\n", str, str, str, str, str, str);
// 		// ft_printf("ft_printf\n|%.s| |%0.s| |%-.s| |%020.s| |%-20.s| |%0-20.s|\n", str, str, str, str, str, str);

	// printf("\n😎\n");
	return (0);
}
