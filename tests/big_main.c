/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 03:52:56 by vserra            #+#    #+#             */
/*   Updated: 2020/02/27 00:14:57 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int		main(int ac, char **av)
{
	char *nombre; //int
	char *width; //int
	char *precision; //int
	char *str; //char* string av[4]
	
	unsigned int unb;
	int nb;

	if (ac > 1)
	{
		printf("\n******************************************* int --> %% d *******************************************\n\n");
		printf("AUGUMENTS : av[1] -> int || av[2] -> width || av[3] -> precision\n");
		nombre = av[1];
		printf("\nTEST width = 4\n");
		printf("-----\n");
		printf("printf\n|%04d| |%-04d| |%0-4d| |%04.d| |%-04.d| |%0-4.d|\n", atoi(nombre), atoi(nombre), atoi(nombre), atoi(nombre), atoi(nombre), atoi(nombre));
		ft_printf("ft_printf\n|%04d| |%-04d| |%0-4d| |%04.d| |%-04.d| |%0-4.d|\n", atoi(nombre), atoi(nombre), atoi(nombre), atoi(nombre), atoi(nombre), atoi(nombre));
		if (ac > 2)
		{
			width = av[2];
			printf("\nTEST width = * %s\n", av[2]);
			printf("-----\n");
			printf("printf\n|%0*d| |%-0*d| |%0-*d| |%0*.d| |%-0*.d| |%0-*.d|\n", atoi(width), atoi(nombre), atoi(width), atoi(nombre), atoi(width), atoi(nombre), atoi(width), atoi(nombre), atoi(width), atoi(nombre), atoi(width), atoi(nombre));
			ft_printf("ft_printf\n|%0*d| |%-0*d| |%0-*d| |%0*.d| |%-0*.d| |%0-*.d|\n", atoi(width), atoi(nombre), atoi(width), atoi(nombre), atoi(width), atoi(nombre), atoi(width), atoi(nombre), atoi(width), atoi(nombre), atoi(width), atoi(nombre));

			printf("\nTEST precision = * %s\n", av[3]);
			printf("-----\n");
			printf("printf\n|%0.*d| |%-0.*d| |%0-.*d| |%.*d| |%-.*d|\n", atoi(width), atoi(nombre), atoi(width), atoi(nombre), atoi(width), atoi(nombre), atoi(width), atoi(nombre), atoi(width), atoi(nombre));
			ft_printf("ft_printf\n|%0.*d| |%-0.*d| |%0-.*d| |%.*d| |%-.*d|\n", atoi(width), atoi(nombre), atoi(width), atoi(nombre), atoi(width), atoi(nombre), atoi(width), atoi(nombre), atoi(width), atoi(nombre));
		}
		if (ac > 3)
		{
			precision = av[3];
			printf("\nTEST width = * %s | precision = * %s\n", av[2], av[3]);
			printf("-----\n");
			printf("printf\n|%d| |%*.*d| |%0*.*d| |%-*.*d| |%-0*.*d|\n", atoi(nombre), atoi(width), atoi(precision), atoi(nombre), atoi(width), atoi(precision), atoi(nombre), atoi(width), atoi(precision), atoi(nombre), atoi(width), atoi(precision), atoi(nombre));
			ft_printf("ft_printf\n|%d| |%*.*d| |%0*.*d| |%-*.*d| |%-0*.*d|\n", atoi(nombre), atoi(width), atoi(precision), atoi(nombre), atoi(width), atoi(precision), atoi(nombre), atoi(width), atoi(precision), atoi(nombre), atoi(width), atoi(precision), atoi(nombre));
		}
 
		if (ac > 4)
		{
			printf("\n\n******************************************* string --> %% s *******************************************\n\n");
			printf("AUGUMENTS : av[4] -> string\n");
			str = av[4];
			printf("\nTEST width = * %s | precision = * %s | str = * %s\n", av[2], av[3], av[4]);
			printf("-----\n");
			printf("printf\n|%s| |%*.*s| |%-*.*s| |%0*.*s| |%-0*.*s|\n", str, atoi(width), atoi(precision), str, atoi(width), atoi(precision), str, atoi(width), atoi(precision), str, atoi(width), atoi(precision), str);
			// ft_printf("ft_printf\n|%s| |%*.*s| |%-*.*s| |%0*.*s|\n", str, atoi(width), atoi(precision), str, atoi(width), atoi(precision), str, atoi(width), atoi(precision), str);
		}

	}
	else if (ac == 1)
	{
		printf("\n******************************************* int --> %% d *******************************************\n\n");
		// printf("\n  ////////////////////////////////////////\n // Met un int en 1er argument ta race //\n////////////////////////////////////////\n");
		nb = 12;
		printf("\nTEST nb = 12 | width = 4\n");
		printf("-----\n");
		printf("printf\n|%d| |%.d| |%0d| |%-d| |%4d| |%04d| |%-04d| |%0-4d| |%04.d| |%-04.d| |%0-4.d|\n", nb, nb, nb, nb, nb, nb, nb, nb, nb, nb, nb);
		ft_printf("ft_printf\n|%d| |%.d| |%0d| |%-d| |%4d| |%04d| |%-04d| |%0-4d| |%04.d| |%-04.d| |%0-4.d|\n", nb, nb, nb, nb, nb, nb, nb, nb, nb, nb, nb);

		nb = 12345;
		printf("\nTEST nb = 12345 | width = 20 | precision = 9\n");
		printf("-----\n");
		printf("printf\n|%d| |%.d| |%0d| |%-d| |%020d| |%-020d| |%0-20d| |%020.9d| |%-020.9d| |%0-20.9d|\n", nb, nb, nb, nb, nb, nb, nb, nb, nb, nb);
		ft_printf("ft_printf\n|%d| |%.d| |%0d| |%-d| |%020d| |%-020d| |%0-20d| |%020.9d| |%-020.9d| |%0-20.9d|\n", nb, nb, nb, nb, nb, nb, nb, nb, nb, nb);

		nb = 0;
		printf("\nTEST nb = 0 | width = 4 | precision = 0\n");
		printf("-----\n");
		printf("printf\n|%d| |%.d| |%0d| |%-d| |%04d| |%-04d| |%0-4d| |%04.d| |%-04.d| |%0-4.d|\n", nb, nb, nb, nb, nb, nb, nb, nb, nb, nb);
		ft_printf("ft_printf\n|%d| |%.d| |%0d| |%-d| |%04d| |%-04d| |%0-4d| |%04.d| |%-04.d| |%0-4.d|\n", nb, nb, nb, nb, nb, nb, nb, nb, nb, nb);
		printf("printf\n|%.0d| |%04.0d| |%-04.0d| |%0-4.0d|\n", nb, nb, nb, nb);
		ft_printf("ft_printf\n|%.0d| |%04.0d| |%-04.0d| |%0-4.0d|\n", nb, nb, nb, nb);

		nb = INT_MAX;
		printf("\nTEST nb = int max | width = 20 | precision = 0\n");
		printf("-----\n");
		printf("printf\n|%d| |%.d| |%0d| |%-d| |%020d| |%-020d| |%0-20d| |%020.d| |%-020.d| |%0-20.d|\n", nb, nb, nb, nb, nb, nb, nb, nb, nb, nb);
		ft_printf("ft_printf\n|%d| |%.d| |%0d| |%-d| |%020d| |%-020d| |%0-20d| |%020.d| |%-020.d| |%0-20.d|\n", nb, nb, nb, nb, nb, nb, nb, nb, nb, nb);
		printf("printf\n|%.0d| |%020.0d| |%-20.0d| |%0-20.0d|\n", nb, nb, nb, nb);
		ft_printf("ft_printf\n|%.0d| |%020.0d| |%-20.0d| |%0-20.0d|\n", nb, nb, nb, nb);

		nb = INT_MIN;
		printf("\nTEST nb = int min | width = 20\n");
		printf("------\n");
		printf("printf\n|%d| |%.d| |%0d| |%-d| |%020d| |%-020d| |%0-20d| |%020.d| |%-020.d| |%0-20.d|\n", nb, nb, nb, nb, nb, nb, nb, nb, nb, nb);
		ft_printf("ft_printf\n|%d| |%.d| |%0d| |%-d| |%020d| |%-020d| |%0-20d| |%020.d| |%-020.d| |%0-20.d|\n", nb, nb, nb, nb, nb, nb, nb, nb, nb, nb);

		printf("\n\n\n******************************************* int --> %% u *******************************************\n\n");
		// printf("\n  ////////////////////////////////////////\n // Met un int en 1er argument ta race //\n////////////////////////////////////////\n");
		unb = 12;
		printf("\nTEST nb = 12 | width = 4\n");
		printf("-----\n");
		printf("printf\n|%u| |%.u| |%0u| |%-u| |%04u| |%-04u| |%0-4u| |%04.u| |%-04.u| |%0-4.u|\n", unb, unb, unb, unb, unb, unb, unb, unb, unb, unb);
		ft_printf("ft_printf\n|%u| |%.u| |%0u| |%-u| |%04u| |%-04u| |%0-4u| |%04.u| |%-04.u| |%0-4.u|\n", unb, unb, unb, unb, unb, unb, unb, unb, unb, unb);

		unb = 12345;
		printf("\nTEST nb = 12345 | width = 20 | precision = 9\n");
		printf("-----\n");
		printf("printf\n|%u| |%.u| |%0u| |%-u| |%020u| |%-020u| |%0-20u| |%020.9u| |%-020.9u| |%0-20.9u|\n", unb, unb, unb, unb, unb, unb, unb, unb, unb, unb);
		ft_printf("ft_printf\n|%u| |%.u| |%0u| |%-u| |%020u| |%-020u| |%0-20u| |%020.9u| |%-020.9u| |%0-20.9u|\n", unb, unb, unb, unb, unb, unb, unb, unb, unb, unb);

		unb = 0;
		printf("\nTEST nb = 0 | width = 4\n");
		printf("-----\n");
		printf("printf\n|%u| |%.u| |%0u| |%-u| |%04u| |%-04u| |%0-4u| |%04.u| |%-04.u| |%0-4.u|\n", unb, unb, unb, unb, unb, unb, unb, unb, unb, unb);
		ft_printf("ft_printf\n|%u| |%.u| |%0u| |%-u| |%04u| |%-04u| |%0-4u| |%04.u| |%-04.u| |%0-4.u|\n", unb, unb, unb, unb, unb, unb, unb, unb, unb, unb);

		unb = UINT_MAX;
		printf("\nTEST nb = unsigned int max | width = 20\n");
		printf("-----\n");
		printf("printf\n|%u| |%.u| |%0u| |%-u| |%020u| |%-020u| |%0-20u| |%020.u| |%-020.u| |%0-20.u|\n", unb, unb, unb, unb, unb, unb, unb, unb, unb, unb);
		ft_printf("ft_printf\n|%u| |%.u| |%0u| |%-u| |%020u| |%-020u| |%0-20u| |%020.u| |%-020.u| |%0-20.u|\n", unb, unb, unb, unb, unb, unb, unb, unb, unb, unb);

		unb = 123456789;
		printf("\nTEST nb = 123456789 | width = 20 | precision = -15\n");
		printf("-----\n");
		printf("printf\n|%u| |%.u| |%0u| |%-u| |%020u| |%-020u| |%0-20u| |%020.*u| |%-020.*u| |%0-20.*u|\n", unb, unb, unb, unb, unb, unb, unb, -15, unb, -15, unb, -15, unb);
		ft_printf("ft_printf\n|%u| |%.u| |%0u| |%-u| |%020u| |%-020u| |%0-20u| |%020.*u| |%-020.*u| |%0-20.*u|\n", unb, unb, unb, unb, unb, unb, unb, -15, unb, -15, unb, -15, unb);

		printf("\n\n\n******************************************* string --> %% s *******************************************\n\n");
		str = "Hello world";
		printf("\nTEST str = Hello word | width = 20 | precision = 5\n");
		printf("-----\n");
		printf("printf\n|%s| |%0s| |%-s| |%20s| |%020s| |%-20s| |%0-20s|\n", str, str, str, str, str, str, str);
		// ft_printf("ft_printf\n|%s| |%0s| |%-s| |%20s| |%020s| |%-20s| |%0-20s|\n", str, str, str, str, str, str, str);
		printf("printf\n|%.5s| |%0.5s| |%-.5s| |%0-.5s| |%020.5s| |%-020.5s| |%-20.5s|\n", str, str, str, str, str, str, str);
		// ft_printf("ft_printf\n|%.5s| |%0.5s| |%-.5s| |%0-.5s| |%020.5s| |%-020.5s| |%-20.5s|\n", str, str, str, str, str, str, str);

		printf("\nTEST str = Hello word | width = 20 | precision = 0\n");
		printf("-----\n");
		printf("printf\n|%20s| |%020s| |%-20s| |%0-20s|\n", str, str, str, str);
		// ft_printf("ft_printf|%20s| |%020s| |%-20s| |%0-20s|\n", str, str, str, str);
		printf("printf\n|%.0s| |%0.0s| |%-.0s| |%0-.0s| |%020.0s| |%-020.0s| |%-20.0s|\n", str, str, str, str, str, str, str);
		// ft_printf("ft_printf\n|%.0s| |%0.0s| |%-.0s| |%0-.0s| |%020.0s| |%-020.0s| |%-20.0s|\n", str, str, str, str, str, str, str);

		printf("\nTEST str = Hello word | width = 4 | precision = 0\n");
		printf("-----\n");
		printf("printf\n|%4s| |%04s| |%-4s| |%0-4s|\n", str, str, str, str);
		// ft_printf("ft_printf\n|%4s| |%04s| |%-4s| |%0-4s|\n", str, str, str, str);
		printf("printf\n|%4s| |%04.0s| |%-04.0s| |%-4.0s|\n", str, str, str, str);
		// ft_printf("ft_printf\n|%4s| |%04.0s| |%-04.0s| |%-4.0s|\n", str, str, str, str);

		printf("\nTEST str = Hello word | width = 15 | precision = -12\n");
		printf("-----\n");
		printf("printf\n|%15s| |%015s| |%-15s| |%0-15s|\n", str, str, str, str);
		// ft_printf("ft_printf\n|%15s| |%015s| |%-15s| |%0-15s|\n", -12, str, -12, str, -12, str, -12, str);
		printf("printf\n|%.*s| |%0.*s| |%-.*s| |%0-.*s| |%015.*s| |%-015.*s| |%-15.*s|\n", -12, str, -12, str, -12, str, -12, str, -12, str, -12, str, -12, str);
		// ft_printf("ft_printf\n|%.*s| |%0.*s| |%-.*s| |%0-.*s| |%015.*s| |%-015.*s| |%-15.*s|\n", -12, str, -12, str, -12, str, -12, str, -12, str, -12, str, -12, str);

		printf("\nTEST str = Hello word | width = 10 | precision = 1\n");
		printf("-----\n");
		printf("printf\n|%10s| |%010s| |%-10s| |%0-10s|\n", str, str, str, str);
		// ft_printf("ft_printf\n|%10s| |%010s| |%-10s| |%0-10s|\n", str, str, str, str);
		printf("printf\n|%.1s| |%0.1s| |%-.1s| |%0-.1s| |%020.1s| |%-020.1s| |%-20.1s|\n", str, str, str, str, str, str, str);
		// ft_printf("ft_printf\n|%.1s| |%0.1s| |%-.1s| |%0-.1s| |%020.1s| |%-020.1s| |%-20.1s|\n", str, str, str, str, str, str, str);

		printf("\nTEST only IS_POINT | width = 20 \n");
		printf("-----\n");
		printf("printf\n|%.s| |%0.s| |%-.s| |%020.s| |%-20.s| |%0-20.s|\n", str, str, str, str, str, str);
		// ft_printf("ft_printf\n|%.s| |%0.s| |%-.s| |%020.s| |%-20.s| |%0-20.s|\n", str, str, str, str, str, str);

		str = "UnE pHrAsE uN pEu LoNgUe PoUr Un TeSt NuLlE a ChIeR";
		printf("\nTEST str = Hello word | width = 75 | precision = 15\n");
		printf("-----\n");
		printf("printf\n|%s| |%0s| |%-s| | 75s| |% 75s| |% 75s| |%0 75s|\n", str, str, str, str, str, str, str);
		// ft_printf("ft_printf\n|%s| |%0s| |%-s| | 75s| |% 75s| |% 75s| |%0 75s|\n", str, str, str, str, str, str, str);
		printf("printf\n|%.15s| |%0.15s| |%-.15s| |%0-.15s| |% 75.15s| |%- 75.15s| |% 75.15s|\n", str, str, str, str, str, str, str);
		// ft_printf("ft_printf\n|%.15s| |%0.15s| |%-.15s| |%0-.15s| |% 75.15s| |%- 75.15s| |% 75.15s|\n", str, str, str, str, str, str, str);

		printf("\nTEST str = Hello word | width = 20 | precision = 0\n");
		printf("-----\n");
		printf("printf\n|%20s| |%020s| |%-20s| |%0-20s|\n", str, str, str, str);
		// ft_printf("ft_printf|%20s| |%020s| |%-20s| |%0-20s|\n", str, str, str, str);
		printf("printf\n|%.0s| |%0.0s| |%-.0s| |%0-.0s| |%020.0s| |%-020.0s| |%-20.0s|\n", str, str, str, str, str, str, str);
		// ft_printf("ft_printf\n|%.0s| |%0.0s| |%-.0s| |%0-.0s| |%020.0s| |%-020.0s| |%-20.0s|\n", str, str, str, str, str, str, str);

		printf("\nTEST str = Hello word | width = 4 | precision = 0\n");
		printf("-----\n");
		printf("printf\n|%4s| |%04s| |%-4s| |%0-4s|\n", str, str, str, str);
		// ft_printf("ft_printf\n|%4s| |%04s| |%-4s| |%0-4s|\n", str, str, str, str);
		printf("printf\n|%4s| |%04.0s| |%-04.0s| |%-4.0s|\n", str, str, str, str);
		// ft_printf("ft_printf\n|%4s| |%04.0s| |%-04.0s| |%-4.0s|\n", str, str, str, str);

		printf("\nTEST str = Hello word | width = 15 | precision = -12\n");
		printf("-----\n");
		printf("printf\n|%15s| |%015s| |%-15s| |%0-15s|\n", str, str, str, str);
		// ft_printf("ft_printf\n|%15s| |%015s| |%-15s| |%0-15s|\n", -12, str, -12, str, -12, str, -12, str);
		printf("printf\n|%.*s| |%0.*s| |%-.*s| |%0-.*s| |%015.*s| |%-015.*s| |%-15.*s|\n", -12, str, -12, str, -12, str, -12, str, -12, str, -12, str, -12, str);
		// ft_printf("ft_printf\n|%.*s| |%0.*s| |%-.*s| |%0-.*s| |%015.*s| |%-015.*s| |%-15.*s|\n", -12, str, -12, str, -12, str, -12, str, -12, str, -12, str, -12, str);

		printf("\nTEST str = Hello word | width = 10 | precision = 1\n");
		printf("-----\n");
		printf("printf\n|%10s| |%010s| |%-10s| |%0-10s|\n", str, str, str, str);
		// ft_printf("ft_printf\n|%10s| |%010s| |%-10s| |%0-10s|\n", str, str, str, str);
		printf("printf\n|%.1s| |%0.1s| |%-.1s| |%0-.1s| |%020.1s| |%-020.1s| |%-20.1s|\n", str, str, str, str, str, str, str);
		// ft_printf("ft_printf\n|%.1s| |%0.1s| |%-.1s| |%0-.1s| |%020.1s| |%-020.1s| |%-20.1s|\n", str, str, str, str, str, str, str);

		printf("\nTEST only IS_POINT | width = 20 \n");
		printf("-----\n");
		printf("printf\n|%.s| |%0.s| |%-.s| |%020.s| |%-20.s| |%0-20.s|\n", str, str, str, str, str, str);
		// ft_printf("ft_printf\n|%.s| |%0.s| |%-.s| |%020.s| |%-20.s| |%0-20.s|\n", str, str, str, str, str, str);

		str = "A";
		printf("\nTEST str = Hello word | width = 20 | precision = 5\n");
		printf("-----\n");
		printf("printf\n|%s| |%0s| |%-s| |%20s| |%020s| |%-20s| |%0-20s|\n", str, str, str, str, str, str, str);
		// ft_printf("ft_printf\n|%s| |%0s| |%-s| |%20s| |%020s| |%-20s| |%0-20s|\n", str, str, str, str, str, str, str);
		printf("printf\n|%.5s| |%0.5s| |%-.5s| |%0-.5s| |%020.5s| |%-020.5s| |%-20.5s|\n", str, str, str, str, str, str, str);
		// ft_printf("ft_printf\n|%.5s| |%0.5s| |%-.5s| |%0-.5s| |%020.5s| |%-020.5s| |%-20.5s|\n", str, str, str, str, str, str, str);

		printf("\nTEST str = Hello word | width = 20 | precision = 0\n");
		printf("-----\n");
		printf("printf\n|%20s| |%020s| |%-20s| |%0-20s|\n", str, str, str, str);
		// ft_printf("ft_printf|%20s| |%020s| |%-20s| |%0-20s|\n", str, str, str, str);
		printf("printf\n|%.0s| |%0.0s| |%-.0s| |%0-.0s| |%020.0s| |%-020.0s| |%-20.0s|\n", str, str, str, str, str, str, str);
		// ft_printf("ft_printf\n|%.0s| |%0.0s| |%-.0s| |%0-.0s| |%020.0s| |%-020.0s| |%-20.0s|\n", str, str, str, str, str, str, str);

		printf("\nTEST str = Hello word | width = 4 | precision = 0\n");
		printf("-----\n");
		printf("printf\n|%4s| |%04s| |%-4s| |%0-4s|\n", str, str, str, str);
		// ft_printf("ft_printf\n|%4s| |%04s| |%-4s| |%0-4s|\n", str, str, str, str);
		printf("printf\n|%4s| |%04.0s| |%-04.0s| |%-4.0s|\n", str, str, str, str);
		// ft_printf("ft_printf\n|%4s| |%04.0s| |%-04.0s| |%-4.0s|\n", str, str, str, str);

		printf("\nTEST str = Hello word | width = 15 | precision = -12\n");
		printf("-----\n");
		printf("printf\n|%15s| |%015s| |%-15s| |%0-15s|\n", str, str, str, str);
		// ft_printf("ft_printf\n|%15s| |%015s| |%-15s| |%0-15s|\n", -12, str, -12, str, -12, str, -12, str);
		printf("printf\n|%.*s| |%0.*s| |%-.*s| |%0-.*s| |%015.*s| |%-015.*s| |%-15.*s|\n", -12, str, -12, str, -12, str, -12, str, -12, str, -12, str, -12, str);
		// ft_printf("ft_printf\n|%.*s| |%0.*s| |%-.*s| |%0-.*s| |%015.*s| |%-015.*s| |%-15.*s|\n", -12, str, -12, str, -12, str, -12, str, -12, str, -12, str, -12, str);

		printf("\nTEST str = Hello word | width = 10 | precision = 1\n");
		printf("-----\n");
		printf("printf\n|%10s| |%010s| |%-10s| |%0-10s|\n", str, str, str, str);
		// ft_printf("ft_printf\n|%10s| |%010s| |%-10s| |%0-10s|\n", str, str, str, str);
		printf("printf\n|%.1s| |%0.1s| |%-.1s| |%0-.1s| |%020.1s| |%-020.1s| |%-20.1s|\n", str, str, str, str, str, str, str);
		// ft_printf("ft_printf\n|%.1s| |%0.1s| |%-.1s| |%0-.1s| |%020.1s| |%-020.1s| |%-20.1s|\n", str, str, str, str, str, str, str);

		printf("\nTEST only IS_POINT | width = 20 \n");
		printf("-----\n");
		printf("printf\n|%.s| |%0.s| |%-.s| |%020.s| |%-20.s| |%0-20.s|\n", str, str, str, str, str, str);
		// ft_printf("ft_printf\n|%.s| |%0.s| |%-.s| |%020.s| |%-20.s| |%0-20.s|\n", str, str, str, str, str, str);

		str = "";
		printf("\nTEST str = Hello word | width = 20 | precision = 5\n");
		printf("-----\n");
		printf("printf\n|%s| |%0s| |%-s| |%20s| |%020s| |%-20s| |%0-20s|\n", str, str, str, str, str, str, str);
		// ft_printf("ft_printf\n|%s| |%0s| |%-s| |%20s| |%020s| |%-20s| |%0-20s|\n", str, str, str, str, str, str, str);
		printf("printf\n|%.5s| |%0.5s| |%-.5s| |%0-.5s| |%020.5s| |%-020.5s| |%-20.5s|\n", str, str, str, str, str, str, str);
		// ft_printf("ft_printf\n|%.5s| |%0.5s| |%-.5s| |%0-.5s| |%020.5s| |%-020.5s| |%-20.5s|\n", str, str, str, str, str, str, str);

		printf("\nTEST str = Hello word | width = 20 | precision = 0\n");
		printf("-----\n");
		printf("printf\n|%20s| |%020s| |%-20s| |%0-20s|\n", str, str, str, str);
		// ft_printf("ft_printf|%20s| |%020s| |%-20s| |%0-20s|\n", str, str, str, str);
		printf("printf\n|%.0s| |%0.0s| |%-.0s| |%0-.0s| |%020.0s| |%-020.0s| |%-20.0s|\n", str, str, str, str, str, str, str);
		// ft_printf("ft_printf\n|%.0s| |%0.0s| |%-.0s| |%0-.0s| |%020.0s| |%-020.0s| |%-20.0s|\n", str, str, str, str, str, str, str);

		printf("\nTEST str = Hello word | width = 4 | precision = 0\n");
		printf("-----\n");
		printf("printf\n|%4s| |%04s| |%-4s| |%0-4s|\n", str, str, str, str);
		// ft_printf("ft_printf\n|%4s| |%04s| |%-4s| |%0-4s|\n", str, str, str, str);
		printf("printf\n|%4s| |%04.0s| |%-04.0s| |%-4.0s|\n", str, str, str, str);
		// ft_printf("ft_printf\n|%4s| |%04.0s| |%-04.0s| |%-4.0s|\n", str, str, str, str);

		printf("\nTEST str = Hello word | width = 15 | precision = -12\n");
		printf("-----\n");
		printf("printf\n|%15s| |%015s| |%-15s| |%0-15s|\n", str, str, str, str);
		// ft_printf("ft_printf\n|%15s| |%015s| |%-15s| |%0-15s|\n", -12, str, -12, str, -12, str, -12, str);
		printf("printf\n|%.*s| |%0.*s| |%-.*s| |%0-.*s| |%015.*s| |%-015.*s| |%-15.*s|\n", -12, str, -12, str, -12, str, -12, str, -12, str, -12, str, -12, str);
		// ft_printf("ft_printf\n|%.*s| |%0.*s| |%-.*s| |%0-.*s| |%015.*s| |%-015.*s| |%-15.*s|\n", -12, str, -12, str, -12, str, -12, str, -12, str, -12, str, -12, str);

		printf("\nTEST str = Hello word | width = 10 | precision = 1\n");
		printf("-----\n");
		printf("printf\n|%10s| |%010s| |%-10s| |%0-10s|\n", str, str, str, str);
		// ft_printf("ft_printf\n|%10s| |%010s| |%-10s| |%0-10s|\n", str, str, str, str);
		printf("printf\n|%.1s| |%0.1s| |%-.1s| |%0-.1s| |%020.1s| |%-020.1s| |%-20.1s|\n", str, str, str, str, str, str, str);
		// ft_printf("ft_printf\n|%.1s| |%0.1s| |%-.1s| |%0-.1s| |%020.1s| |%-020.1s| |%-20.1s|\n", str, str, str, str, str, str, str);

		printf("\nTEST only IS_POINT | width = 20 \n");
		printf("-----\n");
		printf("printf\n|%.s| |%0.s| |%-.s| |%020.s| |%-20.s| |%0-20.s|\n", str, str, str, str, str, str);
		// ft_printf("ft_printf\n|%.s| |%0.s| |%-.s| |%020.s| |%-20.s| |%0-20.s|\n", str, str, str, str, str, str);

		str = NULL;
		printf("\nTEST str = Hello word | width = 20 | precision = 5\n");
		printf("-----\n");
		printf("printf\n|%s| |%0s| |%-s| |%20s| |%020s| |%-20s| |%0-20s|\n", str, str, str, str, str, str, str);
		// ft_printf("ft_printf\n|%s| |%0s| |%-s| |%20s| |%020s| |%-20s| |%0-20s|\n", str, str, str, str, str, str, str);
		printf("printf\n|%.5s| |%0.5s| |%-.5s| |%0-.5s| |%020.5s| |%-020.5s| |%-20.5s|\n", str, str, str, str, str, str, str);
		// ft_printf("ft_printf\n|%.5s| |%0.5s| |%-.5s| |%0-.5s| |%020.5s| |%-020.5s| |%-20.5s|\n", str, str, str, str, str, str, str);

		printf("\nTEST str = Hello word | width = 20 | precision = 0\n");
		printf("-----\n");
		printf("printf\n|%20s| |%020s| |%-20s| |%0-20s|\n", str, str, str, str);
		// ft_printf("ft_printf|%20s| |%020s| |%-20s| |%0-20s|\n", str, str, str, str);
		printf("printf\n|%.0s| |%0.0s| |%-.0s| |%0-.0s| |%020.0s| |%-020.0s| |%-20.0s|\n", str, str, str, str, str, str, str);
		// ft_printf("ft_printf\n|%.0s| |%0.0s| |%-.0s| |%0-.0s| |%020.0s| |%-020.0s| |%-20.0s|\n", str, str, str, str, str, str, str);

		printf("\nTEST str = Hello word | width = 4 | precision = 0\n");
		printf("-----\n");
		printf("printf\n|%4s| |%04s| |%-4s| |%0-4s|\n", str, str, str, str);
		// ft_printf("ft_printf\n|%4s| |%04s| |%-4s| |%0-4s|\n", str, str, str, str);
		printf("printf\n|%4s| |%04.0s| |%-04.0s| |%-4.0s|\n", str, str, str, str);
		// ft_printf("ft_printf\n|%4s| |%04.0s| |%-04.0s| |%-4.0s|\n", str, str, str, str);

		printf("\nTEST str = Hello word | width = 15 | precision = -12\n");
		printf("-----\n");
		printf("printf\n|%15s| |%015s| |%-15s| |%0-15s|\n", str, str, str, str);
		// ft_printf("ft_printf\n|%15s| |%015s| |%-15s| |%0-15s|\n", -12, str, -12, str, -12, str, -12, str);
		printf("printf\n|%.*s| |%0.*s| |%-.*s| |%0-.*s| |%015.*s| |%-015.*s| |%-15.*s|\n", -12, str, -12, str, -12, str, -12, str, -12, str, -12, str, -12, str);
		// ft_printf("ft_printf\n|%.*s| |%0.*s| |%-.*s| |%0-.*s| |%015.*s| |%-015.*s| |%-15.*s|\n", -12, str, -12, str, -12, str, -12, str, -12, str, -12, str, -12, str);

		printf("\nTEST str = Hello word | width = 10 | precision = 1\n");
		printf("-----\n");
		printf("printf\n|%10s| |%010s| |%-10s| |%0-10s|\n", str, str, str, str);
		// ft_printf("ft_printf\n|%10s| |%010s| |%-10s| |%0-10s|\n", str, str, str, str);
		printf("printf\n|%.1s| |%0.1s| |%-.1s| |%0-.1s| |%020.1s| |%-020.1s| |%-20.1s|\n", str, str, str, str, str, str, str);
		// ft_printf("ft_printf\n|%.1s| |%0.1s| |%-.1s| |%0-.1s| |%020.1s| |%-020.1s| |%-20.1s|\n", str, str, str, str, str, str, str);

		printf("\nTEST only IS_POINT | width = 20 \n");
		printf("-----\n");
		printf("printf\n|%.s| |%0.s| |%-.s| |%020.s| |%-20.s| |%0-20.s|\n", str, str, str, str, str, str);
		// ft_printf("ft_printf\n|%.s| |%0.s| |%-.s| |%020.s| |%-20.s| |%0-20.s|\n", str, str, str, str, str, str);
		
	}
	printf("\n😎\n");
	return (0);
}
